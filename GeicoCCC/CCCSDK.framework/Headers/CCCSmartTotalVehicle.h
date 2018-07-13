//
//  CCCSmartTotalVehicle.h
//  CCCSDK
//
//  Created by Animax Deng on 11/20/17.
//  Copyright © 2017 CCC. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface CCCSmartTotalVehicle : NSObject

@property (nonatomic, strong) NSString *_Nullable availability;
@property (nonatomic, strong) NSString *_Nullable carburation;
@property (nonatomic, strong) NSNumber *_Nullable cccModelCode;
@property (nonatomic, strong) NSString *_Nullable cccModelName;

@property (nonatomic, strong) NSString *_Nullable cccRefId;
@property (nonatomic, strong) NSString *_Nullable cccRefId36;

@property (nonatomic, strong) NSString *_Nullable cccStyleName;
@property (nonatomic, strong) NSString *_Nullable ciecaCode;

@property (nonatomic, strong) NSString *_Nullable cylinder;
@property (nonatomic, strong) NSString *_Nullable displacement;
@property (nonatomic, strong) NSString *_Nullable displayEngine;
@property (nonatomic, strong) NSString *_Nullable displayModel;
@property (nonatomic, strong) NSNumber *_Nullable doors;

@property (nonatomic, strong) NSString *_Nullable fuel;
@property (nonatomic, strong) NSString *_Nullable makeCode;
@property (nonatomic, strong) NSString *_Nullable makeDesc;
@property (nonatomic, strong) NSNumber *_Nullable modelSeq;
@property (nonatomic, strong) NSString *_Nullable motorChapterId;
@property (nonatomic, strong) NSString *_Nullable motorSubChapterId;

@property (nonatomic, strong) NSString *_Nullable msrp;
@property (nonatomic, strong) NSString *_Nullable styleId;

@property (nonatomic, strong) NSString *_Nullable trim;
@property (nonatomic, strong) NSString *_Nullable vehBodyTypeCode;
@property (nonatomic, strong) NSString *_Nullable vehBodyTypeDesc;
@property (nonatomic, strong) NSString *_Nullable vehTypeCode;
@property (nonatomic, strong) NSString *_Nullable vehTypeDesc;
@property (nonatomic, strong) NSNumber *_Nullable year;

+ (CCCSmartTotalVehicle *_Nonnull) createVehicleModel:(NSDictionary *_Nonnull)vehicleInfo;


@end
