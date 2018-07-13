//
//  VehicleLocationContact.h
//  CCCSDK
//
//  Created by Viggnesh Kandasamy on 10/19/16.
//  Copyright © 2016 CCC. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "Contact.h"
#import "JSONModelLib.h"

@interface VehicleLocationContact : JSONModel
@property(nonatomic, strong) Contact <Optional> *businessPhone;
@property(nonatomic, strong) Contact <Optional> *homePhone1;
@property(nonatomic, strong) Contact <Optional> *homePhone2;
@property(nonatomic, strong) Contact <Optional> *cellPhone;
@property(nonatomic, strong) Contact <Optional> *dayPhone;
@property(nonatomic, strong) Contact <Optional> *eveningPhone;
@property(nonatomic, strong) Contact <Optional> *homeFax;
@property(nonatomic, strong) Contact <Optional> *businessFax;
@property(nonatomic, strong) Contact <Optional> *otherPhoneNumber;
@property(nonatomic, strong) NSString <Optional> *email;
@property(nonatomic, strong) NSString <Optional> *url;


@end
