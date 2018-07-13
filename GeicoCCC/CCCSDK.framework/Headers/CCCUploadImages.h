//
//  CCCUploadImages.h
//  CCCSDK
//
//  Created by Viggnesh K on 4/22/15.
//  Copyright (c) 2015 cccis. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "CCCSDK_Global.h"

/**
 This service allows users to submit photos to the CCC Claim Folder by calling the method in the CCCUploadImages API class.
 Metadata is passed along with the photos. The photos can be viewed through the CCC Portal. They can be configured to be sent
 across to the insurance carrier through CCC Interfaces.
 
 Metadata includes:
 <ul>
    <li>Latitude and Longitude coordinates</li>
    <li>Timestamp UTC</li>
    <li>Image name</li>
 </ul>
 
 There is no limit to the number of times a photo can be retaken, and the Upload Photo service can be invoked each time.
 
 Note: If interfaces don’t exist for the carrier they would have to be built before the photos can be sent across.
 */
@interface CCCUploadImages : NSObject

/**
 *  Represents the status of uploaded images.
 */
@property (nonatomic, assign) BOOL uploadStatus;

/**
 *  A string representing the status of an uploaded image.
 */
@property (CCC_NULLABLE_PROPERTY nonatomic, assign) __block NSString *uploadStatusText;

/**
 *  A dictionary containing an image and it's details including: creation date, filename, longitude, latitude, photo
 *  position, photo path, additional description.
 */
@property (CCC_NULLABLE_PROPERTY nonatomic, assign) __block NSMutableDictionary *imageDict;

/**
 Uploads a collection of images asyncronously.
 
 This service can be called if images are captured and ready to be uploaded.
 
 @param imageSet Array of CCCPhotoEntity objects representing images.
 @param sessionID Represents the Session ID
 @param successBlock A completion block object to be executed when the task finishes successfully. This block has no return value and takes two arguments: a imageName and status.
 @param failureBlock A completion block object to be executed when the image upload fails. This block has no return value and takes one argument: an Error object.
 @param progressBlock A completion block that describes the progress of the upload service. This block has no return value and takes one argument: a completionPercentage.
 
 @see http://mobilesdk.cccis.com/documentation/
 
 */
+(void) uploadImagesInBackgroundWithImageSet:(CCC_NONNULL NSArray<CCCPhotoEntity *> *)imageSet sessionID :(CCC_NONNULL NSString *)sessionID  success:(CCC_NONNULL CCCUploadImagesSuccessBlock)successBlock failure:(CCC_NONNULL CCCUploadImagesFailureBlock)failureBlock progressBlock:(CCC_NONNULL CCCUploadImagesProgressHandler)progressBlock;

/**
 Uploads a collection of images asyncronously.
 
 This service can be called if images are captured and ready to be uploaded.
 
 @param imageSet NSDictionary for image information
 @param sessionID Represents the Session ID
 @param successBlock A completion block object to be executed when the task finishes successfully. This block has no return value and takes two arguments: a imageName and status.
 @param failureBlock A completion block object to be executed when the image upload fails. This block has no return value and takes one argument: an Error object.
 @param progressBlock A completion block that describes the progress of the upload service. This block has no return value and takes one argument: a completionPercentage.
 
 @see http://mobilesdk.cccis.com/documentation/
 
 */
+(void) uploadImagesInBackgroundWithImageList:(CCC_NONNULL NSDictionary<NSString *, NSDictionary *> *)imageSet sessionID :(CCC_NONNULL NSString *)sessionID  success:(CCC_NONNULL CCCUploadImagesSuccessBlock)successBlock failure:(CCC_NONNULL CCCUploadImagesFailureBlock)failureBlock progressBlock:(CCC_NONNULL CCCUploadImagesProgressHandler)progressBlock;

    

/**
 Uploads a collection of images asyncronously.
 
 This service can be called if images are captured and ready to be uploaded.
 
 @param imageSet NSDictionary for image information
 @param sessionID Represents the Session ID
 @param damageDescription Represents the Damage Description
 @param successBlock A completion block object to be executed when the task finishes successfully. This block has no return value and takes two arguments: a imageName and status.
 @param failureBlock A completion block object to be executed when the image upload fails. This block has no return value and takes one argument: an Error object.
 @param progressBlock A completion block that describes the progress of the upload service. This block has no return value and takes one argument: a completionPercentage.
 
 @see http://mobilesdk.cccis.com/documentation/
 
 */
+(void) uploadImagesInBackgroundWithImageList:(CCC_NONNULL NSDictionary<NSString *, NSDictionary *> *)imageSet sessionID :(CCC_NONNULL NSString *)sessionID damageDescription: (CCC_NONNULL NSString *)damageDescription success:(CCC_NONNULL CCCUploadImagesSuccessBlock)successBlock failure:(CCC_NONNULL CCCUploadImagesFailureBlock)failureBlock progressBlock:(CCC_NONNULL CCCUploadImagesProgressHandler)progressBlock;


//+(void) uploadImagesInBackgroundWithClaimId:(CCC_NONNULL NSString *)claimId sessionID :(CCC_NONNULL NSString *)sessionID  success:(CCC_NONNULL CCCUploadImagesSuccessBlock)successBlock failure:(CCC_NONNULL CCCUploadImagesFailureBlock)failureBlock progressBlock:(CCC_NONNULL CCCUploadImagesProgressHandler)progressBlock;

@end
