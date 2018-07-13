//
//  CCCDownloadManager.h
//  CCCSDK
//
//  Created by Viggnesh Kandasamy on 6/27/17.
//  Copyright © 2017 CCC. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CoreGraphics/CGBase.h>

@interface CCCDownloadManager : NSObject

+ (instancetype)sharedManager;



- (void)cancelAllDownloads;
- (void)cancelDownloadForUrl:(NSString *)fileIdentifier;

- (BOOL)isFileDownloadingForKey:(NSString *)key
              withProgressBlock:(void(^)(CGFloat progress))block
                completionBlock:(void(^)(NSError *error, NSData *fileData))completionBlock;



- (void)downloadShopImageWithSession: (NSString *) session
                          ForKey:(NSString *)key
              progressBlock:(void(^)(CGFloat progress))progressBlock
            completionBlock:(void(^)(NSError *error, NSData *fileData))completionBlock;


- (void)downloadShopImageForKey:(NSString *)key
                       progressBlock:(void(^)(CGFloat progress))progressBlock
                     completionBlock:(void(^)(NSError *error, NSData *fileData))completionBlock;

/**
 *  This method helps checking which downloads are currently ongoing.
 *
 *  @return an NSArray of NSString with the URLs of the currently downloading files.
 */
- (NSArray *)currentDownloads;

@end
