//
//  PreviousEstimate.h
//  CCCSDK
//
//  Created by Viggnesh Kandasamy on 1/30/17.
//  Copyright © 2017 CCC. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "JSONModelLib.h"

typedef enum PreviousEstimatePaid{
    /**YES*/
    PreviousEstimatePaid_Y,
    /**NO*/
    PreviousEstimatePaid_N,
}PreviousEstimatePaid;


typedef enum PreviousEstimateExists{
    /**YES*/
    PreviousEstimateExists_Y,
    /**NO*/
    PreviousEstimateExists_N,
}PreviousEstimateExists;

@interface PreviousEstimate : JSONModel
@property (assign, nonatomic) PreviousEstimatePaid previousEstimateExistsEnum;
@property (assign, nonatomic) PreviousEstimatePaid previousEstimatePaidEnum;

@property (strong, nonatomic, readonly) NSString *previousEstimateExists;
@property (strong, nonatomic, readonly) NSString *previousEstimatePaid;

@end
