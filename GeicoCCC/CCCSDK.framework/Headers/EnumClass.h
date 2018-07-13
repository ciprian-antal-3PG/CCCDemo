//
//  EnumClass.h
//  CCCSDK
//
//  Created by Viggnesh Kandasamy on 2/20/17.
//  Copyright © 2017 CCC. All rights reserved.
//

#import "JSONModel.h"
#import "JSONModelLib.h"

typedef enum 
{
    /**agentType_C – Captive*/
    agentType_C,
    /**agentType_I – Independent*/
    policyType_I
}AgentTypeEnum;

typedef enum {
    /**Collision*/
    CustomerLossTypeCode_C,
    /**Comprehensive*/
    CustomerLossTypeCode_M,
    /**Liability*/
    CustomerLossTypeCode_L,
    /**Other*/
    CustomerLossTypeCode_O
}CustomerLossTypeCodeEnum;

typedef enum
{
    OkToPayFlag_Y,
    OkToPayFlag_N,
    OkToPayFlag_U
}OkToPayFlagEnum;

typedef enum  {
    /**YES*/
    ActiveScheduleIndicator_Y,
    /**NO*/
    ActiveScheduleIndicator_N,
}ActiveScheduleIndicatorEnum;

typedef enum
{
    AssignmentActionCodeEnum_V,
    AssignmentActionCodeEnum_N,
    AssignmentActionCodeEnum_C,
    AssignmentActionCodeEnum_S
}AssignmentActionCodeEnum;

@interface EnumClass : JSONModel
@property(assign, nonatomic) AgentTypeEnum  agentTypeEnum;
//@property (assign, nonatomic) CustomerLossTypeCodeEnum customerLossTypeCodeEnum;
@property (assign, nonatomic) OkToPayFlagEnum okToPayFlagEnum;
@property (assign, nonatomic) AssignmentActionCodeEnum assignmentActionCodeEnum;

/**ActiveSheduleIndicator - YES/NO*/
@property (assign, nonatomic) ActiveScheduleIndicatorEnum activeScheduleIndicatorEnum;

@property (strong, nonatomic, readonly) NSString *code;

@end
