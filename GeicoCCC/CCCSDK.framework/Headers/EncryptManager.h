//
//  EncryptManager.h
//  CCCSDK
//
//  Created by Animax Deng on 9/1/16.
//  Copyright © 2016 CCC. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface EncryptManager : NSObject

+ (NSString *)encryptAES128:(NSString *)content key:(NSString *)key;
+ (NSString *)encryptSHA256withRSA:(NSString *)content privateKey:(NSString *)key;

@end
