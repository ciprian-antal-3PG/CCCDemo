//
//  CCCAppraiser.h
//  CCCSDK
//
//  Created by Viggnesh Kandasamy on 6/2/17.
//  Copyright © 2017 CCC. All rights reserved.
//

#import <UIKit/UIKit.h>
//#import "CCCSDK_Global.h"
#import "JSONModelLib.h"
#import "CCCAppraiserAddress.h"
#import "CCCAppraiserCapacity.h"
#import "CCCAppraiserPhone.h"
#import "CCCAppraiserPaymentTypesOffered.h"
#import "CCCAppraiserServicesOffered.h"
#import "CCCAppraiserShopPhoto.h"
#import "CCCAppraiserBusinessHours.h"
#import "CCCOneFeatures.h"

@protocol CCCAppraiser;

@interface CCCAppraiser: JSONModel

@property (strong, nonatomic) NSString <Optional> *code;
@property (strong, nonatomic) NSString <Optional> *name;
@property (strong, nonatomic) CCCAppraiserAddress <Optional> *address;
@property (strong, nonatomic) NSNumber <Optional> *distanceFromAddress;
@property (strong, nonatomic) NSNumber <Optional> *drpRank;
@property (strong, nonatomic) NSNumber <Optional> *scoreCard;
@property (strong, nonatomic) CCCAppraiserCapacity <Optional> *capacity;
@property (strong, nonatomic) NSString <Optional> *note;
@property (strong, nonatomic) NSNumber <Optional> *rating;
@property (strong, nonatomic) CCCAppraiserPhone <Optional> *phone;
@property (strong, nonatomic) NSNumber <Optional> *latitude;
@property (strong, nonatomic) NSNumber <Optional> *longitude;
@property (nonatomic) BOOL cccOneIndicator;
@property (strong, nonatomic) NSNumber <Optional> *coverageRanking;
@property (strong, nonatomic) CCCOneFeatures <Optional> *cccOneFeatures;
@property (nonatomic) BOOL hasAppointmentScheduling;
@property (strong, nonatomic) NSString <Optional> *carwiseLogoImage;
@property (strong, nonatomic) NSNumber <Optional> *carwiseStarRating;
@property (strong, nonatomic) NSString <Optional> *carwiseStarRatingImage;
@property (strong, nonatomic) NSNumber <Optional> *carwiseReviewCount;
@property (strong, nonatomic) NSNumber <Optional> *yearsInBusiness;
@property (strong, nonatomic) NSString <Optional> *rentalAvailable;
@property (strong, nonatomic) NSString <Optional> *repairFacilityLogoImage;
@property (strong, nonatomic) NSArray<NSString *> <Optional> *paymentTypesOffered;
@property (strong, nonatomic) NSArray<NSString *> <Optional> *servicesOffered;
@property (strong, nonatomic) NSString <Optional> *networkType;
@property (strong, nonatomic) NSArray<CCCAppraiserShopPhoto> *shopPhotos;
@property (strong, nonatomic) NSArray<CCCAppraiserBusinessHours > *businessHours;
@property (strong, nonatomic) NSString <Optional> *appointmentWindowStartTime;
@property (strong, nonatomic) NSString <Optional> *appointmentWindowEndTime;
@property (strong, nonatomic) NSString <Optional> *appointmentTimeZone;


//appointmentWindowStartTime

@end
