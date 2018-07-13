//
//  AdjusterContact.h
//  CCCSDK
//
//  Created by Viggnesh Kandasamy on 10/18/16.
//  Copyright © 2016 CCC. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "Contact.h"
#import "Address.h"
#import "JSONModelLib.h"
#import "PersonCompanyIndicator.h"
#import "DriverLicenseState.h"
@interface AdjusterContact : JSONModel

@property (strong, nonatomic) PersonCompanyIndicator <Optional>* personCompanyIndicator;
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
@property (strong, nonatomic) NSString <Optional> *salutation;
@property (strong, nonatomic) NSString <Optional> *verbalGreeting;
@property (strong, nonatomic) NSString <Optional> *writtenGreeting;
@property (strong, nonatomic) NSString <Optional> *driversLicenseNumber;
@property (strong, nonatomic) DriverLicenseState <Optional> *driverLicenseState;
@property (strong, nonatomic) NSNumber <Optional> *driversLicenseExpirationDate;

@property (strong, nonatomic) Contact <Optional> *contact;


@property(strong, nonatomic) Address <Optional> *address;

@property (strong, nonatomic) NSString <Optional> *adjusterContactEmail;
@property (strong, nonatomic) NSString <Optional> *adjusterContactUrl;

@property (strong, nonatomic) NSString <Optional> *claimNotes;
@property (strong, nonatomic) NSString <Optional> *cesLossTypeCode;
@property (strong, nonatomic) NSString <Optional> *cesLossTypeDescription;

//- (instancetype) initWithPersonCompanyIndicator: (PersonCompanyIndicator *) personCompanyIndicatorTemp companyNameOrLastName : (NSString *) companyNameOrLastName;



@end
