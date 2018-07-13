//
//  Address.h
//  CCCSDK
//
//  Created by Viggnesh Kandasamy on 10/18/16.
//  Copyright © 2016 CCC. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "Zip.h"
#import "JSONModelLib.h"
#import "StringClass.h"
@interface Address : JSONModel

@property (strong, nonatomic) NSString <Optional> *address1;
@property (strong, nonatomic) NSString <Optional> *address2;
@property (strong, nonatomic) NSString <Optional> *addressName;
@property (strong, nonatomic) NSString <Optional> *city;
@property (strong, nonatomic) NSString <Optional> *county;
@property (strong, nonatomic) StringClass <Optional> *stateCode;
@property(strong, nonatomic) Zip <Optional> *zip;
@property (strong, nonatomic) NSString <Optional> *country;


@end
