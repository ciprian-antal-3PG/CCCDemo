//
//  CCCPaymentNotification.h
//  CCCSDK
//
//  Created by Animax Deng on 3/15/17.
//  Copyright © 2017 CCC. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface CCCPaymentNotification : NSObject

+ (void)paymentReqeustWithSession:(NSString *)sessionToken
                       completion:(void (^) (bool, NSError *))completionHandler;

+ (void)paymentReqeustWithCompletion:(void (^) (bool, NSError *))completionHandler;

@end
