//
//  CCCConstants.h
//  CCCSDK
//
//  Created by Viggnesh Kandasamy on 8/11/15.
//  Copyright (c) 2015 CCC. All rights reserved.
//

#import <Foundation/Foundation.h>


//#if TARGET_OS_IPHONE
//#import "CCCNullability.h"
#import "CCCSDK.h"

#define SDK_VERSION @"2.0.0"

//#define SERVER_DEFAULT @"http://PA1002-B2B-641672267.us-east-1.elb.amazonaws.com:80/"                 //INT
//#define SERVER_DEFAULT @"http://photo-analytics-elb-107922493.us-west-2.elb.amazonaws.com/"           //DEV
#define SERVER_DEFAULT @"http://PA1001-B2B-105291213.us-east-1.elb.amazonaws.com:80/"                 //QA
//#define SERVER_DEFAULT @"http://msdk2001-ingest-1881743973.us-east-1.elb.amazonaws.com:8080/" // Business Events
//#define SERVER_DEFAULT @"http://msdk2001-ingest-1881743973.us-east-1.elb.amazonaws.com:9000"


@interface CCCConstants : NSObject

+ (NSString *) RetrieveServerDefaults;
+ (void) setServerDefaults:(NSString *) urlString;

@end
