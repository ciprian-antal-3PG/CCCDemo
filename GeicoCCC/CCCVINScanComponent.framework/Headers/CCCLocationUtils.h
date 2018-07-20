//
//  CCCLocationUtils.h
//  CCCPhotoComponents
//
//  Created by Jerry Walton on 6/6/15.
//  Copyright (c) 2015 CCC. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CoreLocation/CoreLocation.h>

@class CLLocation;

typedef void (^CCCLocationUtilsCompletionHandler)(CLLocation *location);

@protocol CCCLocationUtilsDelegate <NSObject>
@required
- (void)locationManager:(CLLocationManager *)manager didChangeAuthorizationStatus:(CLAuthorizationStatus)status;
- (void)updateUsersLocation :(CLLocation *)location;
@end


@interface CCCLocationUtils : NSObject
    @property (nonatomic, strong) CLLocationManager *locationManager;
    @property (nonatomic, weak) id<CCCLocationUtilsDelegate> delegate;

- (void) updateLocationWithCompletion:(CCCLocationUtilsCompletionHandler)completion;
- (void) updateLocation;

@end
