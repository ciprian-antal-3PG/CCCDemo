//
//  InjuryFlag.h
//  CCCSDK
//
//  Created by Viggnesh Kandasamy on 2/20/17.
//  Copyright © 2017 CCC. All rights reserved.
//

#import "JSONModel.h"
#import "JSONModelLib.h"

typedef enum  {
    /**injuryFlag_Y – YES*/
    injuryFlag_Y,
    /**injuryFlag_N – NO*/
    injuryFlag_N,
    /**injuryFlag_U – Unknown*/
    injuryFlag_U
}InjuryFlagEnum;

@interface InjuryFlag : JSONModel
    @property (assign, nonatomic) InjuryFlagEnum injuryFlagEnum;
    @property (strong, nonatomic, readonly) NSString *code;
@end
