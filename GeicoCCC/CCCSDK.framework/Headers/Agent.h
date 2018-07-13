//
//  Agent.h
//  CCCSDK
//
//  Created by Viggnesh Kandasamy on 10/20/16.
//  Copyright © 2016 CCC. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "AgentContact.h"
#import "EnumClass.h"
#import "StringClass.h"
@interface Agent : JSONModel
@property(strong, nonatomic) NSString <Optional> *agentIdentifier;
@property(strong, nonatomic) EnumClass <Optional> *agentType;
@property(strong, nonatomic) NSString <Optional> *agentLicenseNumber;
@property(strong, nonatomic) AgentContact <Optional> *agentContact;

@property(strong, nonatomic) NSString <Optional> *underwritingCompany;
@property(strong, nonatomic) NSString <Optional> *policyNote;
@property(strong, nonatomic) NSString <Optional> *endorsementNote;
@property(strong, nonatomic) StringClass <Optional> *naiclineofBusiness;


@end
