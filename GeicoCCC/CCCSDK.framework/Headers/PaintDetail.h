//
//  PaintDetail.h
//  CCCSDK
//
//  Created by Viggnesh Kandasamy on 10/19/16.
//  Copyright © 2016 CCC. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "JSONModelLib.h"

@interface PaintDetail : JSONModel

@property (nonatomic, strong) NSNumber <Optional> *sequenceNumber;

@property (nonatomic, strong) NSString <Optional> *pointCode;

@end
