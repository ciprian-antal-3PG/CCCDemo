//
//  ClaimDescriptionTableViewCell.swift
//  GeicoCCC
//
//  Created by Flaviu Adrian Suciu on 13/07/2018.
//  Copyright © 2018 Geico. All rights reserved.
//

import UIKit

class ClaimDescriptionTableViewCell: UITableViewCell {
    
    
    @IBOutlet weak var claimDescriptionTextView: UITextView!
    @IBOutlet weak var titleLabel: UILabel!
    
    override func awakeFromNib() {
        super.awakeFromNib()
        claimDescriptionTextView.layer.cornerRadius = 2
        claimDescriptionTextView.layer.borderWidth = 0.5
        claimDescriptionTextView.layer.borderColor = UIColor.lightGray.cgColor
        claimDescriptionTextView.textContainerInset = UIEdgeInsetsMake(12, 0, 0, 0)
    }
    
}
