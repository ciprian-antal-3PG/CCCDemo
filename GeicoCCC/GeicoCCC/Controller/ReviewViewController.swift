//
//  ReviewViewController.swift
//  GeicoCCC
//
//  Created by Ciprian Antal on 09/07/2018.
//  Copyright © 2018 Geico. All rights reserved.
//

import UIKit
import CCCPhotoComponents
import CCCSDK

class ReviewViewController: BaseViewController, UITableViewDataSource, UITableViewDelegate, UITextViewDelegate, UIActionSheetDelegate {
    @IBOutlet private weak var tableView: UITableView!
    @IBOutlet private weak var uploadButton: UIButton!
    @IBOutlet private weak var addPhotosButton: UIButton!

    var photoCaptureVC: CCCPhotoCaptureVC?
    var progressView: UIProgressView?
    private var alertView: UIAlertController?
    private var claimAdditionalText: String = ""

    private var photos: [CCCPhotoCaptureItem] = [] {
        didSet {
            createCellViewModels()
        }
    }

    var cellViewModels: [PhotosCellViewModel] = [] {
        didSet {
            tableView.reloadData()
        }
    }

    override func viewDidLoad() {
        super.viewDidLoad()
        
        let insets = UIEdgeInsets(top: 0, left: 0, bottom: 50, right: 0)
        tableView.contentInset = insets

        let cellNib = UINib(nibName: "PhotosTableViewCell", bundle: nil)
        tableView.register(cellNib, forCellReuseIdentifier: "PhotosTableViewCell")
        tableView.rowHeight = UITableViewAutomaticDimension
        tableView.estimatedRowHeight = 10
        let claimCellNib = UINib(nibName: "ClaimDescriptionTableViewCell", bundle: nil)
        tableView.register(claimCellNib, forCellReuseIdentifier: "ClaimDescriptionTableViewCell")
        
        NotificationCenter.default.addObserver(self, selector: #selector(ReviewViewController.keyboardWillShow), name: NSNotification.Name.UIKeyboardDidShow, object: nil)
        NotificationCenter.default.addObserver(self, selector: #selector(ReviewViewController.keyboardWillHide), name: NSNotification.Name.UIKeyboardWillHide, object: nil)
        
        uploadButton.layer.cornerRadius = uploadButton.frame.width / 2
        addPhotosButton.layer.cornerRadius = uploadButton.frame.width / 2

        if let photoCaptureVC = photoCaptureVC {
           photos = photoCaptureVC.allPhotoCaptureItems()
        }
    }
    
    deinit {
        NotificationCenter.default.removeObserver(self)
    }

    func tableView(_ tableView: UITableView, numberOfRowsInSection section: Int) -> Int {
        return cellViewModels.count + 1 //extra row for claim description
    }

    func tableView(_ tableView: UITableView, cellForRowAt indexPath: IndexPath) -> UITableViewCell {
        if indexPath.row == cellViewModels.count {
            if let cell = tableView.dequeueReusableCell(withIdentifier: "ClaimDescriptionTableViewCell", for: indexPath) as? ClaimDescriptionTableViewCell {
                cell.claimDescriptionTextView.delegate = self
                return cell
            }
        } else if let cell = tableView.dequeueReusableCell(withIdentifier: "PhotosTableViewCell", for: indexPath) as? PhotosTableViewCell {
            let cellModel = cellViewModels[indexPath.row]
            cell.photos = cellModel.photos
            cell.title = cellModel.title
            cell.didTapOnPhoto = { photoItem in
                let alert = UIAlertController(title: photoItem.saveTitle, message: "Would you like to", preferredStyle: .actionSheet)
                alert.addAction(UIAlertAction(title: "Retake", style: .default, handler: {(UIAlertAction)in
                    if let photoVC = self.photoCaptureVC, let photoEntity = CCCPhotoUtils.thumbnailItem(for: CCCQECaptureVehicleTypeSED, withTitle: photoItem.saveTitle) {
                        self.photoCaptureVC = CCCPhotoCaptureVC.createRetakePhoto(withClaimId: photoVC.claimId, delegate: self, andPhotoCaptureEntity: photoEntity)
                        self.navigationController?.pushViewController(self.photoCaptureVC!, animated: true)
                    }
                }))
                alert.addAction(UIAlertAction(title: "Cancel", style: .cancel))
                self.present(alert, animated: true)
            }

            return cell
        }
        return UITableViewCell()
    }
    
    func tableView(_ tableView: UITableView, didSelectRowAt indexPath: IndexPath) {
        tableView.deselectRow(at: indexPath, animated: false)
    }
    
    private func createCellViewModels() {
        let infoPhotos = photos.filter({ $0.saveTitle == "VIN" || $0.saveTitle == "Odometer" || $0.saveTitle == "Registration" })
        let vehiclePhotos = photos.filter({ $0.saveTitle.contains("Side") })
        let damagePhotos = photos.filter({ $0.saveTitle.contains("Damage") })
        let additionalPhotos = photos.filter({ $0.saveTitle.contains("Photo") })

        let models = [PhotosCellViewModel(title: "Information", photos: infoPhotos),
                      PhotosCellViewModel(title: "Vehicle", photos: vehiclePhotos),
                      PhotosCellViewModel(title: "Damage", photos: damagePhotos),
                      PhotosCellViewModel(title: "Additional photos (+)", photos: additionalPhotos)]
        cellViewModels = models
    }

    @IBAction private func addButtonPressed() {
        if let claimId = photoCaptureVC?.claimId {
            photoCaptureVC = CCCPhotoCaptureVC.createAddPhotos(withClaimId: claimId, delegate: self)

            navigationController?.pushViewController(photoCaptureVC!, animated: true)
        }
    }
    
    @IBAction func didTapUploadPhotos(_ sender: Any) {
        
        if let photoCaptureVC = photoCaptureVC, let photos = photoCaptureVC.allPhotoCaptureWithDetails(),
            let sessionId = UserDefaults.standard.value(forKey: "CCCSessionToken") as? String {
            presentUploadStatus()
            var uploadedPhotoCounter = 0
            
            CCCUploadImages.uploadImagesInBackground(withImageList: photos, sessionID: sessionId, damageDescription: claimAdditionalText, success: { _ in
                uploadedPhotoCounter += 1
                if uploadedPhotoCounter == photos.count {
                    self.alertView?.dismiss(animated: true)
                    let alert = UIAlertController(title: "Upload Successful", message: "\(uploadedPhotoCounter)/\(photos.count) photos finished uploading ", preferredStyle: .alert)
                    alert.addAction(UIAlertAction(title: "Dismiss", style: .cancel, handler: { [weak self] (_) in
                        self?.presentConfirmation()
                    }))
                    self.present(alert, animated:true)
                }
            }, failure: { [weak self] (error) in
                self?.alertView?.dismiss(animated: true)
                let alert = UIAlertController(title: "Upload error.", message: error?.localizedDescription,
                                              preferredStyle: .alert)
                alert.addAction(UIAlertAction(title: "Dismiss", style: .cancel))
                self?.present(alert, animated: true)
            }) { [weak self] (progress) in
                self?.progressView?.progress = progress / 100
            }
        }
    }

    private func presentConfirmation() {
        let confirmationVC = UIStoryboard(name: "Main", bundle: nil).instantiateViewController(withIdentifier: "ConfirmationViewController") as? ConfirmationViewController
        confirmationVC?.photoCaptureVC = photoCaptureVC
        confirmationVC?.generalComment = claimAdditionalText
        navigationController?.pushViewController(confirmationVC!, animated: true)
    }
    
    func presentUploadStatus() {
        if let alertView = alertView {
            progressView?.progress = 0
            present(alertView, animated: true)
        } else {
            alertView = UIAlertController(title: "Please wait", message: "Uploading photos", preferredStyle: .alert)
            guard let alertView = alertView else { return }

            let margin: CGFloat = 10.0
            let rect = CGRect(x: margin, y: 68.0, width: 250.0, height: 2.0)
            progressView = UIProgressView(frame: rect)
            progressView?.tintColor = UIColor.blue

            guard let progressView = progressView else { return }
            alertView.view.addSubview(progressView)
            progressView.progress = 0
            present(alertView, animated: true)
        }
    }
    
    @objc func keyboardWillShow(_ notification:Notification) {
        if let keyboardSize = (notification.userInfo?[UIKeyboardFrameBeginUserInfoKey] as? NSValue)?.cgRectValue {
            tableView.contentInset = UIEdgeInsetsMake(0, 0, keyboardSize.height + 50, 0) // 50pt margin above keyboard
        }
    }
    @objc func keyboardWillHide(_ notification:Notification) {
        tableView.contentInset = UIEdgeInsetsMake(0, 0, 50, 0)
    }
    
    func textViewDidBeginEditing(_ textView: UITextView) {
        if claimAdditionalText.isEmpty {
            textView.text = ""
            textView.textColor = UIColor.black
        }
    }
    
    func textViewDidEndEditing(_ textView: UITextView) {
        if textView.text.isEmpty {
            claimAdditionalText = ""
            textView.text = "Add comment to claim"
            textView.textColor = UIColor.lightGray
        } else if textView.text != "Add comment to claim" {
            claimAdditionalText = textView.text
        }
    }
    
    func textView(_ textView: UITextView, shouldChangeTextIn range: NSRange, replacementText text: String) -> Bool {
        if text == "\n" {
            textView.resignFirstResponder()
            return false
        }
        return true
    }
}

extension ReviewViewController: CCCPhotoUtilsDelegate {
    func continueButtonTouched(_ storeEntities: [PhotoModel]!) {
        guard let photoVC = photoCaptureVC else { return }
        if photoVC.mode == CCCPhotoCaptureModeRetakePhoto, let retakePhoto = storeEntities.first {
            CCCPhotoUtils.replacePhotoWithRetakePhoto(withClaimId: photoVC.claimId, title:retakePhoto.title, image: retakePhoto.photo)
        }
        photos = photoVC.allPhotoCaptureItems()
        navigationController?.popViewController(animated: true)
    }

    func permissionErrorHandle(_ controller: CCCPhotoCaptureVC!, errorCode code: CCCPermissionErrorCode) {}
}
