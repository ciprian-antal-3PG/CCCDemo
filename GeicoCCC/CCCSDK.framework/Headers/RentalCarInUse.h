//
//  RentalCarInUse.h
//  CCCSDK
//
//  Created by Viggnesh Kandasamy on 2/16/17.
//  Copyright © 2017 CCC. All rights reserved.
//

#import "JSONModel.h"

typedef enum {
    /**YES*/
    RentalCarInUseYes,
    /**NO*/
    RentalCarInUseNo,
    /**Unknown*/
    RentalCarInUseUnknown
}RentalCarInUseEnum;

@interface RentalCarInUse : JSONModel
@property (assign, nonatomic) RentalCarInUseEnum rentalCarInUseEnum;
@property (strong, nonatomic, readonly) NSString *code;

@end
