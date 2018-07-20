//
//  CCCPhotoComponentConstants.h
//  CCCPhotoComponents
//
//  Created by Sudhin on 01/02/17.
//  Copyright © 2017 CCC Information Services. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import <CoreLocation/CoreLocation.h>
typedef void (^GetLatLong)(BOOL isSucces, NSString* strText);


#define CCC_PHOTO_BAR_CODE_SCANNER_TEXT             @"Scanning ..."
#define CCC_PHOTO_CAPTURE_FLASH_LABEL_TEXTS         @[@"Auto", @"On", @"Off"]

#define CCC_PHOTO_CAPTURE_CAMERA_VIEW_DIM_MIN               230.f
#define CCC_PHOTO_CAPTURE_CAROUSEL_VIEW_HEIGHT              120.f

#define CCC_PHOTO_CAPTURE_THUMBNAIL_VIEW_DIM                115.f
#define CCC_PHOTO_CAPTURE_THUMBNAIL_VIEW_DIM4               130.f
#define CCC_PHOTO_CAPTURE_THUMBNAIL_VIEW_DIM5               140.f
#define CCC_PHOTO_CAPTURE_THUMBNAIL_VIEW_DIM6               150.f
#define CCC_PHOTO_CAPTURE_THUMBNAIL_VIEW_DIM6PLUS           160.f

#define CCC_PHOTO_CAPTURE_THUMBNAIL_HOLDER_VIEW_DIM         140.f
#define CCC_PHOTO_CAPTURE_THUMBNAIL_HOLDER_VIEW_DIM4        150.f
#define CCC_PHOTO_CAPTURE_THUMBNAIL_HOLDER_VIEW_DIM5        160.f
#define CCC_PHOTO_CAPTURE_THUMBNAIL_HOLDER_VIEW_DIM6        170.f
#define CCC_PHOTO_CAPTURE_THUMBNAIL_HOLDER_VIEW_DIM6PLUS    180.f
#define CCC_PHOTO_COMPONENTS_VIN_SCAN_VALID_NUMBER_OF_CHARS     17

#define CCC_PHOTO_CAPTURE_IMG_VIEW_TAG                      100
#define CCC_PHOTO_CAPTURE_BLANK_OVERLAY_VALUE                   @"blank"


#define EXPRESS_ESTIMATE_STATUS @"expressEstimateStatus"
#define GET_EXPRESS_ESTIATE_STATUS(claimID) [NSString stringWithFormat:@"%@_%@",EXPRESS_ESTIMATE_STATUS,(claimID ? claimID : @"NULL")]

#define CCC_PHOTO_CAPTURE_THUMBNAIL_NAMES                       @"carousel_VIN"
#define CCC_PHOTO_CAPTURE_OVERLAY_IMAGE_NAMES                   @"help_info_vin"
#define CCC_PHOTO_CAMERA_OVERLAY_IMAGE_NAMES                    @"cam_info_vin"

#pragma mark Configurable Keys
#define kConfigAppBoldFont [CCCVINScanComponentConstants getGlobalFontBold]
#define kConfigAppRegularFont [CCCVINScanComponentConstants getGlobalFontRegular]
#define kConfigAppString(strKey) [CCCVINScanComponentConstants getConfigStringForKey:strKey]
#define kConfigAppFloat(strKey) [CCCVINScanComponentConstants getGlobalFloatForKey:strKey]
#define kConfigAppBool(strKey) [CCCVINScanComponentConstants getGlobalBoolForKey:strKey]
#define kConfigAppArray(strKey) [CCCVINScanComponentConstants getConfigArrayForKey:strKey]
#define kConfigAppDictionary(strKey) [CCCVINScanComponentConstants getGlobalDictionaryForKey:strKey]
#define kConfigAppImage(strKey) [CCCVINScanComponentConstants getGlobalImageForKey:strKey]
#define kConfigAppColor(strKey) [CCCVINScanComponentConstants getGlobalColorForKey:strKey]
#define kGetDictionaryObjectForKey(dictionary,key) [dictionary objectForKey:key]?[dictionary objectForKey:key]:nil
#define kIsSmallScreen ([[UIScreen mainScreen] bounds].size.width < 321.0f)
#define kCheckIsEqualStrings(string1,string2) [string1 isEqualToString:string2]
// Keys
#pragma mark Help Overlay Screen Constants
#define kKeyConfigHelpOverlayVehiclePhotoLabelColor @"HelpOverlayVehiclePhotoLabelColor"
#define kKeyConfigHelpOverlayVehiclePhotoLabelFontType @"HelpOverlayVehiclePhotoLabelFontType"
#define kKeyConfigHelpOverlayMidTitleLabelColor @"HelpOverlayMidTitleLabelColor"
#define kKeyConfigHelpOverlayMidTitleLabelFontType @"HelpOverlayMidTitleLabelFontType"
#define kKeyConfigHelpOverlayMidSubTitleLabelColor @"HelpOverlayMidSubTitleLabelColor"
#define kKeyConfigHelpOverlayMidSubTitleLabelFontType @"HelpOverlayMidSubTitleLabelFontType"
#define kKeyConfigHelpOverlayTapAnywhereLabelColor @"HelpOverlayTapAnywhereLabelColor"
#define kKeyConfigHelpOverlayTapAnywhereLabelFontType @"HelpOverlayTapAnywhereLabelFontType"
#define kKeyConfigHelpOverlayImageColor @"HelpOverlayImageColor"
#define kKeyConfigHelpOverlayTextCloseLabel @"HelpOverlayTextCloseLabel"
#define kKeyConfigHelpOverlayDetailsDictionary @"HelpOverlayDetailsDictionary"
#define kKeyConfigHelpOverlayImageBackgroundColor @"HelpOverlayImageBackgroundColor"


#pragma mark VINScan Screen Constants
#define kKeyConfigCarouselLabelColor @"CarouselLabelColor"
#define kKeyConfigCarouselLabelFrontType @"CarouselLabelFrontType"
#define kKeyConfigScanningLabelText @"ScanningLabelText"
#define kKeyConfigScanningLabelTextFontType @"ScanningLabelTextFontType"   // TODO change this to config.plist
#define kKeyConfigTakePhotoFlashLabelFontType @"TakePhotoFlashLabelFontType" // TODO change this to config.plist
#define kKeyConfigManualEntryAlertTitle @"ManualEntryAlertTitle"
#define kKeyConfigManualEntryAlertTitleFontType @"ManualEntryAlertTitleFontType" // TODO add this to config.plist
#define kKeyConfigManualEntryAlertOkButtonText @"ManualEntryAlertOkButtonText"
#define kKeyConfigManualEntryAlertOkButtonTextFontType @"ManualEntryAlertOkButtonTextFontType" // TODO add this to config.plist
#define kKeyConfigManualEntryAlertCancelButtonText @"ManualEntryAlertCancelButtonText"
#define kKeyConfigManualEntryAlertCancelButtonTextFontType @"ManualEntryAlertCancelButtonTextFontType" // TODO add this to config.plist

#define kKeyConfigVINScanNavigationBarColor  @"VINScanNavigationBarColor"

#define kKeyConfigManualVINButtonText @"ManualVINButtonText"
#define kKeyConfigManualVINButtonColor @"ManualVINButtonColor"
#define kKeyConfigManualVINButtonFont @"ManualVINButtonFont"
#define kKeyConfigManualVINButtonBorderColor  @"ManualVINButtonBorderColor"
#define kKeyConfigManualVINButtonBorderWidth @"ManualVINButtonBorderWidth"
#define kKeyconfigManualVINButtonHighlightedColor @"ManualVINButtonHighlightedColor"
#define kKeyConfigManualVINButtonFontColor @"ManualVINButtonFontColor"
#define kKeyConfigManualVINButtonCornerRadius @"ManualVINButtonCornerRadius"

#define kKeyConfigHeaderIconColor @"VINScanHeaderIconColor"
#define kKeyConfigIconTitleColor @"IconTitleColor"
#define kKeyConfigPageCountLabelFontColor @"PageCountLabelFontColor"

#define kKeyConfigTextFlashButtonArray @"TextFlashButtonArray"

#define kKeyConfigTextCarouselPreviewArray @"TextCarouselPreviewArray"
#define kKeyConfigTextVINImageSaveTitle @"TextVINImageSaveTitle"

#define kKeyConfigTextTitle @"TextTitle"
#define kKeyConfigTextTitleFontType @"TextTitleFontType" //
#define kKeyConfigVINSCanTitleColor @"VINScanIconTitleColor"
#define kKeyConfigBlurryAlertMessage @"BlurryAlertMessage"
#define kKeyConfigBlurryAlertTitle @"BlurryAlertTitle"
#define kKeyConfigBlurryAlertRetakeActionTitle @"BlurryAlertRetakeActionTitle"
#define kKeyConfigBlurryAlertUsePhotoActionTitle @"BlurryAlertUsePhotoActionTitle"
#define kKeyConfigBlurValueThreshold @"BlurValueThreshold"
#define kUIImageImageNamed(imageName) [UIImage imageNamed:imageName]?[UIImage imageNamed:imageName]:[UIImage imageNamed:imageName inBundle:[NSBundle bundleForClass:[self class]] compatibleWithTraitCollection:nil]


#define kKeyConfigOverlayAnimationImages 

#pragma mark Application Constants
#define kConfigApplicationHeaderColor @"ApplicationHeaderColor"
#define kKeyConfigApplicationBackgroundColor @"ApplicationBackgroundColor"
#define kKeyConfigApplicationBoldStyleFontName @"ApplicationBoldStyleFontName"
#define kKeyConfigApplicationRegularStyleFontName @"ApplicationRegularStyleFontName"
#define kKeyConfigApplicationStatusbarType @"ApplicationStatusbarType"

#pragma mark NavigationBar
#define kKeyConfigNavigationControllerStatusbarType @"VinScanControllerStatusbarType"
#define kKeyConfigNavigationBarBackgroundColor @"NavigationBarBackgroundColor"
#define kKeyConfigNavigationBarTitleFontType @"NavigationBarTitleFontType"
#define kKeyConfigNavigationBarTitleFontColor @"NavigationBarTitleFontColor"
#define kKeyConfigNavigationBarInfoIconTintColor @"NavigationBarInfoIconTintColor"
#define kKeyConfigNavigationBarFlashIconTintColor @"NavigationBarFlashIconTintColor"
#define kKeyConfigNavigationBarIconTintColor @"NavigationBarIconTintColor"
#define kKeyConfigNavigationBarFlashLabelFontType @"NavigationBarFlashLabelFontType"
#define kKeyConfigNavigationBarFlashLabelFontColor @"NavigationBarFlashLabelFontColor"
#define kKeyConfigHelpOverlayBackgroundColor @"HelpOverlayBackgroundColor"
#define kKeyConfigManualVINButtonHighlightedFontColor @"ManualVINButtonHighlightedFontColor"

#pragma mark Adjuster Info

#define kKeyConfigAdjusterInfoClaimNumberTitle @"AdjusterInfoClaimNumberTitle"
#define kKeyConfigAdjusterInfoContactTitle @"AdjusterInfoContactTitle"
#define kKeyConfigAdjusterInfoOfficeTitle @"AdjusterInfoOfficeTitle"
#define kKeyConfigAdjusterInfoEmailTitle @"AdjusterInfoEmailTitle"
#define kKeyConfigAdjusterInfoTitlesColor @"AdjusterInfoTitlesColor"
#define kKeyConfigAdjusterInfoValueColor @"AdjusterInfoValueColor"
#define kKeyConfigAdjusterInfoPhoneNumberColor @"AdjusterInfoPhoneNumberColor"
#define kKeyConfigAdjusterInfoEmailSubject @"AdjusterInfoEmailSubject"
#define kKeyConfigAdjusterInfoGenericInboxEmail @"AdjusterInfoGenericInboxEmail"
#define kKeyConfigAdjusterInfoPhoneNumber @"AdjusterInfoPhoneNumber"
#define kKeyConfigAdjusterInfoEmailSubjectAppendClaim @"AdjusterInfoEmailSubjectAppendClaim"
#define kKeyConfigAdjusterInfoExtentionSeperator @"AdjusterInfoExtentionSeperator"

@interface CCCVINScanComponentConstants : NSObject<CLLocationManagerDelegate>

@property (nonatomic, strong) CLLocationManager *locationManager;
@property (nonatomic, copy) GetLatLong requestGetLatLong;
+ (CCCVINScanComponentConstants *)sharedInstance;
+ (NSArray*)getConfigArrayForKey:(NSString*)strKey;
+ (NSString*)getConfigStringForKey:(NSString*)strKey;
+ (NSDictionary*)getGlobalDictionaryForKey:(NSString*)strKey;
+ (float)getGlobalFloatForKey:(NSString*)strKey;
+ (BOOL)getGlobalBoolForKey:(NSString*)strKey;
+ (NSString*)getGlobalFontBold;
+ (NSString*)getGlobalFontRegular;
+ (UIImage*)getGlobalImageForKey:(NSString*)strKey;
+ (UIColor*)getGlobalColorForKey:(NSString*)strKey;
+ (UIImage*)getGlobalImageWithName:(NSString *)strName withColor:(UIColor*)tintColor;
+ (UIImage*)getGlobalImageFrom:(UIImage *)givenImage withColor:(UIColor*)tintColor;
+ (id)getConfigHelpOverlayValueForKey:(NSString*)key atIndex:(NSUInteger)index;
+ (UIImage *)imageFromColor:(UIColor *)color;
+ (void)configButton:(UIButton*)button defaultColor:(UIColor*)defaultColor buttonText:(NSString *) buttonText highlighedColor:(UIColor*)highlightedColor cornerRadius:(float)cornerRadius borderColor:(UIColor*)borderColor borderWidth:(float)borderWidth font:(UIFont*)font fontColor:(UIColor*)fontColor;
+ (void)configLabel:(UILabel*)label color:(UIColor*)color fontName:(NSString*)fontName;
- (void) getTextOverlayWithLatLongDate:(void (^ __nullable)(BOOL isSucces, NSString* strText)) handler;
+ (NSString*)getTextOverlayWithLatitude:(float)latitude longitude:(float)longitude;
- (void)getSuperImposedImage:(UIImage*)image  outputImage:(void(^)(UIImage* superImposedImage))outputImage;
+ (UIImage*)getSuperImposedImage:(UIImage*)image text:(NSString*)text;
+ (CGFloat) getHeightOfLabel:(UILabel*)label;
+(void)showAlertViewWithTitle:(NSString*) title message:(NSString*) message cancelButton:(NSString*) cancelButton otherButton:(NSString*) otherButton withController:(UIViewController*)controller buttonClicked:(void(^)(NSString* buttonTitle, NSInteger buttonIndex))buttonClicked;
- (void)enableLocationServices;
+(NSString*) getFormatedPhoneNumber:(NSString*)phoneNumber;
@end
