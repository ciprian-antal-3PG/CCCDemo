//
//  Zip.h
//  CCCSDK
//
//  Created by Viggnesh Kandasamy on 10/19/16.
//  Copyright © 2016 CCC. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "JSONModelLib.h"

@interface Zip : JSONModel
@property(strong, nonatomic) NSString <Optional> *zipCode;
@property(strong, nonatomic) NSString <Optional> *zipExt;

@end
