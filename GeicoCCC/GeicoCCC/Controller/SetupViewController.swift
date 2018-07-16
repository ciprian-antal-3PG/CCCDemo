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

    var claim: Claim?

    @IBOutlet private weak var vinTextLabel: UILabel!
    @IBOutlet private weak var scanVinButton: UIButton!
    @IBOutlet private weak var confirmVinButton: UIButton!
    @IBOutlet private weak var vinLabel: UILabel!

    @IBOutlet private weak var carPickerView: UIPickerView!

    private var pickerData: [String] = [String]()
    private var vinConfirmed: Bool = false
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
        populateVIN()
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
    @IBAction func confirmVinButtonPressed(_ sender: UIButton) {
        sender.isEnabled = false
        scanVinButton.isHidden = true
        vinConfirmed = true
    }

    @IBAction func scanVinButtonPressed(_ sender: Any) {
        let alert = UIAlertController(title: "Scan VIN", message: "Entry point to vin scanning. Will be implemented in the integration phase.", preferredStyle: .alert)
        alert.addAction(UIAlertAction(title: "Simulate scan", style: .cancel, handler: { [weak self] (_) in
            self?.scanVinButton.isHidden = true
            self?.confirmVinButton.isEnabled = false
            self?.confirmVinButton.isHidden = false
            self?.vinConfirmed = true
            self?.vinLabel.text = "WF0HXXWPJH7M88550"
            self?.vinLabel.isHidden = false
            self?.vinTextLabel.isHidden = false
        }))
        present(alert, animated: true)
    }

    @IBAction private func didTapPhotoCapture(_ sender: Any) {
        checkCameraPermission { [weak self] (authorized) in
            guard let strongSelf = self else { return }
            guard let claimId = self?.claim?.claimID else { return }

            if !authorized {
                strongSelf.displayAlert(title: "Camera access needed", message: "Go to Settings to allow camera access.")

                return
            }

            if !strongSelf.checkLocationPermission() {
                strongSelf.displayAlert(title: "Location access needed", message: "Go to Settings to enable location services while using the app.")

                return
            }

            strongSelf.photoCaptureVC = CCCPhotoUtils.photoCaptureView(withClaimId: claimId,
                                                                       vehicleType: strongSelf.selectedVehicleType,
                                                                       delegate: self,
                                                                       skipVINThumbnail: false,
                                                                       withDataArray: nil)

            if strongSelf.vinConfirmed, let photoEntities = strongSelf.photoCaptureVC?.thumbnailItems as? [CCCPhotoCaptureEntity] {
                let sorted = photoEntities.filter({ $0.title != "VIN" })
                strongSelf.photoCaptureVC = CCCPhotoCaptureVC.create(withClaimId: claimId, delegate: self, andCustomItems: sorted)
            }

            strongSelf.photoCaptureVC?.enableWizardStyle = true
            strongSelf.present(strongSelf.photoCaptureVC!, animated: true)
        }
    }

    // MARK: Private

    private func populateVIN() {
        guard let vin = claim?.vin else {
            vinLabel.isHidden = true
            vinTextLabel.isHidden = true
            confirmVinButton.isHidden = true

            return
        }
        vinLabel.text = vin
    }

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
