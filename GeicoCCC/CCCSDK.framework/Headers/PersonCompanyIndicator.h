//
//  PersonCompanyIndicator.h
//  CCCSDK
//
//  Created by Viggnesh Kandasamy on 2/16/17.
//  Copyright © 2017 CCC. All rights reserved.
//

#import "JSONModel.h"
#import "JSONModelLib.h"

typedef enum  {
    personCompanyIndicator_P,
    personCompanyIndicator_C
} PersonCompanyIndicatorEnum;

@interface PersonCompanyIndicator : JSONModel

@property (assign, nonatomic) PersonCompanyIndicatorEnum personCompanyIndicatorEnum;
@property (strong, nonatomic, readonly) NSString *code;

@end
