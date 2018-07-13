//
//  Appointment.h
//  CCCSDK
//
//  Created by Viggnesh Kandasamy on 10/19/16.
//  Copyright © 2016 CCC. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "JSONModelLib.h"

@interface Appointment : JSONModel
@property (nonatomic, strong) NSNumber <Optional> *appointmentDate;
@property (nonatomic, strong) NSNumber <Optional> *requestDate;
@property (nonatomic, strong) NSNumber <Optional> *estimatedDuration;
@property (nonatomic, strong) NSString <Optional> *confirmationId;
@end
