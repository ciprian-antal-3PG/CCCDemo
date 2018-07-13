//
//  CCCOperation.h
//  CCCSDK
//
//  Created by Viggnesh K on 4/28/15.
//  Copyright (c) 2015 cccis. All rights reserved.
//

#import <Foundation/Foundation.h>

extern NSString *const HTTPResponseErrorDomain;

typedef void (^CCCCompletionHandler)(NSString* fieldName,NSURLResponse *response, NSData *data, NSError *error);
typedef void (^CCCProgressHandler)(float progress, NSInteger bytesTransferred, NSInteger totalBytes);
typedef void (^CCCAuthenticationChallengeHandler)(NSURLAuthenticationChallenge *challenge);

typedef enum
{
    RequestQueueModeFirstInFirstOut = 0,
    RequestQueueModeLastInFirstOut
}
RequestQueueMode;

@interface CCCOperation : NSOperation


@property (nonatomic, copy) NSString *fieldName;

@property (nonatomic, readonly) NSURLRequest *request;
@property (nonatomic, copy) CCCCompletionHandler completionHandler;
@property (nonatomic, copy) CCCProgressHandler uploadProgressHandler;
@property (nonatomic, copy) CCCProgressHandler downloadProgressHandler;
@property (nonatomic, copy) CCCAuthenticationChallengeHandler authenticationChallengeHandler;
@property (nonatomic, copy) NSSet *autoRetryErrorCodes;
@property (nonatomic) NSTimeInterval autoRetryDelay;
@property (nonatomic) BOOL autoRetry;

+ (instancetype)operationWithRequest:(NSURLRequest *)request;
- (instancetype)initWithRequest:(NSURLRequest *)request;

@end
