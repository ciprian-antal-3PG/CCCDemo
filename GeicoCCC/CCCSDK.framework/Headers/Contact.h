//
//  Contact.h
//  CCCSDK
//
//  Created by Viggnesh Kandasamy on 10/18/16.
//  Copyright © 2016 CCC. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "JSONModelLib.h"
#import "PhoneContact.h"
#define PMKE(txt) [NSException exceptionWithName:@"invalidInit" reason:@"invalidInit: " txt userInfo:nil]

@interface Contact : JSONModel



@property (strong, nonatomic) PhoneContact <Optional> *businessPhone;
@property (strong, nonatomic) PhoneContact <Optional> *homePhone1;
@property (strong, nonatomic) PhoneContact <Optional> *homePhone2;
@property (strong, nonatomic) PhoneContact <Optional> *cellPhone;
@property (strong, nonatomic) PhoneContact <Optional> *dayPhone;
@property (strong, nonatomic) PhoneContact <Optional> *eveningPhone;
@property (strong, nonatomic) PhoneContact <Optional> *homeFax;
@property (strong, nonatomic) PhoneContact <Optional> *businessFax;
@property (strong, nonatomic) PhoneContact <Optional> *otherPhoneNumber;
@property (strong, nonatomic) NSString <Optional> *email;
@property (strong, nonatomic) NSString <Optional> *url;



@end
