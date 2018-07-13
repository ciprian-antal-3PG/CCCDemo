//
//  VehicleLocation.h
//  CCCSDK
//
//  Created by Viggnesh Kandasamy on 10/19/16.
//  Copyright © 2016 CCC. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "JSONModelLib.h"
#import "VehicleLocationIndicator.h"
#import "Address.h"
#import "Contact.h"
@interface VehicleLocation : JSONModel
    @property(strong, nonatomic) VehicleLocationIndicator <Optional> *vehicleLocationIndicator;
    @property(strong, nonatomic) Address <Optional> *address;
    @property(strong, nonatomic) Contact <Optional> *vehicleLocationContact;

@end
