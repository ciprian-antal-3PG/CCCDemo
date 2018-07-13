//
//  AssignmentAdministration.h
//  CCCSDK
//
//  Created by Viggnesh Kandasamy on 10/21/16.
//  Copyright © 2016 CCC. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "JSONModelLib.h"
#import "EnumClass.h"


@interface AssignmentAdministration : JSONModel
@property (strong, nonatomic) EnumClass <Optional> *assignmentActionCode;
@property (strong, nonatomic) NSString <Optional> *predictiveMOIRequestID;
@property (strong, nonatomic) EnumClass <Optional> *activeScheduleIndicator;

@end
