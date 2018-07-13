//
//  CCCStaffAppointment.h
//  CCCSDK
//
//  Created by Viggnesh Kandasamy on 6/16/17.
//  Copyright © 2017 CCC. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "JSONModelLib.h"

@interface CCCStaffAppointment : JSONModel

@property (nonatomic, strong) NSString <Optional> *appointmentType;
@property (nonatomic, strong) NSArray <NSString *> <Optional> *requiredSkills;

@end
