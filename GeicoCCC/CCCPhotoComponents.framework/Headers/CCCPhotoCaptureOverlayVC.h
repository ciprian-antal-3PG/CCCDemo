//
//  CCCPhotoCaptureOverlayVC.h
//  CCCPhotoComponents
//
//  Created by Jerry Walton on 5/28/15.
//  Copyright (c) 2015 CCC. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface CCCPhotoCaptureOverlayVC : UIViewController


@property (weak, nonatomic) IBOutlet UIView *viewHolder;
@property (nonatomic, weak) IBOutlet UILabel *headerLbl;
@property (nonatomic, weak) IBOutlet UIImageView *imageView;
@property (nonatomic, weak) IBOutlet UILabel *titleLbl;
@property (nonatomic, weak) IBOutlet UILabel *descrLbl;
@property (weak, nonatomic) IBOutlet UILabel *footerDescLabel;
@property (nonatomic, weak) IBOutlet UILabel *lblTapAnyWhere;

@property (strong, nonatomic) IBOutlet NSLayoutConstraint *constraintTopViewHeight;
@property (strong, nonatomic) IBOutlet NSLayoutConstraint *ConstraintDesLabelHeight;

@end
