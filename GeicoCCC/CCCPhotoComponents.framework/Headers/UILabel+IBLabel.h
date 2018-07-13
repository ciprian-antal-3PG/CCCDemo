//
//  UILabel+IBLabel.h
//  CCCSmartAppraiserSearchComponent
//
//  Created by Sudhin on 21/12/17.
//  Copyright © 2017 CTS. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface UILabel (IBLabel)
    @property (nonatomic) IBInspectable NSString *TextConfigKey;
    @property (nonatomic) IBInspectable NSString *ColorConfigKey;
    @property (nonatomic) IBInspectable NSString *FontConfigKey;
@end
