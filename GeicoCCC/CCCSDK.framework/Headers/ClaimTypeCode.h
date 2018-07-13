//
//  ClaimTypeCode.h
//  CCCSDK
//
//  Created by Viggnesh Kandasamy on 2/16/17.
//  Copyright © 2017 CCC. All rights reserved.
//

#import "JSONModel.h"
#import "JSONModelLib.h"
typedef enum {
    /**Vehicle*/
    claimTypeCode_VE,
    /**Structural*/
    claimTypeCode_ST,
    /**Motorcycle*/
    claimTypeCode_MC,
    /**Other*/
    claimTypeCode_OT,
    /**Bus*/
    claimTypeCode_BS,
    /**Emergency*/
    claimTypeCode_EM,
    /**Heavy Equipment*/
    claimTypeCode_HE,
    /**Heavy Truck*/
    claimTypeCode_HT,
    /**Recreational Vehicles & Campers*/
    claimTypeCode_RV,
    /**Sport/Off Road*/
    claimTypeCode_SR,
    /**Trailer*/
    claimTypeCode_TR,
    /**Watercraft*/
    claimTypeCode_WC
}ClaimTypeCodeEnum;

@interface ClaimTypeCode : JSONModel
/** ClaimTypeCode ~ Required to identify type of claim property */
@property (assign, nonatomic) ClaimTypeCodeEnum claimTypeCodeEnum;
@property (strong, nonatomic, readonly) NSString *code;
@end
