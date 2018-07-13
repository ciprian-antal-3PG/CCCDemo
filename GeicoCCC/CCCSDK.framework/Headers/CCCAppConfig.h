//
//  CCCAppConfig.h
//  CCCSDK
//
//  Created by Viggnesh Kandasamy on 11/14/17.
//  Copyright © 2017 CCC. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "CCCSDK_Global.h"
#import "JSONModelLib.h"
#import "CCCConfigValues.h"
@protocol CCCConfigValues;
@interface CCCAppConfig : JSONModel
@property (strong, nonatomic) NSString <Optional> * _Nullable companyCode;
@property (strong, nonatomic) NSString <Optional> * _Nullable configType;
@property (strong, nonatomic) NSArray<CCCConfigValues>  * _Nullable configValues;

/**
 Asyncronously fetches app configs associated with current Session ID
 
 @param block     completionBlock A block object to be executed when the task finishes successfully. The block returns EstimateStatus enum and NSError object.
 
 @see http://mobilesdk.cccis.com/documentation/
 */
+ (void) fetchAppConfigWithconfigType:(CCC_NONNULL NSString *) configType  CompletionBlock:(CCC_NULLABLE CCCAppConfigBlock)block;

/**
 Asyncronously fetches current status in the express estimate process for a specific claim
 
 @param sessionID sessionID
 @param block     completionBlock A block object to be executed when the task finishes successfully. The block returns EstimateStatus enum and NSError object.
 
 @see http://mobilesdk.cccis.com/documentation/
 */
+ (void) fetchAppConfigWithSessionID :(CCC_NONNULL NSString *) sessionID configType :(CCC_NONNULL NSString *) configType  completionBlock:(CCC_NULLABLE CCCAppConfigBlock)block;

@end
