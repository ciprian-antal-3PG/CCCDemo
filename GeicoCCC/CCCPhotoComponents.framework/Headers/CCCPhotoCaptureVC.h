//
//  CCCPhotoCaptureVC.h
//  CCCPhotoComponents
//
//  Created by Jerry Walton on 4/10/15.
//  Copyright (c) 2015 CCC. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "CCCPhotoUtils.h"
#import "CCCPhotoCaptureEntity.h"
#import "PhotosModel.h"
#import "CCCPhotoCaptureAdjuster.h"

@protocol CCCPhotoUtilsDelegate;

//@class CCCPhotoCaptureOverlayModel;
@class CCCPhotoCaptureItem;

typedef void (^CCCPhotoCaptureCompletionHandlerBool)(BOOL aBool, NSError *error);

typedef enum : NSUInteger {
    CCCPhotoCaptureModeDefault = 0,
    CCCPhotoCaptureModeCustomize,
    CCCPhotoCaptureModeRetakePhoto,
    CCCPhotoCaptureModeAddPhotos,
    CCCPhotoCaptureModeMinValue = CCCPhotoCaptureModeDefault,
    CCCPhotoCaptureModeMaxValue = CCCPhotoCaptureModeAddPhotos
} CCCPhotoCaptureMode;

typedef enum : NSUInteger {
    CCCPhotoCaptureRetake = 0,
    CCCPhotoCaptureDuration,
    CCCPhotoCaptureBlurry,
    CCCPhotoCaptureHelpOverlay,
    CCCPhotoCaptureFlashChange,
    CCCPhotoCaptureCarouselClick,
    CCCPhotoCaptureShowAdjusterInfo,
    CCCPhotoCaptureTimeSpent,
} CCCPhotoCaptureAnalyticsEventType;

typedef enum : NSUInteger {
    // The default state has to be off - see LLSimpleCamera
    CCCPhotoCaptureFlashAuto = 0,
    CCCPhotoCaptureFlashOn,
    CCCPhotoCaptureFlashOff,
    CCCPhotoCaptureFlashMin = CCCPhotoCaptureFlashAuto,
    CCCPhotoCaptureFlashMax = CCCPhotoCaptureFlashOff
} CCCPhotoCaptureFlash;

typedef enum : NSUInteger {
    CCCPhotoCaptureOverlayTagHeader = 100,
    CCCPhotoCaptureOverlayTagTitle,
    CCCPhotoCaptureOverlayTagDescription
} CCCPhotoCaptureOverlayTag;

typedef NS_ENUM(NSUInteger, PhotoCaptureOverlayType) {
    PhotoCaptureOverlayTypeDefault  = 0,
    PhotoCaptureOverlayTypeWithFooter   = 1,
};

@interface CCCPhotoCaptureVC : UIViewController

#pragma mark - Photo capture function setting
@property (nonatomic, strong) NSTimer *myTimer;

/**
 *  Required - Delegate for check status of photo capture. Should be with some value if initialize from 'Create' function
 */
@property (nonatomic, assign) id<CCCPhotoUtilsDelegate> delegate;
/**
 *  Required - Claim id. Should be with some value if initialize from 'Create' function
 */
@property (nonatomic, strong) NSString *claimId;

/**
 *  Customization mode
 */
@property (nonatomic, assign) CCCPhotoCaptureMode mode;
/**
 *  Current photo capture entities. It will auto-fill up if it's nil
 */
@property (nonatomic, strong) NSMutableArray<CCCPhotoCaptureEntity *> *thumbnailItems;
/**
 *  Re-take photo entity
 */
@property (nonatomic, strong) CCCPhotoCaptureEntity  *retakePhotoEntity;
/**
 *  Adjuster Information
 */
@property (nonatomic, strong) CCCPhotoCaptureAdjuster  *adjusterInfo;

/**
 *  Custom footer message for help overlay
 */
@property (nonatomic, strong) NSString *helpOverlayFooterMessage;

@property (nonatomic, assign) PhotoCaptureOverlayType overlayType;


/**
 *  If wizardStyle, carousel auto-advances to next item
 */
@property (nonatomic, assign) BOOL enableWizardStyle;
@property (nonatomic, assign) BOOL hideContinueButton;

/**
 *  VIN barcode scanning support
 */
@property (nonatomic, assign) BOOL enableVinScanning;
/**
 *  VIN Barcode
 */
@property (nonatomic, strong) NSString *vinBarCode;

@property (nonatomic, assign) BOOL additionalPhotoMode;

@property (nonatomic, strong) NSMutableDictionary *savedImageDictionary;

@property (nonatomic, strong) NSDate *startingTime;

@property (nonatomic, assign) BOOL enableBackButton;

/**
 *  Always display empty default capture photo, if set to false then it will dispaly the lastest saved photos.
 */
@property (nonatomic, assign) BOOL launchPhotoCaptureViewWithDefaultImagesAlways;

@property (weak, nonatomic) IBOutlet UIImageView *cameraOverlayImage;

#pragma mark - End-user customize elements
@property (nonatomic, weak) IBOutlet UIView *backgroundView;

@property (nonatomic, weak) IBOutlet UIView *useRetakeOperationArea;
@property (nonatomic, weak) IBOutlet UIButton *retakeBtn;
@property (nonatomic, weak) IBOutlet UIButton *usePhotoBtn;
@property (nonatomic, weak) IBOutlet UIButton *continueBtn;

@property (weak, nonatomic) IBOutlet UIView *ipXUserRetakeOperationArea;
@property (nonatomic, weak) IBOutlet UIButton *ipXretakeBtn;
@property (nonatomic, weak) IBOutlet UIButton *ipXusePhotoBtn;
@property (nonatomic, weak) IBOutlet UIButton *iPXcontinueBtn;

@property (nonatomic, weak) IBOutlet UIButton *manuallyEnterVINBtn;
@property (nonatomic, weak) IBOutlet UIButton *snapBtn;

@property (nonatomic, assign) BOOL showNavigateBar;

@property (nonatomic, assign) BOOL enableImageExposureAdjusted;

/**
 *  Allows the user to customize the top right help button
 *
 */
- (void) setNavigationHelpButtonImage:(UIImage*)image;

/**
 *  Custom Retake button with image
 *
 *  @param image button image
 */
- (void) setRetakeButtonImage:(UIImage *)image;
/**
 *  Custom Use photo button with image
 *
 *  @param image button image
 */
- (void) setUsePhotoButtonImage:(UIImage *)image;
/**
 *  Custom Continue button with image
 *
 *  @param image button image
 */
- (void) setContinueButtonImage:(UIImage *)image;
/**
 *  Custom Vin button with image
 *
 *  @param image button image
 */
- (void) setVinButtonImage:(UIImage *)image;

/**
 *  Custom Retake button with image
 *
 *  @param image          Image for normal status
 *  @param hightlightImage Image for hightlight status
 *  @param disabledImage   Image for disabled status
 */
- (void) setRetakeButtonNormalImage:(UIImage *)image
                    hightlightImage:(UIImage *)hightlightImage
                      disabledImage:(UIImage *)disabledImage;
/**
 *  Custom Use button with image
 *
 *  @param image          Image for normal status
 *  @param hightlightImage Image for hightlight status
 *  @param disabledImage   Image for disabled status
 */
- (void) setUsePhotoButtonNormalImage:(UIImage *)image
                      hightlightImage:(UIImage *)hightlightImage
                        disabledImage:(UIImage *)disabledImage;
/**
 *  Custom Continue button with image
 *
 *  @param image          Image for normal status
 *  @param hightlightImage Image for hightlight status
 *  @param disabledImage   Image for disabled status
 */
- (void) setContinueButtonNoramlImage:(UIImage *)image
                      hightlightImage:(UIImage *)hightlightImage
                        disabledImage:(UIImage *)disabledImage;
/**
 *  Custom Vin button with image
 *
 *  @param image          Image for normal status
 *  @param hightlightImage Image for hightlight status
 *  @param disabledImage   Image for disabled status
 */
- (void) setVinButtonNoramlImage:(UIImage *)image
                 hightlightImage:(UIImage *)hightlightImage
                   disabledImage:(UIImage *)disabledImage;


- (void)setNavigationBackgroundColor:(UIColor *)color;
/**
 *  Custom navigation title and buttons color
 *
 *  @param color UIColor
 */
- (void)setNavigationItemTintColor:(UIColor *)color;

#pragma mark - Initial functions, controller should be initialized from them
+ (CCCPhotoCaptureVC*)createWithClaimId:(NSString*)claimId delegate:(id<CCCPhotoUtilsDelegate>)delegate;
+ (CCCPhotoCaptureVC*)createWithClaimId:(NSString*)claimId delegate:(id<CCCPhotoUtilsDelegate>)delegate andCustomItems:(NSArray<CCCPhotoCaptureEntity *> *)items;
+ (CCCPhotoCaptureVC*)createRetakePhotoWithClaimId:(NSString *)claimId delegate:(id<CCCPhotoUtilsDelegate>)delegate andPhotoCaptureEntity:(CCCPhotoCaptureEntity *)entity;
+ (CCCPhotoCaptureVC* )createRetakePhotoWithClaimId:(NSString *)claimId delegate:(id<CCCPhotoUtilsDelegate>)delegate andPhotoCaptureEntity:(CCCPhotoCaptureEntity *)entity adjusterInfo:(CCCPhotoCaptureAdjuster *) adjuster;
+ (CCCPhotoCaptureVC*)createAddPhotosWithClaimId:(NSString *)claimId delegate:(id<CCCPhotoUtilsDelegate>)delegate;

+ (CCCPhotoCaptureVC*)createRetakePhotoWithClaimId:(NSString *)claimId delegate:(id<CCCPhotoUtilsDelegate>)delegate photoTitle :(NSString *) photoTitle andVehicleType:(CCCQECaptureVehicleType)type;
+ (CCCPhotoCaptureVC*)createRetakePhotoWithClaimId:(NSString *)claimId delegate:(id<CCCPhotoUtilsDelegate>)delegate photoTitle :(NSString *) photoTitle vehicleType:(CCCQECaptureVehicleType)type adjusterInfo:(CCCPhotoCaptureAdjuster *)adjuster;
/**
 Function for show up the photo capture, must use this function for show up this controller.
 In default, it will check if it can use delegete as parent controller, otherwise do nothing.
 */
- (void)openUI;


/**
 Function for show up the photo capture, must use this function for show up this controller.

 @param controller parent controller
 */
- (void)openUI:(UIViewController *)controller;

/**
 Function for dismiss the photo capture, must use this function for dismiss this controller.
 */
- (void)dismiss;

#pragma mark -

/**
 *  Dictionary of photo capture items for each photo taken
 *
 *  @return Capture items
 */
- (NSDictionary*)photoCaptureItems;

/**
 *  Geo location indicating where photos taken
 *
 *  @return Geo location information
 */
- (CLLocation*) locationWherePhotosTaken;

/**
 *  Get all photo with Capture item objects
 *
 */
- (NSArray<CCCPhotoCaptureItem *> *) allPhotoCaptureItems;

/**
 *  Get all photo paths
 *
 *  @return Key:Photo title, Value:Photo path
 */
- (NSDictionary<NSString *, NSString *> *) allPhotoCapturePaths;

/**
 *  Get all photo with detail information
 *
 *  @return Key:Photo title, Value:Photo detail information
 */
- (NSDictionary<NSString *, NSDictionary *> *) allPhotoCaptureWithDetails;

/**
 *  Returns the image (user taken image or default thumbnail image) to be displayed on thumbnail.
 *
 *  @param displayTitle Image title
 */
- (UIImage *)getThumbnailImageFromDisplayTitle:(NSString *)displayTitle;

/**
 *  Returns an array of CCCThumbnailPreviewItem created from additional photos taken by user based on claim id.
 *
 *  @return Array photo capture entities
 */
- (NSArray<CCCPhotoCaptureEntity *>*)getAdditionalThumbnailItemsArray;


/**
 *  //Returns CCCThumbnailPreviewItem by title.
 *
 *  @param displayTitle title
 */
- (CCCPhotoCaptureEntity*)getSelectedThumbnailItemForDisplayTitle:(NSString *)displayTitle;

/**
 *  Returns selected CCCThumbnailPreviewItem based on title for collection cell.
 */
- (CCCPhotoCaptureEntity *)getThumbnailItemWithDisplayTitle:(NSString *)displayTitle;

/**
 *  Saves additional photos to NSUSerDefaults and NSDocumentDirectory.
 *
 *  @param image      Image to save
 *  @param title      Additional title
 *  @param index      index
 *  @param completion completion block
 */
- (void)saveAdditionalThumbnailImage:(UIImage *)image
                           withTitle:(NSString *)title
                               index:(int)index
                          completion:(CCCPhotoCaptureCompletionHandlerBool)completion;

/**
 *  Deletes additional photos to NSUSerDefaults and NSDocumentDirectory.
 *
 *  @param thumbnailItem    Remove specify photo from saved photos
 */
- (void)deletePhotoThumbnailItem:(CCCPhotoCaptureEntity *)thumbnailItem;

@end
