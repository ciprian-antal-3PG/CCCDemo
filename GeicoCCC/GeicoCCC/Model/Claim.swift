//
//  Claim.swift
//  GeicoCCC
//
//  Created by Flaviu Adrian Suciu on 06/07/2018.
//  Copyright © 2018 Geico. All rights reserved.
//

import UIKit

struct Claim {
    let claimID: String
    let username: String
    var vin: String?

    init(claimID: String, username: String, vin: String? = nil) {
        self.claimID = claimID
        self.username = username
        self.vin = vin
    }
}
