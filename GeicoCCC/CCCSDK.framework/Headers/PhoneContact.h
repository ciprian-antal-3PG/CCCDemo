//
//  PhoneContact.h
//  CCCSDK
//
//  Created by Viggnesh Kandasamy on 2/1/17.
//  Copyright © 2017 CCC. All rights reserved.
//

#import "JSONModel.h"
#import "JSONModelLib.h"

@interface PhoneContact : JSONModel

@property (strong, nonatomic) NSString <Optional> *countryCode;
@property (strong, nonatomic) NSString <Optional> *cityCode;
@property (strong, nonatomic) NSString <Optional> *areaCode;
@property (strong, nonatomic) NSString <Optional> *localNum;
@property (strong, nonatomic) NSString <Optional> *extn;

@end
