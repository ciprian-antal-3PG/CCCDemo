//
//  CCCFetchSchedule.h
//  CCCSDK
//
//  Created by Viggnesh Kandasamy on 6/15/17.
//  Copyright © 2017 CCC. All rights reserved.
//

#import <CCCSDK/CCCSDK.h>
#import "JSONModel.h"
#import "JSONModelLib.h"
#import "CCCScheduleDays.h"
#import "CCCAppraiserType.h"
#import "CCCScheduleDays.h"

@protocol CCCFetchSchedule;
@protocol CCCScheduleDays;
@interface CCCFetchSchedule : JSONModel
@property (nonatomic, strong) NSString <Optional> * _Nullable appraiserCode;
@property (nonatomic, strong) NSString <Optional> * _Nullable fromDate;
@property (nonatomic, strong) NSString <Optional> * _Nullable toDate;
@property (nonatomic, strong) NSString <Optional> * _Nullable duration;
@property (strong, nonatomic) NSString <Optional> * _Nullable appraiserType;

//output
@property (strong, nonatomic) NSArray<CCCScheduleDays> * _Nullable days;

//With Session
- (void) fetchScheduleAppraiserTypes :(CCCAppraiserType *_Nullable) appraiserTypes session:(NSString *_Nullable)sessionToken  appraiserCode :( NSString *_Nullable) appraiserCode completionBlock:(nullable void(^)(NSArray<CCCScheduleDays > * __nullable cccScheduleDays, NSError * _Nullable error))block;

//Without Session
- (void) fetchScheduleAppraiserTypes :(CCCAppraiserType *_Nullable) appraiserTypes  appraiserCode :( NSString *_Nullable) appraiserCode completionBlock:(nullable void(^)(NSArray<CCCScheduleDays > * __nullable cccScheduleDays, NSError * _Nullable error))block;

//Return Schedule by hours
- (void) fetchScheduleByHours:(CCCAppraiserType *_Nullable) appraiserTypes appraiserCode :( NSString *_Nullable) appraiserCode completionBlock:(nullable void(^)(NSDictionary<NSDate *, NSArray<NSDate *> *> *__nullable cccScheduleList, NSError * _Nullable error))block;

@end
