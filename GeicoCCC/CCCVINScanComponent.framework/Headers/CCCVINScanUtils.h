//
//  CCCPhotoUtils.h
//  CCCPhotoComponents
//
//  Created by Jerry Walton on 4/10/15.
//  Copyright (c) 2015 CCC. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <CoreLocation/CoreLocation.h>
#import "CCCVINCaptureVC.h"
#import "CCCVINPhotoCaptureItem.h"

#define CCC_PHOTO_CAPTURE_ADDITIONAL_PHOTO_TITLE_PREFIX         @"Photo"
#define CCC_PHOTO_COMPONENTS_DIRECTORY_NAME                     @"CCCPhotos"

@class CCCVINCaptureVC;
@class CCCVINPhotoCaptureEntity;

typedef enum : NSUInteger {
    CCCPhotoUtilsErrorCodeNoPhotosFound = 100
} CCCPhotoUtilsErrorCode;

//@protocol CCCPhotoUtilsDelegate <NSObject>
//@required

/**
 *  Event trigger when user click on the "Continue" button after all photo are token.
 *
 *  @param storeEntities return lastest photo with title
 */

/*@optional

- (void) customizeAfterViewDidLoad:(CCCVINCaptureVC*)photoCaptureVC;
- (void) photoCaptureWithPath:(NSString*)path title:(NSString*)title;
- (void) photoAddWithPath:(NSString*)path title:(NSString*)title;
- (void) fetchCachedImageDictionary:(NSMutableDictionary *)imageDict;

@end
*/
typedef void (^CCCPhotoUtilsCompletionHandler)(NSError *error);
typedef void (^CCCPhotoUtilsCompletionHandlerString)(NSString *aString, NSError *error);
typedef void (^CCCPhotoUtilsCompletionHandlerImage)(UIImage *anImage, NSError *error);
typedef void (^CCCPhotoUtilsCompletionHandlerArray)(NSArray *anArray, NSError *error);
typedef void (^CCCPhotoUtilsCompletionHandlerBool)(BOOL aBool, NSError *error);
typedef void (^CCCPhotoUtilsCompletionHandlerInteger)(NSInteger anInteger, NSError *error);
typedef void (^CCCPhotoUtilsCompletionHandlerImageString)(UIImage *anImage, NSString *aString, NSError *error);
typedef void (^CCCPhotoUtilsCompletionHandlerImages)(UIImage *anImage, UIImage *otherImage, NSError *error);
typedef void (^CCCPhotoUtilsCompletionHandlerDoubleDouble)(double latitude, double longitude, NSError *error);

@interface CCCVINScanUtils : NSObject

////////////////////////////////////////////////////////////////////////////////
// Methods to return built-in thumbnail preview items
// -or- built-in thumbnail preview items with custom titles
////////////////////////////////////////////////////////////////////////////////


/**
 *  return default CCCPhotoCaptureEntity array
 *
 */
+ (NSArray<CCCVINPhotoCaptureEntity *>*)builtinCCCPhotoCaptureEntitis;

/**
 *  returns default CCCPhotoCaptureEntity array
 */
+ (void)builtinThumbnailPreviewItemsWithCompletion:(CCCPhotoUtilsCompletionHandlerArray)completion;

////////////////////////////////////////////////////////////////////////////////
// Photo file handling methods for saving, loading
// and deleting images on file system
////////////////////////////////////////////////////////////////////////////////

/**
 *  return array of names of all photos taken for the given claim
 *
 */
+ (NSArray<NSString *> *) allPhotoNamesWithClaimId:(NSString*)claimId;

/**
 *  Get all photo names by claim ID
 *
 *  @param claimId    Claim ID
 *  @param completion Completion block
 */
+ (void) allPhotoNamesWithClaimId:(NSString*)claimId completion:(CCCPhotoUtilsCompletionHandlerArray)completion;

/**
 *  return all normal photos (Not retake photos) by claim ID,
 */
+ (NSArray<UIImage *> *) allPhotosWithClaimId:(NSString*)claimId;

+ (NSString*) createPhotoPathWithClaimId:(NSString *)claimId title:(NSString *)title;


/**
 *  return bool indicting if all photos have been taken using given titles
 */
+ (BOOL) hasAllPhotosBeenTakenWithClaimId:(NSString*)claimId thumbnailPreviewItems:(NSArray*)items;
+ (void) hasAllPhotosBeenTakenWithClaimId:(NSString*)claimId thumbnailPreviewItems:(NSArray*)items completion:(CCCPhotoUtilsCompletionHandlerBool)completion;
+ (BOOL) hasAllPhotosBeenTakenWithClaimIdWithoutPath:(NSString*)claimId thumbnailPreviewItems:(NSArray*)items;


/**
 *  save photo to directory on device
 *
 *  @return Path
 */
+ (NSString*) savePhotoWithClaimId:(NSString*)claimId image:(UIImage*)image title:(NSString *)title path:(NSString *)path;


/**
 *  Get one photo from directory on device with claim ID and title
 */
+ (UIImage*) loadPhotoWithClaimId:(NSString*)claimId title:(NSString*)title;
+ (void) loadPhotoWithClaimId:(NSString*)claimId title:(NSString*)title completion:(CCCPhotoUtilsCompletionHandlerImage)completion;
+ (void) loadPhotoAndPathWithClaimId:(NSString*)claimId title:(NSString*)title completion:(CCCPhotoUtilsCompletionHandlerImages)completion;

/**
 *  Return path of photo, if photo exists with title
 *  @return String path
 */
+ (UIImage*) photoWithClaimId:(NSString*)claimId title:(NSString*)title;


/**
 *  Delete photo from directory on device
 *  @return Success deleted or not
 */
+ (BOOL) deletePhotoWithClaimId:(NSString*)claimId title:(NSString*)title;
/**
 *  Delete photo from directory on device
 *  @param completion Completion block
 */
+ (void) deletePhotoWithClaimId:(NSString*)claimId title:(NSString*)title completion:(CCCPhotoUtilsCompletionHandlerBool)completion;

/**
 *  Delete all retakes photos by Claim ID
 *
 *  @return Success or not
 */
+ (BOOL) deleteAllPendingRetakesWithClaimId:(NSString*)claimId;

/**
 *  return BOOL indicating if camera and location permissions granted
 */
+ (BOOL) hasCameraAndLocationPermissions;


/**
 *  Prevent iOS from backing up files to icloud
 */
+ (BOOL)addSkipBackupAttributeToItemAtURL:(NSURL *)URL;

+ (void)writeFile:(UIImage *)image ToPath:(NSString *)path;

+ (NSInteger) indexOfNextPhotoToBeTakenWithClaimId:(NSString*)claimId thumbnailPreviewItems:(NSArray*)items savedPhotoNames:(NSMutableDictionary *)savedPhotos;

+ (NSString *) getPhotoPathWithClaimId:(NSString*)claimId title:(NSString *)title;

+ (NSArray<CCCVINPhotoCaptureItem *>*) allPhotoCaptureItemsWithClaimId:(NSString*)claimId location:(CLLocation*)location photoTitleArray:(NSArray *)photoTitleArray;

+ (NSString *) createClaimDirAsNeededWithClaimId:(NSString*)claimId;

+(NSMutableArray<CCCVINPhotoCaptureEntity *> *)thumbnailItems;


+ (UIImage *)compressImage:(UIImage *)image;
+(void)setPhotoInAdditionalPhotosUserdefaultsTitle:(NSString*)title;

@end
