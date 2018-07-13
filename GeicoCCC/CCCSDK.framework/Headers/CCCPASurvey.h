//
//  CCCSurvey.h
//  CCCSDK
//
//  Created by Animax Deng on 10/10/16.
//  Copyright © 2016 CCC. All rights reserved.
//

#import <Foundation/Foundation.h>


/**
 Survey answer option model
 */
@interface CCCSurveyOption : NSObject

/**
 Option ID Key
 */
@property (strong, nonatomic) NSString *optionKey;

/**
 Option String
 */
@property (strong, nonatomic) NSString *option;

/**
 Mark it's the answer for the survey
 */
@property (nonatomic) BOOL selectedAsAnswer;

@end

/**
 Survey serivce module
 */
@interface CCCPASurvey : NSObject

/**
 Question ID key
 */
@property (strong, nonatomic) NSString *questionKey;

/**
 Question String
 */
@property (strong, nonatomic) NSString *question;

/**
 Question options
 */
@property (strong, nonatomic) NSArray<CCCSurveyOption *> *options;

// dynamic function

/**
 Get/Set Survey answer.
 When set answer: if the answer object is not in the option list then it will set to no answer for this question;
 When get answer: if not answer for this question, it returns nil
 */
@property (assign, nonatomic) CCCSurveyOption* answer;

/**
 Get/Set Survey answer base on index
 */
@property (assign, nonatomic) NSInteger answerAtIndex;


/**
 Fetch survey questions

 @param completionHandler Completed callback with Survey objects
 */
+ (void)getSurveyWithCompletion:(void(^)(NSArray<CCCPASurvey *> *, NSError *error))completionHandler;


/**
 Post Survey answers

 @param surveies       Survey object with answers
 @param completedBlock Completed callback with indicate for displaying estimate
 */
+ (void)postSurvey:(NSArray<CCCPASurvey *> *)surveies completed:(void(^)(BOOL show, NSError *error))completedBlock;

@end
