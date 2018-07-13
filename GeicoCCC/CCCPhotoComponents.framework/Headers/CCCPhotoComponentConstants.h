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
typedef void (^GetLatLong)(BOOL isSucces, NSString* strText, CLLocationCoordinate2D coordinate);

#pragma mark Configurable Keys
#define kConfigAppBoldFont [CCCPhotoComponentConstants getGlobalFontBold]
#define kConfigAppRegularFont [CCCPhotoComponentConstants getGlobalFontRegular]
#define kConfigAppString(strKey) [CCCPhotoComponentConstants getConfigStringForKey:strKey]
#define kConfigAppFloat(strKey) [CCCPhotoComponentConstants getGlobalFloatForKey:strKey]
#define kConfigAppArray(strKey) [CCCPhotoComponentConstants getConfigArrayForKey:strKey]
#define kConfigAppDictionary(strKey) [CCCPhotoComponentConstants getGlobalDictionaryForKey:strKey]
#define kConfigAppImage(strKey) [CCCPhotoComponentConstants getGlobalImageForKey:strKey]
#define kConfigAppColor(strKey) [CCCPhotoComponentConstants getGlobalColorForKey:strKey]
#define kConfigAppBool(strKey) [CCCPhotoComponentConstants getGlobalBoolForKey:strKey]
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
#define kKeyConfigHelpOverlayBackgroundColor @"HelpOverlayBackgroundColor"
#pragma mark Take Photo Screen Constants
#define kKeyConfigTakePhotoBackgroundColor @"TakePhotoBackgroundColor"
#define kKeyConfigTakePhotoHeaderIconColor @"TakePhotoHeaderIconColor"
#define kKeyConfigTakePhotoFlashLabelFontType @"TakePhotoFlashLabelFontType"
#define kKeyConfigTakePhotoCameraButtonColor @"TakePhotoCameraButtonColor"
#define kKeyConfigTakePhotoCameraButtonHighlightedColor @"TakePhotoCameraButtonHighlightedColor"
#define kKeyConfigTakePhotoIconTitleColor @"TakePhotoIconTitleColor"
#define kKeyConfigTakePhotoPreviewTitleFontType @"TakePhotoPreviewTitleFontType"
#define kKeyConfigTakePhotoRetakeButtonColor @"TakePhotoRetakeButtonColor"
#define kKeyConfigTakePhotoRetakeButtonBorderColor @"TakePhotoRetakeButtonBorderColor"
#define kKeyConfigTakePhotoRetakeButtonBorderWidth @"TakePhotoRetakeButtonBorderWidth"
#define kKeyConfigTakePhotoRetakeButtonHighlightedColor @"TakePhotoRetakeButtonHighlightedColor"
#define kKeyConfigTakePhotoRetakeButtonFontColor @"TakePhotoRetakeButtonFontColor"
#define kKeyConfigTakePhotoRetakeButtonFontType @"TakePhotoRetakeButtonFontType"
#define kKeyConfigTakePhotoRetakeButtonCornerRadius @"TakePhotoRetakeButtonCornerRadius"
#define kKeyConfigTakePhotoUsePhotoButtonColor @"TakePhotoUsePhotoButtonColor"
#define kKeyConfigTakePhotoUsePhotoButtonHighlightedColor @"TakePhotoUsePhotoButtonHighlightedColor"
#define kKeyConfigTakePhotoUsePhotoButtonBorderWidth @"TakePhotoUsePhotoButtonBorderWidth"
#define kKeyConfigTakePhotoUsePhotoButtonBorderColor @"TakePhotoUsePhotoButtonBorderColor"
#define kKeyConfigTakePhotoUsePhotoButtonFontColor @"TakePhotoUsePhotoButtonFontColor"
#define kKeyConfigTakePhotoUsePhotoButtonFontType @"TakePhotoUsePhotoButtonFontType"
#define kKeyConfigTakePhotoUsePhotoButtonCornerRadius @"TakePhotoUsePhotoButtonCornerRadius"
#define kKeyConfigTakePhotoContinueButtonFontColor @"TakePhotoContinueButtonFontColor"
#define kKeyConfigTakePhotoContinueButtonFontType @"TakePhotoContinueButtonFontType"
#define kKeyConfigTakePhotoContinueButtonHighlightedColor @"TakePhotoContinueButtonHighlightedColor"
#define kKeyConfigTakePhotoContinueButtonColor @"TakePhotoContinueButtonColor"
#define kKeyConfigTakePhotoContinueButtonBorderColor @"TakePhotoContinueButtonBorderColor"
#define kKeyConfigTakePhotoContinueButtonBorderWidth @"TakePhotoContinueButtonBorderWidth"
#define kKeyConfigTakePhotoContinueButtonCornerRadius @"TakePhotoContinueButtonCornerRadius"
#define kKeyConfigTakePhotoImageViewBackgroundColor @"TakePhotoImageViewBackgroundColor"

#define kKeyConfigTakePhotoPageCountLabelFontColor @"TakePhotoPageCountLabelFontColor"
#define kKeyConfigTakePhotoPageCountLabelFontType @"TakePhotoPageCountLabelFontType"
#define kKeyConfigTakePhotoTextFlashButtonArray @"TakePhotoTextFlashButtonArray"
#define kKeyConfigTakePhotoTextCarouselPreviewArray @"TakePhotoTextCarouselPreviewArray"
#pragma mark NavigationBar
#define kKeyConfigNavigationBarBackgroundColor @"NavigationBarBackgroundColor"
#define kKeyConfigNavigationBarTitleFontType @"NavigationBarTitleFontType"
#define kKeyConfigNavigationBarTitleFontColor @"NavigationBarTitleFontColor"
#define kKeyConfigNavigationBarInfoIconTintColor @"NavigationBarInfoIconTintColor"
#define kKeyConfigNavigationBarFlashIconTintColor @"NavigationBarFlashIconTintColor"
#define kKeyConfigNavigationBarIconTintColor @"NavigationBarIconTintColor"
#define kKeyConfigNavigationBarFlashLabelFontType @"NavigationBarFlashLabelFontType"
#define kKeyConfigNavigationBarFlashLabelFontColor @"NavigationBarFlashLabelFontColor"


// TODO remove if not needed

#define kKeyConfigReviewPhotosVehiclePhotoTitles @"ReviewPhotosVehiclePhotoTitles"
#define kKeyConfigReviewPhotosDamagePhotoTitles @"ReviewPhotosDamagePhotoTitles"
#define kKeyConfigReviewPhotosOdometerVINPhotoTitles @"ReviewPhotosOdometerVINPhotoTitles"

// Overaly Arrays
#define kKeyConfigTakePhotoHelpOverlayImagesArray @"TakePhotoHelpOverlayImagesArray"
#define kKeyConfigTakePhotoCameraOverlayImagesArray @"TakePhotoCameraOverlayImagesArray"

// Thumbnail Image Arrays
#define kKeyConfigTakePhotoCaptureThumbnailImagesArray @"TakePhotoCaptureThumbnailImagesArray"


#define kKeyConfigTakePhotoSaveNames @"TakePhotoTextPhotoSaveNameArray"
#define kKeyConfigTakePhotoTextHeader @"TakePhotoTextHeader"
#define kKeyConfigTakePhotoTextButtonUsePhoto @"TakePhotoTextButtonUsePhoto"
#define kKeyConfigTakePhotoTextButtonRetake @"TakePhotoTextButtonRetake"
#define kKeyConfigTakePhotoTextButtonContinue @"TakePhotoTextButtonContinue"
#define kKeyConfigTakePhotoBlurryAlertMessage @"TakePhotoBlurryAlertMessage"
#define kKeyConfigTakePhotoBlurryAlertTitle @"TakePhotoBlurryAlertTitle"
#define kKeyConfigTakePhotoBlurryAlertRetakeActionTitle @"TakePhotoBlurryAlertRetakeActionTitle"
#define kKeyConfigTakePhotoBlurryAlertUsePhotoActionTitle @"TakePhotoBlurryAlertUsePhotoActionTitle"
#define kKeyConfigTakePhotoBlurValueThreshold @"TakePhotoBlurValueThreshold"
#define kUIImageImageNamed(imageName) [UIImage imageNamed:imageName]?[UIImage imageNamed:imageName]:[UIImage imageNamed:imageName inBundle:[NSBundle bundleForClass:[self class]] compatibleWithTraitCollection:nil]

// Additional photo/ retake

#define kKeyConfigTakePhotoCarouselPageLabelOf  @"TakePhotoCarouselPageLabelOf"
#define kKeyConfigTakePhotoTextHeaderRetake  @"TakePhotoTextHeaderRetake"
#define kKeyConfigTakePhotoAdditionalPhotoButtonTitle  @"TakePhotoAdditionalPhotoButtonTitle"
#define kKeyConfigTakePhotoAdditionalPhotoNamePrefix  @"TakePhotoAdditionalPhotoNamePrefix"
#define kKeyConfigTakePhotoAdditionalPhotoSaveNamePrefix @"TakePhotoAdditionalPhotoSaveNamePrefix"
#define kKeyConfigTakePhotoShouldSuperImposeLocationTime @"TakePhotoShouldSuperImposeLocationTime"

#pragma mark Application Constants
#define kConfigApplicationHeaderColor @"ApplicationHeaderColor"
#define kKeyConfigApplicationBackgroundColor @"ApplicationBackgroundColor"
#define kKeyConfigApplicationBoldStyleFontName @"ApplicationBoldStyleFontName"
#define kKeyConfigApplicationRegularStyleFontName @"ApplicationRegularStyleFontName"
#define kKeyConfigTakePhotoControllerStatusbarType @"TakePhotoControllerStatusbarType"
#define kKeyConfigApplicationStatusbarType @"ApplicationStatusbarType"

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
@interface CCCPhotoComponentConstants : NSObject<CLLocationManagerDelegate>

@property (nonatomic, strong) CLLocationManager *locationManager;
@property (nonatomic, strong) NSMutableDictionary *latLonDict;
@property (nonatomic, copy) GetLatLong requestGetLatLong;
+ (CCCPhotoComponentConstants *)sharedInstance;
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
+ (void)configButton:(UIButton*)button defaultColor:(UIColor*)defaultColor highlighedColor:(UIColor*)highlightedColor cornerRadius:(float)cornerRadius borderColor:(UIColor*)borderColor borderWidth:(float)borderWidth font:(UIFont*)font fontColor:(UIColor*)fontColor;
+ (void)configLabel:(UILabel*)label color:(UIColor*)color fontName:(NSString*)fontName;
- (void) getTextOverlayWithLatLongDate:(void (^ __nullable)(BOOL isSucces, NSString* strText)) handler;
+ (NSString*)getTextOverlayWithLatitude:(float)latitude longitude:(float)longitude;
- (void)getSuperImposedImage:(UIImage*)image forTitle: (NSString *)title outputImage:(void(^)(UIImage* superImposedImage))outputImage;
//- (void)getSuperImposedImage:(UIImage*)image  outputImage:(void(^)(UIImage* superImposedImage))outputImage;
+ (UIImage*)getSuperImposedImage:(UIImage*)image text:(NSString*)text;
+ (CGFloat) getHeightOfLabel:(UILabel*)label;
+(void)showAlertViewWithTitle:(NSString*) title message:(NSString*) message cancelButton:(NSString*) cancelButton otherButton:(NSString*) otherButton withController:(UIViewController*)controller buttonClicked:(void(^)(NSString* buttonTitle, NSInteger buttonIndex))buttonClicked;
- (void)enableLocationServices;
+ (NSString*) getFormatedPhoneNumber:(NSString*)phoneNumber;
// TODO Remove if not needed
+(NSString*)getDisplayNameFromFileName:(NSString*)fileName;

@end
