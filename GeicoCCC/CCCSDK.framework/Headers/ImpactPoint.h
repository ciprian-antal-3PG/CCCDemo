//
//  ImpactPoint.h
//  CCCSDK
//
//  Created by Viggnesh Kandasamy on 10/19/16.
//  Copyright © 2016 CCC. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "JSONModelLib.h"
#import "Code.h"
@interface ImpactPoint : JSONModel
@property(strong, nonatomic) Code <Optional> *impactPointNumber;
@property(strong, nonatomic) Code <Optional> *impactAreaCode;

@end
