//
//  CCCPhotoEntity.h
//  CCCSDK
//
//  Created by Viggnesh Kandasamy on 5/12/16.
//  Copyright © 2016 CCC. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "CCCSDK_Global.h"

@interface CCCPhotoEntity : NSObject

/** 
 * @optional isTakenFromCamera = true, represents if if the photo is taken from users camera
 */
@property (nonatomic, assign) BOOL isTakenFromCamera;

/**
 * @required Represents the image path
 */
@property (nonatomic, copy) NSString * CCC_NONNULL_S imagePath;

/**
 * @required Represents the image position or angle
 */
@property (CCC_NULLABLE_PROPERTY nonatomic, copy) NSString *imagePosition;

/**
 * @optional Represents the image latitude
 *  eg. 64.12
 */
@property (CCC_NULLABLE_PROPERTY nonatomic, copy) NSString *imageLatitude;

/**
 * @optional Represents the image created date in UTC format
 *  eg. 2016-05-13T15:11Z
 */
@property (nonatomic, copy) NSString * CCC_NONNULL_S imageCreatedDate;


/**
 * @optional  Represents the image longitude
 *  eg. -82.99
 */
@property (CCC_NULLABLE_PROPERTY nonatomic, copy) NSString *imageLongitude;

/**
 * @optional Represents any additional description provided by user
 */
@property (CCC_NULLABLE_PROPERTY nonatomic, copy) NSString *additionalDescription;

/**
 * @optional Represents file name
 */
@property (nonatomic, copy) NSString * CCC_NONNULL_S fileName;

/**
 * @optional Represents file type
 * eg. png, jpeg ..etc
 */
@property (CCC_NULLABLE_PROPERTY nonatomic, copy) NSString *type;

/**
 * @optional Image display order
 * eg. 1, 2 ..etc
 */
@property (CCC_NULLABLE_PROPERTY nonatomic, copy) NSNumber *displayOrder;


- (CCC_NONNULL id) initWithImagePath : (CCC_NONNULL NSURL *) imagePath imagePosition : (CCC_NONNULL NSString *) imagePosition;


@end
