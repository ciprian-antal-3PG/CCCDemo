//
//  CCCUploadVideoUtil.h
//  VideoComponentDemo
//
//  Created by Sudhin on 03/08/17.
//  Copyright © 2017 POC. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "CCCUploadVideo.h"

@interface CCCUploadVideoUtil : NSObject
/// returns form data with additional parameters
+(NSMutableData*_Nullable)getFullFormDataWithVideo:(VideoModel*_Nullable)video
                                           claimID:(NSString*_Nullable)claimID;
/// Returns NSURLRequest with video upload settings.
+(NSMutableURLRequest*_Nullable)getVideoUplaodRequestWithURL:(NSURL*_Nullable)uploadURL
                                                   sessionID:(NSString*_Nullable)sessionID
                                                  dataLength:(float)dataLength;
+(NSString*_Nullable)getFileCreatedDateURL:(NSURL*_Nullable)url;
+ (void) showSimpleAlertWithTitle:(NSString*_Nullable)title message:(NSString*_Nullable)message;
@end
