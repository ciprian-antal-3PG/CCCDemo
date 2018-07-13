//
//  CCCEstimate.h
//  CCCSDK
//
//  Created by Animax Deng on 10/10/16.
//  Copyright © 2016 CCC. All rights reserved.
//

#import <Foundation/Foundation.h>


/**
 Fetch Esimate Service module
 */
@interface CCCPAEstimate : NSObject

@property (strong, nonatomic) NSDecimalNumber *totalRepairCost;
@property (nonatomic) BOOL completed;

/**
 Fetch Predicted estimate

 @param completionHandler Completed callback, return repair cost and the estimate if complted or not.
 */
+ (void) getPredictedEstimate:(void (^) (CCCPAEstimate *estimate, NSError *error))completionHandler;

@end
