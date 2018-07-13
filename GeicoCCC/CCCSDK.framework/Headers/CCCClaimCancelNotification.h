//
//  CCCClaimCancelNotification.h
//  CCCSDK
//
//  Created by Animax Deng on 3/15/17.
//  Copyright © 2017 CCC. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface CCCClaimCancelNotification : NSObject

+ (void)calaimCancelWithSession:(NSString *)sessionToken completion:(void (^) (bool, NSError *))completionHandler;
+ (void)calaimCancel:(void (^) (bool, NSError *))completionHandler;

@end
