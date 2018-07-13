//
//  TransactionControlHeader.h
//  CCCSDK
//
//  Created by Viggnesh Kandasamy on 2/10/17.
//  Copyright © 2017 CCC. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "JSONModelLib.h"
#import "CCCID.h"
#import "EstimatingSystem.h"

@interface TransactionControlHeader : JSONModel

@property (strong, nonatomic) NSString *uniqueTransactionID;

@property (strong, nonatomic) NSString *primaryInsuranceCompanyID;

@property (strong, nonatomic) CCCID <Optional> *cccid;

@property (strong, nonatomic) NSString <Optional> *lossReferenceID;

@property (strong, nonatomic) NSNumber <Optional> *transactionDateTime;

@property (strong, nonatomic) EstimatingSystem <Optional> *estimatingSystem;

@property (strong, nonatomic) NSString <Optional> *echoField;

@property (strong, nonatomic) NSString <Optional> *cccactionCode;


@property (strong, nonatomic) NSString <Optional> *fileType;

@property (strong, nonatomic) NSString <Optional> *fileVersion;

@property (strong, nonatomic) NSString <Optional> *headerVersion;

@end
