//
//  ClaimPartyAddressType.h
//  CCCSDK
//
//  Created by Viggnesh Kandasamy on 2/16/17.
//  Copyright © 2017 CCC. All rights reserved.
//

#import "JSONModel.h"
typedef enum  {
    /**HM – Home*/
    ClaimPartyAddressType_HM,
    /**OF – Office*/
    ClaimPartyAddressType_OF,
    /**HO – Home Office*/
    ClaimPartyAddressType_HO,
    /**CO – Claim Office*/
    ClaimPartyAddressType_CO,
    /**MA – Mailing*/
    ClaimPartyAddressType_MA,
    /**OT – Other*/
    ClaimPartyAddressType_OT
}ClaimPartyAddressTypeEnum;

@interface ClaimPartyAddressType : JSONModel
@property (assign, nonatomic) ClaimPartyAddressTypeEnum claimPartyAddressTypeEnum;
@property (strong, nonatomic, readonly) NSString *code;

@end
