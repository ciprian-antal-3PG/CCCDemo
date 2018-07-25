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
import CCCVINScanComponent

class SetupViewController: BaseViewController, UIPickerViewDelegate, UIPickerViewDataSource {
    var claim: Claim?

    @IBOutlet private weak var vinTextLabel: UILabel!
    @IBOutlet private weak var scanVinButton: UIButton!
    @IBOutlet private weak var confirmVinButton: UIButton!
    @IBOutlet private weak var vinLabel: UILabel!
    @IBOutlet private weak var carTypeLabel: UILabel!

    @IBOutlet private weak var carPickerView: UIPickerView!
    @IBOutlet private weak var activityIndicator: UIActivityIndicatorView!

    private var pickerData: [String] = [String]()
    private var vinScanned: Bool = false

    private var hasVinOnFile: Bool {
        return photoCaptureVC?.allPhotoCaptureItems().contains(where: {$0.saveTitle == "VIN"}) ?? false
    }

    private var selectedVehicleType: CCCQECaptureVehicleType = CCCQECaptureVehichleTypeUNKNOWN

    private var photoCaptureVC: CCCPhotoCaptureVC?
    private var vinScanVC: CCCVINCaptureVC?

    private let vehicleTypesDict = ["UNKNOWN": CCCQECaptureVehichleTypeUNKNOWN,
                                    "SED": CCCQECaptureVehicleTypeSED,
                                    "SUV": CCCQECaptureVehicleTypeSUV,
                                    "COUPE": CCCQECaptureVehicleTypeCOUPE,
                                    "HATCHBACK": CCCQECaptureVehicleTypeHATCHBACK,
                                    "VAN": CCCQECaptureVehicleTypeVAN,
                                    "WAGON": CCCQECaptureVehicleTypeWAGON]
    
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
    }

    @IBAction func scanVinButtonPressed(_ sender: Any) {
        guard let claimId = claim?.claimID else { return }
        vinScanVC = CCCVINCaptureVC.createVinScannerManualOptionView(with: self, claimId: claimId)
        vinScanVC?.hasBackButton = true

        present(vinScanVC!, animated: true)
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


            guard var thumbnailItems = strongSelf.photoCaptureVC?.thumbnailItems as? [CCCPhotoCaptureEntity] else { return }

            if let registrationItem = CCCPhotoCaptureEntity.create(withTitle: "Registration", thumbnail: #imageLiteral(resourceName: "Placeholder"),
                                                                overlayHeader: "Registration header",
                                                                overlayTitle: "Registration title",
                                                                overlayDesc: "Registration description",
                                                                overlayImage: #imageLiteral(resourceName: "Placeholder"), cameraOverlayIamge: nil,
                                                                overlayAutoDisplay: true, saveTitle: "Registration") {
                thumbnailItems.insert(registrationItem, at: thumbnailItems.count - 1)
            }

            if (strongSelf.vinScanned || strongSelf.hasVinOnFile) {
                thumbnailItems = thumbnailItems.filter({ $0.title != "VIN" })
            }
            strongSelf.photoCaptureVC = CCCPhotoCaptureVC.create(withClaimId: claimId, delegate: self, andCustomItems: thumbnailItems)

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
        decodeVIN()
    }

    private func setup() {
        setupPickerView()

        guard let claimId = claim?.claimID else { return }
        photoCaptureVC = CCCPhotoUtils.photoCaptureView(withClaimId: claimId,
                                                        vehicleType: selectedVehicleType,
                                                        delegate: self,
                                                        skipVINThumbnail: false,
                                                        withDataArray: nil)
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

extension SetupViewController: VinScannerVCDelegate {
    func didCompleteScanning(_ vinNumber: String!, isVINScanned: Bool, isVINValid: Bool, error: Error!) {
        guard isVINValid else {
            vinScanVC?.dismiss(animated: true)
            let alert = UIAlertController(title: "Error", message: "This is not a valid VIN. Please try again", preferredStyle: .alert)
            alert.addAction(UIAlertAction(title: "Cancel", style: .cancel))
            present(alert, animated: true)
            return
        }
        claim?.vin = vinNumber
        vinScanned = isVINScanned
        vinLabel.text = claim?.vin
        confirmVinButton.isEnabled = false
        confirmVinButton.isHidden = false
        vinLabel.isHidden = false
        vinTextLabel.isHidden = false
        scanVinButton.isHidden = true

        decodeVIN()
        
        vinScanVC?.dismiss(animated: true)
    }

    private func decodeVIN() {
        carTypeLabel.text = "Car Type: Detecting..."
        activityIndicator.startAnimating()

        CCCVinDecode.decodeVIN(claim?.vin) { [weak self] (vehicles, _) in
            guard let strongSelf = self else { return }

            let bodyType = vehicles?.first?.bodyType ?? "UNKNOWN"
            let index = strongSelf.pickerData.index(of: bodyType) ?? (strongSelf.pickerData.index(of: "UNKNOWN") ?? 0)

            strongSelf.carTypeLabel.text = "Car Type: \(bodyType)"
            strongSelf.carPickerView.selectRow(index, inComponent: 0, animated: true)
            strongSelf.selectedVehicleType = strongSelf.vehicleTypesDict[strongSelf.pickerData[index]] ?? CCCQECaptureVehichleTypeUNKNOWN
            strongSelf.activityIndicator.stopAnimating()
        }
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
