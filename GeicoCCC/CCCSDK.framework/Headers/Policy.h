//
//  Policy.h
//  CCCSDK
//
//  Created by Viggnesh Kandasamy on 10/20/16.
//  Copyright © 2016 CCC. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "Agent.h"
#import "JSONModelLib.h"
#import "PolicyType.h"
#import "BookofBusiness.h"
#import "DeductibleType.h"
#import "StringClass.h"


@interface Policy : JSONModel
@property (strong, nonatomic) NSString <Optional> * _Nullable policyNumber;
@property (strong, nonatomic) NSString <Optional> * _Nullable policyNumberExt;
@property (strong, nonatomic) PolicyType <Optional> * _Nullable policyType;
@property (strong, nonatomic) BookofBusiness <Optional> * _Nullable bookofBusiness;
@property (strong, nonatomic) DeductibleType <Optional> * _Nullable deductibleType;

@property (strong, nonatomic) NSNumber <Optional> * _Nullable deductible;
@property (strong, nonatomic) NSString <Optional> * _Nullable policyCoverageIndicator;

@property (strong, nonatomic) StringClass <Optional> * _Nullable naiclineofBusiness;
@property (strong, nonatomic) NSNumber <Optional> * _Nullable policyStartDate;
@property (strong, nonatomic) NSNumber <Optional> * _Nullable policyExpirationDate;
@property (strong, nonatomic) Agent <Optional> * _Nullable agent;
@property (strong, nonatomic) NSString <Optional> * _Nullable underwritingCompany;
@property (strong, nonatomic) NSString <Optional> * _Nullable policyNote;
@property (strong, nonatomic) NSString <Optional> * _Nullable endorsementNote;

@end
