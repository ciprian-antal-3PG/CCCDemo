//
//  CCCIncident.h
//  CCCSDK
//
//  Created by Animax Deng on 9/1/16.
//  Copyright © 2016 CCC. All rights reserved.
//

#import <Foundation/Foundation.h>


/**
 FNOL service module
 */
@interface CCCPAFNOL : NSObject


/**
 Vin number with should be same as the vin sent to Vin decode service
 */
@property (strong, nonatomic) NSString *vin;

/**
 Year of the vehicle, should in the list of vin decode service returns
 */
@property (nonatomic) NSInteger year;

/**
 Mark of the vehicle, should in the list of vin decode service returns
 */
@property (strong, nonatomic) NSString *make;

/**
 Model of the vehicle, should in the list of vin decode service returns
 */
@property (strong, nonatomic) NSString *model;

/**`
 Model of the vehicle, should in the list of vin decode service returns
 */
@property (strong, nonatomic) NSString *trim;

/**
 Owner zip code
 */
@property (strong, nonatomic) NSString *ownerZip;

/**
 Owner State
 */
@property (strong, nonatomic) NSString *ownerState;

/**
 Demage image angle
 */
@property (nonatomic) double imageAngle;

/**
 Primary damage code for pointing the primary damage area
 */
@property (nonatomic) NSInteger primaryDamageCode;

/**
 If the vehicle still drivable, Enum value: Yes; No
 */
@property (strong, nonatomic) NSString *drivable;

/**
 If the airbag is deployed, Enum value: Yes; No
 */
@property (strong, nonatomic) NSString *airbagDeployed;

/**
 Number of odometer reading
 */
@property (strong, nonatomic) NSString *odometerReading;

/**
 Does secondary available, Enum value: Yes; No
 */
@property (strong, nonatomic) NSString *secondaryDamage;

/**
 [Optional Param] Claim refernce id
 */
@property (strong, nonatomic) NSString *claimId;

/**
 [Optional Param] Longitude
 */
@property (nonatomic) float longitude;

/**
 [Optional Param] Latitude
 */
@property (nonatomic) float latitude;


/**
 Submit MOI information
 
 @param completionHandler Completed callback
 */
- (void)submitIncident:(void (^) (id data, NSError *error))completionHandler;

@end
