//
//  CCCUrlSession.h
//  CCCSDK
//
//  Created by Animax Deng on 3/8/16.
//  Copyright © 2016 CCC. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface CCCUrlSession : NSObject

@property (strong, nonatomic) NSMutableURLRequest *request;
@property (weak, nonatomic, readonly) NSURLSessionTask *sessionTask;
@property (copy, nonatomic) void (^completitionBlock) (NSData *data, NSURLResponse *response, NSError *err);
@property (copy, nonatomic) void (^progessBlock) (float progress, NSInteger bytesTransferred, NSInteger totalBytes);

- (instancetype)initWithRequest:(NSURLRequest *)request;
- (instancetype)initWithRequest:(NSURLRequest *)request andCompletition:(void (^) (NSData *data, NSURLResponse *response, NSError *err))block;

- (void)start;
- (void)startUpload;
- (void)suspend;
- (void)cancel;

@end
