//
//  CCCPhotoCaptureItem.h
//  CCCPhotoComponents
//
//  Created by Jerry Walton on 4/21/15.
//  Copyright (c) 2015 CCC. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

@interface CCCPhotoCaptureItem : NSObject
@property (nonatomic, strong) NSString *claimId;
@property (nonatomic, strong) NSString *photoTitle;
@property (nonatomic, strong) NSString *saveTitle;
@property (nonatomic, strong) UIImage *photo;
@property (nonatomic, strong) NSDate *imageCreatedDate;
@property (nonatomic, copy) NSString *imagePath;
@property (nonatomic, assign) double latitude;
@property (nonatomic, assign) double longitude;
@end
