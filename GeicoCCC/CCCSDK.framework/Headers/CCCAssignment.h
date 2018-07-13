//
//  CCCAssignment.h
//  CCCSDK
//
//  Created by Viggnesh Kandasamy on 2/10/17.
//  Copyright © 2017 CCC. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "CCCAssignmentObj.h"
#import "TransactionControlHeader.h"
#import "ServiceManager.h"
#import "CCCSDK_Global.h"
#import <Foundation/Foundation.h>

@interface CCCAssignment : JSONModel


//input
@property (strong, nonatomic) TransactionControlHeader * _Nullable transactionControlHeader;
@property (strong, nonatomic) NSString  <Optional> * _Nullable version;
@property (strong, nonatomic) CCCAssignmentObj  <Optional> * _Nullable cccassignment;

// Output
@property (strong, nonatomic) NSNumber  <Optional> * _Nullable responseCode;
@property (strong, nonatomic) NSString  <Optional> * _Nullable responseDescription;

/**
 *  CreateAssignment request server call - passing full params
 *  @param primaryInsuranceCompanyID
 *  @param lossReferenceID
 *  @param claimReferenceId
 *  @param assignmentActionCode
 *  @param activeScheduleIndicator
 *  @param assignmentRecipientID
 *  @param claimPartyRoleType Defines the claim party role with respect to the claim vehicle.
 *  @param personCompanyIndicator identifies the Claim Contact as a Person or Company
 *  @param personCompanyName If personCompanyIndicator is company, then provide company name. If person, then provide person's last name.
 */
//not supported
//activeScheduleIndicator:(NSString *)activeScheduleIndicator
//- (void)createAssignmentWithPrimaryInsuranceCompanyID:(NSString *)primaryInsuranceCompanyID
//                                      lossReferenceID:(NSString *)lossReferenceID
//                                  uniqueTransactionID:(NSString *)uniqueTransactionID
//                                          claimOffice:(NSString *)claimOffice
//                                        claimTypeCode:(ClaimTypeCode)claimTypeCode
//                                  transactionDateTime:(NSDate *)transactionDateTime
//                                 assignmentActionCode:(AssignmentActionCode *)assignmentActionCode
//                                assignmentRecipientID:(NSString *)assignmentRecipientID
//                              assignmentRecipientType:(AssignmentRecipientType)assignmentRecipientType
//                                     InspectionMethod:(NSString *)InspectionMethod
//                                      cccLossCategory:(CCCLossCategory)cccLossCategory
//                                 customerLossTypeCode:(CustomerLossTypeCode)customerLossTypeCode
//                                           claimParty:(ClaimParty *)claimParty
//                                    completionHandler:(void (^) (id data, NSError *error))completionHandler;


//- (id) initWithPrimaryInsuranceCompanyID: (NSString *) primaryInsuranceCompanyID lossReferenceID : (NSString *) lossReferenceID;
//ccclossCategory = "collision"

/**
 * This service invokation creates an incomplete assignment (which is updated later) using only the required field.
 * @param primaryInsuranceCompanyID
 * @param lossReferenceID
 * @param uniqueTransactionID
 * @param claimOffice
 * @param assignmentRecipientID
 * @param assignmentRecipientTypeEnum
 * @param claimPartyContactIndicator
 * @param claimPartyContactLastName
 * @param callback
 * @throws Exception
 */
+ (void) initiateAssignmentWithSessionId : (NSString * _Nullable)sessionToken
                primaryInsuranceCompanyID:(NSString *_Nonnull)primaryInsuranceCompanyID
                          lossReferenceID:(NSString *_Nonnull)lossReferenceID
                      uniqueTransactionID:(NSString *_Nonnull)uniqueTransactionID
                      transactionDateTime:(NSDate *_Nonnull)transactionDateTime
                              claimOffice:(NSString *_Nonnull)claimOffice
                    assignmentRecipientID:(NSString *_Nonnull)assignmentRecipientID
                         inspectionMethod:(NSString *_Nonnull)inspectionMethod
                  assignmentRecipientType:(AssignmentRecipientTypeEnum)assignmentRecipientTypeEnum
                     assignmentActionCode: (AssignmentActionCodeEnum) assignmentActionCodeEnum
                       claimPartyRoleType:(ClaimPartyRoleTypeEnum)claimPartyRoleTypeEnum
                            claimTypeCode:(ClaimTypeCodeEnum)claimTypeCodeEnum
                     customerLossTypeCode:(CustomerLossTypeCodeEnum)customerLossTypeCodeEnum
                       claimPartyContact : (ClaimPartyContact *_Nonnull) claimPartyContact
                        completionHandler:(void (^_Nullable) (id _Nullable data, NSError *_Nullable error))completionHandler;


/**
 * This service invokation creates an incomplete assignment (which is updated later) using some of the most commonly used fields.
 * @param primaryInsuranceCompanyID
 * @param lossReferenceID
 * @param uniqueTransactionID
 * @param claimOffice
 * @param assignmentRecipientID
 * @param assignmentRecipientType
 * @param claimPartyPersonCompanyIndicator
 * @param claimPartyContactLastName
 * @param adjusterCode
 * @param vehicleYear
 * @param vehicleMake
 * @param vehicleModel
 * @param inspectionMethod
 * @param ccclossCategory
 * @param customerLossTypeCode
 * @param claimTypeCode
 * @param transactionDateTime
 * @param assignmentActionCode
 * @param claimPartyContactContactType
 * @param vehicleDriveableIndicator
 * @param vehicleLocationAddress
 * @param policyDeductibleType
 * @param policyDeductible
 * @param callback {@link BaseCCCAPIRequestCallback<CreateAssignmentResponse>}
 * @throws Exception
 */


+ (void) initiateAssignmentWithSessionId : (NSString * _Nullable)sessionToken
                primaryInsuranceCompanyID:(NSString *_Nonnull)primaryInsuranceCompanyID
                          lossReferenceID:(NSString *_Nonnull)lossReferenceID
                      uniqueTransactionID:(NSString *_Nonnull)uniqueTransactionID
                      transactionDateTime:(NSDate *_Nonnull)transactionDateTime
                              claimOffice:(NSString *_Nonnull)claimOffice
                    assignmentRecipientID:(NSString *_Nonnull)assignmentRecipientID
                         inspectionMethod:(NSString *_Nonnull)inspectionMethod
                  assignmentRecipientType:(AssignmentRecipientTypeEnum)assignmentRecipientTypeEnum
                     assignmentActionCode: (AssignmentActionCodeEnum) assignmentActionCodeEnum
                       claimPartyRoleType:(ClaimPartyRoleTypeEnum)claimPartyRoleTypeEnum
                            claimTypeCode:(ClaimTypeCodeEnum)claimTypeCodeEnum
                     customerLossTypeCode:(CustomerLossTypeCodeEnum)customerLossTypeCodeEnum
                       claimPartyContact : (ClaimPartyContact *_Nonnull) claimPartyContact

                             adjusterCode: (NSString *_Nonnull) adjusterCode
                              vehicleYear: (NSNumber *_Nonnull) vehicleYear
                              vehicleMake: (NSString *_Nonnull) vehicleMake
                             vehicleModel: (NSString *_Nonnull) vehicleModel
                          ccclossCategory:(CCClossCategoryEnum)ccclossCategoryEnum

               vehicleDrivableIndicator : (NSString *_Nullable) vehicleDrivableIndicator
                 vehicleLocationAddress : (Address *_Nullable) vehicleLocationAddress
                   policyDeductibleType : (DeductibleTypeEnum)policyDeductibleType
                        policyDeductible : (NSDecimalNumber *_Nullable)policyDeductible
                       completionHandler:(void (^_Nullable) (id _Nullable data, NSError *_Nullable error))completionHandler;





+ (void) createAssignmentWithSessionId : (NSString * _Nullable)sessionToken
                assignmentObj:(CCCAssignment *_Nonnull)assignmentObj
                        completionHandler:(void (^_Nullable) (id _Nullable data, NSError *_Nullable error))completionHandler;


+ (void) updateAssignmentWithSessionId : (NSString * _Nullable)sessionToken
                          assignmentObj:(CCCAssignment *_Nonnull)assignmentObj
                      completionHandler:(void (^_Nullable) (id _Nullable data, NSError *_Nullable error))completionHandler;

+ (void) updateAssignment:(CCCAssignment *_Nonnull)assignmentObj
                      completionHandler:(void (^_Nullable) (id _Nullable data, NSError *_Nullable error))completionHandler;



+ (void) CreateAssignmentFromJSONRequest : (NSDictionary *_Nullable) jsonDict completionBlock:(nullable void(^)(Boolean isAssignmentAccepted, NSError * _Nullable error))block;

- (void) mapJSONToAssignment : (NSDictionary *_Nullable) jsonDict;

- (void) mapJSONToAssignmentData : (NSData *_Nullable) jsonData;

/**
 Retreives the assignment for a claim.
 @param block A block object to be executed when the task finishes successfully. This block returns a value and takes two arguments: a CCCFetchEstimate response object and an NSError object.
 
 @see http://mobilesdk.cccis.com/documentation/
 
 */
+ (void) fetchAssignmentWithSessionId : (NSString * _Nullable)sessionToken CompletionBlock:(CCC_NULLABLE CCCAssignmentBlock)block;
+ (void) fetchAssignment:(CCC_NULLABLE CCCAssignmentBlock)block;

@end
