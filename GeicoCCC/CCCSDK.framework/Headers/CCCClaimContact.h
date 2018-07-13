//
//  CCCClaimContact.h
//  CCCSDK
//
//  Created by Sudhin on 08/01/18.
//  Copyright © 2018 CCC. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "CCCSDK_Global.h"
#import "JSONModelLib.h"

@interface CCCContactInfo : JSONModel
@property (strong, nonatomic) NSString <Optional> * _Nonnull custClmRefID;
@property (strong, nonatomic) NSString <Optional> * _Nonnull userType;
@property (strong, nonatomic) NSString <Optional> * _Nonnull recipientName;
@property (strong, nonatomic) NSString <Optional> * _Nonnull recipientEmailAddress;
@property (strong, nonatomic) NSString <Optional> * _Nonnull recipientPhone;
@end

@interface CCCClaimContact : JSONModel

/**
 Asyncronously fetches Adjuster Info associated with current Session ID

 @param block     completionBlock A block object to be executed when the task finishes successfully. The block returns Contact Info Model and NSError object.

 @see http://mobilesdk.cccis.com/documentation/
 */
+ (void) fetchClaimContactCompletionBlock:(CCC_NULLABLE CCCContactInfoBlock)block;

/**
 Asyncronously fetches Contact Info Model for a specific claim

 @param sessionID sessionID
 @param block     completionBlock A block object to be executed when the task finishes successfully. The block returns Contact Info Model and NSError object.

 @see http://mobilesdk.cccis.com/documentation/
 */
+ (void) fetchClaimContactWithSessionID :(CCC_NONNULL NSString *) sessionID completionBlock:(CCC_NULLABLE CCCContactInfoBlock)block;

@end
