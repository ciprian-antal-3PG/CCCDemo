//
//  CCCDeviceUtils.h
//  CCCPhotoComponents
//
//  Created by Jerry Walton on 4/15/15.
//  Copyright (c) 2015 CCC. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "NSBundle+MYBundle.h"

#define CCC_DEVICE_UTILS_IPHONE4_MODELS         @[@"iPhone3,1",@"iPhone3,2",@"iPhone3,3",@"iPhone4,1"]
#define CCC_DEVICE_UTILS_IPHONE5_MODELS         @[@"iPhone5,1",@"iPhone5,2",@"iPhone5,3",@"iPhone5,4",@"iPhone6,1",@"iPhone6,2"]
#define CCC_DEVICE_UTILS_IPHONE6_MODELS         @[@"iPhone7,2"]
#define CCC_DEVICE_UTILS_IPHONE6PLUS_MODELS     @[@"iPhone7,1"]
#define IOS_VERSION_ON_THIS_DEVICE [UIDevice currentDevice].systemVersion.floatValue

#define FILE_SYSTEM_FREE_SIZE_BUFFER            1024

typedef enum : NSUInteger {
    CCCDeviceUtilsModelUnknown,
    CCCDeviceUtilsModel4,           // iPhone 3,1 | 3,2 | 3,3 | 4,1
    CCCDeviceUtilsModel5,           // iPhone 5,1 | 5,2 | 5,3 | 5,4 | 6,1 | 6,2
    CCCDeviceUtilsModel6,           // iPhone 7,2
    CCCDeviceUtilsModel6Plus        // iPhone 7,1
} CCCDeviceUtilsModel;

@interface CCCDeviceUtils : NSObject

+ (BOOL) isiPhone4Device;
+ (NSString *)platformRawString;
+ (CCCDeviceUtilsModel) iPhoneDeviceModel;
+ (BOOL) isCameraUsePermitted;
+ (BOOL) isLocationUsePermitted;
+ (BOOL) isEnoughFreeSpaceToSaveImage:(UIImage*)image;

@end
