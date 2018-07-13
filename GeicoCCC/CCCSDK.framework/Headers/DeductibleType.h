//
//  DeductibleType.h
//  CCCSDK
//
//  Created by Viggnesh Kandasamy on 2/20/17.
//  Copyright © 2017 CCC. All rights reserved.
//

#import "JSONModel.h"
#import "JSONModelLib.h"



typedef enum
{
    /**deductibleType_A - Amount*/
    deductibleType_A,
    /**deductibleType_V - Actual Cash Value*/
    deductibleType_V,
    /**deductibleType_P - Percent*/
    deductibleType_P
}DeductibleTypeEnum;

@interface DeductibleType : JSONModel
@property (assign, nonatomic) DeductibleTypeEnum deductibleTypeEnum;
@property (strong, nonatomic, readonly) NSString *code;

@end
