//
//  VINMapViewController.h
//  CCCVINScanComponent
//
//  Created by Viggnesh Kandasamy on 7/1/18.
//  Copyright © 2018 cccis. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <AVFoundation/AVFoundation.h>
#import "CCCVINScanAdjuster.h"

//@protocol CCCVinScannerDelegate;

@protocol VinScannerVCDelegate <NSObject>
@required
- (void) didCompleteScanning: (NSString *_Nullable)vinNumber isVINScanned:(BOOL)isVINScanned error: (NSError *_Nullable) error;
@optional
- (void) cameraBuffer : (CMSampleBufferRef) buffer;
@end

@interface CCCVINCaptureVC : UIViewController


@property (nonatomic, strong) NSString *claimId;
@property (nonatomic) BOOL hasBackButton;
@property (nonatomic) BOOL enableLandscapeMode;
@property (nonatomic, strong) IBOutlet UIView * _Nullable backView;

/**
 *  Adjuster Information
 */
@property (nonatomic, strong) CCCVINScanAdjuster  *_Nullable adjusterInfo;

/**
 *  Required - Delegate for check status of photo capture. Should be with some value if initialize from 'Create' function
 */
@property (nonatomic, weak, nullable) id  <VinScannerVCDelegate> delegate;

@property (nonatomic, assign) BOOL showManualEntry;


+ (CCCVINCaptureVC *_Nonnull) Create;

- (void)startBarCodeScanner;

- (void)stopBarCodeScanner;

- (void) promptForVin;

#pragma mark - Initial functions, controller should be initialized from them
+ (CCCVINCaptureVC*_Nullable)createVinScannerViewWithDelegate:(id <VinScannerVCDelegate>)delegate claimId:(NSString *_Nullable) claimId;

+ (CCCVINCaptureVC*_Nullable)createVinScannerViewWithDelegate:(id<VinScannerVCDelegate>)delegate adjuster:(CCCVINScanAdjuster *_Nullable) adjuster claimId:(NSString *_Nullable) claimId;

+ (CCCVINCaptureVC*_Nullable)createVinScannerManualOptionViewWithDelegate:(id<VinScannerVCDelegate>)delegate claimId:(NSString *_Nullable) claimId;

+ (CCCVINCaptureVC*_Nullable)createVinScannerManualOptionViewWithDelegate:(id  <VinScannerVCDelegate>)delegate adjuster:(CCCVINScanAdjuster *_Nullable) adjuster claimId:(NSString *_Nullable) claimId;

@end
