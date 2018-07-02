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
    
    @IBOutlet weak var numberOfCarPhotosLabel: UILabel!
    @IBOutlet weak var photosLabel: UILabel!
    @IBOutlet weak var styleSwitch: UISwitch!
    @IBOutlet weak var skipVINSwitch: UISwitch!
    @IBOutlet weak var carPickerView: UIPickerView!
    @IBOutlet weak var carTypeLabel: UILabel!
    
    private var pickerData: [String] = [String]()
    private var isVINEnabled: Bool = true
    private var isFreeStyle: Bool = false
    private var selectedVehicleType: CCCQECaptureVehicleType = CCCQECaptureVehichleTypeUNKNOWN
    
    private let vehicleTypesDict = ["Unknown": CCCQECaptureVehichleTypeUNKNOWN,
                                    "Sedan": CCCQECaptureVehicleTypeSED,
                                    "SUV": CCCQECaptureVehicleTypeSUV,
                                    "Coupe": CCCQECaptureVehicleTypeCOUPE,
                                    "HatchBack": CCCQECaptureVehicleTypeHATCHBACK,
                                    "Van": CCCQECaptureVehicleTypeVAN,
                                    "Wagon": CCCQECaptureVehicleTypeWAGON]
    
    override func viewDidLoad() {
        super.viewDidLoad()
        
        self.carPickerView.delegate = self
        self.carPickerView.dataSource = self
        
        pickerData = Array(vehicleTypesDict.keys)
        self.styleSwitch .setOn(false, animated: false)
        self.skipVINSwitch .setOn(false, animated: false)
        
    }
    
    func numberOfComponents(in pickerView: UIPickerView) -> Int {
        return 1
    }
    
    func pickerView(_ pickerView: UIPickerView, numberOfRowsInComponent component: Int) -> Int {
        return pickerData.count
    }
    
    func pickerView(_ pickerView: UIPickerView, titleForRow row: Int, forComponent component: Int) -> String? {
        return pickerData[row]
    }
    
    func pickerView(_ pickerView: UIPickerView, didSelectRow row: Int, inComponent component: Int) {
        if let auxSelectedVehicle = vehicleTypesDict[pickerData[row]] {
            self.selectedVehicleType = auxSelectedVehicle
        }
    }
    
    @IBAction func didTapStyleToggle(_ sender: Any) {
        print("Toggled Style")
        self.isFreeStyle = self.styleSwitch.isOn
    }
    
    @IBAction func didTapVinSwitch(_ sender: Any) {
        print("Toggled VIN enable/disable")
        self.isVINEnabled = !self.skipVINSwitch.isOn
    }
    
    @IBAction func didTapPhotoCapture(_ sender: Any) {
    }
    
    @IBAction func didTapPhotoUpload(_ sender: Any) {
    }
    
}
