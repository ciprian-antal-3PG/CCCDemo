//
//  CCCShopSelection.h
//  CCCSDK
//
//  Created by Animax Deng on 3/15/17.
//  Copyright © 2017 CCC. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface CCCShopSelection : NSObject

+ (void)selectShopWithSession:(NSString *)sessionToken
                appraiserType:(NSString *)appraiserType
               relationshipId:(NSString *)relationshipId
                  appraiserId:(NSString *)appraiserId
                   completion:(void (^) (bool, NSError *))completionHandler;

+ (void)selectShop:(NSString *)appraiserType
    relationshipId:(NSString *)relationshipId
       appraiserId:(NSString *)appraiserId
        completion:(void (^) (bool, NSError *))completionHandler;


+ (void)selectSmartSearchShopWithSession:(NSString *)sessionToken
                appraiserType:(NSString *)appraiserType
                           appraiserCode:(NSString *)appraiserCode
                            newtworkType:(NSString *) networkType
                   completion:(void (^) (bool, NSError *))completionHandler;

+ (void)selectSmartSearchShop:(NSString *)appraiserType
                appraiserCode:(NSString *)appraiserCode
                 newtworkType:(NSString *) networkType
        completion:(void (^) (bool, NSError *))completionHandler;

+ (void)deSelectSmartSearchShopSession:(NSString *)sessionToken
                         appraiserType:(NSString *)appraiserType
                         appraiserCode:(NSString *)appraiserCode
                          newtworkType:(NSString *) networkType
                            completion:(void (^) (bool, NSError *))completionHandler;
+ (void)deSelectSmartSearchShop:(NSString *)appraiserType
                  appraiserCode:(NSString *)appraiserCode
                   newtworkType:(NSString *) networkType
                     completion:(void (^) (bool, NSError *))completionHandler;

@end
