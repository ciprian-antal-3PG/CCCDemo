//
//  PhotosTableViewCell.swift
//  GeicoCCC
//
//  Created by Ciprian Antal on 10/07/2018.
//  Copyright © 2018 Geico. All rights reserved.
//

import UIKit
import CCCPhotoComponents

class PhotosTableViewCell: UITableViewCell, UICollectionViewDataSource, UICollectionViewDelegate {

    var photos: [CCCPhotoCaptureItem] = [] {
        didSet {
            collectionView.reloadData()
        }
    }

    var title: String = "" {
        didSet {
            titleLabel.text = title
        }
    }
    
    var didTapOnPhoto: ((CCCPhotoCaptureItem)->())?

    @IBOutlet weak var titleLabel: UILabel!
    @IBOutlet weak var collectionViewHeight: NSLayoutConstraint!
    @IBOutlet weak var collectionView: UICollectionView!

    override func awakeFromNib() {
        super.awakeFromNib()
        let nib = UINib(nibName: "PhotoCollectionViewCell", bundle: nil)
        collectionView.register(nib, forCellWithReuseIdentifier: "PhotoCollectionViewCell")
        collectionView.dataSource = self
        collectionView.delegate = self
    }

    func collectionView(_ collectionView: UICollectionView, cellForItemAt indexPath: IndexPath) -> UICollectionViewCell {
        if let cell = collectionView.dequeueReusableCell(withReuseIdentifier: "PhotoCollectionViewCell", for: indexPath) as? PhotoCollectionViewCell {
            cell.setup(image: photos[indexPath.row].photo, title: photos[indexPath.row].saveTitle)

            return cell
        }

        return UICollectionViewCell()
    }

    func collectionView(_ collectionView: UICollectionView, numberOfItemsInSection section: Int) -> Int {
        return photos.count
    }
    
    func collectionView(_ collectionView: UICollectionView, didSelectItemAt indexPath: IndexPath) {
        didTapOnPhoto?(photos[indexPath.row])
    }

    override func systemLayoutSizeFitting(_ targetSize: CGSize, withHorizontalFittingPriority horizontalFittingPriority: UILayoutPriority, verticalFittingPriority: UILayoutPriority) -> CGSize {
        let automaticSize = super.systemLayoutSizeFitting(targetSize, withHorizontalFittingPriority: horizontalFittingPriority, verticalFittingPriority: verticalFittingPriority)

        collectionView.frame = CGRect(x: 0, y: 0, width: targetSize.width, height: 1)
        collectionViewHeight.constant = collectionView.collectionViewLayout.collectionViewContentSize.height

        let collectionHeight = collectionView.collectionViewLayout.collectionViewContentSize.height

        return CGSize(width: automaticSize.width, height: automaticSize.height + collectionHeight)
    }
    
    override func point(inside point: CGPoint, with event: UIEvent?) -> Bool {
        print("Passing all touches to the next view (if any), in the view stack.")
        return true
    }
}
