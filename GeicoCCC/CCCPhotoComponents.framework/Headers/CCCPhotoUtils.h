//
//  CCCPhotoUtils.h
//  CCCPhotoComponents
//
//  Created by Jerry Walton on 4/10/15.
//  Copyright (c) 2015 CCC. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <CoreLocation/CoreLocation.h>
#import "CCCPhotoCaptureVC.h"
#import "CCCPhotoCaptureItem.h"
#import "CCCPhotoCapture_Global.h"
#import "CCCPhotoCaptureAdjuster.h"

#define CCC_PHOTO_CAPTURE_ADDITIONAL_PHOTO_TITLE_PREFIX         kConfigAppString(kKeyConfigTakePhotoAdditionalPhotoSaveNamePrefix)
#define CCC_PHOTO_COMPONENTS_DIRECTORY_NAME                     @"CCCPhotos"
#define CCC_PHOTO_COMPONENTS_RETAKE_DIRECTORY_NAME              @"Retakes"
#define CCC_PHOTO_CAPTURE_ADDITIONAL_PHOTO_TITLE           [kConfigAppString(kKeyConfigTakePhotoAdditionalPhotoButtonTitle) stringByReplacingOccurrencesOfString:@"\\n" withString:@"\n"]

@class CCCPhotoCaptureVC;
@class CCCPhotoCaptureEntity;
@class PhotoModel;

typedef enum : NSUInteger {
    CCCPhotoUtilsErrorCodeNoPhotosFound = 100
} CCCPhotoUtilsErrorCode;

typedef enum : NSUInteger {
    CCCPermissionErrorCodeLocationRestricted        = 1,
    CCCPermissionErrorCodeLocationDenied            = 2,
    CCCPermissionErrorCodeCameraRestricted          = 3,
    CCCPermissionErrorCodeCameraDenied              = 4,
    CCCPermissionCameraAllowedAccess                = 5,
    CCCPermissionLocationAllowedAccess              = 6
} CCCPermissionErrorCode;

@protocol CCCPhotoUtilsDelegate <NSObject>
@required

/**
 *  Event trigger when user click on the "Continue" button after all photo are token.
 *
 *  @param storeEntities return lastest photo with title
 */
- (void) continueButtonTouched:(NSArray<PhotoModel *> *)storeEntities;
//- (void) permissionErrorHandle:(CCCPhotoCaptureVC *)controller errorCode:(CCCPermissionErrorCode)code;

@optional

- (void) customizeAfterViewDidLoad:(CCCPhotoCaptureVC*)photoCaptureVC;
- (void) photoCaptureWithPath:(NSString*)path title:(NSString*)title;
- (void) photoRetakeWithPath:(NSString*)path title:(NSString*)title;
- (void) photoAddWithPath:(NSString*)path title:(NSString*)title;
- (void) fetchCachedImageDictionary:(NSMutableDictionary *)imageDict;
- (void) photoDidSaveForTitle: (NSString *)photoTitle location:(CLLocation *)location;

@end

typedef void (^CCCPhotoUtilsCompletionHandler)(NSError *error);
typedef void (^CCCPhotoUtilsCompletionHandlerString)(NSString *aString, NSError *error);
typedef void (^CCCPhotoUtilsCompletionHandlerImage)(UIImage *anImage, NSError *error);
typedef void (^CCCPhotoUtilsCompletionHandlerArray)(NSArray *anArray, NSError *error);
typedef void (^CCCPhotoUtilsCompletionHandlerBool)(BOOL aBool, NSError *error);
typedef void (^CCCPhotoUtilsCompletionHandlerInteger)(NSInteger anInteger, NSError *error);
typedef void (^CCCPhotoUtilsCompletionHandlerImageString)(UIImage *anImage, NSString *aString, NSError *error);
typedef void (^CCCPhotoUtilsCompletionHandlerImages)(UIImage *anImage, UIImage *otherImage, NSError *error);
typedef void (^CCCPhotoUtilsCompletionHandlerDoubleDouble)(double latitude, double longitude, NSError *error);

@interface CCCPhotoUtils : NSObject

////////////////////////////////////////////////////////////////////////////////
// Methods to return built-in thumbnail preview items
// -or- built-in thumbnail preview items with custom titles
////////////////////////////////////////////////////////////////////////////////


/**
 *  return default CCCPhotoCaptureEntity array
 *
 */
+ (NSArray<CCCPhotoCaptureEntity *>*)builtinCCCPhotoCaptureEntitis;

/**
 *  return default CCCPhotoCaptureEntity array for VIN Skip
 *
 */
+ (NSArray<CCCPhotoCaptureEntity *>*)builtinCCCPhotoCaptureEntitisWithSkipVIN:(BOOL) skipVIN;

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


/**
 *  return array of names of all "additional" photos taken for the given claim
 */
+ (NSArray*) additionalPhotoNamesWithClaimId:(NSString*)claimId;
/**
 *  return array of names of all "additional" photos taken for the given claim
 *
 *  @param claimId    Claim ID
 *  @param completion Completion block
 */
+ (void) additionalPhotoNamesWithClaimId:(NSString*)claimId completion:(CCCPhotoUtilsCompletionHandlerArray)completion;


+ (NSArray*) pendingRetakePhotoCaptureItemsWithClaimId:(NSString*)claimId;
+ (void) pendingRetakePhotoCaptureItemsWithClaimId:(NSString*)claimId completion:(CCCPhotoUtilsCompletionHandlerArray)completion;

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
+ (UIImage*) loadRetakePhotoWithClaimId:(NSString*)claimId title:(NSString *)title;

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
 *  Save retake photo to retake directory on device
 *  @return Image path
 */
+ (NSString*) saveRetakePhotoWithClaimId:(NSString*)claimId image:(UIImage*)image title:(NSString*)title;
+ (void) saveRetakePhotoWithClaimId:(NSString*)claimId image:(UIImage*)image title:(NSString*)title completion:(CCCPhotoUtilsCompletionHandlerString)completion;

/**
 *  Return path of retake photo, if retake photo exists with title
 *
 *  @param claimId Claim ID
 *  @param title   Photo title
 *
 *  @return Image path
 */
+ (NSString*) retakePhotoPathWithClaimId:(NSString*)claimId title:(NSString*)title;

/**
 *  Delete photo from retake directory on device
 *  @return Success deleted or not
 */
+ (BOOL) deleteRetakePhotoWithClaimId:(NSString*)claimId title:(NSString*)title;
/**
 *  Delete photo from directory on device
 *  @param completion Completion block
 */
+ (void) deleteRetakePhotoWithClaimId:(NSString*)claimId title:(NSString*)title completion:(CCCPhotoUtilsCompletionHandlerBool)completion;

/**
 *  Replace photo with retake photo from retake directory on device
 *
 *  @param claimId Claim ID
 *  @param title   Photo title
 *  @param image   Replace image
 *
 *  @return replaced path
 */
+ (NSString*) replacePhotoWithRetakePhotoWithClaimId:(NSString*)claimId title:(NSString*)title image:(UIImage *)image;

/**
 *  return YES/NO indicating if photo exists in the Retakes folder with same title
 */
+ (BOOL) doesRetakePhotoExistWithClaimId:(NSString*)claimId title:(NSString*)title;
/**
 *  return YES/NO indicating if photo exists in the Retakes folder with same title
 */
+ (void) doesRetakePhotoExistWithClaimId:(NSString*)claimId title:(NSString*)title completion:(CCCPhotoUtilsCompletionHandlerBool)completion;
+ (BOOL) doesRetakePhotoExistWithTitle:(NSString *)title claimId:(NSString*)claimId;
+ (NSString*) createPhotoPathWithClaimId:(NSString *)claimId title:(NSString *)title;
+ (NSString*) createRetakePhotoPathWithClaimId:(NSString *)claimId title:(NSString *)title;

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

+ (NSArray<CCCPhotoCaptureItem *>*) allPhotoCaptureItemsWithClaimId:(NSString*)claimId location:(CLLocation*)location photoTitleArray:(NSArray *)photoTitleArray;

+ (NSString *) createClaimDirAsNeededWithClaimId:(NSString*)claimId;

+ (NSString *) photoIndexFromRetakeDictionaryWithTitle:(NSString *)title claimId:(NSString*)claimId;

+ (CCCPhotoCaptureVC*)photoCaptureViewWithClaimId:(NSString*)claimId delegate:(id<CCCPhotoUtilsDelegate>)delegate isCustomizedView:(BOOL)cutomizedView withDataArray:(NSArray *)dataArray;

+ (CCCPhotoCaptureVC *)photoCaptureViewWithClaimId:(NSString*)claimId vehicleType:(CCCQECaptureVehicleType)type delegate:(id<CCCPhotoUtilsDelegate>)delegate skipVINThumbnail:(BOOL)skipVINThumbnail withDataArray:(NSArray *)dataArray;
+ (CCCPhotoCaptureVC *)photoCaptureViewWithClaimId:(NSString*)claimId vehicleType:(CCCQECaptureVehicleType)type delegate:(id<CCCPhotoUtilsDelegate>)delegate;

+ (CCCPhotoCaptureVC *)photoCaptureViewWithClaimId:(NSString*)claimId vehicleType:(CCCQECaptureVehicleType)type delegate:(id<CCCPhotoUtilsDelegate>)delegate adjusterInfo:(CCCPhotoCaptureAdjuster *) adjuster skipVINThumbnail:(BOOL)skipVINThumbnail;

+(NSMutableArray<CCCPhotoCaptureEntity *> *)thumbnailItems;
+(NSMutableArray<CCCPhotoCaptureEntity *> *)thumbnailItems: (NSInteger) thumNailCount;
+(NSMutableArray<CCCPhotoCaptureEntity *> *)thumbnailItems:(CCCQECaptureVehicleType)type forceUpdate: (BOOL)force skipVINThumbnail:(BOOL)skipVINThumbnail;
+(CCCPhotoCaptureEntity *)thumbnailItemForType:(CCCQECaptureVehicleType)type withTitle: (NSString *) title;

+ (void)clearThumbnailItems;
+ (void)setThumbnailItems:(NSArray<CCCPhotoCaptureEntity *> *)items;

+ (void)resetRetakeDictionaryClaimId:(NSString*)claimId;
+ (NSArray *)getRetakePhotoNamesFromUserDefaultsClaimId:(NSString*)claimId;
+ (UIImage *)compressImage:(UIImage *)image;
+(void)setPhotoInAdditionalPhotosUserdefaultsTitle:(NSString*)title claimID:(NSString*)claimId;
+(void)updateRetakePhotosUserdefaultsTitle:(NSString*)title claimID:(NSString*)claimId;
+(void)resetPhotoComponents;
+(CCCQECaptureVehicleType) getBodyTypeEnum:(NSString *) bodyTypeCode;
+(NSMutableArray<CCCPhotoCaptureEntity *> *)thumbnailItemsFromArray:(NSMutableArray*)arrayItems;
+ (NSInteger) getNumberOfPhotosTakenWithClaimId:(NSString*)claimId thumbnailPreviewItems:(NSArray*)items;
+ (NSArray*) getAllPhotoNamesWithClaimId:(NSString *)claimId;
@end

