//
//  CCCPhotoCaptureOverlayVC.h
//  CCCPhotoComponents
//
//  Created by Jerry Walton on 5/28/15.
//  Copyright (c) 2015 CCC. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface CCCVINCaptureOverlayVC : UIViewController
@property (nonatomic, weak) IBOutlet UILabel *headerLbl;
@property (nonatomic, weak) IBOutlet UIImageView *imageView;
@property (nonatomic, weak) IBOutlet UILabel *titleLbl;
@property (nonatomic, weak) IBOutlet UILabel *descrLbl;
@property (nonatomic, weak) IBOutlet UILabel *lblTapAnyWhere;

@end
