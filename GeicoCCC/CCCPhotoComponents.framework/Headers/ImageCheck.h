//
//  ImageCheck.h
//  ImageBlur
//
//  Created by Developer on 01/11/16.
//  Copyright © 2016 POC. All rights reserved.
//


#import <UIKit/UIKit.h>
#import <Foundation/Foundation.h>
#import <AVFoundation/AVCaptureDevice.h>
///Enum containg different brightness status
typedef enum {
    kBrightnessTooHigh,
    kBrightnessNormal,
    kBrightnessTooLow
}BrightnessStatus;

@interface ImageCheck : NSObject
///Check and Analyze image Blurriness
+ (BOOL)checkImageIsBlurrUsingLaplacian:(UIImage *)image;

///Another blur checking method
+ (BOOL)checkImageIsBlurrBaseOnPosition:(UIImage *)image;

///Calculate dark pixels from image.
+ (double)getBrightnessFromImage:(UIImage *)image;

///Analyze and returns the brightness status.
+ (int)getBrightnessStatusFromImage:(UIImage*)image;

///Calculate Brightness threshold from Image.
+ (double)getBrightnessThresholdFromImage:(UIImage *)inputImage;

///Apply Image ExposureAdjust Filter with given saturation Value.
+ (UIImage*) getExposureAdjustedImage:(UIImage*)image;
@end
