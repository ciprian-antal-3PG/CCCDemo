//
//  CCCHeatMap.h
//  CCCSDK
//
//  Created by Animax Deng on 8/5/16.
//  Copyright © 2016 CCC. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

typedef enum : NSUInteger {
    HeatMapStatus_Done = 0,
    HeatMapStatus_Timeout,
    HeatMapStatus_Error,
} HeatMapStatus;


/**
 Fetch heatmap object model
 */
@interface CCCHeatMapImage : NSObject


/**
 Title of the image
 */
@property (strong, nonatomic) NSString * _Nullable imageTitle;

/**
 Name of the image
 */
@property (strong, nonatomic) NSString * _Nullable imageName;

/**
 Image it selfs
 */
@property (strong, nonatomic) UIImage * _Nullable image;

/**
 Direction of the heatmap image it wouble be front, rear
 */
@property (strong, nonatomic) NSString* _Nullable  direction;

/**
 Direction of the heatmap image it wouble be right, left
 */
@property (strong, nonatomic) NSString* _Nullable  side;

@end


/**
 Fetch heatmap module
 */
@interface CCCHeatMap : NSObject

/**
 Error message from API service if any error
 */
@property (strong, nonatomic) NSString* _Nullable  errorDescription;

/**
 Heatmap response status
 */
@property (nonatomic) HeatMapStatus status;


@property (strong, nonatomic) NSError* _Nullable errorObj;

/**
 All heatmap images
 */
@property (strong, nonatomic) NSArray<CCCHeatMapImage *> * _Nonnull heatMapImages;

/**
 Fetch Heatmap - returns a completionblock with image details
 
 @param completionHandler Completed callback
 */
+ (void)getHeatMap:(void (^_Nonnull) (CCCHeatMap * _Nonnull))completionHandler;

@end
