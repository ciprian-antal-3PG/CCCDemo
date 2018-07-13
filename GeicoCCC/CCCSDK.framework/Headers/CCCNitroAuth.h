//
//  CCCNitroAuth.h
//  CCCSDK
//
//  Created by Animax Deng on 8/7/17.
//  Copyright © 2017 CCC. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "CCCSDK_Global.h"


@interface CCCNitroAuth : NSObject <NSCoding, NSCopying>


/**
 *  Boolean representing whether the CCC User is logged in or not
 */
@property (nonatomic, readonly) BOOL isLoggedIn;

@property (nonatomic, strong, readonly) NSString *_Nullable sessionToken;
@property (nonatomic, strong, readonly) NSString *_Nullable signingKey;
@property (nonatomic, strong, readonly) NSString *_Nullable encrytionKey;

/**
 Fetch Identity token returns a identity token (Expires after 1 day)
 
 @param identity userId or appid or any unique id identifiying the user/app
 @param token    Carrier token
 @param block    Completed callback
 */
- (void)fetchIdentityToken:(NSString *_Nonnull)identity
              carrierToken:(NSString *_Nonnull)token
             completeBlock:(nullable void(^)(NSString * _Nullable identityToken, NSError * _Nullable error))block;

/**
 Fetch Identity token returns a identity token
 
 @param identity userId or appid or any unique id identifiying the user/app
 @param token    Carrier token
 @param ttl      Timeout time (mins)
 @param block    Completed callback
 */
- (void)fetchIdentityToken:(NSString *_Nonnull)identity
              carrierToken:(NSString *_Nonnull)token
                       ttl:(NSInteger)ttl
             completeBlock:(nullable void(^)(NSString * _Nullable identityToken, NSError * _Nullable error))block;

/**
 Fetch session token returns a session id (Expires after 30 mins)
 
 @param token    Identity token - returned from fetch identity token
 @param block    Completed callback block which returns session id
 */
- (void)beginSessionWithIdentityToken:(NSString *_Nonnull)token completeBlock:(nullable void(^)(NSString * _Nullable sessionId, NSError * _Nullable error))block;

/**
 Fetch session token returns a session id \\
 
 @param token    Identity token - returned from fetch identity token
 @param ttl      Timeout time (mins)
 @param block    Completed callback block which returns session id
 */
- (void)beginSessionWithIdentityToken:(NSString *_Nonnull)token ttl:(NSInteger)ttl completeBlock:(nullable void(^)(NSString * _Nullable sessionId, NSError * _Nullable error))block;


/**
 Fetch Session token from carrier token
 
 @param carrier     Carrier token
 @param identity    userId or appid or any unique id identifiying the user/app
 @param block       Completed callback block which returns session id
 */
- (void)fetchSeesionWithCarrier:(NSString *_Nonnull)carrier identity:(NSString *_Nonnull)identity completeBlock:(nullable void(^)(NSString * _Nullable sessionId, NSError * _Nullable error))block;

/**
 Fetch Session token from carrier token
 
 @param carrier     Carrier token
 @param identity    userId or appid or any unique id identifiying the user/app
 @param block       Completed callback block which returns session id
 */
- (void)fetchSeesionWithCarrier:(NSString *_Nonnull)carrier identity:(NSString *_Nonnull)identity ttl:(NSInteger)ttl completeBlock:(nullable void(^)(NSString * _Nullable sessionId, NSError * _Nullable error))block;

/**
 Refresh Session, A utility method which refreshes the session based previously provided identity token
 @param block Completed callback
 */
- (void)refreshSession:(void(^_Nullable)(NSString *_Nullable sessionId, NSError *_Nullable error))block;



@end
