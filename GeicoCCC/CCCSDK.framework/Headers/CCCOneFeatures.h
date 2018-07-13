//
//  CCCOneFeatures.h
//  CCCSDK
//
//  Created by Viggnesh Kandasamy on 6/15/17.
//  Copyright © 2017 CCC. All rights reserved.
//

#import "JSONModelLib.h"
#import <Foundation/Foundation.h>

@protocol CCCOneFeatures;
@interface CCCOneFeatures : JSONModel
@property (nonatomic) BOOL advisor;
@property (nonatomic) BOOL imaging;
@property (nonatomic) BOOL repairOrder;
@property (nonatomic) BOOL updatePlus;

@end
