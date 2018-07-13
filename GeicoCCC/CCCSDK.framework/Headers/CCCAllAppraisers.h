//
//  CCCAllAppraisers.h
//  CCCSDK
//
//  Created by Viggnesh Kandasamy on 6/6/17.
//  Copyright © 2017 CCC. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "JSONModelLib.h"
#import "CCCAppraiserType.h"
#import "CCCShopSearch.h"
//#import "CCCAppraiser.h"

@protocol CCCAppraiser;
@protocol CCCAllAppraisers;

@interface CCCAllAppraisers : JSONModel
//@property (strong, nonatomic) NSString <Optional> *description;
@property (strong, nonatomic) NSNumber <Optional> *numberOfRows;
@property (strong, nonatomic) CCCAppraiserType <Optional> *appraiserType;
@property (strong, nonatomic) NSArray<CCCAppraiser> *appraiser;


+(CCCFacilityModel *) getFacilityModels: (NSArray<CCCAllAppraisers *>*) appriasers appraiserType:(NSString *) appraiserType;

@end
