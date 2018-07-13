//
//  PhotosModel.h
//  TestApp
//
//  Created by Jerry Walton on 5/11/15.
//  Copyright (c) 2015 CCC. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

#import "CCCPhotoCapture_Global.h"

@class CCCPhotoCaptureEntity;

typedef enum : NSUInteger {
    SafecoEventImagesUploaded = 0,
    SafecoEventImagesReSubmitted = 3,
    SafecoEventMailingAddressSaved = 5,
    SafecoEventEstimateReceived = 2,
    SafecoEventContact = 4
} SafecoEventCode;

@interface PhotoModel : NSObject {
    
}


@property (nonatomic, strong) NSString *title;
@property (nonatomic, strong) NSString *saveTitle;
@property (nonatomic, assign) BOOL isPhotoTaken;
@property (nonatomic, assign) BOOL isAdditionalPhotoItem;
@property (nonatomic, strong) UIImage  *photo;
@property (nonatomic, strong) NSString *photoPath;
@property (nonatomic, strong) NSString *overlayImageName;
@property (nonatomic, strong) NSBundle *bundle;

@end

@interface PhotosModel : NSObject

/**
 *  return array of default thumbnail items
 */
+ (NSArray<CCCPhotoCaptureEntity *>*) defaultCCCPhotoCaptureEntitis;

/**
 *  return an dictionary of PhotoModel objects for each photo taken
 */
+ (NSDictionary<NSString *, PhotoModel *> *) photoModelsWithClaimId:(NSString*)claimId thumbnailPreviewItems:(NSArray*)thumbnailPreviewItems;

/**
 *  return photos
 */
+ (NSArray *) allPhotoItemsArrayWithClaimId:(NSString *)claimId;
+ (NSArray<CCCPhotoCaptureEntity *>*) additionalPhotoModelsWithClaimId:(NSString*)claimId;
+ (NSDictionary<NSString *, PhotoModel *> *) allPhotoModelsWithClaimId:(NSString*)claimId thumbnailPreviewItems:(NSArray*)thumbnailPreviewItems;

+ (NSString*) currentClaimId;

+ (NSString*) additionalPhotoTitleWithNumber:(NSInteger)number;

+ (NSString*) photoPathWithClaimId:(NSString*)claimId title:(NSString*)title;
+ (NSArray*) getAdditionalPhotoModelsWithClaimId:(NSString*)claimId;

 +(NSString*) additionalPhotoOverlayTitleWithNumber:(NSInteger)number;
+(NSString*) additionalPhotoSavenameWithNumber:(NSInteger)number;

@end
