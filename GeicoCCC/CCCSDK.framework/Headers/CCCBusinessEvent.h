//
//  CCCBusinessEvent.h
//  CCCSDK
//
//  Created by bkongara on 9/13/16.
//  Copyright © 2016 CCC. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "CCCSDK.h"

#define DATE_FORMAT @"EEE, dd MMM yyyy HH:mm"
#define DATE_FORMAT_SECTION @"EEE, MMM dd"
#define TIME_FORMAT @"hh:mm"

@class CCCBusinessEvent;
typedef void  (^getBusinessEventsCompleted)(NSArray<CCCBusinessEvent *> * __nullable businessEvents,CCCFacilityModel * __nullable currentAppraiser, NSError * __nullable error);

@interface CCCBusinessEvent : NSObject

@property (strong,nonatomic) NSString * _Nonnull eventId;
@property (strong,nonatomic) NSString *_Nonnull eventCode;
@property (strong,nonatomic) NSString *_Nonnull eventDescription;
@property (strong,nonatomic) NSString *_Nonnull eventNote;
@property (strong,nonatomic) NSDate *_Nonnull eventCreatedTime;
@property (strong,nonatomic) NSDate *_Nonnull eventOccurredTime;


+(NSMutableDictionary * _Nonnull) groupEventsByDateTime:(NSMutableArray * _Nonnull) businessEvents;
+(void)getBusinessEventsWithCompletedBlock:(getBusinessEventsCompleted _Nullable)completionHandler;
+(void)getBusinessEventsWithSession:(NSString * _Nullable)session completedBlock:(getBusinessEventsCompleted _Nullable)completionHandler;

@end
