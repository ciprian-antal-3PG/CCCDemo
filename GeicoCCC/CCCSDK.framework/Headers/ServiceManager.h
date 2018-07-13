//
//  ServiceManager.h
//  CCCSDK
//
//  Created by Viggnesh K on 4/14/15.
//  Copyright (c) 2015 cccis. All rights reserved.
//

#import <Foundation/Foundation.h>

typedef NS_ENUM (NSInteger, CCCNetworkRequestMethod) {
	CCCNetwork_GET= 0,
	CCCNetwork_POST,
	CCCNetwork_PUT,
	CCCNetwork_PATCH,
	CCCNetwork_DELETE,
};

typedef NS_ENUM (NSInteger, CCCServerContractType) {
    CCCServerContract_Default = 0,
    CCCServerContract_PhotoAnalysis,
    CCCServerContract_TvR,
};

typedef void (^CCCNetworkCompletionBlock) (id data, NSError *error);
typedef void (^CCCNetworkProgressBlock) (float progress, NSInteger bytesTransferred, NSInteger totalBytes);

@interface ServiceManager : NSObject

/**
 *  Share instance for config base params;
 *
 *  @return ServiceManager
 */
+ (ServiceManager *)shareInstance;

@property (nonatomic) BOOL isRecordingNetworkLog;
@property (nonatomic) double requestTimeout;
@property (nonatomic) CCCServerContractType contractType;

/**
 *  Service call - synchronization
 *
 *  @param restType  HTTP type: GET, POST, PUT, PATCH, DELETE
 *  @param urlModule Command module, e.g. @[@"api_portal",@"identity_token"]
 *  @param urlParams Url params: it will always come with the URL
 *  @param hander    Header Dicitionary
 *  @param params
 *  @param encrypt   Do encrypt data or not
 *  @return NSDictionary or NSArray, depend on the return data
 */
+ (id)composeRequestToCall:(CCCNetworkRequestMethod)restType
                 urlModule:(NSArray *)urlModule
                 urlParams:(NSDictionary<NSString *, NSString*> *)urlParams
                   headers:(NSDictionary *)headers
                    params:(id)params
                   encrypt:(BOOL)encrypt;

/**
 *  Service call - synchronization
 *
 *  @param restType  HTTP type: GET, POST, PUT, PATCH, DELETE
 *  @param urlModule Command module, e.g. @[@"api_portal",@"identity_token"]
 *  @param hander    Header Dicitionary
 *  @param params
 *  @param encrypt   Do encrypt data or not
 *  @return NSDictionary or NSArray, depend on the return data
 */
+ (id)composeRequestToCall:(CCCNetworkRequestMethod)restType
                 urlModule:(NSArray *)urlModule
                   headers:(NSDictionary *)headers
                    params:(id)params
                   encrypt:(BOOL)encrypt;

/**
 *  Service call - synchronization
 *
 *  @param restType  HTTP type: GET, POST, PUT, PATCH, DELETE
 *  @param urlModule Command module, e.g. @[@"api_portal",@"identity_token"]
 *  @param urlParams Url params: it will always come with the URL
 *  @param hander    Header Dicitionary
 *  @param params
 *
 *  @return NSDictionary or NSArray, depend on the return data
 */
+ (id)composeRequestToCall:(CCCNetworkRequestMethod)restType
                 urlModule:(NSArray *)urlModule
                 urlParams:(NSDictionary<NSString *, NSString*> *)urlParams
                   headers:(NSDictionary *)headers
                    params:(id)params;
/**
*  Service call - synchronization
*
*  @param restType  HTTP type: GET, POST, PUT, PATCH, DELETE
*  @param urlModule Command module, e.g. @[@"api_portal",@"identity_token"]
*  @param hander    Header Dicitionary
*  @param params
*
*  @return NSDictionary or NSArray, depend on the return data
*/
+ (id)composeRequestToCall:(CCCNetworkRequestMethod)restType
                 urlModule:(NSArray *)urlModule
                   headers:(NSDictionary *)headers
                    params:(id)params;

/**
 *  Service call - synchronization
 *
 *  @param restType  HTTP type: GET, POST, PUT, PATCH, DELETE
 *  @param urlModule Command module, e.g. @[@"api_portal",@"identity_token"]
 *  @param params
 *
 *  @return NSDictionary or NSArray, depend on the return data
 */
+ (id)composeRequestToCall:(CCCNetworkRequestMethod)restType
                 urlModule:(NSArray *)urlModule
                    params:(id)params;


/**
 *  Service call - asynchronization
 *
 *  @param restType  HTTP type: GET, POST, PUT, PATCH, DELETE
 *  @param urlModule Command module, e.g. @[@"api_portal",@"identity_token"]
 *  @param urlParams Url params: it will always come with the URL
 *  @param hander    Header Dicitionary
 *  @param paramDic
 *  @param encrypt   Do encrypt data or not
 *  @param block     Completion block included data(NSDictionary or NSArray) and nonable NSError
 */
+ (void)composeRequestToCall:(CCCNetworkRequestMethod)restType
                   urlModule:(NSArray<NSString *> *)urlModule
                   urlParams:(NSDictionary<NSString *, NSString*> *)urlParams
                     headers:(NSDictionary *)headers
                      params:(id)paramDic
                     encrypt:(BOOL)encrypt
             completionBlock:(CCCNetworkCompletionBlock)block;

/**
 *  Service call - asynchronization
 *
 *  @param restType  HTTP type: GET, POST, PUT, PATCH, DELETE
 *  @param urlModule Command module, e.g. @[@"api_portal",@"identity_token"]
 *  @param hander    Header Dicitionary
 *  @param paramDic
 *  @param encrypt   Do encrypt data or not
 *  @param block     Completion block included data(NSDictionary or NSArray) and nonable NSError
 */
+ (void)composeRequestToCall:(CCCNetworkRequestMethod)restType
                   urlModule:(NSArray<NSString *> *)urlModule
                     headers:(NSDictionary *)headers
                      params:(id)paramDic
                     encrypt:(BOOL)encrypt
             completionBlock:(CCCNetworkCompletionBlock)block;

/**
 *  Service call - asynchronization
 *
 *  @param restType  HTTP type: GET, POST, PUT, PATCH, DELETE
 *  @param urlModule Command module, e.g. @[@"api_portal",@"identity_token"]
 *  @param urlParams Url params: it will always come with the URL
 *  @param hander    Header Dicitionary
 *  @param paramDic
 *  @param encrypt   Do encrypt data or not
 *  @param block     Completion block included data(NSDictionary or NSArray) and nonable NSError
 */
+ (void)composeRequestToCall:(CCCNetworkRequestMethod)restType
                   urlModule:(NSArray *)urlModule
                   urlParams:(NSDictionary<NSString *, NSString*> *)urlParams
                     headers:(NSDictionary *)headers
                      params:(id)paramDic
             completionBlock:(CCCNetworkCompletionBlock)block;

/**
 *  Service call - asynchronization
 *
 *  @param restType  HTTP type: GET, POST, PUT, PATCH, DELETE
 *  @param urlModule Command module, e.g. @[@"api_portal",@"identity_token"]
 *  @param hander    Header Dicitionary
 *  @param paramDic
 *  @param block     Completion block included data(NSDictionary or NSArray) and nonable NSError
 */
+ (void)composeRequestToCall:(CCCNetworkRequestMethod)restType
                   urlModule:(NSArray *)urlModule
                     headers:(NSDictionary *)headers
                      params:(id)paramDic
             completionBlock:(CCCNetworkCompletionBlock)block;

/**
 *  Service call - asynchronization
 *
 *  @param restType  HTTP type: GET, POST, PUT, PATCH, DELETE
 *  @param urlModule Command module, e.g. @[@"api_portal",@"identity_token"]
 *  @param paramDic
 *  @param block     Completion block included data(NSDictionary or NSArray) and nonable NSError
 */
+ (void)composeRequestToCall:(CCCNetworkRequestMethod)restType
                   urlModule:(NSArray *)urlModule
                      params:(id)paramDic
             completionBlock:(CCCNetworkCompletionBlock)block;

/**
 *  File upload - asynchronization
 *
 *  @param imagePath       Path of uploading image
 *  @param fileFieldName   Field name of file
 *  @param fileFullname    fulle name, e.g. abc.jpg
 *  @param urlModule       Command module, e.g. @[@"api_portal",@"identity_token"]
 *  @param hander          Header Dicitionary
 *  @param params
 *  @param encrypt         Do encrypt data or not
 *  @param completionBlock Completion block included data(NSDictionary or NSArray) and nonable NSError
 *  @param progessBlock    Upload progress block
 */
+ (void)composeRequestToCallUpload:(NSData *)file
                     fileFieldName:(NSString *)fileFieldName
                      fileFullname:(NSString *)fullname
                         urlModule:(NSArray *)urlModule
                         urlParams:(NSDictionary *)urlParams
                           headers:(NSDictionary *)headers
                            params:(id)params
                           encrypt:(BOOL)encrypt
                   completionBlock:(CCCNetworkCompletionBlock)completionBlock
                     progressBlock:(CCCNetworkProgressBlock)progessBlock;
/**
 *  File upload - asynchronization
 *
 *  @param imagePath       Path of uploading image
 *  @param fileFullname    fulle name, e.g. abc.jpg
 *  @param urlModule       Command module, e.g. @[@"api_portal",@"identity_token"]
 *  @param hander          Header Dicitionary
 *  @param params
 *  @param encrypt         Do encrypt data or not
 *  @param completionBlock Completion block included data(NSDictionary or NSArray) and nonable NSError
 *  @param progessBlock    Upload progress block
 */
+ (void)composeRequestToCallUpload:(NSData *)file
                      fileFullname:(NSString *)fullname
                         urlModule:(NSArray *)urlModule
                         urlParams:(NSDictionary *)urlParams
                           headers:(NSDictionary *)headers
                            params:(id)params
                           encrypt:(BOOL)encrypt
                   completionBlock:(CCCNetworkCompletionBlock)completionBlock
                     progressBlock:(CCCNetworkProgressBlock)progessBlock;

/**
 *  File upload - asynchronization
 *
 *  @param imagePath       Path of uploading image
 *  @param fileFullname    fulle name, e.g. abc.jpg
 *  @param urlModule       Command module, e.g. @[@"api_portal",@"identity_token"]
 *  @param hander          Header Dicitionary
 *  @param params
 *  @param completionBlock Completion block included data(NSDictionary or NSArray) and nonable NSError
 *  @param progessBlock    Upload progress block
 */
+ (void)composeRequestToCallUpload:(NSData *)file
                      fileFullname:(NSString *)fullname
                         urlModule:(NSArray *)urlModule
                           headers:(NSDictionary *)headers
                            params:(id)params
                   completionBlock:(CCCNetworkCompletionBlock)completionBlock
                     progressBlock:(CCCNetworkProgressBlock)progessBlock;

/**
 *  File upload - asynchronization
 *
 *  @param imagePath       Path of uploading image
 *  @param fileFullname    fulle name, e.g. abc.jpg
 *  @param urlModule       Command module, e.g. @[@"api_portal",@"identity_token"]
 *  @param params
 *  @param completionBlock Completion block included data(NSDictionary or NSArray) and nonable NSError
 *  @param progessBlock    Upload progress block
 */
+ (void)composeRequestToCallUpload:(NSData *)file
                      fileFullname:(NSString *)fullname
                         urlModule:(NSArray *)urlModule
                            params:(id)params
                   completionBlock:(CCCNetworkCompletionBlock)completionBlock
                     progressBlock:(CCCNetworkProgressBlock)progessBlock;

+ (id)parseJSONData:(NSData *)responseData module:(NSObject *)module status:(NSInteger)status;

+ (NSMutableURLRequest *)makeFileUploadRequest:(NSData *)file
                                      fileName:(NSString *)filename
                                      mimetype:(NSString *)mimetype
                                     urlModule:(NSArray *)urlModule
                                     urlParams:(NSDictionary *)urlParams
                                       headers:(NSDictionary *)headers
                                        params:(id)paramDic
                                       encrypt:(BOOL)encrypt;

+ (NSMutableURLRequest *)makeFileUploadRequest1:(NSData *)file
                                      fileName:(NSString *)filename
                                      mimetype:(NSString *)mimetype
                                     urlModule:(NSArray *)urlModule
                                       headers:(NSDictionary *)headers
                                        params:(id)paramDic
                                       encrypt:(BOOL)encrypt;


+ (NSMutableURLRequest *)makeFileDownloadRequestWithURLModule:(NSArray *)urlModule
                                       urlParams:(NSDictionary *)urlParams
                                         headers:(NSDictionary *)headers
                                          params:(id)paramDic;

@end
