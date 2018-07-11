//
//  ReviewViewController.swift
//  GeicoCCC
//
//  Created by Ciprian Antal on 09/07/2018.
//  Copyright © 2018 Geico. All rights reserved.
//

import UIKit
import CCCPhotoComponents

class ReviewViewController: BaseViewController, UITableViewDataSource, UITableViewDelegate {
    @IBOutlet weak var tableView: UITableView!

    var photos: [PhotoModel]?

    var cellViewModels: [PhotosCellViewModel] = [] {
        didSet {
            tableView.reloadData()
        }
    }

    override func viewDidLoad() {
        super.viewDidLoad()

        let cellNib = UINib(nibName: "PhotosTableViewCell", bundle: nil)
        tableView.register(cellNib, forCellReuseIdentifier: "PhotosTableViewCell")

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
}

extension ReviewViewController: UICollectionViewDelegate {
    func collectionView(_ collectionView: UICollectionView, didSelectItemAt indexPath: IndexPath) {
        print("image selected")
    }
}
