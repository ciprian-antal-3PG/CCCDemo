//
//  TheftFlag.h
//  CCCSDK
//
//  Created by Viggnesh Kandasamy on 2/20/17.
//  Copyright © 2017 CCC. All rights reserved.
//

#import "JSONModel.h"
#import "JSONModelLib.h"

typedef enum  {
    /**theftFlag_Y – YES*/
    theftFlag_Y,
    /**theftFlag_N – NO*/
    theftFlag_N,
    /**theftFlag_U – Unknown*/
    theftFlag_U
}TheftFlagEnum;
@interface TheftFlag : JSONModel

@property (assign, nonatomic) TheftFlagEnum theftFlagEnum;
@property (strong, nonatomic, readonly) NSString *code;

@end
