//
//  CCCAuth.h
//  CCCSDK
//
//  Created by Viggnesh K on 4/14/15.
//  Copyright (c) 2015 cccis. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "CCCSDK_Global.h"

/**
 The Authentication Service allows the user to be authenticated using Claim ID and Last Name. In order to use other services
 mentioned below authentication is mandatory.
 
 Note
 <ul>
    <li>This service can be used only after the claim is created</li>
    <li>A Session ID is created after successful claim authentication, and this is used by the other services described below.</li>
 </ul>
 
 */
@interface CCCAuth : NSObject <NSCoding, NSCopying>

@property (nonatomic, strong, readonly) NSString *_Nullable userId;
@property (nonatomic, strong, readonly) NSString *_Nullable sessionToken;



/**
 SDK Login

 @param claimId claimId
 @param lastName lastName
 @param block completed block
 */
- (void)SDKLoginWithClaimID:(NSString *_Nonnull)claimId
                   lastName:(NSString *_Nonnull)lastName
              completeBlock:(nullable void(^)(NSString * _Nullable sessionId, NSError * _Nullable error))block;

/**
 SDK Login
 
 @param token token
 @param phoneNumber phoneNumber
 @param block completed block
 */
- (void)SDKLoginWithToken:(NSString *_Nonnull)token
                    phone:(NSString *_Nonnull)phoneNumber
              completeBlock:(nullable void(^)(NSString * _Nullable sessionId, NSError * _Nullable error))block;


/**
 Syncronously performs user validation.
 
 The service will check if the provided Claim ID and Last Name match backend claim records. If they do, then the user is
 validated as owning the referenced claim. Otherwise, an authentication error message will be returned on authentication
 attempt.
 
 @param claimID Represents the Claim ID
 @param lastName Represents the user's Last Name
 @param block block has no return value and takes two arguments: a CCCAuth response object and an NSError object. Note: This parameter cannot be nil, because this is used to retrieve response data.
 
 @see http://mobilesdk.cccis.com/documentation/
 
 */
+ (void) validateWithClaimID:(CCC_NULLABLE NSString *)claimID lastName:(CCC_NULLABLE NSString *)lastName block:(CCC_NONNULL CCCUserResultBlock)block;

/**
 Syncronously performs user validation.
 
 The service will check if the provided Claim ID and Last Name match backend claim records. If they do, then the user is
 validated as owning the referenced claim. Otherwise, an authentication error message will be returned on authentication
 attempt.
 
 @param Token Represents the Access Token
 @param Phonenumber Represents the user's phone number
 @param block block has no return value and takes two arguments: a CCCAuth response object and an NSError object. Note: This parameter cannot be nil, because this is used to retrieve response data.
 
 @see http://mobilesdk.cccis.com/documentation/
 
 */
+ (void) validateWithToken:(CCC_NULLABLE NSString *)token phoneNumber:(CCC_NULLABLE NSString *)phoneNumber block:(CCC_NONNULL CCCUserResultBlock)block;

/**
 Asyncronously peforms user validation.
 
 The service will check if the provided Claim ID and Last Name match backend claim records. If they do, then the user is
 validated as owning the referenced claim. Otherwise, an authentication error message will be returned on authentication
 attempt.
 
 @param claimID Represents the Claim ID
 @param lastName Represents the user's Last Name
 @param block block has no return value and takes two arguments: a CCCAuth response object and an NSError object. Note: This parameter cannot be nil, because this is used to retrieve response data.
 
 @see http://mobilesdk.cccis.com/documentation/
 
 */
+(void)validateInBackgroundWithClaimID:(CCC_NULLABLE NSString *)claimID lastName:(CCC_NULLABLE NSString *)lastName block:(CCC_NONNULL CCCUserResultBlock)block;

@end
