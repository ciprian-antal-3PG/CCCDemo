//
//  PersistManager.h
//  CCCSDK
//
//  Created by Viggnesh K on 4/20/15.
//  Copyright (c) 2015 cccis. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface PersistManager : NSObject

+ (id)loadCustomObjectWithKey:(NSString *)key;
+ (void)saveCustomObject:(id)object key:(NSString *)key;


+ (void)saveInKeychain:(id)object key:(NSString *)key;
+ (id)fetchFromKeychainKey:(NSString *)key;
+ (BOOL)deleteFromKeychain:(NSString *)key;


+ (void)saveInUserDefaults:(id)object key:(NSString *)key;
+ (id)fetchFromUserDefaultsKey:(NSString *)key;
+ (BOOL)deleteFromUserDefaults:(NSString *)key;


+ (void)saveBoolInUserDefaults:(BOOL)object key:(NSString *)key;
+ (BOOL)fetchBoolFromUserDefaultsKey:(NSString *)key;


@end
