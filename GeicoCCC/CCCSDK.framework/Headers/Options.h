//
//  Options.h
//  CCCSDK
//
//  Created by Viggnesh Kandasamy on 10/19/16.
//  Copyright © 2016 CCC. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "VehicleOption.h"
#import "JSONModelLib.h"

@interface Options : JSONModel
@property(nonatomic, strong) NSMutableArray<VehicleOption *> <Optional> *vehicleOption;
@end
