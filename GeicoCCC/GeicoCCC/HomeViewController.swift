//
//  HomeViewController.swift
//  GeicoCCC
//
//  Created by Flaviu Adrian Suciu on 28/06/2018.
//  Copyright © 2018 Geico. All rights reserved.
//

import UIKit
import CCCSDK
import CCCPhotoComponents

class HomeViewController: UIViewController, UIPickerViewDelegate, UIPickerViewDataSource {
    
    @IBOutlet private weak var numberOfCarPhotosLabel: UILabel!
    @IBOutlet private weak var photosLabel: UILabel!
    @IBOutlet private weak var styleSwitch: UISwitch!
    @IBOutlet private weak var skipVINSwitch: UISwitch!
    @IBOutlet private weak var carPickerView: UIPickerView!
    @IBOutlet private weak var carTypeLabel: UILabel!
    @IBOutlet private weak var progressView: UIProgressView!
    @IBOutlet private weak var uploadPhotosButton: UIButton!
    @IBOutlet private weak var uploadedPhotosLabel: UILabel!

    private var pickerData: [String] = [String]()
    private var skipVIN: Bool = false
    private var isWizardStyle: Bool = true
    private var selectedVehicleType: CCCQECaptureVehicleType = CCCQECaptureVehichleTypeUNKNOWN
    private var photoCaptureVC: CCCPhotoCaptureVC?
    private var uploadedPhotosCount: Int = 0 {
        didSet {
            uploadedPhotosLabel.text = "\(uploadedPhotosCount)"
        }
    }
    
    private let vehicleTypesDict = ["Unknown": CCCQECaptureVehichleTypeUNKNOWN,
                                    "Sedan": CCCQECaptureVehicleTypeSED,
                                    "SUV": CCCQECaptureVehicleTypeSUV,
                                    "Coupe": CCCQECaptureVehicleTypeCOUPE,
                                    "HatchBack": CCCQECaptureVehicleTypeHATCHBACK,
                                    "Van": CCCQECaptureVehicleTypeVAN,
                                    "Wagon": CCCQECaptureVehicleTypeWAGON]
    
    override func viewDidLoad() {
        super.viewDidLoad()
        
        carPickerView.delegate = self
        carPickerView.dataSource = self
        
        pickerData = Array(vehicleTypesDict.keys)
    }

    // MARK: UIPickerViewDataSource
    
    func numberOfComponents(in pickerView: UIPickerView) -> Int {
        return 1
    }
    
    func pickerView(_ pickerView: UIPickerView, numberOfRowsInComponent component: Int) -> Int {
        return pickerData.count
    }

    // MARK: UIPickerViewDelegate

    func pickerView(_ pickerView: UIPickerView, titleForRow row: Int, forComponent component: Int) -> String? {
        return pickerData[row]
    }
    
    func pickerView(_ pickerView: UIPickerView, didSelectRow row: Int, inComponent component: Int) {
        if let auxSelectedVehicle = vehicleTypesDict[pickerData[row]] {
            selectedVehicleType = auxSelectedVehicle
        }
    }
    
    @IBAction func didTapStyleToggle(_ sender: Any) {
        print("Toggled Style")
        isWizardStyle = styleSwitch.isOn
    }
    
    @IBAction func didTapVinSwitch(_ sender: Any) {
        print("Toggled VIN enable/disable")
        skipVIN = skipVINSwitch.isOn
    }
    
    @IBAction func didTapPhotoCapture(_ sender: Any) {
        if let claimId = UserDefaults.standard.value(forKey: "CCCClaimId") as? String {
            photoCaptureVC = CCCPhotoUtils.photoCaptureView(withClaimId: claimId, vehicleType: CCCQECaptureVehicleTypeSED,
                                                            delegate: self, skipVINThumbnail: skipVIN,
                                                            withDataArray: nil)
            photoCaptureVC?.enableWizardStyle = isWizardStyle
            navigationController?.pushViewController(photoCaptureVC!, animated: true)
        }
    }
    
    @IBAction func didTapPhotoUpload(_ sender: Any) {
        if let photoCaptureVC = photoCaptureVC, let photos = photoCaptureVC.allPhotoCaptureWithDetails(),
            let sessionId = UserDefaults.standard.value(forKey: "CCCSessionToken") as? String {
            progressView.progress = 0
            progressView.isHidden = false
            uploadedPhotosCount = 0

            CCCUploadImages.uploadImagesInBackground(withImageList: photos, sessionID: sessionId, success: { [weak self] _ in
                self?.uploadedPhotosCount += 1
            }, failure: { [weak self] (error) in
                let alert = UIAlertController(title: "Upload error.", message: error?.localizedDescription,
                                              preferredStyle: .alert)
                alert.addAction(UIAlertAction(title: "Cancel", style: .cancel))
                self?.present(alert, animated: true)
            }) { [weak self] (progress) in
                self?.progressView.progress = progress / 100

                if progress == 100 {
                    let alert = UIAlertController(title: "Upload finished.", message: "Success.",
                                                  preferredStyle: .alert)
                    alert.addAction(UIAlertAction(title: "Cancel", style: .cancel))
                    self?.present(alert, animated: true)
                    self?.progressView.isHidden = true
                }
            }
        }
    }
}

extension HomeViewController: CCCPhotoUtilsDelegate {
    func continueButtonTouched(_ storeEntities: [PhotoModel]!) {
        // TODO: Save photos
        
        if (storeEntities.count > 0) {
            uploadPhotosButton.isEnabled = true
            numberOfCarPhotosLabel.text = "\(storeEntities.count)"
        }
        
        navigationController?.popViewController(animated: true)
    }

    func permissionErrorHandle(_ controller: CCCPhotoCaptureVC!, errorCode code: CCCPermissionErrorCode) {
        // TODO: Present errors
    }
}
