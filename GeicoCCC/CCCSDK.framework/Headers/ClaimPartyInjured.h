//
//  ClaimPartyInjured.h
//  CCCSDK
//
//  Created by Viggnesh Kandasamy on 2/20/17.
//  Copyright © 2017 CCC. All rights reserved.
//

#import "JSONModel.h"
#import "JSONModelLib.h"

typedef enum  {
    /**ClaimPartyInjuredEnum_Y – YES*/
    ClaimPartyInjuredEnum_Y,
    /**ClaimPartyInjuredEnum_N – NO*/
    ClaimPartyInjuredEnum_N,
    /**ClaimPartyInjuredEnum_U – Unknown*/
    ClaimPartyInjuredEnum_U
}ClaimPartyInjuredEnum;

@interface ClaimPartyInjured : JSONModel

@property (assign, nonatomic) ClaimPartyInjuredEnum claimPartyInjuredEnum;
@property (strong, nonatomic, readonly) NSString *code;


@end
