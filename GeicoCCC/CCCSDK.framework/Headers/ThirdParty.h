//
//  ThirdParty.h
//  CCCSDK
//
//  Created by Viggnesh Kandasamy on 10/20/16.
//  Copyright © 2016 CCC. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "Policy.h"
#import "JSONModelLib.h"

@interface ThirdParty : JSONModel
@property(strong, nonatomic) NSString <Optional> *thirdPartyInsuranceCarrierName;
@property(strong, nonatomic) NSString <Optional> *thirdPartyClaimNumber;
@property(strong, nonatomic) Policy <Optional> *policy;

@end
