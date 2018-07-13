//
//  CCCAppointmentTimeSlots.h
//  CCCSDK
//
//  Created by Viggnesh Kandasamy on 6/15/17.
//  Copyright © 2017 CCC. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "JSONModel.h"

@protocol CCCAppointmentTimeSlots;
@interface CCCAppointmentTimeSlots : JSONModel

@property (nonatomic, strong) NSString <Optional> *appointmentStartTime;
@property (nonatomic, strong) NSString <Optional> *appointmentEndTime;

@end
