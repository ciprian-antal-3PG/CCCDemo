//
//  CCCNotificationService.h
//  CCCSDK
//
//  Created by Viggnesh K on 5/13/15.
//  Copyright (c) 2015 cccis. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "CCCSDK_Global.h"




/**
 This service returns a notification if the estimate is available for the claim. Once the estimate is available, the Estimate
 can be invoked to provide more details on the estimate value.
 */
@interface CCCNotificationService : NSObject

/**
 *  Represents the Notification Type
 */
@property (CCC_NULLABLE_PROPERTY nonatomic, copy) NSString *notificationType;

/**
 *  Represents the Notification Message
 */
@property (CCC_NULLABLE_PROPERTY nonatomic, copy) NSString *notificationDescription;

/**
 *  Represents the Notification Date
 */
@property (CCC_NULLABLE_PROPERTY nonatomic, strong) NSDate *timestamp;


/**
 Syncronously fetches notifications when an estimate is available.
 
 @param sessionID Represents the Session Token
 @param block A block object to be executed when the task finishes successfully. This block has no return value and takes two arguments: an NSArray object of type CCCNotificationService and an NSError object.
 
 @see http://mobilesdk.cccis.com/documentation/
 
 */
+ (void) fetchCCCNotificationWithSessionID :(CCC_NULLABLE NSString *) sessionID completionBlock:(CCC_NULLABLE CCCNotificationBlock)block;

/**
 Asyncronously fetches notifications when an estimate is available.
 
 @param sessionID Represents the Session Token
 @param block A block object to be executed when the task finishes successfully. This block has no return value and takes two arguments: an NSArray object of type CCCNotificationService and an NSError object.
 
 @see http://mobilesdk.cccis.com/documentation/
 
 */
+ (void) fetchCCCNotificationInBackgroundWithSessionID :(CCC_NULLABLE NSString *) sessionID completionBlock:(CCC_NULLABLE CCCNotificationBlock)block;


-(CCC_NONNULL id)fetchResponseFromNotificationServiceWithSessionID :(CCC_NONNULL NSString *) ssid;


@end
