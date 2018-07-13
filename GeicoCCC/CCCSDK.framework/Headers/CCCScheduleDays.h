//
//  CCCScheduleDays.h
//  CCCSDK
//
//  Created by Viggnesh Kandasamy on 6/15/17.
//  Copyright © 2017 CCC. All rights reserved.
//

#import <CCCSDK/CCCSDK.h>
#import "CCCAppointmentTimeSlots.h"

@protocol CCCScheduleDays;
@interface CCCScheduleDays : JSONModel

@property (nonatomic, strong) NSDate <Optional> *date;
@property (nonatomic, strong) NSArray<CCCAppointmentTimeSlots > *appointmentTimeSlots;
@property (nonatomic, strong) NSString <Optional> *appraiserCode;

@end
