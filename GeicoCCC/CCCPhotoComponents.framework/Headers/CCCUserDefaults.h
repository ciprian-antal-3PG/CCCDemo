//
//  CCCUserDefaults.h
//  Safeco_Express_Estimate
//
//  Created by Sudhin on 11/10/17.
//  Copyright © 2017 CCCIS. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface CCCUserDefaults : NSObject
+ (void)setObject:(id _Nullable )object forKey:(NSString *_Nullable)key;
+ (id _Nullable )objectForKey:(NSString *_Nullable)key;
+ (BOOL)removeObjectForkey :(NSString *_Nullable)key;
+ (void)setBool:(BOOL)object forKey:(NSString *_Nullable)key;
+ (BOOL)boolForKey:(NSString *_Nullable) key;
+ (void)setObject:(id _Nullable )value forKey:(NSString *_Nonnull)defaultName claimID:(NSString*_Nullable)claimID;
+ (nullable id)objectForKey:(NSString *_Nullable)defaultName claimID:(NSString*_Nullable)claimID;
+ (void)removeObjectForKey:(NSString *_Nullable)defaultName claimID:(NSString*_Nullable)claimID;
+ (void)setInteger:(NSInteger)value forKey:(NSString *_Nullable)defaultName claimID:(NSString*_Nullable)claimID;
+ (NSInteger)integerForKey:(NSString *_Nullable)defaultName claimID:(NSString*_Nullable)claimID;
+ (void)setFloat:(float)value forKey:(NSString *_Nullable)defaultName claimID:(NSString*_Nullable)claimID;
+ (float)floatForKey:(NSString *_Nullable)defaultName claimID:(NSString*_Nullable)claimID;
+ (void)setDouble:(double)value forKey:(NSString *_Nullable)defaultName claimID:(NSString*_Nullable)claimID;
+ (double)doubleForKey:(NSString *_Nullable)defaultName claimID:(NSString*_Nullable)claimID;
+ (void)setBool:(BOOL)value forKey:(NSString *_Nullable)defaultName claimID:(NSString*_Nullable)claimID;
+ (BOOL)boolForKey:(NSString *_Nullable)defaultName claimID:(NSString*_Nullable)claimID;
+ (NSMutableDictionary*_Nullable)getAllClaimsDictionary;
+ (void)clearUserDefaultsForClaimID:(NSString*_Nullable)claimID;
@end
