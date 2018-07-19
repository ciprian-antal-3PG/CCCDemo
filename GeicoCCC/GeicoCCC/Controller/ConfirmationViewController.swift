//
//  ConfirmationViewController.swift
//  GeicoCCC
//
//  Created by Ciprian Antal on 17/07/2018.
//  Copyright © 2018 Geico. All rights reserved.
//

import UIKit
import CCCPhotoComponents

class ConfirmationViewController: BaseViewController, UITableViewDataSource {

    @IBOutlet weak var tableView: UITableView!

    var photoCaptureVC: CCCPhotoCaptureVC?
    var generalComment: String = ""

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

        if let photoCaptureVC = photoCaptureVC {
            photos = photoCaptureVC.allPhotoCaptureItems()
        }

        navigationItem.hidesBackButton = true
    }

    func tableView(_ tableView: UITableView, numberOfRowsInSection section: Int) -> Int {
        return generalComment.isEmpty ? cellViewModels.count : cellViewModels.count + 1
    }

    func tableView(_ tableView: UITableView, cellForRowAt indexPath: IndexPath) -> UITableViewCell {
        switch indexPath.row {
        case 0:
            if let cell = tableView.dequeueReusableCell(withIdentifier: "PhotosTableViewCell", for: indexPath) as? PhotosTableViewCell {
                let cellModel = cellViewModels[indexPath.row]
                cell.photos = cellModel.photos
                cell.title = cellModel.title

                return cell
            }
        case 1:
            if !generalComment.isEmpty {
                let cell = tableView.dequeueReusableCell(withIdentifier: "CommentCell", for: indexPath)
                cell.textLabel?.text = "Comment: " + generalComment

                return cell
            }
        default: break
        }
        return UITableViewCell()
    }

    private func createCellViewModels() {
        cellViewModels = [PhotosCellViewModel(title: "Photos submitted", photos: photos)]
    }
}
