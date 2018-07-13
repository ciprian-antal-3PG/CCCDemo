//
//  CCCEstimateStatus.h
//  CCCSDK
//
//  Created by Viggnesh Kandasamy on 11/7/16.
//  Copyright © 2016 CCC. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "CCCSDK_Global.h"

@interface CCCWorkflowStatus : NSObject

/**
 Asyncronously fetches current status in the express estimate process for a specific claim with currect Session ID
 
 @param block     completionBlock A block object to be executed when the task finishes successfully. The block returns EstimateStatus enum and NSError object.
 
 @see http://mobilesdk.cccis.com/documentation/
 */
+ (void) fetchStatusWithCompletionBlock:(CCC_NULLABLE CCCWorkflowStatusBlock)block;

/**
 Asyncronously fetches current status in the express estimate process for a specific claim
 
 @param sessionID sessionID
 @param block     completionBlock A block object to be executed when the task finishes successfully. The block returns EstimateStatus enum and NSError object.
 
 @see http://mobilesdk.cccis.com/documentation/
 */
+ (void) fetchStatusWithSessionID :(CCC_NONNULL NSString *) sessionID completionBlock:(CCC_NULLABLE CCCWorkflowStatusBlock)block;


@end
