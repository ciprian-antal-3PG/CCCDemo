//
//  CCCPredictSmartTotal.h
//  CCCSDK
//
//  Created by Animax Deng on 10/31/17.
//  Copyright © 2017 CCC. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

typedef enum : NSUInteger {
    SmartTotalRepairable,
    SmartTotalTotalLoss,
    SmartTotalUnknown,
} SmartTotalResultStatus;

@interface CCCPredictSmartTotalParams : NSObject

@property (strong, nonatomic) UIImage * _Nullable capturedImage;

@property (strong, nonatomic) NSString * _Nullable year;
@property (strong, nonatomic) NSString * _Nullable makeCode;
@property (strong, nonatomic) NSString * _Nullable model;
@property (strong, nonatomic) NSString * _Nullable doors;
@property (strong, nonatomic) NSString * _Nullable chapterID;
@property (strong, nonatomic) NSString * _Nullable vehicleType;
@property (strong, nonatomic) NSString * _Nullable bodyTypeCode;
@property (strong, nonatomic) NSString * _Nullable vehTypeCode;

@property (strong, nonatomic) NSString * _Nullable correlationID;
@property (strong, nonatomic) NSString * _Nullable ownerStateCode;

@property (strong, nonatomic) NSString * _Nullable stateCode;
@property (strong, nonatomic) NSString * _Nullable airbagDeployed;
@property (strong, nonatomic) NSString * _Nullable drivable;
@property (strong, nonatomic) NSString * _Nullable odometer;
@property (strong, nonatomic) NSString * _Nullable zipCode;
@property (strong, nonatomic) NSString * _Nullable primaryDamageCode;
@property (strong, nonatomic) NSString * _Nullable imageName;
@property (strong, nonatomic) NSString * _Nullable imageCreatedDate;
@property (strong, nonatomic) NSString * _Nullable imageLatitude;
@property (strong, nonatomic) NSString * _Nullable imageLongitude;
@property (strong, nonatomic) NSString * _Nullable imagePosition;
@property (strong, nonatomic) NSString * _Nullable additionalDescription;

- (NSString *_Nonnull)convertToJSON;

@end

@interface CCCPredictSmartTotalResponse : NSObject

@property (nonatomic) SmartTotalResultStatus status;
@property (strong, nonatomic) NSString * _Nonnull resourceId;

@end

typedef void (^fetchPredictSmartTotalCompleted)(CCCPredictSmartTotalResponse * __nullable result,NSError * __nullable error);

@interface CCCPredictSmartTotal : NSObject

+ (void)fetchSmartTotal:(CCCPredictSmartTotalParams * _Nonnull)param completionBlock:(fetchPredictSmartTotalCompleted _Nonnull)completetionHandler;

@end
