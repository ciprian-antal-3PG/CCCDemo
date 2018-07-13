//
//  CCCSmartSearch.h
//  CCCSDK
//
//  Created by Viggnesh Kandasamy on 5/24/17.
//  Copyright © 2017 CCC. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "ServiceManager.h"
#import "CCCSDK_Global.h"
#import "JSONModel.h"
#import "JSONModelLib.h"
#import "CCCAllAppraisers.h"
#import "CCCAppraiserType.h"
#import "CCCStaffAppointment.h"
#import "CCCScheduleDays.h"
#import "CCCAppointmentTimeSlots.h"

@class CCCScheduleDays;

typedef enum{
    /**VE – Description*/
    claimType_VE,
    /**MC – Description*/
    claimType_MC
}ClaimTypeEnum;

typedef enum{
    /**ASC – Ascending*/
    sortOrder_ASC,
    /**DESC – Descending*/
    sortOrder_DESC
}SortOrderEnum;



typedef enum{
    /**RF – Distance*/
    sortType_D,
    /**CR – Carwise Star Rating*/
    sortType_CR,
    /**CRC – Carwise Review Count*/
    sortType_CRC,
    /**SCR – Score*/
    sortType_SCR,
     /**DNT – Distance Network Type*/
    sortType_DNT,
    /**DF – Default*/
     sortType_DF,
}SortTypeEnum;

typedef enum{
    /**DRP – DRP*/
    networkTypeEnum_DRP,
    /**OPEN – Open Shop*/
    networkTypeEnum_OPEN,
    /**ALL – All*/
    networkTypeEnum_ALL
}NetworkTypeEnum;



typedef enum{
    /**US – EASTERN*/
    US_EASTERN,
    /**US - ALASKA*/
    US_ALASKA,
    /**US - PACIFIC*/
    US_PACIFIC,
    /**US - MOUNTAIN*/
    US_MOUNTAIN,
    /**US - ARIZONA*/
    US_ARIZONA,
    /**AMERICA-PUERTO-RICO*/
    AMERICA_PUERTO_RICO,
    /**US - HAWAII*/
    US_HAWAII,
    /**US - CENTRAL*/
    US_CENTRAL
}AppointmentTimeZone;


@interface CCCSmartSearch : JSONModel
//inputs for search
@property(assign, nonatomic) ClaimTypeEnum claimTypeEnum;
@property(assign, nonatomic) SortTypeEnum sortTypeEnum;
@property(assign, nonatomic) SortOrderEnum sortOrderEnum;
@property(assign, nonatomic) NetworkTypeEnum networkTypeEnum;
@property(assign, nonatomic) AppointmentTimeZone appointmentTimeZoneEnum;
@property (strong, nonatomic, readonly) NSString <Optional> * _Nullable networkType;
@property (strong, nonatomic, readonly) NSString <Optional> * _Nullable claimType;
@property (strong, nonatomic) NSMutableArray<NSString *> <Optional> * _Nullable appraiserType;
@property (strong, nonatomic, readonly) NSString <Optional> * _Nullable sortType;
@property (strong, nonatomic, readonly) NSString <Optional> * _Nullable sortOrder;
@property (strong, nonatomic, readonly) NSString <Optional> * _Nullable appointmentTimeZone;
@property (strong, nonatomic) CCCStaffAppointment <Optional> * _Nullable staffAppointment;
@property (strong, nonatomic) NSString <Optional> * _Nullable appraiserName;
@property (strong, nonatomic) NSString <Optional> * _Nullable addressLine;
@property (strong, nonatomic) NSString <Optional> * _Nullable city;
@property (strong, nonatomic) NSString <Optional> * _Nullable state;
@property (strong, nonatomic) NSString <Optional> * _Nullable postalCode;
@property (strong, nonatomic) NSNumber <Optional> * _Nullable radius;
@property (strong, nonatomic) NSNumber <Optional> * _Nullable duration;
@property (strong, nonatomic) NSString <Optional> * _Nullable searchStartDate;
@property (strong, nonatomic) NSNumber <Optional> * _Nullable noOfDaysToSearch;
@property (strong, nonatomic) NSString <Optional> * _Nullable appointmentWindow;

// service response
@property (strong, nonatomic) NSArray<CCCAllAppraisers>  * _Nullable allAppraisers;


- (void) fetchShopsWithClaimTypeEnum : (ClaimTypeEnum ) claimType session:(NSString *_Nullable)sessionToken  appraiserTypes :( NSArray<CCCAppraiserType *>*  _Nullable) appraiserTypes postalCode : (NSString *_Nullable) postalCode completionBlock:(nullable void(^)(NSArray<CCCAllAppraisers *> * __nullable cccAllAppraisers, NSError * _Nullable error))block;



- (void) fetchShopsWithClaimTypeEnum : (ClaimTypeEnum ) claimType appraiserTypes :( NSArray<CCCAppraiserType *>*  _Nullable) appraiserTypes postalCode : (NSString *_Nullable) postalCode completionBlock:(nullable void(^)(NSArray<CCCAllAppraisers *> * __nullable cccAllAppraisers, NSError * _Nullable error))block;

// Staff Search
- (void) fetchStaffScheduleWithClaimTypeEnum : (ClaimTypeEnum ) claimType session:(NSString *_Nullable)sessionToken  appraiserTypes :( NSArray<CCCAppraiserType *>*  _Nullable) appraiserTypes postalCode : (NSString *_Nullable) postalCode completionBlock:(nullable void(^)(NSArray<CCCScheduleDays *> * __nullable staffScheduleDays, NSError * _Nullable error))block;

- (void) fetchStaffScheduleWithClaimTypeEnum : (ClaimTypeEnum ) claimType appraiserTypes :( NSArray<CCCAppraiserType *>*  _Nullable) appraiserTypes postalCode : (NSString *_Nullable) postalCode completionBlock:(nullable void(^)(NSArray<CCCScheduleDays *> * __nullable staffScheduleDays, NSError * _Nullable error))block;

-(NSArray<CCCScheduleDays *> *_Nonnull) staffSearchGroupSlots:(NSArray<CCCAllAppraisers *> * __nullable) cccAllAppraisers;
@end
