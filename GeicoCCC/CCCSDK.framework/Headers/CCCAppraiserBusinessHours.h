//
//  CCCAppraiserBusinessHours.h
//  CCCSDK
//
//  Created by Viggnesh Kandasamy on 6/6/17.
//  Copyright © 2017 CCC. All rights reserved.
//

#import "CCCSDK_Global.h"
#import "JSONModelLib.h"

@protocol CCCAppraiserBusinessHours;
@interface CCCAppraiserBusinessHours : JSONModel
@property (strong, nonatomic) NSString <Optional> *dayOfWeek;
@property (strong, nonatomic) NSString <Optional> *openTime;
@property (strong, nonatomic) NSString <Optional> *closeTime;
@property (strong, nonatomic) NSString <Optional> *apptWindowStart;
@property (strong, nonatomic) NSString <Optional> *apptWindowEnd;
@property (strong, nonatomic) NSString <Optional> *apptWindowTimeZone;
//@property (strong, nonatomic)  <Optional> *isOpen;
@property (assign, nonatomic) BOOL isOpen;

@end
