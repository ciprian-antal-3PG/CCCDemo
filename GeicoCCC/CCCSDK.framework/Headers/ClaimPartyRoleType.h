//
//  ClaimPartyRoleType.h
//  CCCSDK
//
//  Created by Viggnesh Kandasamy on 2/16/17.
//  Copyright © 2017 CCC. All rights reserved.
//

#import "JSONModel.h"
#import "JSONModelLib.h"

typedef enum  {
    /**Vehicle Owner – Insured*/
    ClaimPartyRoleType_VI,
    /**Vehicle Owner*/
    ClaimPartyRoleType_VO,
    /**IN – Vehicle Insured*/
    ClaimPartyRoleType_IN,
    /**CL – Claimant*/
    ClaimPartyRoleType_CL,
    /**DR – Driver*/
    ClaimPartyRoleType_DR,
    /**AT – Attorney*/
    ClaimPartyRoleType_AT,
    /**LH – Lien Holder*/
    ClaimPartyRoleType_LH,
    /**WI – Witness*/
    ClaimPartyRoleType_WI,
    /**OT – Other*/
    ClaimPartyRoleType_OT
    
}ClaimPartyRoleTypeEnum;

@interface ClaimPartyRoleType : JSONModel


@property (assign, nonatomic) ClaimPartyRoleTypeEnum claimPartyRoleTypeEnum;
@property (strong, nonatomic, readonly) NSString *code;

@end
