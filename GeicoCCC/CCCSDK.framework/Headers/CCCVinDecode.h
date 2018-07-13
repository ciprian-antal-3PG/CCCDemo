//
//  CCCVinDecode.h
//  CCCSDK
//
//  Created by Viggnesh Kandasamy on 8/3/16.
//  Copyright © 2016 CCC. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface CCCVehicle : NSObject

/**
 Vin decode result: number of vin
 */
@property (nonatomic, strong) NSString *_Nullable vinNumber;
/**
 Vin decode result: Make year of the vehicle
 */
@property (nonatomic) NSInteger vehicleYear;
/**
 Vin decode result: Body type of the vehicle - SED:UTV
 */
@property (nonatomic, strong) NSString *_Nullable bodyType;
/**
 Vin decode result: Make of the vehicle - eg. Toyota
 */
@property (nonatomic, strong) NSString *_Nullable make;

/**
 Vin decode result: Make Code of the vehicle - eg. HOND
 */
@property (nonatomic, strong) NSString *_Nullable makeCode;
/**
 Vin decode result: trim of the vehicle - eg. CE
 */
@property (nonatomic, strong) NSString *_Nullable trim;

/**
 Vin decode result: Model of the vehicle - eg. Camry
 */
@property (nonatomic, strong) NSString *_Nullable vehicleModel;

/**
 Vin decode result: Display Model of the vehicle - eg. Accord Coupe Touring Automatic
 */
@property (nonatomic, strong) NSString *_Nullable displayModel;

/**
 Vin decode result:Motor Chapter ID of vehicle - eg.
 */
@property (nonatomic, strong) NSString *_Nullable motorChapterId;

/**
 Vin decode result:CCCSvId of vehicle - eg.
 */

@property (nonatomic, strong) NSString *_Nullable cccSvId;


+ (CCCVehicle *_Nonnull) createVehicleModel:(NSDictionary *_Nonnull) vehicleInfo;
- (id _Nonnull)jsonObject;

@end


/**
 Vin decode service module
 */
@interface CCCVinDecode : NSObject


/**
 Decode VIN - Returns the vehicle year, make, model, body type and trim

 @param vin VIN Number
 @param completionHandler Completed callback with CCCVinDecode object array and an error object
 */
+ (void)decodeVIN:(NSString *_Nullable)vin
       completion:(void (^_Nullable) (NSArray<CCCVehicle *> *_Nullable, NSError *_Nullable))completionHandler;


/**
 Decode VIN - Returns the vehicle year, make, model, body type and trim

 @param vin                VIN Number
 @param session            Session ID
 @param completionHandler  Completed callback with CCCVinDecode object array and an error object
 */

+ (void)decodeVIN:(NSString *_Nullable)vin
       sessionId : (NSString *_Nullable)session
       completion:(void (^_Nullable) (NSArray<CCCVehicle *> *_Nullable, NSError *_Nullable))completionHandler;

+ (void)decodeVIN:(NSString *_Nullable)vin
        sessionId:(NSString *_Nullable)session
            count:(NSString *_Nullable)count
       completion:(void (^_Nullable) (NSArray<CCCVehicle *> *_Nullable, NSError *_Nullable))completionHandler;
+ (void)decodeVIN:(NSString *_Nullable)vin
            count:(NSString *_Nullable)count
       completion:(void (^_Nullable) (NSArray<CCCVehicle *> *_Nullable, NSError *_Nullable))completionHandler;

@end
