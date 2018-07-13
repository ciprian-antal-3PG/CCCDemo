//
//  CCCFetchEstimate.h
//  CCCSDK
//
//  Created by Viggnesh K on 4/20/15.
//  Copyright (c) 2015 cccis. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "CCCSDK_Global.h"

/**
 This service returns the estimate data written against the claim. This estimate is usually written by the staff or desk
 appraiser after they have reviewed the photos.
 
 Specifically, this service will return the estimated pay, estimated deductible, and estimate PDF binary for the claim.
 */
@interface CCCFetchEstimate : NSObject

/** Represents estimated pay */
@property (CCC_NULLABLE_PROPERTY nonatomic, strong) NSNumber *estimatedPay;
/** Represents the total deductible amount */
@property (CCC_NULLABLE_PROPERTY nonatomic, strong) NSNumber *estimatedDeductible;
/** Represents the date the estimate was created */
@property (CCC_NULLABLE_PROPERTY nonatomic, strong) NSDate *estimateCreatedOn;
/** Represents the PDF data contained in the PDF file */
@property (CCC_NULLABLE_PROPERTY nonatomic, strong) NSData *pdfData;


/**
 Retreives the user's estimate details contained in a CCCFetchEstimate object. This service will be called after images have
 been uploaded.
 
 @param block A block object to be executed when the task finishes successfully. This block has no return value and takes two arguments: a CCCFetchEstimate response object and an NSError object.
 
 @see http://mobilesdk.cccis.com/documentation/
 
 */

+ (void) fetchEstimateValueWithCompletionBlock:(CCC_NULLABLE CCCEstimateResultBlock)block;

/**
 Retreives the user's estimate details contained in a CCCFetchEstimate object. This service will be called after images have
 been uploaded.
 
 @param sessionID Represents the Session Token for the user
 @param block A block object to be executed when the task finishes successfully. This block has no return value and takes two arguments: a CCCFetchEstimate response object and an NSError object.
 
 @see http://mobilesdk.cccis.com/documentation/

 */
+ (void) fetchEstimateValueWithSessionID :sessionID completionBlock:(CCC_NULLABLE CCCEstimateResultBlock)block;

/**
 Retreives the user's estimate details contained in a CCCFetchEstimate object.
 
 @param block A block object to be executed when the task finishes successfully. This block has no return value and takes two arguments: a CCCFetchEstimate response object and an NSError object.
 
 @see http://mobilesdk.cccis.com/documentation/
 
 */

+ (void) fetchEstimateValueInBackgroundWithCompletionBlock:(CCC_NULLABLE CCCEstimateResultBlock)block;

/**
 Retreives the user's estimate details contained in a CCCFetchEstimate object.
 
 @param sessionID Represents the Session Token for the user
 @param block A block object to be executed when the task finishes successfully. This block has no return value and takes two arguments: a CCCFetchEstimate response object and an NSError object.
 
 @see http://mobilesdk.cccis.com/documentation/
 
 */
+ (void) fetchEstimateValueInBackgroundWithSessionID :sessionID completionBlock:(CCC_NULLABLE CCCEstimateResultBlock)block;

/**
 Syncronously Retrieves the user's estimate details view PDF binary data.
 
 @param sessionID Represents the Session Token for the user
 @param block A block object to be executed when the task finishes successfully. This block has no return value and takes two arguments: a CCCFetchEstimate response object and an NSError object.
 
 @see http://mobilesdk.cccis.com/documentation/

 */
+ (void) fetchEstimatePDFInBackgroundWithSessionID :sessionID completionBlock:(CCC_NULLABLE CCCEstimateResultBlock)block;

/**
 Syncronously Retrieves the user's estimate details view PDF binary data.
 
 @param sessionID Represents the Session Token for the user
 @param block A block object to be executed when the task finishes successfully. This block has no return value and takes two arguments: a CCCFetchEstimate response object and an NSError object.
 
 @see http://mobilesdk.cccis.com/documentation/

 */
+ (void) fetchEstimatePDFWithWithSessionID :sessionID completionBlock:(CCC_NULLABLE CCCEstimateResultBlock)block;

@end
