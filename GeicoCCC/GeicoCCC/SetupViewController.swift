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
        if let claimId = UserDefaults.standard.value(forKey: "CCCClaimId") as? String {
            photoCaptureVC = CCCPhotoUtils.photoCaptureView(withClaimId: claimId, vehicleType: selectedVehicleType,
                                                            delegate: self, skipVINThumbnail: skipVIN,
                                                            withDataArray: nil)
            navigationController?.pushViewController(photoCaptureVC!, animated: true)
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
}

extension SetupViewController: CCCPhotoUtilsDelegate {
    func continueButtonTouched(_ storeEntities: [PhotoModel]!) {
        
        navigationController?.popViewController(animated: true)
    }

    func permissionErrorHandle(_ controller: CCCPhotoCaptureVC!, errorCode code: CCCPermissionErrorCode) {
        // TODO: Present errors
    }
}
