//
//  CCCAppraiserType.h
//  CCCSDK
//
//  Created by Viggnesh Kandasamy on 6/8/17.
//  Copyright © 2017 CCC. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "JSONModelLib.h"
typedef enum{
    /**RF – Description*/
    appraiserType_RF,
    /**STAP – Description*/
    appraiserType_STAP,
    /**DRVI – Description*/
    appraiserType_DRVI,
    /**IA – Description*/
    appraiserType_IA
}AppraiserTypeEnum;

@interface CCCAppraiserType : JSONModel
@property(assign, nonatomic) AppraiserTypeEnum appraiserTypeEnum;
@property (strong, nonatomic, readonly) NSString <Optional> *code;
@property (strong, nonatomic) NSString *appraiserTypeDescription;

- (id) initWithAppraiserType: (AppraiserTypeEnum) appraiserType;
@end
