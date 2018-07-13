//
//  NSError+CCCError.h
//  CCCSDK
//
//  Created by Viggnesh Kandasamy on 11/8/17.
//  Copyright © 2017 CCC. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface NSError (CCCError)
- (NSError *) constructErrorInCCCFormat;
@end
