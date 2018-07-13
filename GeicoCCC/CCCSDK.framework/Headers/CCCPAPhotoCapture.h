//
//  CCCPAPhotoCapture.h
//  CCCSDK
//
//  Created by Animax Deng on 11/10/16.
//  Copyright © 2016 CCC. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CoreLocation/CoreLocation.h>

/**
 CCC uploaded image object
 */
@interface CCCImage : NSObject

/**
 Image key
 */
@property (nonatomic, strong) NSString *imageKey;

/**
 Image store path
 */
@property (nonatomic, strong) NSString *imageFullPath;

@end

/**
 CCC validated image
 **/
@interface CCCValidatedImage : NSObject

/**
 Image key
 */
@property (nonatomic, strong) NSString *imageKey;

/**
 Result of validate photo: valid:invalid:inprogress
 */
@property (nonatomic, strong) NSString *validationResult;

@end


/**
 Photo upload module
 */
@interface CCCPAPhotoCapture : NSObject

/**
 Callback type for completed upload image
 
 @param image CCCUploadImages object with included image key and path
 @param error NSError if any exception
 */
typedef void (^CCCUploadImageCompletionBlock) (CCCImage *image, NSError *error);

/**
 *  Upload image - Uploads an image with the provided metadata
 *
 *  @param imageFullPath Full image path
 *  @param sessionId     Session id provided from user
 *  @param position      Position string: "Driver Side Front, Driver Side Raer, Driver Pass Front, Driver Pass Raer"
 *  @param created       Request created date
 *  @param coordinate
 *  @param description
 *  @param last          Is last image going to submit
 *  @param block         Completed block
 */
+ (void)uploadImage:(NSString *)imageFullPath
          sessionId:(NSString *)sessionId
       positionName:(NSString *)position
            created:(NSDate *)created
           location:(CLLocationCoordinate2D)coordinate
        description:(NSString *)description
          lastImage:(BOOL)last
          completed:(CCCUploadImageCompletionBlock)block;

/**
 *  Upload image - Uploads an image with the provided metadata
 *
 *  @param imageFullPath Full image path
 *  @param position      Position string: "Driver Side Front, Driver Side Raer, Driver Pass Front, Driver Pass Raer"
 *  @param coordinate
 *  @param description
 *  @param last          Is last image going to submit
 *  @param block         Completed block
 */
+ (void)uploadImage:(NSString *)imageFullPath
       positionName:(NSString *)position
           location:(CLLocationCoordinate2D)coordinate
        description:(NSString *)description
          lastImage:(BOOL)last
          completed:(CCCUploadImageCompletionBlock)block;


/**
 Validate uploaded photo - returns a completion block with imagekey and validation result
 
 @param key               Image key from Upload image API
 @param completionHandler Completed callback
 */
+ (void)validatePhotoWithImageKey:(NSString *)key
                       completion:(void (^) (CCCValidatedImage *, NSError *))completionHandler;

/**
 Validate uploaded photo - returns a completion block with imagekey and validation result
 
 @param key               Image key from Upload image API
 @param sessionId         Session ID
 @param completionHandler Completed callback
 */
+ (void)validatePhotoWithImageKey:(NSString *)key
                        sessionId:(NSString *)sessionId
                       completion:(void (^) (CCCValidatedImage *, NSError *))completionHandler;


@end
