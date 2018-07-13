//
//  CCCPhotoCaptureEntity.h
//  CCCPhotoComponents
//
//  Created by Jerry Walton on 4/21/15.
//  Copyright (c) 2015 CCC. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface CCCPhotoCaptureEntity : NSObject

@property (nonatomic, strong) NSString *title;
@property (nonatomic, strong) NSString *saveTitle;
@property (nonatomic, strong) UIImage *thumbnailImage;

@property (nonatomic, strong) NSString *overlayHeader;
@property (nonatomic, strong) NSString *overlayTitle;
@property (nonatomic, strong) NSString *overlayDesc;
@property (nonatomic, strong) UIImage *overlayImage;
@property (nonatomic, strong) NSArray *animationOverlayImages;
@property (nonatomic, strong) UIImage *cameraOverlayImage;


@property (nonatomic, assign) BOOL autoDisplayFirstTime;
@property (nonatomic, assign) BOOL hasBeenDisplayed;


- (BOOL) isValidModel;

+ (NSArray<CCCPhotoCaptureEntity *> *)makeDefaultItems ;

+ (CCCPhotoCaptureEntity *)createWithTitle:(NSString *)title
                                   thumbnail:(UIImage *)thumbnail
                               overlayHeader:(NSString *)header
                                overlayTitle:(NSString *)title
                                 overlayDesc:(NSString *)desc
                                overlayImage:(UIImage *)image
                          cameraOverlayIamge: (UIImage *) cameraOverlayImage
                          overlayAutoDisplay:(BOOL)display  saveTitle:(NSString *)saveTitle;

+ (CCCPhotoCaptureEntity *)createWithTitle:(NSString *)title
                                   thumbnail:(UIImage *)thumbnail
                               overlayHeader:(NSString *)header
                                overlayTitle:(NSString *)overlaytitle
                                 overlayDesc:(NSString *)desc
                                overlayImage:(UIImage *)image
                        cameraOverlayIamge: (UIImage *) cameraOverlayImage saveTitle:(NSString *)saveTitle;

+ (CCCPhotoCaptureEntity *)createWithTitle:(NSString *)title
                               overlayHeader:(NSString *)header
                                overlayTitle:(NSString *)overlaytitle
                                 overlayDesc:(NSString *)desc
                          overlayAutoDisplay:(BOOL)display saveTitle:(NSString *)saveTitle;

+ (CCCPhotoCaptureEntity *)createWithTitle:(NSString *)title
                                  bundleName:(NSString *)bundle
                               thumbnailName:(NSString *)thumbnail
                               overlayHeader:(NSString *)header
                                overlayTitle:(NSString *)overlaytitle
                                 overlayDesc:(NSString *)desc
                            overlayImageName:(NSString *)image
                        cameraOverlayIamge: (UIImage *) cameraOverlayImage
                          overlayAutoDisplay:(BOOL)display saveTitle:(NSString *)saveTitle;

- (CCCPhotoCaptureEntity *)setThumbnailWithName:(NSString *)name
                                      bunldeName:(NSString *)bundle;
- (CCCPhotoCaptureEntity *)setThumbnailWithPath:(NSString *)path;

- (CCCPhotoCaptureEntity *)setOverlayWithName:(NSString *)name
                                     bunldeName:(NSString *)bundle;
- (CCCPhotoCaptureEntity *)setOverlayWithPath:(NSString *)path;

@end

