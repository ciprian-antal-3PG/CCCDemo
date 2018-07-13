//
//  CCCQEHeatMap.h
//  CCCSDK
//
//  Created by Animax Deng on 11/27/17.
//  Copyright © 2017 CCC. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

@interface CCCQEHeatMapImage : NSObject

@property (strong, nonatomic) NSString * _Nullable label;
@property (strong, nonatomic) NSString * _Nullable filename;
@property (strong, nonatomic) NSString * _Nullable imageDescription;
@property (strong, nonatomic) NSString * _Nullable createDate;
@property (strong, nonatomic) UIImage  * _Nullable image;

@end

@interface CCCQEHeatMap : NSObject

+ (void) fetchHeatmapWithCompletion:(void (^_Nonnull) (NSArray<CCCQEHeatMapImage *> * _Nullable heatmaps, NSError * _Nullable error))completionHandler;
+ (void) fetchHeatmap:(NSString * _Nonnull)authorization completion:(void (^_Nonnull) (NSArray<CCCQEHeatMapImage *> * _Nullable heatmaps, NSError * _Nullable error))completionHandler;

@end
