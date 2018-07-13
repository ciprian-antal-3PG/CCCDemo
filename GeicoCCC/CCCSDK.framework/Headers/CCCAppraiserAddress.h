//
//  CCCAppraiserAddress.h
//  CCCSDK
//
//  Created by Viggnesh Kandasamy on 6/6/17.
//  Copyright © 2017 CCC. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "CCCSDK_Global.h"
#import "JSONModelLib.h"

@interface CCCAppraiserAddress : JSONModel
@property (strong, nonatomic) NSString <Optional> *addressLine;
@property (strong, nonatomic) NSString <Optional> *city;
@property (strong, nonatomic) NSString <Optional> *state;
@property (strong, nonatomic) NSString <Optional> *postalCode;

@end
