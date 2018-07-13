//
//  CCCAppraiserPhone.h
//  CCCSDK
//
//  Created by Viggnesh Kandasamy on 6/6/17.
//  Copyright © 2017 CCC. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "CCCSDK_Global.h"
#import "JSONModelLib.h"

@interface CCCAppraiserPhone : JSONModel
@property (strong, nonatomic) NSString <Optional> *number;
@property (strong, nonatomic) NSString <Optional> *type;

@end
