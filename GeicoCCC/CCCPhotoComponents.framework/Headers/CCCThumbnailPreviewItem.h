//
//  CCCThumbnailPreviewItem.h
//  CCCPhotoComponents
//
//  Created by Jerry Walton on 4/21/15.
//  Copyright (c) 2015 CCC. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface CCCThumbnailPreviewItem : NSObject
@property (nonatomic, strong) NSString *title;
@property (nonatomic, strong) NSString *displayTitle;
@property (nonatomic, strong) UIImage *thumbnailImage;
@property (nonatomic, strong) NSString *thumbnailImageName;
@property (nonatomic, strong) NSString *thumbnailImagePath;
@property (nonatomic, strong) NSString *overlayImageName;
@property (nonatomic, strong) NSString *overlayImagePath;
@property (nonatomic, strong) NSString *overlayHeader;
@property (nonatomic, strong) NSString *overlayTitle;
@property (nonatomic, strong) NSString *overlayDesc;
@end
