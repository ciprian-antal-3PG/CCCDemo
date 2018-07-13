//
//  VehicleUsage.h
//  CCCSDK
//
//  Created by Viggnesh Kandasamy on 10/19/16.
//  Copyright © 2016 CCC. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "JSONModelLib.h"
#import "UsageCode.h"

@interface VehicleUsage : JSONModel
@property(strong, nonatomic) UsageCode <Optional> *usageCode;
@property(strong, nonatomic) NSNumber <Optional> *usage;
@end
