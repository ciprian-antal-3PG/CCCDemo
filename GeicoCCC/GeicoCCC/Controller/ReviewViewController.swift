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

class ReviewViewController: BaseViewController, UITableViewDataSource, UITableViewDelegate {
    @IBOutlet private weak var tableView: UITableView!
    @IBOutlet private weak var uploadButton: UIButton!
    
    var photoCaptureVC: CCCPhotoCaptureVC?
    var progressView: UIProgressView?

    private var alertView: UIAlertController?

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

        let cellNib = UINib(nibName: "PhotosTableViewCell", bundle: nil)
        tableView.register(cellNib, forCellReuseIdentifier: "PhotosTableViewCell")
        tableView.rowHeight = UITableViewAutomaticDimension
        tableView.estimatedRowHeight = 10
        
        uploadButton.layer.cornerRadius = uploadButton.frame.width / 2

        if let photoCaptureVC = photoCaptureVC {
           photos = photoCaptureVC.allPhotoCaptureItems()
        }

        var rightBarButtons = navigationItem.rightBarButtonItems
        let addButton = UIBarButtonItem(barButtonSystemItem: .add, target: self, action: #selector(addButtonPressed))
        rightBarButtons?.append(addButton)

        navigationItem.setRightBarButtonItems(rightBarButtons, animated: false)
    }

    func tableView(_ tableView: UITableView, numberOfRowsInSection section: Int) -> Int {
        return cellViewModels.count
    }

    func tableView(_ tableView: UITableView, cellForRowAt indexPath: IndexPath) -> UITableViewCell {
        if let cell = tableView.dequeueReusableCell(withIdentifier: "PhotosTableViewCell", for: indexPath) as? PhotosTableViewCell {
            let cellModel = cellViewModels[indexPath.row]
            cell.photos = cellModel.photos
            cell.title = cellModel.title

            return cell
        }
        return UITableViewCell()
    }

    private func createCellViewModels() {
        let infoPhotos = photos.filter({ $0.photoTitle == "VIN" || $0.photoTitle == "Odometer" })
        let vehiclePhotos = photos.filter({ $0.photoTitle.contains("Side") })
        let damagePhotos = photos.filter({ $0.photoTitle.contains("Damage") })
        let additionalPhotos = photos.filter({ $0.photoTitle.contains("Photo") })

        let models = [PhotosCellViewModel(title: "Information", photos: infoPhotos),
                      PhotosCellViewModel(title: "Vehicle", photos: vehiclePhotos),
                      PhotosCellViewModel(title: "Damage", photos: damagePhotos),
                      PhotosCellViewModel(title: "Additional photos (+)", photos: additionalPhotos)]
        cellViewModels = models
    }

    @objc private func addButtonPressed() {
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
            
            CCCUploadImages.uploadImagesInBackground(withImageList: photos, sessionID: sessionId, success: { _ in
                uploadedPhotoCounter += 1
                if uploadedPhotoCounter == photos.count {
                    self.alertView?.dismiss(animated: true)
                    let alert = UIAlertController(title: "Upload Successful", message: "\(uploadedPhotoCounter)/\(photos.count) photos finished uploading ", preferredStyle: .alert)
                    alert.addAction(UIAlertAction(title: "Dismiss", style: .cancel))
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
}

extension ReviewViewController: CCCPhotoUtilsDelegate {
    func continueButtonTouched(_ storeEntities: [PhotoModel]!) {
        if let photoCaptureVC = photoCaptureVC {
            photos = photoCaptureVC.allPhotoCaptureItems()
        }

        navigationController?.popViewController(animated: true)
    }

    func permissionErrorHandle(_ controller: CCCPhotoCaptureVC!, errorCode code: CCCPermissionErrorCode) {}
}
