//
//  PolicyType.h
//  CCCSDK
//
//  Created by Viggnesh Kandasamy on 2/20/17.
//  Copyright © 2017 CCC. All rights reserved.
//

#import "JSONModel.h"
#import "JSONModelLib.h"

typedef enum
{
    /**policyType_P – Personal*/
    policyType_P,
    /**policyType_C – Commercial*/
    policyType_C,
    /**policyType_None – None*/
    policyType_None
}PolicyTypeEnum;

@interface PolicyType : JSONModel
@property (assign, nonatomic) PolicyTypeEnum policyTypeEnum;
@property (strong, nonatomic, readonly) NSString *code;

@end
