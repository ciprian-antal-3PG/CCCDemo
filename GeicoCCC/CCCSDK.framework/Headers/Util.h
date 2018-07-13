//
//  Utility.h
//  CCCSDK
//
//  Created by Viggnesh K on 4/21/15.
//  Copyright (c) 2015 cccis. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
//#import "CCCSDK_Global.h"
#import "CCCClaimContact.h"
@interface Util : NSObject
{
    NSString *claimID;
    NSString *lastName;
    NSString *sessionToken;
    NSString *passCode;
}

//shared instance
@property (nonatomic, retain) NSString *claimID;
@property (nonatomic, retain) NSString *lastName;
@property (nonatomic, retain) NSString *phoneNumber;
@property (nonatomic, retain) NSString *asscessToken;
@property (nonatomic, retain) NSString *sessionToken;
@property (nonatomic, retain) NSString *passCode;
@property (nonatomic, retain) CCCContactInfo *adjusterInfo;
@property (nonatomic, retain) CCCContactInfo *ownerInfo;
#define EXPRESS_ESTIMATE_STATUS @"expressEstimateStatus"
#define GET_EXPRESS_ESTIATE_STATUS(claimID) [NSString stringWithFormat:@"%@_%@",EXPRESS_ESTIMATE_STATUS,(claimID ? claimID : @"NULL")]

+ (id)sharedUtil;
+ (NSString *)convertNSDateToISO :(NSDate *)date;
+ (BOOL) fileExistsInProject:(NSString *)fileName;
+ (NSString *)generateBoundaryString;
+ (NSString *)mimeTypeForPath:(NSString *)path;
+ (NSError *) invokeAlertWithErrorCode :(NSError *)errorCode;
+(NSDate *) dateFromDateTime:(NSDate*) dateTime;
+(NSDate *) dateFromString:(NSString*) dateString dateFormat:(NSString *) dateFormat;
+(NSString *) stringFromDate:(NSDate*) date dateFormat:(NSString *) dateFormat;
+(NSString *) sectionStringFromDate:(NSDate*) date dateFormat:(NSString *) dateFormat;
+(NSString *) timeStringFromDate:(NSDate *) dateTime dateFormat:(NSString *) dateFormat;
+ (NSDate *) convertToISODate: (NSDate *) date;
+ (NSDictionary<NSString *, NSString *> *)A_PropertiesFromClass:(Class)cls;
+ (NSDate *) stringToDate:(NSString *)dateString;
+(BOOL) CheckForNotNull:(id) value;

@end
