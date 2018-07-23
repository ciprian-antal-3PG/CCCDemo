//
//  CCCVINCaptureVC.h
//  CCCVINScanComponent
//


#import <UIKit/UIKit.h>
#import "CCCVINScanUtils.h"
#import "CCCVINPhotoCaptureEntity.h"
#import "CCCVINScanAdjuster.h"
@protocol VinScannerVCDelegate;

//@class CCCPhotoCaptureOverlayModel;
@class CCCVINPhotoCaptureItem;

typedef void (^CCCPhotoCaptureCompletionHandlerBool)(BOOL aBool, NSError *error);

typedef enum : NSUInteger {
    CCCVINCaptureModeDefault = 0,
    CCCVINCaptureModeCustomize
} CCCVINCaptureMode;

typedef enum : NSUInteger {
    CCCVinCaptureHelpOverlay = 0,
    CCCVinCaptureFlashChange,
    CCCVinCaptureTimeSpent,
    CCCVinCaptureHamburgerClick
} CCCVinCaptureAnalyticsEventType;

typedef enum : NSUInteger {
    // The default state has to be off - see LLSimpleCamera
    CCCVINCaptureFlashOff = 0,
    CCCVINCaptureFlashOn,
    CCCVINCaptureFlashMin = CCCVINCaptureFlashOff,
    CCCVINCaptureFlashMax = CCCVINCaptureFlashOn
} CCCVINCaptureFlash;

typedef enum : NSUInteger {
    CCCPhotoCaptureOverlayTagHeader = 100,
    CCCPhotoCaptureOverlayTagTitle,
    CCCPhotoCaptureOverlayTagDescription
} CCCPhotoCaptureOverlayTag;


@protocol VinScannerVCDelegate <NSObject>
@required
- (void) didCompleteScanning: (NSString *) vinNumber isVINScanned:(BOOL)isVINScanned isVINValid:(BOOL) isVINValid error: (NSError *) error;
@optional

@end

@interface CCCVINCaptureVC : UIViewController

#pragma mark - Photo capture function setting

/**
 *  Required - Delegate for check status of photo capture. Should be with some value if initialize from 'Create' function
 */
@property (nonatomic, weak) id<VinScannerVCDelegate> delegate;
/**
 *  Required - Claim id. Should be with some value if initialize from 'Create' function
 */
@property (nonatomic, strong) NSString *claimId;
/**
 *  Customization mode
 */
@property (nonatomic, assign) CCCVINCaptureMode mode;
/**
 *  Current photo capture entities. It will auto-fill up if it's nil
 */
@property (nonatomic, strong) NSMutableArray<CCCVINPhotoCaptureEntity *> *thumbnailItems;

/**
 *  Adjuster Information
 */
@property (nonatomic, strong) CCCVINScanAdjuster  *adjusterInfo;
/**
 *  If wizardStyle, carousel auto-advances to next item
 */
@property (nonatomic, assign) BOOL enableWizardStyle;

@property (nonatomic, assign) BOOL enableLandscapeMode;

/**
 *  VIN barcode scanning support
 */
@property (nonatomic, assign) BOOL enableVinScanning;

@property (nonatomic, assign) BOOL hasBackButton;

@property (nonatomic, assign) BOOL showManualEntry;

/**
 *  Enable the image exposure adjustment
 */
@property (nonatomic, assign) BOOL enableImageExposureAdjusted;

/**
 *  VIN Barcode
 */
@property (nonatomic, strong) NSString *vinBarCode;

@property (nonatomic, assign) BOOL additionalPhotoMode;

@property (nonatomic, strong) NSMutableDictionary *savedImageDictionary;

@property (nonatomic, assign) BOOL enableLocationServices;

/**
 *  Always display empty default capture photo, if set to false then it will dispaly the lastest saved photos.
 */
@property (nonatomic, assign) BOOL launchPhotoCaptureViewWithDefaultImagesAlways;

#pragma mark - End-user customize elements
@property (nonatomic, weak) IBOutlet UIView *backgroundView;
@property (nonatomic, weak) IBOutlet UIButton *manuallyEnterVINBtn;

@property (nonatomic, assign) BOOL showNavigateBar;

/**
 *  Allows the user to customize the top right help button
 *
 */
- (void) setNavigationHelpButtonImage:(UIImage*)image;


/**
 *  Custom Vin button with image
 *
 *  @param image button image
 */
- (void) setVinButtonImage:(UIImage *)image;

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
+ (CCCVINCaptureVC*)createVinScannerViewWithDelegate:(id<VinScannerVCDelegate>)delegate claimId:(NSString *) claimId;

+ (CCCVINCaptureVC*)createVinScannerViewWithDelegate:(id<VinScannerVCDelegate>)delegate adjuster:(CCCVINScanAdjuster *) adjuster claimId:(NSString *) claimId;

+ (CCCVINCaptureVC*)createVinScannerManualOptionViewWithDelegate:(id<VinScannerVCDelegate>)delegate claimId:(NSString *) claimId;

+ (CCCVINCaptureVC*)createVinScannerManualOptionViewWithDelegate:(id<VinScannerVCDelegate>)delegate adjuster:(CCCVINScanAdjuster *) adjuster claimId:(NSString *) claimId;

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
- (NSArray<CCCVINPhotoCaptureItem *> *) allPhotoCaptureItems;

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



@end
