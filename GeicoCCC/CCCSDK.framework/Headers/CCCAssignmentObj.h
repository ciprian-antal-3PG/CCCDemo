//
//  CCCAssignment.h
//  CCCSDK
//
//  Created by Viggnesh Kandasamy on 9/6/16.
//  Copyright © 2016 CCC. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "Claim.h"
#import "Vehicle.h"
#import "Appointment.h"
#import "ClaimParty.h"
#import "Loss.h"
#import "Policy.h"
#import "AssignmentAdministration.h"
#import "AssignmentRecipient.h"
#import "JSONModelLib.h"
#import "ThirdParty.h"

@class ClaimParty;
@interface CCCAssignmentObj : JSONModel




#pragma mark - AssignmentAdministration
@property (strong, nonatomic) AssignmentAdministration  <Optional> *assignmentAdministration;

#pragma mark - AssignmentRecipient
@property (strong, nonatomic) AssignmentRecipient  <Optional> *assignmentRecipient;

#pragma mark - Claim
@property(strong, nonatomic) Claim  <Optional> *claim;

#pragma mark - Vehicle
@property(strong, nonatomic) Vehicle  <Optional> *vehicle;

#pragma mark - Appointment
@property(strong, nonatomic) Appointment  <Optional> *appointment;

#pragma mark - ClaimParty
@property(strong, nonatomic) NSArray<ClaimParty>  *claimParty;

#pragma mark - Loss
@property(strong, nonatomic) Loss  <Optional> *loss;

#pragma mark - Policy
@property(strong, nonatomic) Policy  <Optional> *policy;

//#pragma mark - Adjuster
//@property(strong, nonatomic) Adjuster  <Optional> *adjuster;

#pragma mark - Third Party
@property(strong, nonatomic) ThirdParty  <Optional> *thirdParty;

@end

