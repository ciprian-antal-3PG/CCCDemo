//
//  CCCShopReviewsResponse.h
//  CCCSDK
//
//  Created by Viggnesh Kandasamy on 6/16/17.
//  Copyright © 2017 CCC. All rights reserved.
//

#import <CCCSDK/CCCSDK.h>
@protocol CCCShopReviewsResponse;
@interface CCCShopReviewsResponse : JSONModel
@property (nonatomic, strong) NSString <Optional> *question;
@property (nonatomic, strong) NSString <Optional> *responseValue;
@property (nonatomic, strong) NSString <Optional> *responseText;
@property (nonatomic, strong) NSString <Optional> *responseImage;

@end
