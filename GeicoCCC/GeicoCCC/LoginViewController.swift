//
//  ViewController.swift
//  GeicoCCC
//
//  Created by Ciprian Antal on 28/06/2018.
//  Copyright © 2018 Geico. All rights reserved.
//

import UIKit
import CCCSDK
import CCCPhotoComponents

class LoginViewController: UIViewController {

    @IBOutlet private weak var claimIdTextField: UITextField!
    @IBOutlet private weak var lastNameTextField: UITextField!
    @IBOutlet private weak var activityIndicator: UIActivityIndicatorView!

    override func viewDidLoad() {
        super.viewDidLoad()

        claimIdTextField.text = "346632058010110601"
        lastNameTextField.text = "Bolten"
    }

    // MARK: - UI Actions

    @IBAction private func loginButtonPressed(_ sender: UIButton) {
        hideKeyboard()
        activityIndicator.startAnimating()

        guard let claimId = claimIdTextField.text, claimId != "", let lastName = lastNameTextField.text, lastName != "" else {
            let alert = UIAlertController(title: "Login error", message: "Please provide credentials.",
                                          preferredStyle: .alert)
            alert.addAction(UIAlertAction(title: "Cancel", style: .cancel))
            present(alert, animated: true)

            activityIndicator.stopAnimating()

            return
        }

        CCCAuth.validate(withClaimID: claimId, lastName: lastName) { [weak self] (cccAuth, error) in
            self?.activityIndicator.stopAnimating()

            if let error = error {
                let alert = UIAlertController(title: "Login error", message: error.localizedDescription,
                                              preferredStyle: .alert)
                alert.addAction(UIAlertAction(title: "Cancel", style: .cancel))
                self?.present(alert, animated: true)
            } else {
                if let sessionToken = cccAuth?.sessionToken {
                    UserDefaults.standard.set(sessionToken, forKey: "CCCSessionToken")
                    UserDefaults.standard.set(claimId, forKey: "CCCClaimId")

                    let homeVC = UIStoryboard(name: "Main", bundle: nil).instantiateViewController(withIdentifier: "HomeViewController")
                    self?.navigationController?.pushViewController(homeVC, animated: true)
                }
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
