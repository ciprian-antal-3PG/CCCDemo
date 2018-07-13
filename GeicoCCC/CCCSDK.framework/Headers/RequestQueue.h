//
//  RequestQueue.h
//  CCCSDK
//
//  Created by Viggnesh K on 4/28/15.
//  Copyright (c) 2015 cccis. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "CCCOperation.h"


@interface RequestQueue : NSObject
@property (nonatomic) NSUInteger maxConcurrentRequestCount;
@property (nonatomic, getter = isSuspended) BOOL suspended;
@property (nonatomic, readonly) NSUInteger requestCount;
@property (nonatomic, copy, readonly) NSArray *requests;
@property (nonatomic) RequestQueueMode queueMode;
@property (nonatomic) BOOL allowDuplicateRequests;

+ (instancetype)mainQueue;

- (void)addOperation:(CCCOperation *)operation;
- (void)addRequest:(NSURLRequest *)request completionHandler:(CCCCompletionHandler)completionHandler;
- (void)cancelRequest:(NSURLRequest *)request;
- (void)cancelAllRequests;

@end
