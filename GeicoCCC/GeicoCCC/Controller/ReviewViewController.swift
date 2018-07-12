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
    @IBOutlet weak var tableView: UITableView!
    @IBOutlet weak var uploadButton: UIButton!
    
    var photoCaptureVC: CCCPhotoCaptureVC?
    private var alertView: UIAlertController?
    var photos: [PhotoModel]?
    var progressView: UIProgressView?

    var cellViewModels: [PhotosCellViewModel] = [] {
        didSet {
            tableView.reloadData()
        }
    }

    override func viewDidLoad() {
        super.viewDidLoad()

        let cellNib = UINib(nibName: "PhotosTableViewCell", bundle: nil)
        tableView.register(cellNib, forCellReuseIdentifier: "PhotosTableViewCell")
        
        uploadButton.layer.cornerRadius = uploadButton.frame.width / 2

        cellViewModels = createCellViewModels()
    }

    func tableView(_ tableView: UITableView, numberOfRowsInSection section: Int) -> Int {
        return cellViewModels.count
    }

    func tableView(_ tableView: UITableView, cellForRowAt indexPath: IndexPath) -> UITableViewCell {
        if let cell = tableView.dequeueReusableCell(withIdentifier: "PhotosTableViewCell", for: indexPath) as? PhotosTableViewCell {
            let cellModel = cellViewModels[indexPath.row]
            cell.photos = cellModel.photos
            cell.title = cellModel.title
            cell.setCollectionViewDataSourceDelegate(self)

            return cell
        }
        return UITableViewCell()
    }

    private func createCellViewModels() -> [PhotosCellViewModel] {
        let infoPhotos = photos?.filter({ $0.title == "VIN" || $0.title == "Odometer" }) ?? []
        let vehiclePhotos = photos?.filter({ $0.title.contains("Side") }) ?? []
        let damagePhotos = photos?.filter({ $0.title.contains("Damage") }) ?? []

        return [PhotosCellViewModel(title: "Information", photos: infoPhotos),
                PhotosCellViewModel(title: "Vehicle", photos: vehiclePhotos),
                PhotosCellViewModel(title: "Damage", photos: damagePhotos)]
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
            //alertView.addAction(UIAlertAction(title: "Cancel", style: .cancel))
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

extension ReviewViewController: UICollectionViewDelegate {
    func collectionView(_ collectionView: UICollectionView, didSelectItemAt indexPath: IndexPath) {
        print("image selected")
    }
}
