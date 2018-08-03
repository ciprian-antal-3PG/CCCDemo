//
//  VINUtility.h
//  CCCPredictMOISDK
//
//  Created by Animax Deng on 3/6/17.
//  Copyright © 2017 CCC. All rights reserved.
//

#import <Foundation/Foundation.h>


@interface CCCVINDetails : NSObject

@property (strong, nonatomic) NSString *VIN;
@property (assign, nonatomic) BOOL isValid;

@end

@interface VINUtility : NSObject

+(BOOL) checkVINValidity:(NSString *)vin;
+(NSString *) replaceCharactersInVIN:(NSString *)vin;
@end
