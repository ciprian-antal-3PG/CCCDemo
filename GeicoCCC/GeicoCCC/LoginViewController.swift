//
//  ViewController.swift
//  GeicoCCC
//
//  Created by Ciprian Antal on 28/06/2018.
//  Copyright © 2018 Geico. All rights reserved.
//

import UIKit
import CCCSDK

class LoginViewController: UIViewController {

    @IBOutlet private weak var claimIdTextField: UITextField!
    @IBOutlet private weak var lastNameTextField: UITextField!

    @IBOutlet private weak var bottomConstraint: NSLayoutConstraint!

    override func viewDidLoad() {
        super.viewDidLoad()

        claimIdTextField.text = "346632058010110601"
        lastNameTextField.text = "Bolten"
    }

    // MARK: - UI Actions

    @IBAction private func loginButtonPressed(_ sender: UIButton) {
        hideKeyboard()

        guard let claimId = claimIdTextField.text, let lastName = lastNameTextField.text else {
            // TODO: Present error: Credentials not provided
            return
        }

        CCCAuth.validate(withClaimID: claimId, lastName: lastName) { (cccAuth, error) in
            if let error = error {
                // TODO:
                print(error.localizedDescription)
            } else {
                // save user Id and session Id
                if let sessionToken = cccAuth?.sessionToken {
                    //TODO: Save session Token and Navigate to home
                    UserDefaults.standard.set(sessionToken, forKey: "CCCSessionToken")
                }
                print("USER ID: \(cccAuth?.userId))" + "/nSESSION ID: \(cccAuth?.sessionToken)")
            }
        }
    }

    @IBAction private func didTapViewController(_ sender: Any) {
        guard claimIdTextField.isFirstResponder || lastNameTextField.isFirstResponder else { return }
        hideKeyboard()
    }

    // MARK: - Private

    private func hideKeyboard() {
        claimIdTextField.resignFirstResponder()
        lastNameTextField.resignFirstResponder()
    }
}
