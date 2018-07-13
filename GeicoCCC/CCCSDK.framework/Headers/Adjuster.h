//
//  Adjuster.h
//  CCCSDK
//
//  Created by Viggnesh Kandasamy on 10/17/16.
//  Copyright © 2016 CCC. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "AdjusterContact.h"
#import "JSONModelLib.h"

@interface Adjuster : JSONModel
@property (strong, nonatomic) NSString <Optional> *adjusterCode;
@property (strong, nonatomic) NSString <Optional> *claimUnit;
@property (strong, nonatomic) AdjusterContact <Optional> *adjusterContact;

@end
