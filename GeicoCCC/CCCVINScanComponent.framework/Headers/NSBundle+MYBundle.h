//
//  NSBundle+MYBundle.h
//  Safeco_Express_Estimate
//
//  Created by Viggnesh Kandasamy on 6/19/15.
//  Copyright (c) 2015 CCCIS. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

@interface NSBundle (MYBundle)
+ (UIImage*)imageWithBundle :(NSBundle *)bundle imageName:(NSString*)imageName;
@end
