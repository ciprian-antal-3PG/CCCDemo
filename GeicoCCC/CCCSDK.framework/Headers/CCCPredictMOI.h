//
//  CCCPredictMOI.h
//  CCCSDK
//
//  Created by bkongara on 9/28/16.
//  Copyright © 2016 CCC. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "CCCVinDecode.h"
#import <CCCSDK/CCCSDK.h>

@class CCCMOIRecommendation;
@class CCCVehicleMake;
@class CCCVehicleModel;

typedef void  (^getMOIRecommendationsCompleted)(NSArray<CCCMOIRecommendation *> * __nullable recommendations,NSError * __nullable error);
typedef void (^getVehicleYearsCompleted)(NSArray<NSString *> * __nullable modelYears, NSError * __nullable error);
typedef void (^getVehicleMakesCompleted)(NSArray<CCCVehicleMake *> * __nullable modelMakes, NSError * __nullable error);
typedef void (^getVehicleModelsCompleted)(NSArray<CCCVehicleModel *> * __nullable vehicleModels ,NSError * __nullable error);
typedef void (^getVehiclesCompleted)(NSArray<CCCVehicle *> * __nullable vehicles, NSError * __nullable error);


@interface CCCVehicleBodyType : NSObject

@property (strong, nonatomic) NSString * _Nonnull displayName;
@property (strong, nonatomic) NSString * _Nonnull value;

+ (CCCVehicleBodyType * _Nonnull)create:(NSString * _Nonnull)name value:(NSString * _Nonnull)value;

@end

@interface CCCVehicleMake : NSObject

@property (strong, nonatomic) NSString * _Nonnull code;
@property (strong, nonatomic) NSString * _Nonnull desc;

@end

@interface CCCVehicleModel : NSObject

@property (strong, nonatomic) NSString * _Nonnull displayModel;
@property (strong, nonatomic) NSString * _Nonnull modelCode;
@property (strong, nonatomic) NSString * _Nonnull modelName;
@property (strong, nonatomic) NSString * _Nonnull styleName;
@property (strong, nonatomic) NSString * _Nonnull trim;

@end

@interface CCCMOIRecommendation : NSObject

@property (strong, nonatomic) NSString * _Nonnull totalLossCategory;
@property (strong, nonatomic) NSString * _Nonnull suggestion;
@property (strong, nonatomic) NSString * _Nonnull totalLossCategoryCodeDescription;
@property (strong, nonatomic) NSString * _Nonnull suggestionCodeDescription;
@property (strong, nonatomic) NSString * _Nonnull stdTLCategoryCode;
@property (strong, nonatomic) NSString * _Nonnull stdMOISuggestionCode;
@property (strong, nonatomic) NSString * _Nullable appraiserDistance;
@property (nonatomic) NSInteger ruleID;
@property (nonatomic) NSInteger priority;

@end


@interface CCCVehicleDetails : NSObject

@property (strong, nonatomic) NSString * _Nonnull year;
@property (strong, nonatomic) NSString * _Nonnull make;
@property (strong, nonatomic) NSString * _Nonnull model;
@property (strong, nonatomic) NSString * _Nonnull vin;
@property (strong, nonatomic) NSString * _Nonnull vehicleType;
@property (strong, nonatomic) NSString * _Nonnull ownerStateCode;
@property (strong, nonatomic) NSString * _Nonnull ownerPostalCode;
@property (strong, nonatomic) NSString * _Nonnull ownerPostalCodeExtn;

// ---------------------
// Fetch Vehicles Years
// ---------------------
+(void) fetchVehicleYearsWithSession:(NSString * _Nonnull)session completion:(getVehicleYearsCompleted _Nullable)completionHandler;
+(void) fetchVehicleYears:(getVehicleYearsCompleted _Nullable)completionHandler;

// ---------------------
// Fetch Vehicles Makes
// ---------------------
+(void) fetchVehicleMakesWithSession:(NSString * _Nonnull)session Year:(NSString * _Nonnull) modelYear completionBlock:(getVehicleMakesCompleted _Nullable)completionHandler;
+(void) fetchVehicleMakes:(NSString * _Nonnull) modelYear completionBlock:(getVehicleMakesCompleted _Nullable)completionHandler;

// ---------------------
// Fetch Vehicles Models
// ---------------------
+(void) fetchVehicleModelsWithSession:(NSString * _Nonnull)session
                               Year:(NSString * _Nonnull) modelYear
                               Make:(NSString * _Nonnull) modelMake
                    completionBlock:(getVehicleModelsCompleted _Nullable)completionHandler;
+(void) fetchVehicleModelsWithYear:(NSString * _Nonnull) modelYear
                            Make:(NSString * _Nonnull) modelMake
                 completionBlock:(getVehicleModelsCompleted _Nullable)completionHandler;

// ---------------------
// Fetch Vehicles
// ---------------------

+(void) fetchVehiclesWithSession:(NSString * _Nonnull)session
                          year:(NSString * _Nonnull) year
                          make:(NSString * _Nonnull) make
                         model:(NSString * _Nonnull) model
               completionBlock:(getVehiclesCompleted _Nullable)completionHandler;
+(void) fetchVehiclesWithSession:(NSString * _Nonnull)session
                          Year:(NSString * _Nonnull) year
                          make:(NSString * _Nonnull) make
                         model:(NSString * _Nonnull) model
                          trim:(NSString * _Nullable) trim
               completionBlock:(getVehiclesCompleted _Nullable)completionHandler;

+(void) fetchVehiclesByYear:(NSString * _Nonnull) year
                     make:(NSString * _Nonnull) make
                    model:(NSString * _Nonnull) model
          completionBlock:(getVehiclesCompleted _Nullable)completionHandler;
+(void) fetchVehiclesByYear:(NSString * _Nonnull) year
                     make:(NSString * _Nonnull) make
                    model:(NSString * _Nonnull) model
                     trim:(NSString * _Nullable) trim
          completionBlock:(getVehiclesCompleted _Nullable)completionHandler;

@end


@interface CCCVehicleDamageInfo : NSObject

@property (strong, nonatomic) NSNumber * _Nonnull primaryDamageCode;
@property (strong, nonatomic) NSNumber * _Nonnull secondaryDamageCode;
@property (strong, nonatomic) NSString * _Nonnull driveableIndicator;
@property (strong, nonatomic) NSString * _Nonnull airBagDeployedIndicator;
@property (strong, nonatomic) NSString * _Nonnull odometerReading;

@end


@interface CCCPredictMOIInputParams : NSObject

@property (strong, nonatomic) NSString * _Nonnull requestId;
@property (strong, nonatomic) NSString * _Nonnull insuranceCompanyCode;
@property (strong, nonatomic) NSString * _Nonnull claimReferenceId;
@property (strong, nonatomic) NSString * _Nonnull claimOfficeBranchCode;

@property (strong, nonatomic) CCCVehicleDetails * _Nonnull vehicle;
@property (strong, nonatomic) CCCVehicleDamageInfo * _Nonnull damageInfo;

@property (strong, nonatomic) NSString * _Nonnull partyKind;
@property (strong, nonatomic) NSString * _Nonnull liabilityConfirmed;
@property (strong, nonatomic) NSString * _Nonnull severity;
@property (strong, nonatomic) NSString * _Nonnull intentToRepair;
@property (strong, nonatomic) NSString * _Nonnull rentalInUse;
@property (strong, nonatomic) NSString * _Nonnull injuries;

@property (strong, nonatomic) NSString * _Nonnull userFirstName;
@property (strong, nonatomic) NSString * _Nonnull userLastName;

@property (strong, nonatomic) NSArray<NSString *> * _Nonnull customFields;


@end


@interface CCCPredictMOI : NSObject

@property (strong,nonatomic) NSString * _Nonnull partyKind;
@property (assign,nonatomic) bool liabilityConfirmed;
@property (strong,nonatomic) NSString * _Nonnull severity;
@property (assign,nonatomic) bool intentToRepair;
@property (assign,nonatomic) bool rentalInUse;
@property (assign,nonatomic) bool injuries;
@property (strong,nonatomic) NSDictionary * _Nonnull sourceUserName;
@property (strong,nonatomic) NSDictionary * _Nonnull actualAction;
@property (strong,nonatomic) NSDictionary * _Nonnull actualTotalLossCategory;
@property (strong,nonatomic) NSMutableArray * _Nonnull customFields;

+(void)getMOIRecommendations:(CCCPredictMOIInputParams * _Nonnull)params
             completionBlock:(getMOIRecommendationsCompleted _Nullable)completionHandler;


+(void)getMOIRecommendationsWithSession:(NSString * _Nonnull)session
             requestParams:(CCCPredictMOIInputParams * _Nonnull)params
             completionBlock:(getMOIRecommendationsCompleted _Nullable)completionHandler;
@end
