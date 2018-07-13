//
//  Loss.h
//  CCCSDK
//
//  Created by Viggnesh Kandasamy on 10/20/16.
//  Copyright © 2016 CCC. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "Address.h"
#import "JSONModelLib.h"
#import "InjuryFlag.h"
#import "TheftFlag.h"


@interface Loss : JSONModel
@property (strong, nonatomic) InjuryFlag <Optional> *injuryFlag;
@property (strong, nonatomic) TheftFlag <Optional> *theftFlag;
@property (strong, nonatomic) NSString <Optional> *lossMemoText;
@property (strong, nonatomic) NSNumber <Optional> *lossDateTime;
@property (strong, nonatomic) NSNumber <Optional> *lossReportedDateTime;
@property (strong, nonatomic) NSString <Optional> *catastropheCode;
@property (strong, nonatomic) Address <Optional> *lossLocation;

@end
