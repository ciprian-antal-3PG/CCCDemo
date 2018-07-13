//
//  Common.h
//  ImageBlur
//
//  Created by Sudhin on 01/11/16.
//  Copyright © 2016 POC. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

#define kGetFileWithNameFromDocuments(fileName) [[NSSearchPathForDirectoriesInDomains(NSDocumentDirectory,NSUserDomainMask,YES) firstObject] stringByAppendingPathComponent:fileName]
//#define kUserDefaultObjectForKey(key) [[NSUserDefaults standardUserDefaults] objectForKey:key]
//#define kUserDefaultSetObjectForKey(object,key)  {[[NSUserDefaults standardUserDefaults] setObject:object forKey:key]; [[NSUserDefaults standardUserDefaults] synchronize];}
#define kGetObjectForKey(dictionary,key) [dictionary objectForKey:key]?[dictionary objectForKey:key]:nil
#define kCheckIsEqualStrings(string1,string2) [string1 isEqualToString:string2]
#define kConfigGlobalString(strKey) [ImageCommon getGlobalStringForKey:strKey]
#define kConfigGlobalFloat(strKey) [ImageCommon getGlobalFloatForKey:strKey]
#define kGetLuminance(R,G,B) (0.299*R + 0.587*G + 0.114*B)

#define TakePhotoBlurValueThreshold 175.0
#define TakePhotoBrightnessThresholdConstant 0.8
#define TakePhotoBrightAdjustmentConstant 10
#define TakePhotoCompressImageQuality 0.65

#define kUserdefaultBlurrValueArray @"blur values"
#define kKeyName @"Name"
#define kKeyAdjustedImageName @"AdjustedImageName"
#define kKeyBrightnessThreshold @"brightnessThreshold"
#define kKeyBlurriness @"Blurriness"
#define kKeyImagesFoldername @"ImagesTaken"

@interface ImageCommon : NSObject
+(UIImage*)drawFront:(UIImage*)image text:(NSString*)text;
+(void)showAlertViewWithTitle:(NSString*) title
                      message:(NSString*) message
                 cancelButton:(NSString*) cancelButton
                  otherButton:(NSString*) otherButton
                buttonClicked:(void(^)(NSString* buttonTitle, NSInteger buttonIndex))buttonClicked;
+ (NSIndexPath *)indexPathForCellContainingView:(UIView *)view inTableView:(UITableView *)tableView;
+ (NSString*)getGlobalStringForKey:(NSString*)strKey;
+ (float)getGlobalFloatForKey:(NSString*)strKey;

@end
