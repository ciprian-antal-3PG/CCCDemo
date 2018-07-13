//
//  Vehicle.h
//  CCCSDK
//
//  Created by Viggnesh Kandasamy on 10/19/16.
//  Copyright © 2016 CCC. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "VehicleUsage.h"
#import "Zip.h"
#import "Address.h"
#import "ImpactPoint.h"
#import "PaintDetail.h"
#import "Options.h"
#import "Appointment.h"
#import "JSONModelLib.h"
#import "StateofRegistration.h"
#import "Code.h"
#import "TotalLossFlag.h"
#import "VehicleLocation.h"
#import "Contact.h"
@interface Vehicle : JSONModel


@property(strong, nonatomic) NSString <Optional> *identificationNumber;
@property(strong, nonatomic) NSString <Optional> *licensePlateNumber;
@property(strong, nonatomic) StateofRegistration <Optional> *stateofRegistration;

@property(strong, nonatomic) NSNumber <Optional> *licensePlateExpirationDate;
@property(strong, nonatomic) NSNumber <Optional> *modelYear;
//@property(assign, nonatomic) NSInteger modelYear;
@property(strong, nonatomic) NSString <Optional> *makeCode;
@property(strong, nonatomic) NSString <Optional> *makeDescription;
@property(strong, nonatomic) NSString <Optional> *model;
@property(strong, nonatomic) VehicleUsage <Optional> *vehicleUsage;
@property(strong, nonatomic) NSString <Optional> *bodyStyle;
@property(strong, nonatomic) NSString <Optional> *externalColor;
@property(strong, nonatomic) NSString <Optional> *internalColor;
@property(strong, nonatomic) Code <Optional> *conditionCode;
@property(strong, nonatomic) NSString <Optional> *engineSize;
@property(strong, nonatomic) NSNumber <Optional> *productionDate;
@property(strong, nonatomic) NSString <Optional> *priorDamageText;
@property(strong, nonatomic) NSString <Optional> *damageMemoText;
@property(strong, nonatomic) NSString <Optional> *impactNotes;
@property(strong, nonatomic) NSString <Optional> *vehicleMemoText;
@property(strong, nonatomic) Code <Optional> *drivableFlag;
@property(strong, nonatomic) Code <Optional> *airbagDeployedFlag;
@property(strong, nonatomic) NSNumber <Optional> *severity;
@property(strong, nonatomic) Code <Optional> *intentToRepair;
@property(strong, nonatomic) TotalLossFlag <Optional> *totalLossFlag;
@property(strong, nonatomic) Zip <Optional> *garagedZip;
@property(strong, nonatomic) VehicleLocation <Optional> *vehicleLocation;
@property(strong, nonatomic) NSArray<ImpactPoint *> <Optional> *impactPoint;

@property(strong, nonatomic) NSString <Optional> *interiorCode;
@property(strong, nonatomic) NSString <Optional> *moldingCode;
@property(strong, nonatomic) NSString <Optional> *stripeCode;
@property(strong, nonatomic) NSNumber <Optional> *toneIndicator;
@property(strong, nonatomic) NSString <Optional> *trimCode;
@property(strong, nonatomic) NSString <Optional> *trimColor;
@property(strong, nonatomic) NSNumber <Optional> *paintStageIndicator;
@property(strong, nonatomic) NSMutableArray<PaintDetail *>  <Optional> *paintDetail;
@property(strong, nonatomic) Options <Optional> *options;
@property(strong, nonatomic) Appointment <Optional> *appointment;
@end
