//
//  BaseViewController.swift
//  GeicoCCC
//
//  Created by Ciprian Antal on 06/07/2018.
//  Copyright © 2018 Geico. All rights reserved.
//

import UIKit

class BaseViewController: UIViewController {

    override func viewDidLoad() {
        super.viewDidLoad()

        let closeButton = UIBarButtonItem(barButtonSystemItem: .cancel, target: self, action: #selector(cancelButtonPressed))
        navigationItem.rightBarButtonItem = closeButton
    }

    @objc private func cancelButtonPressed() {
        navigationController?.popToRootViewController(animated: true)
    }
}
