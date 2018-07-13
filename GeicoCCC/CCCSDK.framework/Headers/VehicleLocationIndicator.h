//
//  VehicleLocationIndicator.h
//  CCCSDK
//
//  Created by Viggnesh Kandasamy on 2/16/17.
//  Copyright © 2017 CCC. All rights reserved.
//

#import "JSONModel.h"
#import "JSONModelLib.h"

typedef enum  {
    /**OH – Vehicle Owner home address*/
    VehicleLocationIndicator_OH,
    /**OW – Vehicle Owner work address*/
    VehicleLocationIndicator_OW,
    /**AR – At approved repair facility*/
    VehicleLocationIndicator_AR,
    /**NR – At non-approved repair*/
    VehicleLocationIndicator_NR,
    /**SY – At Salvage Yard*/
    VehicleLocationIndicator_SY,
    /**DF – Atdrive-in facility*/
    VehicleLocationIndicator_DF,
    /**Other*/
    VehicleLocationIndicator_O
}VehicleLocationIndicatorEnum;

@interface VehicleLocationIndicator : JSONModel
@property(assign, nonatomic) VehicleLocationIndicatorEnum vehicleLocationIndicatorEnum;
@property (strong, nonatomic, readonly) NSString *code;

@end
