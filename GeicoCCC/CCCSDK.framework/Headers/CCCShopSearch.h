//
//  CCCShopSearch.h
//  CCCSDK
//
//  Created by bkongara on 8/31/16.
//  Copyright © 2016 CCC. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <MapKit/MapKit.h>
#import "CCCAppraiserShopPhoto.h"
#import "CCCAppraiserBusinessHours.h"

@interface CCCFacilityModel : NSObject

@property (strong, nonatomic) NSString * _Nullable locationId;
@property (strong, nonatomic) NSString * _Nullable relationshipId;
@property (strong, nonatomic) NSString * _Nullable name;
@property (strong, nonatomic) NSString * _Nullable address;
@property (strong, nonatomic) NSString * _Nullable city;
@property (strong, nonatomic) NSString * _Nullable state;
@property (strong, nonatomic) NSString * _Nullable zipcode;
@property (strong, nonatomic) NSString * _Nullable phoneNumber;
@property (strong, nonatomic) NSString * _Nullable typeCode;
@property (strong, nonatomic) NSNumber * _Nullable ratingValue;
@property (strong, nonatomic) NSNumber * _Nullable carWiseratingValue;
@property (strong, nonatomic) NSNumber * _Nullable carWiseratingCount;
@property (nonatomic, strong) NSString * _Nullable appraiserCode;
@property (strong, nonatomic) NSArray<CCCAppraiserShopPhoto> *  _Nullable shopPhotos;
@property (strong, nonatomic) NSArray<CCCAppraiserBusinessHours *> * _Nullable businessHours;

@property (nonatomic) BOOL isInNetwork;
@property (nonatomic) BOOL hasAppointmentScheduling;
@property (nonatomic) double latitude;
@property (nonatomic) double longitude;
@property (nonatomic) float distance;



+ (CCCFacilityModel *_Nullable) createCCCFacilityModel:(NSDictionary *_Nullable)eachFacilityDict;
+ (CCCFacilityModel *_Nonnull) createCCCFacilityModel:(NSDictionary *_Nonnull) eachFacilityDict withAppraiserCode:(NSString *_Nonnull) appraiserCode;
- (NSString *_Nonnull) prepareFullAddressString;
- (NSDictionary *_Nullable) getFacilityDictionary;

@end

@interface CCCAddressModel : NSObject

@property (strong, nonatomic) NSString * _Nullable addressLine;
@property (strong, nonatomic) NSString * _Nullable city;
@property (strong, nonatomic) NSString * _Nullable state;
@property (strong, nonatomic) NSString * _Nullable postalCode;


+(CCCAddressModel *_Nonnull) getAddressFromPlacemark:(CLPlacemark *_Nonnull) placemark;

@end


typedef void  (^searchShopCompleted)(NSArray<CCCFacilityModel *> * __nullable shopItems, NSError * __nullable error);

typedef void  (^addressConversionCompleted)(CCCAddressModel * __nullable address , NSError * __nullable error);

@interface CCCShopSearch : NSObject


+(void) shopSearchForCompany:(NSString *_Nullable) companyCode withAddress:(CCCAddressModel *_Nonnull)address  appraiserTypes:(NSArray *_Nonnull) appraiserTypes radiusMile:(NSInteger)radius completedBlock:(searchShopCompleted _Nullable)completionHandler;
+(void) shopSearchForCompany:(NSString *_Nullable) companyCode withSession:(NSString *_Nullable)sessionToken Address:(CCCAddressModel *_Nullable)address appraiserTypes:(NSArray *_Nullable) appraiserTypes radiusMile:(NSInteger)radius completedBlock:(searchShopCompleted _Nullable)completionHandler;
+(void) setLatLongFromAddress:(NSString * _Nonnull) addressString toFacilityModel:(CCCFacilityModel *_Nonnull) appraiser;
+(void) getAddressFromLocation:(CLLocation * _Nonnull)location completedBlock:(addressConversionCompleted _Nullable) completionHandler;

@end
