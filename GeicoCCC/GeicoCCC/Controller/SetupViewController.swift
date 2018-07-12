//
//  SetupViewController.swift
//  GeicoCCC
//
//  Created by Flaviu Adrian Suciu on 28/06/2018.
//  Copyright © 2018 Geico. All rights reserved.
//

import UIKit
import CCCSDK
import CCCPhotoComponents

class SetupViewController: BaseViewController, UIPickerViewDelegate, UIPickerViewDataSource {

    @IBOutlet private weak var skipVINSwitch: UISwitch!
    @IBOutlet private weak var carPickerView: UIPickerView!
    @IBOutlet private weak var carTypeLabel: UILabel!
    
    private var pickerData: [String] = [String]()
    private var skipVIN: Bool = false
    private var selectedVehicleType: CCCQECaptureVehicleType = CCCQECaptureVehichleTypeUNKNOWN
    private var photoCaptureVC: CCCPhotoCaptureVC?
    
    private let vehicleTypesDict = ["Unknown": CCCQECaptureVehichleTypeUNKNOWN,
                                    "Sedan": CCCQECaptureVehicleTypeSED,
                                    "SUV": CCCQECaptureVehicleTypeSUV,
                                    "Coupe": CCCQECaptureVehicleTypeCOUPE,
                                    "HatchBack": CCCQECaptureVehicleTypeHATCHBACK,
                                    "Van": CCCQECaptureVehicleTypeVAN,
                                    "Wagon": CCCQECaptureVehicleTypeWAGON]
    
    override func viewDidLoad() {
        super.viewDidLoad()

        setup()
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

    // MARK: UI Actions

    @IBAction private func didTapVinSwitch(_ sender: Any) {
        skipVIN = skipVINSwitch.isOn
    }
    
    @IBAction private func didTapPhotoCapture(_ sender: Any) {
        checkCameraPermission { [weak self] (authorized) in
            guard let strongSelf = self else { return }
            guard let claimId = UserDefaults.standard.value(forKey: "CCCClaimId") as? String else { return }

            if !authorized {
                strongSelf.displayAlert(title: "Camera access needed", message: "Permission needed to continue photo capturing.")

                return
            }

            if !strongSelf.checkLocationPermission() {
                strongSelf.displayAlert(title: "Location access needed", message: "Location message.")

                return
            }
            strongSelf.photoCaptureVC = CCCPhotoUtils.photoCaptureView(withClaimId: claimId,
                                                                       vehicleType: strongSelf.selectedVehicleType,
                                                                       delegate: self,
                                                                       skipVINThumbnail: strongSelf.skipVIN,
                                                                       withDataArray: nil)
            strongSelf.present(strongSelf.photoCaptureVC!, animated: true)
        }
    }

    // MARK: Private

    private func setup() {
        setupPickerView()
    }

    private func setupPickerView() {
        carPickerView.delegate = self
        carPickerView.dataSource = self

        pickerData = Array(vehicleTypesDict.keys)

        if let firstValue = pickerData.first, let auxSelectedVehicle = vehicleTypesDict[firstValue] {
            selectedVehicleType = auxSelectedVehicle
        }
    }

    private func checkCameraPermission(completion: ((Bool) -> ())?) {
        switch AVCaptureDevice.authorizationStatus(for: .video) {
        case .authorized:
            completion?(true)
        case .notDetermined:
            AVCaptureDevice.requestAccess(for: .video) { granted in
                DispatchQueue.main.async {
                    if granted {
                        completion?(true)
                    } else {
                        completion?(false)
                    }
                }
            }
        case .denied:
            completion?(false)
        case .restricted:
            completion?(false)
        }
    }

    private func checkLocationPermission() -> Bool {
        return CLLocationManager.authorizationStatus() == .authorizedWhenInUse ||
            CLLocationManager.authorizationStatus() == .authorizedAlways ||
            CLLocationManager.authorizationStatus() == .notDetermined
    }

    private func displayAlert(title: String, message: String) {
        let alert = UIAlertController(title: title, message: message, preferredStyle: .alert)
        alert.addAction(UIAlertAction(title: "Cancel", style: .cancel))

        present(alert, animated: true)
    }
}

extension SetupViewController: CCCPhotoUtilsDelegate {
    func continueButtonTouched(_ storeEntities: [PhotoModel]!) {
        if storeEntities.count > 0, var viewControllers = navigationController?.viewControllers,
            let reviewVC = UIStoryboard(name: "Main", bundle: nil).instantiateViewController(withIdentifier: "ReviewViewController") as? ReviewViewController {
            reviewVC.photos = storeEntities
            reviewVC.photoCaptureVC = photoCaptureVC
            viewControllers.append(reviewVC)

            navigationController?.viewControllers = viewControllers
        }

        photoCaptureVC?.dismiss(animated: true)
    }

    func permissionErrorHandle(_ controller: CCCPhotoCaptureVC!, errorCode code: CCCPermissionErrorCode) {
        if code == CCCPermissionErrorCodeLocationDenied || code == CCCPermissionErrorCodeCameraRestricted {
            controller.dismiss(animated: true) { [weak self] in
                self?.displayAlert(title: "Location access needed", message: "Location message.")
            }
        }
    }
}
