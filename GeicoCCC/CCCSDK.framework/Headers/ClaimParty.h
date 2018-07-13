//
//  ClaimParty.h
//  CCCSDK
//
//  Created by Viggnesh Kandasamy on 10/19/16.
//  Copyright © 2016 CCC. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "ClaimPartyContact.h"
#import "JSONModelLib.h"
#import "ClaimPartyRoleType.h"
#import "ClaimPartyInjured.h"
#import "ClaimPartyAddressType.h"



@protocol ClaimParty;

@interface ClaimParty : JSONModel

@property (strong, nonatomic) ClaimPartyAddressType <Optional> *claimPartyAddressType;

@property (strong, nonatomic) ClaimPartyRoleType <Optional> *claimPartyRoleType;

@property (strong, nonatomic) ClaimPartyInjured <Optional> *claimPartyInjured;

@property (strong, nonatomic) ClaimPartyContact <Optional> *claimPartyContact;

@property (strong, nonatomic) NSString <Optional> *accidentStatement;

- (id) initWithClaimPartyRoleType: (ClaimPartyRoleType *) claimPartyRoleType ClaimPartyContact : (ClaimPartyContact *) claimPartyContact;
@end
