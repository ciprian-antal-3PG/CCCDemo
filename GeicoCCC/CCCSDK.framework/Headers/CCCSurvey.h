//
//  CCCSurvey.h
//  CCCSDK
//
//  Created by bkongara on 3/3/17.
//  Copyright © 2017 CCC. All rights reserved.
//

#import <Foundation/Foundation.h>


typedef enum {
    SLIDER,
    DROPDOWN,
    TEXT,
}QuestionType;


@interface CCCSurveyResponseModel : NSObject

@property (nonatomic) NSInteger questionId;
@property (nonatomic) NSInteger answerId;

@end

@interface CCCSurveyQuestionOptionsModel : NSObject

@property (nonatomic) NSInteger  answerId;
@property (nonatomic) NSInteger  scale;
@property (strong, nonatomic) NSString *  _Nonnull answer;

+ (CCCSurveyQuestionOptionsModel * _Nonnull) createCCCSurveyQuestionOptionsModel:(NSDictionary * _Nonnull) eachQuestionOptionsDict;


@end

@interface CCCSurveyQuestionModel : NSObject

@property (nonatomic) NSInteger  questionId;
@property (strong, nonatomic) NSString *  _Nonnull question;
@property (strong, nonatomic) NSArray <CCCSurveyQuestionOptionsModel *> *  _Nonnull answerOptions;
@property (strong, nonatomic) NSString *  _Nonnull questionType;
@property (strong, nonatomic) NSString * _Nullable freeTextAnswer;

@property (strong, nonatomic) CCCSurveyQuestionOptionsModel * _Nonnull selectedAnswer;

+ (CCCSurveyQuestionModel * _Nonnull) createCCCSurveyQuestionModel:(NSDictionary *  _Nonnull) eachQuestionDict;
//-(void) setQuestionType: (CCCSurveyQuestionModel *_Nullable) questionModel usingString:  (NSString *_Nullable) questionType;

@end


typedef void  (^getSurveyCompleted)(NSArray<CCCSurveyQuestionModel *> * __nullable surveyQuestions, BOOL isCommentsAllowed, NSError * __nullable error);

typedef void  (^postSurveyCompleted)(id _Nullable data, NSError * __nullable error);

@interface CCCSurvey : NSObject


+(void) getSurveyQuestions:(NSString * _Nonnull) surveyType completedBlock:(getSurveyCompleted __nullable) completedBlock;
+(void) getSurveyQuestions:(NSString * _Nonnull) surveyType withSession:(NSString * _Nonnull) sessionID completedBlock:(getSurveyCompleted __nullable) completedBlock;
+(void) postSurvey:(NSString * _Nonnull) surveyType withResponses: (NSMutableArray * _Nonnull) responses additionalComments: (NSString * __nullable ) comments  completedBlock:(postSurveyCompleted __nullable) completedBlock;
+(void) postSurvey:(NSString * _Nonnull) surveyType withSession:(NSString * _Nonnull) sessionID withResponses: (NSMutableArray * _Nonnull) responses additionalComments: (NSString * __nullable ) comments  completedBlock:(postSurveyCompleted __nullable) completedBlock;

@end



