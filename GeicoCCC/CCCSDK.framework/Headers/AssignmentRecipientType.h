//
//  AssignmentRecipientType.h
//  CCCSDK
//
//  Created by Viggnesh Kandasamy on 2/16/17.
//  Copyright © 2017 CCC. All rights reserved.
//

#import "JSONModel.h"
#import "JSONModelLib.h"


typedef enum {
    /**STAP – Staff Appraiser*/
    AssignmentRecipientType_STAP,
    /**DRVI – Staff Drive-In*/
    AssignmentRecipientType_DRVI,
    /**DRP – DRP or Open Shop Repair Facilities*/
    AssignmentRecipientType_DRP,
    /**IA – Independent Appraiser*/
    AssignmentRecipientType_IA
}AssignmentRecipientTypeEnum;


@interface AssignmentRecipientType : JSONModel

/** AssignmentRecipientType ~ used to defined recipient appraiser type. */
@property(assign, nonatomic) AssignmentRecipientTypeEnum assignmentRecipientTypeEnum;

@property(assign, nonatomic, readonly) NSString *code;

@end
