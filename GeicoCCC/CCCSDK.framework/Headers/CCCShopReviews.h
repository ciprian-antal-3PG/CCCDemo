//
//  CCCShopReviews.h
//  CCCSDK
//
//  Created by Viggnesh Kandasamy on 6/16/17.
//  Copyright © 2017 CCC. All rights reserved.
//

#import <CCCSDK/CCCSDK.h>
#import "CCCShopReviewsResponse.h"
@protocol CCCShopReviewsResponse;
@protocol CCCShopReviews;
@interface CCCShopReviews : JSONModel
@property (nonatomic, strong) NSString <Optional> * _Nullable appraiserCode;
@property (nonatomic, strong) NSNumber <Optional> * _Nullable page;
@property (nonatomic, strong) NSString <Optional> * _Nullable vehicleOwnerFirstName;
@property (nonatomic, strong) NSString <Optional> * _Nullable vehicleYear;
@property (nonatomic, strong) NSString <Optional> * _Nullable vehicleMake;
@property (nonatomic, strong) NSDate <Optional>  * _Nullable reviewDate;
//@property (nonatomic, strong) NSString <Optional> * _Nullable reviewDate;
@property (nonatomic, strong) NSString <Optional> * _Nullable reviewType;
@property (nonatomic, strong) NSString <Optional> * _Nullable overallRating;
@property (nonatomic, strong) NSString <Optional> * _Nullable overallRatingImage;


@property (nonatomic, strong) NSArray<CCCShopReviewsResponse> * _Nullable reviewResponse;

@property (nonatomic, strong) NSArray<CCCShopReviews> * _Nullable items;


+ (void) FetchShopReviewsWithAppraiserCode : (NSString *_Nullable) appraiserCode page : (NSNumber *_Nullable) page completionBlock:(nullable void(^)(NSArray<CCCShopReviews> * __nullable reviewResponse, NSError * _Nullable error))block;

+ (void) FetchShopReviewsWithSession: (NSString *_Nullable) sessionToken appraiserCode : (NSString *_Nullable) appraiserCode page : (NSNumber *_Nullable) page completionBlock:(nullable void(^)(NSArray<CCCShopReviews> * __nullable reviewResponse, NSError * _Nullable error))block;

@end
