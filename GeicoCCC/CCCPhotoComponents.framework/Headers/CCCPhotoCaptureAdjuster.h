//
//  CCCPhotoCaptureAdjusterInfo.h
//  CCCPhotoComponents
//
//  Created by bkongara on 1/15/18.
//  Copyright © 2018 CCC Information Services. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface CCCPhotoCaptureAdjuster : NSObject

@property (strong, nonatomic) NSString  * _Nonnull custClmRefID;
@property (strong, nonatomic) NSString  * _Nonnull userType;
@property (strong, nonatomic) NSString  * _Nonnull recipientName;
@property (strong, nonatomic) NSString  * _Nonnull recipientEmailAddress;
@property (strong, nonatomic) NSString  * _Nonnull recipientPhone;

@end
