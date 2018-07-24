//
//  PhotoCollectionViewCell.swift
//  GeicoCCC
//
//  Created by Ciprian Antal on 10/07/2018.
//  Copyright © 2018 Geico. All rights reserved.
//

import UIKit

class PhotoCollectionViewCell: UICollectionViewCell {
    @IBOutlet weak var imageView: UIImageView!
    @IBOutlet weak var titleLabel: UILabel!

    func setup(image: UIImage, title: String) {
        imageView.image = image
        titleLabel.text = title
    }

    override var isSelected: Bool {
        didSet {
            imageView.alpha = isSelected ? 0.5 : 1
        }
    }

    override var isHighlighted: Bool {
        didSet {
            imageView.alpha = isHighlighted ? 0.5 : 1
        }
    }
}
