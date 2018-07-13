//
//  CCCConfigValues.h
//  CCCSDK
//
//  Created by Viggnesh Kandasamy on 11/14/17.
//  Copyright © 2017 CCC. All rights reserved.
//

#import <CCCSDK/CCCSDK.h>
#import "CCCSDK_Global.h"
#import "JSONModelLib.h"
@interface CCCConfigValues : JSONModel
@property (strong, nonatomic) NSString <Optional> * _Nonnull code;
@property (strong, nonatomic) NSString <Optional> * _Nonnull value;

@end
