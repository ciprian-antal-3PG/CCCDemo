//
//  CcclossCategory.h
//  CCCSDK
//
//  Created by Viggnesh Kandasamy on 2/16/17.
//  Copyright © 2017 CCC. All rights reserved.
//

#import "JSONModel.h"

typedef enum  {
    /**Collision*/
    CCCLossCategory_C,
    /**Comprehensive*/
    CCCLossCategory_M,
    /**Liability*/
    CCCLossCategory_L,
    /**Other*/
    CCCLossCategory_O
}CCClossCategoryEnum;

@interface CcclossCategory : JSONModel
/** CCCLossCategory ~ Type of Loss for RF and IA appraisal sources */
@property (assign, nonatomic) CCClossCategoryEnum ccclossCategoryEnum;
@property (strong, nonatomic, readonly) NSString *code;

@end
