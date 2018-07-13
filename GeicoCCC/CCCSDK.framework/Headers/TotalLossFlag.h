//
//  TotalLossFlag.h
//  CCCSDK
//
//  Created by Viggnesh Kandasamy on 2/16/17.
//  Copyright © 2017 CCC. All rights reserved.
//

#import "JSONModel.h"
#import "JSONModelLib.h"

typedef enum
{
    TotalLossFlag_Y,
    TotalLossFlag_N,
    TotalLossFlag_U
}TotalLossFlagEnum;

@interface TotalLossFlag : JSONModel
@property(assign, nonatomic) TotalLossFlagEnum totalLossFlagEnum;
@property (strong, nonatomic, readonly) NSString *code;

@end
