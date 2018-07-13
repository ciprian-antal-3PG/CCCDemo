//
//  CCCPAVinDecode.h
//  CCCSDK
//
//  Created by Animax Deng on 8/7/17.
//  Copyright © 2017 CCC. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "CCCVinDecode.h"

@interface CCCPAVinDecode : NSObject

+ (void)decodeVIN:(NSString *_Nullable)vin
       completion:(void (^_Nullable) (NSArray<CCCVehicle *> *_Nullable, NSError *_Nullable))completionHandler;

/**
 Decode VIN - Returns the vehicle year, make, model, body type and trim
 
 @param vin                VIN Number
 @param session            Session ID
 @param isSDKMode          Yes - In SDK mode, NO - In Photo Anatlyic mode
 @param completionHandler  Completed callback with CCCVinDecode object array and an error object
 */
+ (void)decodeVIN:(NSString *_Nullable)vin
        sessionId:(NSString *_Nullable)session
       completion:(void (^_Nullable) (NSArray<CCCVehicle *> *_Nullable, NSError *_Nullable))completionHandler;


+ (void)setVin:(CCCVehicle *_Nonnull)vinModel;


/**
 Check Vin eligibility
 
 @param vin                 VIN Number
 @param bodyType            Body Type
 @param completionHandler   Completed callback with BOOL and an error object
 */
+ (void)vinEligibility:(NSString *_Nullable)vin
              bodyType:(NSString *_Nullable)bodyType
            completion:(void (^_Nullable) (BOOL, NSError *_Nullable))completionHandler;

/**
 Check Vin eligibility
 
 @param vin                 VIN Number
 @param bodyType            Body Type
 @param session             Session ID
 @param completionHandler   Completed callback with BOOL and an error object
 */
+ (void)vinEligibility:(NSString *_Nullable)vin
              bodyType:(NSString *_Nullable)bodyType
             sessionId:(NSString *_Nullable)session
            completion:(void (^_Nullable) (BOOL, NSError *_Nullable))completionHandler;

@end
