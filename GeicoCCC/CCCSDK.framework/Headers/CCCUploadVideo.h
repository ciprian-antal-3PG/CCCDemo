//
//  CCCVideoUploadManager.h
//  CCCVideoComponents
//
//  Created by Sudhin on 04/07/17.
//  Copyright © 2017 CCC. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface VideoModel : NSObject{

}
/// The file URL of the video
@property (nonatomic, strong) NSURL  * _Nullable videoURL;
/// The Latitude of the device
@property double videoLatitude;
/// The Longitude of the device
@property double videoLongitude;
/// The Name of the video
@property (nonatomic, strong) NSString * _Nullable videoName;
/// The Created of the Video
@property (nonatomic, strong) NSString * _Nullable videoCreatedDate;
/// The video type
@property (nonatomic, strong) NSString * _Nullable videoType;
/// Uplaoded State
@property BOOL isUploaded;

/// Returns a video model with given parameters
+(VideoModel*_Nullable)createVideoModelName:(NSString*_Nullable)videoName
                                   videoURL:(NSURL*_Nullable)videoURL
                              videoLatitude:(double)videoLatitude
                             videoLongitude:(double)videoLongitude
                           videoCreatedDate:(NSString *_Nullable)videoCreatedDate
                                  videoType:(NSString*_Nullable)videoType
                                 isUploaded:(BOOL)isUploaded;
@end

@interface CCCUploadVideo : NSObject <NSURLSessionDelegate>
/// Upload the given video model with additional parameters. This method is meant for foreground and background app states. The Internet connection failiures will not be notified to user, instead the upload will resume on next cnnectivity.
+(void)backgroundUploadVideoItem:(VideoModel*_Nullable)video
                        claimID:(NSString*_Nullable)claimID
                      sessionId:(NSString*_Nullable)sessionId
                       didStart:(nullable void (^)(BOOL started))didStart
                       progress:(nullable void (^)(NSProgress * _Nonnull uploadProgress))progress
                        success:(void (^_Nullable)(id _Nullable responseObject))success
                        failure:(void (^_Nullable)(NSError * _Nullable error))failure;
/// Upload the given video model with additional parameters. This method is only meant for foreground state unless background task is enabled in the application..
+(void)uploadVideoItem:(VideoModel*_Nullable)video
               claimID:(NSString*_Nullable)claimID
             sessionId:(NSString*_Nullable)sessionId
              didStart:(nullable void (^)(BOOL started))didStart
              progress:(nullable void (^)(NSProgress * _Nonnull uploadProgress))progress
               success:(void (^_Nullable)(id _Nullable responseObject))success
               failure:(void (^_Nullable)(NSError * _Nullable error))failure;
@end
