//
//  HomeViewController.swift
//  GeicoCCC
//
//  Created by Flaviu Adrian Suciu on 28/06/2018.
//  Copyright © 2018 Geico. All rights reserved.
//

import UIKit
import CCCPhotoComponents

class HomeViewController: UIViewController, UIPickerViewDelegate, UIPickerViewDataSource {

    @IBOutlet weak var numberOfCarPhotosLabel: UILabel!
    @IBOutlet weak var photosLabel: UILabel!
    @IBOutlet weak var styleSwitch: UISwitch!
    @IBOutlet weak var skipVINSwitch: UISwitch!
    @IBOutlet weak var carPickerView: UIPickerView!
    @IBOutlet weak var carTypeLabel: UILabel!
    
    var pickerData: [String] = [String]()
    var isVINEnabled: Bool = true
    var isFreeStyle: Bool = false
    
    override func viewDidLoad() {
        super.viewDidLoad()
        
        self.carPickerView.delegate = self
        self.carPickerView.dataSource = self

        pickerData = ["SUV","Car","Van","Bus"]
        // Do any additional setup after loading the view.
    }

    override func didReceiveMemoryWarning() {
        super.didReceiveMemoryWarning()
        // Dispose of any resources that can be recreated.
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
        print("i selected ", row)
    }
    
    @IBAction func didTapStyleToggle(_ sender: Any) {
        print("Toggled Style")
    }

    @IBAction func didTapVinSwitch(_ sender: Any) {
        print("Toggled VIN enable/disable")
    }
    
    @IBAction func didTapPhotoCapture(_ sender: Any) {
        if let claimId = UserDefaults.standard.value(forKey: "CCCClaimId") as? String {
            let photoCaptureVC: CCCPhotoCaptureVC = CCCPhotoUtils.photoCaptureView(withClaimId: claimId,
                                                                                   vehicleType: CCCQECaptureVehicleTypeSED,
                                                                                   delegate: self, skipVINThumbnail: false,
                                                                                   withDataArray: nil)
            navigationController?.pushViewController(photoCaptureVC, animated: true)
        }

    }
    
    @IBAction func didTapPhotoUpload(_ sender: Any) {
    }
    
    /*
    // MARK: - Navigation

    // In a storyboard-based application, you will often want to do a little preparation before navigation
    override func prepare(for segue: UIStoryboardSegue, sender: Any?) {
        // Get the new view controller using segue.destinationViewController.
        // Pass the selected object to the new view controller.
    }
    */
}

extension HomeViewController: CCCPhotoUtilsDelegate {
    func continueButtonTouched(_ storeEntities: [PhotoModel]!) {
        // TODO: Save photos
    }

    func permissionErrorHandle(_ controller: CCCPhotoCaptureVC!, errorCode code: CCCPermissionErrorCode) {
        // TODO: Present errors
    }
}
