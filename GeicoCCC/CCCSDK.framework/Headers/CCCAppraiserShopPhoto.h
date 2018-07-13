//
//  CCCAppraiserShopPhoto.h
//  CCCSDK
//
//  Created by Viggnesh Kandasamy on 6/6/17.
//  Copyright © 2017 CCC. All rights reserved.
//

//#import <CCCSDK/CCCSDK.h>
#import <Foundation/Foundation.h>
#import "JSONModelLib.h"

@protocol CCCAppraiserShopPhoto;
@interface CCCAppraiserShopPhoto : JSONModel
@property (strong, nonatomic) NSString <Optional> *photoUuid;
@property (strong, nonatomic) NSString <Optional> *photoLabel;
@property (strong, nonatomic) NSString <Optional> *photoHeigh;
@property (strong, nonatomic) NSString <Optional> *photoWidth;

@end
