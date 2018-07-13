//
//  CCCAppraiserCapacity.h
//  CCCSDK
//
//  Created by Viggnesh Kandasamy on 6/6/17.
//  Copyright © 2017 CCC. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "CCCSDK_Global.h"
#import "JSONModelLib.h"

@interface CCCAppraiserCapacity : JSONModel
@property (strong, nonatomic) NSNumber <Optional> *claimAssigned;
@property (strong, nonatomic) NSNumber <Optional> *claimAllowed;
@property (strong, nonatomic) NSNumber <Optional> *capacityTimeFrame;

@end
