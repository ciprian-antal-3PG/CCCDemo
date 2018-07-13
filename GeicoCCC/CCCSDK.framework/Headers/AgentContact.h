//
//  AgentContact.h
//  CCCSDK
//
//  Created by Viggnesh Kandasamy on 10/20/16.
//  Copyright © 2016 CCC. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "Contact.h"
#import "Address.h"
#import "JSONModelLib.h"
#import "PersonCompanyIndicator.h"
#import "StringClass.h"
@interface AgentContact : JSONModel

@property (strong, nonatomic) PersonCompanyIndicator <Optional> *personCompanyIndicator;
@property (strong, nonatomic) NSString <Optional> *companyName;
/** CompanyOfficeID - Identifies the company claim contact office ID. */
@property (strong, nonatomic) NSString <Optional> *companyOfficeID;
/** Identifies the company claim contact office type. */
@property (strong, nonatomic) NSString <Optional> *companyOfficeType;
@property (strong, nonatomic) NSString <Optional> *companyGovtId;
@property (strong, nonatomic) NSString <Optional> *companyFedTaxInfo;
@property (strong, nonatomic) NSString <Optional> *title;
@property (strong, nonatomic) NSString <Optional> *firstName;
@property (strong, nonatomic) NSString <Optional> *middleName;
@property (strong, nonatomic) NSString <Optional> *lastName;
@property (strong, nonatomic) NSString <Optional> *suffix;
@property (strong, nonatomic) NSString <Optional> *nickName;
@property (strong, nonatomic) NSString <Optional> *noah;
@property (strong, nonatomic) NSString <Optional> *salutation;
@property (strong, nonatomic) NSString <Optional> *verbalGreeting;
@property (strong, nonatomic) NSString <Optional> *writtenGreeting;
@property (strong, nonatomic) NSString <Optional> *driversLicenseNumber;
@property (strong, nonatomic) StringClass <Optional> *driverLicenseState;
@property (strong, nonatomic) NSNumber <Optional> *driversLicenseExpirationDate;

@property(strong, nonatomic) Contact <Optional> *contact;
@property(strong, nonatomic) Address <Optional> *address;



//- (instancetype) initWithPersonCompanyIndicator: (PersonCompanyIndicator *) personCompanyIndicatorTemp companyNameOrLastName : (NSString *) companyNameOrLastName;


@end

