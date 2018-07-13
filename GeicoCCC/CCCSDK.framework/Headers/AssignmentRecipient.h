//
//  AssignmentRecipient.h
//  CCCSDK
//
//  Created by Viggnesh Kandasamy on 10/21/16.
//  Copyright © 2016 CCC. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "JSONModelLib.h"
#import "AssignmentRecipientType.h"
#import "StringClass.h"

@interface AssignmentRecipient : JSONModel
/** AssignmentRecipientID ~ code value to define appraisal recipient */
@property(strong, nonatomic) NSString <Optional> *assignmentRecipientID;

@property(strong, nonatomic) AssignmentRecipientType <Optional> *assignmentRecipientType;

/** DateAssigned ~ Date and time the assignment was sent by the sender */
@property(strong, nonatomic) NSNumber <Optional> *dateAssigned;
/** MOI for the vehicle. */
@property(strong, nonatomic) StringClass <Optional> *inspectionMethod;
/** InstructionsToEstimator ~ Notes to give recipients specific instructions */
@property (strong, nonatomic) NSString <Optional> *instructionsToEstimator;
/** InspectionRequirements ~ Notes to give recipients specific instructions */
@property (strong, nonatomic) NSString <Optional> *inspectionRequirements;
/** AssignedBy ~ Individual (Consumer) creating and sending the assignment */
@property (strong, nonatomic) NSString <Optional> *assignedBy;

@end
