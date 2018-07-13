//
//  AssignmentClaimInfo.h
//  CCCSDK
//
//  Created by Viggnesh Kandasamy on 10/17/16.
//  Copyright © 2016 CCC. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "Adjuster.h"
#import "JSONModelLib.h"
#import "PreviousEstimate.h"
#import "ClaimTypeCode.h"
#import "ClaimTypeDetail.h"
#import "RentalCarInUse.h"
#import "CcclossCategory.h"
#import "EnumClass.h"







@interface Claim : JSONModel
@property (strong, nonatomic) NSString <Optional>  *lossReferenceId;
@property (strong, nonatomic) NSString <Optional>  *primaryInsuranceCompanyID;
@property (strong, nonatomic) NSString <Optional>  *subsidiaryInsuranceCompanyID;
@property (strong, nonatomic) NSString <Optional>  *claimOffice;
@property (strong, nonatomic) ClaimTypeCode <Optional>  *claimTypeCode;

/** ClaimTypeDetail ~ optional code value for further identification of type of claim property */
@property (strong, nonatomic) ClaimTypeDetail <Optional>  *claimTypeDetail;


@property (strong, nonatomic) NSString <Optional>  *customerLossTypeCode;
//@property (assign, nonatomic) CustomerLossTypeCodeEnum customerLossTypeCode;


@property (strong, nonatomic) NSNumber <Optional>  *reportedDateTime;

@property (strong, nonatomic) RentalCarInUse <Optional>  *rentalCarInUse;

@property (strong, nonatomic) NSNumber <Optional>  *dailyCost;

@property (strong, nonatomic) EnumClass <Optional> *okToPayFlag;

@property (strong, nonatomic) Adjuster <Optional> *adjuster;

@property (strong, nonatomic) NSString <Optional> *claimNotes;
@property (strong, nonatomic) NSString <Optional> *cesLossTypeCode;
@property (strong, nonatomic) NSString <Optional> *cesLossTypeDescription;
@property (strong, nonatomic) CcclossCategory <Optional> *ccclossCategory;

@property (strong, nonatomic) PersonCompanyIndicator <Optional>  *personCompanyIndicator;
//@property (strong, nonatomic) NSString <Optional>  *paymentComments;
//
//@property (strong, nonatomic) NSMutableArray *otherClaimPartyRoleTypeList;
//@property (strong, nonatomic) PreviousEstimate *previousEstimate;


@end
