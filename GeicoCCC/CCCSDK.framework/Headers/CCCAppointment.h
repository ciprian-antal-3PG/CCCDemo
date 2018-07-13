//
//  CCCAppointment.h
//  CCCSDK
//
//  Created by Viggnesh Kandasamy on 6/16/17.
//  Copyright © 2017 CCC. All rights reserved.
//

#import <CCCSDK/CCCSDK.h>
#import "CCCAppraiserType.h"
#import "ServiceManager.h"
@interface CCCAppointment : JSONModel

@property (nonatomic, strong) NSString <Optional> * _Nullable firstName;
@property (nonatomic, strong) NSString <Optional> * _Nullable lastName;
@property (nonatomic, strong) NSString <Optional> * _Nullable phoneNumber;
@property (nonatomic, strong) NSString <Optional> * _Nullable appraiserCode;
@property (nonatomic, strong) NSString <Optional> * _Nullable appointmentStartTime;
@property (nonatomic, strong) NSString <Optional> * _Nullable appointmentEndTime;
@property(assign, nonatomic) AppraiserTypeEnum appraiserTypeEnum;
@property (strong, nonatomic, readonly) NSString <Optional> * _Nullable appraiserType;
@property (nonatomic, strong) NSString <Optional> * _Nullable email;
@property (nonatomic, strong) NSString <Optional> * _Nullable commPreference;
@property (nonatomic, strong) NSString <Optional> * _Nullable vehicleYear;
@property (nonatomic, strong) NSString <Optional> * _Nullable vehicleMake;
@property (nonatomic, strong) NSString <Optional> * _Nullable vehicleModel;
@property (nonatomic, strong) NSString <Optional> * _Nullable damageDescription;


//output
@property (nonatomic, strong) NSString <Optional> * _Nullable status;

// Book Appointment With Session
- (void) bookAppointmentWithSessionId : (NSString * _Nullable)sessionToken appraiserCode :(NSString * _Nullable) appraiserCode appraiserTypeEnum : (AppraiserTypeEnum) appraiserTypeEnum appointmentStartTime :(NSString *_Nullable)appointmentStartTime appointmentEndTime :(NSString *_Nullable)appointmentEndTime firstName :(NSString * _Nullable) firstName lastName :(NSString * _Nullable) lastName phoneNumber : (NSString * _Nullable) phoneNumber completionBlock:(nullable void(^)(NSString * __nullable status, NSError * _Nullable error))block;

// Book Appointment Without Session
- (void) bookAppointmentWithAppraiserCode :(NSString * _Nullable) appraiserCode appraiserTypeEnum : (AppraiserTypeEnum) appraiserTypeEnum appointmentStartTime :(NSString *_Nullable)appointmentStartTime appointmentEndTime :(NSString *_Nullable)appointmentEndTime firstName :(NSString * _Nullable) firstName lastName :(NSString * _Nullable) lastName phoneNumber : (NSString * _Nullable) phoneNumber  completionBlock:(nullable void(^)(NSString * __nullable status, NSError * _Nullable error))block;


+ (void) FetchAppointmentWithSession : (NSString *_Nullable) sessionToken completionBlock:(nullable void(^)(CCCAppointment * __nullable cccAppointment, NSError * _Nullable error))block;

+ (void) FetchAppointmentWithCompletionBlock:(nullable void(^)(CCCAppointment * __nullable cccAppointment, NSError * _Nullable error))block;

+ (void) CancelAppointmentWithSession : (NSString *_Nullable) sessionToken completionBlock:(nullable void(^)(bool success, NSError * _Nullable error))block;

+ (void) CancelAppointmentWithCompletionBlock:(nullable void(^)(bool success, NSError * _Nullable error))block;

@end
