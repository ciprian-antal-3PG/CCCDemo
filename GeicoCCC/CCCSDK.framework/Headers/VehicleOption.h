//
//  VehicleOption.h
//  CCCSDK
//
//  Created by Viggnesh Kandasamy on 10/19/16.
//  Copyright © 2016 CCC. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "JSONModelLib.h"

@interface VehicleOption : JSONModel
@property(nonatomic, strong) NSString <Optional> *optionCode;
@property(nonatomic, strong) NSString <Optional> *optionDescription;
@end
