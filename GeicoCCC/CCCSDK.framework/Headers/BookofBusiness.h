//
//  BookofBusiness.h
//  CCCSDK
//
//  Created by Viggnesh Kandasamy on 2/20/17.
//  Copyright © 2017 CCC. All rights reserved.
//

#import "JSONModel.h"
typedef enum 
{
    /**bookofBusiness_S – Standard*/
    bookofBusiness_S,
    /**bookofBusiness_NonStandard – Non-Standard*/
    bookofBusiness_N,
    /**bookofBusiness_None - None*/
    bookofBusiness_None
}BookofBusinessEnum;
@interface BookofBusiness : JSONModel
@property (assign, nonatomic) BookofBusinessEnum bookofBusinessEnum;
@property (strong, nonatomic, readonly) NSString *code;

@end
