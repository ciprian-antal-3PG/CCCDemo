//
//  CCCSDK.h
//  CCCSDK
//
//  Created by Viggnesh Kandasamy on 8/11/15.
//  Copyright (c) 2015 CCC. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

/**
 *  Project version number for the CCCSDK
 */
FOUNDATION_EXPORT double CCCSDKVersionNumber;

/**
 *  Project version string for the CCCSDK.
 */
FOUNDATION_EXPORT const unsigned char CCCSDKVersionString[];


// In this header, you should import all the public headers of your framework using statements like #import <CCCSDK/PublicHeader.h>
#import "CCCSDK_Global.h"
#import "CCCAuth.h"
#import "CCCNitroAuth.h"
#import "CCCVinDecode.h"
#import "CCCPAVinDecode.h"
#import "CCCPAPhotoCapture.h"
#import "CCCHeatMap.h"
#import "CCCQEHeatMap.h"
#import "CCCShopSearch.h"
#import "CCCPAFNOL.h"
#import "CCCBusinessEvent.h"
#import "CCCPASurvey.h"
#import "CCCPAEstimate.h"
#import "CCCPredictMOI.h"
#import "CCCAssignment.h"
#import "CCCSurvey.h"
#import "CCCUploadImages.h"
#import "CCCFetchEstimate.h"
#import "CCCNotificationService.h"
#import "CCCWorkflowStatus.h"

#import "CCCShopSelection.h"
#import "CCCPaymentNotification.h"
#import "CCCClaimCancelNotification.h"

#import "CCCPhotoEntity.h"
#import "PersistManager.h"
#import "EncryptManager.h"

#import "CCCAppraiserShopPhoto.h"
#import "CCCSmartSearch.h"
#import "CCCFetchSchedule.h"
#import "CCCAppraiser.h"
#import "CCCAppointment.h"
#import "CCCShopReviews.h"
#import "CCCPredictSmartTotal.h"
#import "CCCSmartTotalVehicle.h"
#import "CCCSmartTotalVindecode.h"

#import "CCCUploadVideo.h"
#import "CCCUploadVideoUtil.h"
#import "BackgroundSessionManager.h"

#import "CCCDownloadManager.h"
#import "CCCAppConfig.h"
#import "CCCConfigValues.h"
#import "CCCClaimContact.h"
/**
 
 CCCSDK can perform operations that involves communicating with CCC servers. It exposes native objects and does not provide
 any user interface. Developers can design their own UI to display the data returned by the service component. For example,
 the Authentication Service takes Claim ID and Last Name as input parameters and returns whether the claim is valid or not.
 The screen to provide Claim ID and Last Name and screen to show past successful authentication is at the discretion of the
 developer and the insurance company.
 
 */
@interface CCCSDK : NSObject

#pragma mark - public properties

/**
 * Provides a list of supported environments
 */
typedef enum Environment: NSInteger {
    DEV,
    INT,
    INT2,
    QA,
    PX,
    CT,
    PROD
} Environment;

/**
 * Provides a list of supported environments
 */
typedef enum NitroServerType: NSInteger {
    NitroServerPhotoAnalytic,
    NitroServerTvR,
} NitroServerType;


/**
 *  Point to CCCAuth module
 */
@property (readonly, assign, nonatomic, nonnull) CCCAuth *CCCAuth;

/**
 *  Point to CCCNitroAuth module
 */
@property (readonly, assign, nonatomic, nonnull) CCCNitroAuth *CCCNitroAuth;

@property (readonly, assign, nonatomic, nullable) CCCVehicle *CurrentVehicle;

//- (void)setInit

/**
 * Provides a shared instance of CCCSDK for iOS.
 *
 *  @return Shared instance of the CCCSDK.
 */
+ (CCCSDK *_Nonnull)sharedInstance;
+ (Environment)convertStringToEnvironment:(NSString *_Nonnull)env;

- (void) setCurrentVehicle:(CCCVehicle *_Nonnull)vehicle;

/**
 *  Initialize CCCCSK with environment and company code
 *
 *  @param companyCode Represents the Company Code
 *  @param environment Represents the Environment
 *  @param Auto set server URL as well
 */
- (void) initializeCCCSDKWithCompanyCode :(NSString * _Nullable)companyCode serverEnvironment:(Environment) env isSetServerURL:(BOOL)isSetServerURL;

/**
 *  Initialize CCCCSK with environment and company code
 *
 *  @param companyCode Represents the Company Code
 *  @param env Represents the Environment
 */
- (void) initializeCCCSDKWithCompanyCode :(NSString * _Nullable)companyCode serverEnvironment:(Environment) env;


/**
 Initialize Nitro Server CCCCSK with environment and carrier token

 @param serverType  Nitro Server Type
 @param environment Represents the Environment
 */
- (void)initializeNitroCCCSDK:(NitroServerType)serverType withServerEnvironment:(Environment)environment;

/**
 *  Initialize CCCCSK with environment and company code
 *
 *  @param environment Represents the Environment
 */
- (void) initializeCCCSDKWithServerEnvironment:(Environment) env;

/**
 *  Setup and store environment string, it will not change others CCCSDK setting
 *
 *  @param The Environment
 */
- (void) setupOnlyEnvironment:(NSString *_Nonnull)env;

+ (void) setServerDefaults:(NSString *_Nonnull) urlString;

+ (NSDictionary *_Nonnull) getDeviceInfo;


/**
 *  Store VIN
 *
 *  @param VIN
 */

- (void) addRedFlagIntegrationWithVIN:(NSString *_Nonnull) vin;

/**
 *  Represents the environment to which the CCCSDK points to.
 */
@property(nonatomic, retain) NSString * _Nonnull serverEnviroment;

/**
 *  Represents the companycode to which the CCCSDK points to.
 */
@property(nonatomic, retain) NSString * _Nullable companyCode;

/**
 *  Represents the CarrierToken to which the CCCSDK points to [Nirto Server Only]
 */
@property(nonatomic, retain) NSString * _Nullable carrierToken;


@end
