//
//  Global.h
//  Component_PhotoCapture
//
//  Created by Viggnesh K on 2/6/15.
//  Copyright (c) 2015 wsm. All rights reserved.
//
#import "CCCNullability.h"
#import <Foundation/Foundation.h>

@class CCCAuth;
@class CCCFetchEstimate;
@class CCCUploadImages;
@class CCCNotificationService;
@class CCCPhotoEntity;
@class CCCAssignment;
@class CCCAppConfig;
@class CCCContactInfo;
#ifndef CCCSDK_CCCCONSTANTS_H // constants_h
#define CCCSDK_CCCCONSTANTS_H// constants_h

//####################################### MESSAGE STARTS #######################################################################


#define COULD_NOT_SIGN_IN_MESSAGE_TITLE @"Could Not Sign In"
#define COULD_NOT_SIGN_IN_MESSAGE_SUBTITLE @"The information you entered was not found in our system. Please try again."

#define UNABLE_TO_COMPLETE_REQUEST_TITLE @"Unable to Complete Request"
#define UNABLE_TO_COMPLETE_REQUEST_SUBTITLE @"We were unable to process your reqest at this time. Please try again."

#define STORAGE_FULL_ALERT_TITLE @"Not Enough Storage"
#define STORAGE_FULL_ALERT_SUBTITLE @"Please free up space on your device to be able to take photos."

#define UNABLE_TO_UPLOAD_TITLE @"Unable to upload!"
#define UNABLE_TO_UPLOAD_SUBTITLE @"Unable to upload the images due to network issues. Check your internet connection and retry"


#define CCCErrorCode @"CCCErrorCode"
#define CCCMessageTitle @"CCCMessageTitle"
#define CCCMessageBody @"CCCMessageBody"
#define NO_INTERNET_TITLE  @"Internet Connection Unavailable"
#define NO_INTERNET_SUBTITLE @"Please connect to the Internet to complete this action."
#define UNABLE_TO_REACH_SERVER_TITLE @"Unable to Complete Request"
#define UNABLE_TO_REACH_SERVER_SUBTITLE @"Unknown Server Error"
#define NETWORK_ERROR_TITLE @"Network error"
#define NETWORK_ERROR_SUBTITLE @"An error occurred while communicating with the server."
#define UNKNOWN_ERROR_TITLE @"Unable to Complete Request"
#define UNKNOWN_ERROR_SUBTITLE @"Unknown Error"


#define REDIRECT_TO_SETTINGS_TITLE @"Allow Permissions to Continue"
#define REDIRECT_TO_SETTINGS_SUBTITLE @"Please go to Settings and enable the Location and Camera permissions for Express Estimate to continue."


#define INTERNAL_SERVER_ERROR @"Internal Server Error"

#define SERVER_ERROR_TITLE @"Server Error"
#define SERVER_ERROR_SUBTITLE @"The server either does not recognize the request method, or it lacks the ability to fulfill the request."

#define BAD_GATEWAY @"Bad Gateway"
#define SERVICE_UNAVAILABLE @"Service Unavailable"
#define GATEWAY_TIMEOUT @"Gateway Timeout"
#define HTTP_VERSION_NOT_SUPPORTED @"HTTP Version Not Supported"
#define UNKNOWN_ERROR @"Unknown Error"

#define CLIENT_ERROR_TITLE @"Client Error"
#define CLIENT_ERROR_SUBTITLE_BAD_REQUEST @"Bad Request"
#define CLIENT_ERROR_SUBTITLE_FORBIDDEN @"The request was a valid request, but the server is refusing to respond to it."
#define CLIENT_ERROR_SUBTITLE_NOTFOUND @"The requested resource could not be found"

#define SERVER_TIMEOUT_TITLE @"Request Timeout"
#define CLIENT_ERROR_SUBTITLE_REQUEST_TIMEOUT @"The server timed out waiting for the request."

#define OUTPUT_DEBUG true


//###################################################### MESSAGE ENDS ############################################################################################################

typedef enum workflowStatus: NSInteger {
    /**UNKNOWN - Default status */
    UNKNOWN                 = -1,
    /**New User - Signed in but required photos are not captured*/
    NEW_USER                = 1,  /* App Logic Status */
    /**Pre-Upload - Signed in and required photos are captured**/
    PRE_UPLOAD              = 2,  /* App Logic Status */
    /**Post-Upload - Signed in and uploaded all photos*/
    POST_UPLOAD             = 5,
    /**Estimate Available - Estimate is available to be retrieved*/
    ESTIMATE_AVAILABLE      = 15,
    /**APPRAISER SELECTED - User selected appraiser*/
    APPRAISER_SELECTED      = 10,
    /**PAYMENT REQUESTED  - User requested payment */
    PAYMENT_REQUESTED       = 20,
    /**Estimate Available - User cancelled the claim*/
    CANCEL_ASSIGNMENT       = 25,
    
     /**APPRAISER APPOINTMENT BOOKED */
    APPRAISER_APPOINTMENT_BOOKED      = 30,
     /**APPRAISER APPOINTMENT CANCELLED */
    APPRAISER_APPOINTMENT_CANCELLED   = 35,
    /**APPRAISER DESELECTED - User deselected appraiser*/
    APPRAISER_DESELECTED              = 40
    
} WorkflowStatus;



///--------------------------------------
/// @name Blocks
///--------------------------------------

/**
 *  CCCUserResultBlock has no return value and takes two arguments: a CCCAuth response object and an NSError object. Note: This parameter cannot be nil, because this is used to retrieve response data.
 *
 *  @param user  CCCAuth object representing the user.
 *  @param error NSError object.
 */
typedef void (^CCCUserResultBlock)(CCCAuth *CCC_NULLABLE_S user, NSError *CCC_NULLABLE_S error);

/**
 *  A block object to be executed when the task finishes successfully. This block has no return value and takes two arguments: a CCCFetchEstimate response object and an NSError object.
 *
 *  @param cccFetchEstimate Object that contains information about the fetched estimate.
 *  @param error            NSError object.
 */
typedef void (^CCCEstimateResultBlock)(CCCFetchEstimate *CCC_NULLABLE_S cccFetchEstimate, NSError *CCC_NULLABLE_S error);

/**
 *  A block object to be executed when the task finishes successfully. This block has no return value and takes two arguments: a CCCUploadImages response object and an NSError object.
 *
 *  @param cccUploadImages Object containing data about uploaded images.
 *  @param error           NSError object.
 */
typedef void (^CCCUploadImagesResultBlock)(CCCUploadImages *CCC_NULLABLE_S cccUploadImages, NSError *CCC_NULLABLE_S error);



/**
 *  A completion block object to be executed when the task finishes successfully. This block has no return value and takes two arguments: a imageName and status.
 *
 *  @param imageName String containing data about uploaded images.
 */
typedef void (^CCCUploadImagesSuccessBlock)(NSString *CCC_NULLABLE_S imageName);

/**
 *  A block object to be executed when the task finishes successfully. This block has no return value and takes two arguments: a CCCUploadImages response object and an NSError object.
 *
 *  @param error           NSError object.
 */
typedef void (^CCCUploadImagesFailureBlock)(NSError *CCC_NULLABLE_S error);


/**
 *  A block that describes the progress of the upload service. This block has no return value and takes two arguments: a float variable and an NSUInteger object.
 *
 *  @param completionPercentage Represents the percentage of upload that has been completed.
 */
typedef void (^CCCUploadImagesProgressHandler)(float  completionPercentage);

/**
 *  A block object to be executed when the task finishes successfully. This block has no return value and takes two arguments: an NSArray object of type CCCNotificationService and an NSError object.
 *
 *  @param notificationsList NSArray containing notification details.
 *  @param error        NSError object.
 */
typedef void (^CCCNotificationBlock)(NSMutableArray<CCCNotificationService *> *CCC_NULLABLE_S notificationsList, NSError *CCC_NULLABLE_S error);


/**
 A block object to be executed when the task finishes successfully. The block returns EstimateStatus enum and NSError object.
 
 @param workflowStatus EstimateStatus is an enum that holds the status value
 @param error             NSError Object
 */
typedef void (^CCCAppConfigBlock)(CCCAppConfig *CCC_NULLABLE_S cccAppConfig, NSError *CCC_NULLABLE_S error);

/**
 A block object to be executed when the task finishes successfully. The block returns Contact Info Model and NSError object.

 @param workflowStatus EstimateStatus is an enum that holds the status value
 @param error             NSError Object
 */
typedef void (^CCCContactInfoBlock)(CCCContactInfo *CCC_NULLABLE_S ownerInfo,CCCContactInfo *CCC_NULLABLE_S adjusterInfo, NSError *CCC_NULLABLE_S error);

/**
 A block object to be executed when the task finishes successfully. The block returns EstimateStatus enum and NSError object.

 @param workflowStatus EstimateStatus is an enum that holds the status value
 @param error             NSError Object
 */
typedef void (^CCCWorkflowStatusBlock)(WorkflowStatus workflowStatus, NSError *CCC_NULLABLE_S error);



/**
 *  A block object to be executed when the task finishes successfully. This block has no return value and takes two arguments: a CCCAssignment response object and an NSError object.
 *
 *  @param cccAssignment Object that contains information about the fetched assignment.
 *  @param error            NSError object.
 */
typedef void (^CCCAssignmentBlock)(CCCAssignment *CCC_NULLABLE_S cccAssignment, NSError *CCC_NULLABLE_S error);

#endif
