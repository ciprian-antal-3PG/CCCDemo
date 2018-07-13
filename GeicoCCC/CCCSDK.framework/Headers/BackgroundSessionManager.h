//
//  BackgroundSessionManager.h
//  VideoComponentDemo
//
//  Created by Sudhin on 02/08/17.
//  Copyright © 2017 POC. All rights reserved.
//

#import "AFHTTPSessionManager.h"

@interface BackgroundSessionManager : AFHTTPSessionManager
+ (instancetype)sharedManager;
@property (nonatomic, copy) void (^savedCompletionHandler)(void);
@end
