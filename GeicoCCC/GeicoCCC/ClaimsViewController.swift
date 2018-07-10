//
//  ClaimsViewController.swift
//  GeicoCCC
//
//  Created by Ciprian Antal on 28/06/2018.
//  Copyright © 2018 Geico. All rights reserved.
//

import UIKit
import CCCSDK
import CCCPhotoComponents

class ClaimsViewController: UIViewController, UITableViewDelegate, UITableViewDataSource {
    
    @IBOutlet weak var claimsTableView: UITableView!
    @IBOutlet weak var darkBackgroundView: UIView!
    @IBOutlet weak var activityIndicatorView: UIActivityIndicatorView!
    
    internal var currentClaims = [Claim]()
    
    override func viewDidLoad() {
        super.viewDidLoad()
        
        claimsTableView.delegate = self
        claimsTableView.dataSource = self
        claimsTableView.rowHeight =  60
        
        currentClaims.append(Claim(claimID: "346632058010110601", userName: "Bolten"))
        currentClaims.append(Claim(claimID: "310445072010109201", userName: "Jones"))
        currentClaims.append(Claim(claimID: "329812783010101601", userName: "Hawley"))
        currentClaims.append(Claim(claimID: "311100444010101411", userName: "Demo"))
    }
    
    override func viewWillAppear(_ animated: Bool) {
        darkBackgroundView.isHidden = true
        activityIndicatorView.isHidden = true
        activityIndicatorView.stopAnimating()
    }

    // MARK: - Table view methods
    
    func tableView(_ tableView: UITableView, numberOfRowsInSection section: Int) -> Int {
        return currentClaims.count
    }
    
    func numberOfSections(in tableView: UITableView) -> Int {
        return 1
    }
    
    func tableView(_ tableView: UITableView, didSelectRowAt indexPath: IndexPath) {
        darkBackgroundView.isHidden = false
        activityIndicatorView.isHidden = false
        activityIndicatorView.startAnimating()
        
        let cell = claimsTableView.cellForRow(at: indexPath)
        
        authenticateWith(username: cell?.detailTextLabel?.text, claimID: cell?.textLabel?.text)
            
        claimsTableView.deselectRow(at: indexPath, animated: false)
    }
    
    func tableView(_ tableView: UITableView, cellForRowAt indexPath: IndexPath) -> UITableViewCell {
        let cell = claimsTableView.dequeueReusableCell(withIdentifier: "ClaimsCell", for: indexPath) as UITableViewCell
        cell.textLabel?.text = currentClaims[indexPath.row].claimID
        cell.detailTextLabel?.text = currentClaims[indexPath.row].userName
        return cell
    }
    
    internal func authenticateWith(username: String?,claimID: String?) {
        CCCAuth.validate(withClaimID: claimID, lastName: username) { [weak self] (cccAuth, error) in
            if let error = error {
                let alert = UIAlertController(title: "Login error", message: error.localizedDescription,
                                              preferredStyle: .alert)
                alert.addAction(UIAlertAction(title: "Cancel", style: .cancel))
                self?.present(alert, animated: true)
            } else {
                if let sessionToken = cccAuth?.sessionToken {
                    UserDefaults.standard.set(sessionToken, forKey: "CCCSessionToken")
                    UserDefaults.standard.set(claimID, forKey: "CCCClaimId")
                    
                    let homeVC = UIStoryboard(name: "Main", bundle: nil).instantiateViewController(withIdentifier: "HomeViewController")
                    self?.navigationController?.pushViewController(homeVC, animated: true)
                }
            }
        }
    }
}
