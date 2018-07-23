//
//  CCCViewAdjusterInfo.h
//  Safeco_Express_Estimate
//
//  Created by Sudhin on 11/01/18.
//  Copyright © 2018 CCCIS. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "CCCVINScanAdjuster.h"

@interface CCCVINScanAdjusterInfo : UIView
@property (strong, nonatomic) IBOutlet NSLayoutConstraint *constraintAdjusterTop;
@property (strong, nonatomic) IBOutlet NSLayoutConstraint *constraintAdjusterClaimNumberHeight;
@property (strong, nonatomic) IBOutlet NSLayoutConstraint *constraintAdjusterNameHeight;
@property (strong, nonatomic) IBOutlet NSLayoutConstraint *constraintAdjusterPhoneHeight;
@property (strong, nonatomic) IBOutlet NSLayoutConstraint *constraintAdjusterEmailHeight;
@property (strong, nonatomic) UIView *viewAdjusterInfo;
@property (strong, nonatomic) IBOutlet UIView *viewBG;
@property (strong, nonatomic) IBOutlet UILabel *labelClaim;
@property (strong, nonatomic) IBOutlet UILabel *labelUserType;
@property (weak, nonatomic) IBOutlet UILabel *lblClaimNumber;
@property (weak, nonatomic) IBOutlet UILabel *lblOffice;
@property (weak, nonatomic) IBOutlet UILabel *lblEmail;
@property (strong, nonatomic) IBOutlet UILabel *labelUserName;
@property (strong, nonatomic) IBOutlet UILabel *labelofficeNumber;
@property (strong, nonatomic) IBOutlet UILabel *labelEmail;
@property (strong, nonatomic) IBOutlet UIImageView *imagePhone;
@property (weak, nonatomic) IBOutlet UILabel *lblContactMsg;

@property (strong, nonatomic) CCCVINScanAdjuster  * _Nonnull adjusterInfo;

-(IBAction)dismissAdjusterInfo;
+(void)showInViewController:(UIViewController*)viewController withAdjusterInfo:(CCCVINScanAdjuster *) adjusterInfo;
@end
