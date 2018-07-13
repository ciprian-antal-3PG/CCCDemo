//
//  CCCSmartTotalVindecode.h
//  CCCSDK
//
//  Created by Animax Deng on 11/17/17.
//  Copyright © 2017 CCC. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "CCCSmartTotalVehicle.h"

typedef void (^fetchSmartTotalVindecodeCompleted)(NSArray<CCCSmartTotalVehicle *> * __nullable result,NSError * __nullable error);

@interface CCCSmartTotalVindecode : NSObject

+ (void)vindecode:(NSString * _Nonnull)vin completionBlock:(fetchSmartTotalVindecodeCompleted _Nonnull)completetionHandler;

@end
