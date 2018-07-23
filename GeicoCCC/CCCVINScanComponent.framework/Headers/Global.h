//
//  Global.h
//  Component_PhotoCapture
//
//  Created by Viggnesh K on 2/6/15.
//  Copyright (c) 2015 wsm. All rights reserved.
//

#ifndef Component_PhotoCapture_Global_h
#define Component_PhotoCapture_Global_h
//#import "AppDelegate.h"

#define PRIMARY_COLOR [UIColor colorWithRed:255.0f/255.0f green:173.0f/255.0f blue:0.0f/255.0f alpha:1.0f]
#define CarouselFont [UIFont fontWithName:@"AvenirNext-Bold" size:16]

#define BUTTON_TEXT_COLOR [UIColor colorWithRed:23.0f/255.0f green:42.0f/255.0f blue:97.0f/255.0f alpha:1.0f]

#define BG_GRADIENT_FROM [UIColor colorWithRed:222.0f/255.0f green:228.0f/255.0f blue:212.0f/255.0f alpha:1.0f]
#define BG_GRADIENT_TO [UIColor colorWithRed:128.0f/255.0f green:147.0f/255.0f blue:156.0f/255.0f alpha:1.0f]


#define BTN_GRADIENT_NORMAL_FROM [UIColor colorWithRed:23.0f/255.0f green:42.0f/255.0f blue:97.0f/255.0f alpha:1.0f]
#define BTN_GRADIENT_NORMAL_TO [UIColor colorWithRed:23.0f/255.0f green:42.0f/255.0f blue:97.0f/255.0f alpha:1.0f]

#define BTN_GRADIENT_HIGHLIGHTED_FROM [UIColor colorWithRed:23.0f/255.0f green:42.0f/255.0f blue:97.0f/255.0f alpha:1.0f]
#define BTN_GRADIENT_HIGHLIGHTED_TO [UIColor colorWithRed:23.0f/255.0f green:42.0f/255.0f blue:97.0f/255.0f alpha:1.0f]

#define APP_DELEGATE ((AppDelegate *)[UIApplication sharedApplication].delegate)

#define UICOLOR_FROM_RGB(rgbValue) [UIColor colorWithRed:((float)((rgbValue & 0xFF0000) >> 16))/255.0 green:((float)((rgbValue & 0xFF00) >> 8))/255.0 blue:((float)(rgbValue & 0xFF))/255.0 alpha:1.0]

#define UICOLOR_VALUES_FROM_RGB(rgbValue) ((float)((rgbValue & 0xFF0000) >> 16))/255.0, ((float)((rgbValue & 0xFF00) >> 8))/255.0, ((float)(rgbValue & 0xFF))/255.0, 1.0



#define BTN_TYPE1_NORMAL_GRADIENT_TOP UICOLOR_VALUES_FROM_RGB(0xecbd91)
#define BTN_TYPE1_NORMAL_GRADIENT_BOTTOM UICOLOR_VALUES_FROM_RGB(0xdd8739)

#define BTN_TYPE1_HIGHLIGHTED_GRADIENT_TOP UICOLOR_VALUES_FROM_RGB(0xdd8739)
#define BTN_TYPE1_HIGHLIGHTED_GRADIENT_BOTTOM UICOLOR_VALUES_FROM_RGB(0xecbd91)

#define BTN_TYPE_NORMAL_STROKE UICOLOR_FROM_RGB(0xd97a23)

#define BTN_TYPE2_NORMAL_GRADIENT_TOP UICOLOR_VALUES_FROM_RGB(0xffffff)
#define BTN_TYPE2_NORMAL_GRADIENT_BOTTOM UICOLOR_VALUES_FROM_RGB(0xc0c0c1)

#define BTN_TYPE2_HIGHLIGHTED_GRADIENT_TOP UICOLOR_VALUES_FROM_RGB(0xc0c0c1)
#define BTN_TYPE2_HIGHLIGHTED_GRADIENT_BOTTOM UICOLOR_VALUES_FROM_RGB(0xffffff)


#define BTN_TYPE_DISABLED_GRADIENT_TOP UICOLOR_VALUES_FROM_RGB(0xffffff)
#define BTN_TYPE_DISABLED_GRADIENT_BOTTOM UICOLOR_VALUES_FROM_RGB(0xc1c1c2)

#define BTN_TYPE_DISABLED_STROKE UICOLOR_FROM_RGB(0xd8d8d9)



#define NAVIGATIONBAR_COLOR [UIColor colorWithRed:246.0f/255.0f green:246.0f/255.0f blue:246.0f/255.0f alpha:1.0f]

#define TEXT_COLOR [UIColor colorWithRed:97.0f/255.0f green:98.0f/255.0f blue:101.0f/255.0f alpha:1.0f]

#define NAV_TITLE_IMAGE  @"nav_logo"
#define NAV_SHARE_IMAGE  @"nav_btn_share"
#define NAV_BACK_IMAGE   @"nav_btn_back"

#define STORYBOARD_NAME @"Main"


#define PHOTOS_MODEL_CURRENT_CLAIM_ID               @"1234567890"


#define SAFECO_AGENT_PHONE  @"844-222-3203"

//#define DatabaseName @"safeco"
#define DatabaseName @"safeco"
#define DAMAGE_DESCRIPTION_LIMIT 250

#define TEXTFIELD_LIMIT 25


#define NOT_ENOUGH_FREE_SPACE_EXCEPTION @"NotEnoughFreeSpaceException"

#define APP_ID_KEYCHAIN  [[[NSBundle mainBundle] infoDictionary] objectForKey:@"CFBundleIdentifier"]

//####################################### MESSAGE STARTS #######################################################################


#define COULD_NOT_SIGN_IN_MESSAGE_TITLE @"Could Not Sign In"
#define COULD_NOT_SIGN_IN_MESSAGE_SUBTITLE @"The information you entered was not found in our system. Please try again."

#define UNABLE_TO_COMPLETE_REQUEST_TITLE @"Unable to Complete Request"
#define UNABLE_TO_COMPLETE_REQUEST_SUBTITLE @"We were unable to process your reqest at this time. Please try again."

#define STORAGE_FULL_ALERT_TITLE @"Not Enough Storage"
#define STORAGE_FULL_ALERT_SUBTITLE @"Please free up space on your device to be able to take photos."

#define UNABLE_TO_UPLOAD_TITLE @"Unable to upload!"
#define UNABLE_TO_UPLOAD_SUBTITLE @"Unable to upload the images due to network issues. Check your internet connection and retry"


#define NO_INTERNET_TITLE @"Internet Connection Unavailable"
#define NO_INTERNET_SUBTITLE @"Please connect to the Internet to complete this action."

#define UNABLE_TO_REACH_SERVER_TITLE @"Unable to Complete Request"
#define UNABLE_TO_REACH_SERVER_SUBTITLE @"We were unable to process your request at this time.  Please try again."

#define REDIRECT_TO_SETTINGS_TITLE @"Allow Permissions to Continue"
#define REDIRECT_TO_SETTINGS_SUBTITLE @"Please go to Settings and enable the Location and Camera permissions for Express Estimate to continue."



//###################################################### MESSAGE ENDS ############################################################################################################



//###################################################### CALL SAFECO ALERT MESSAGES STARTS #######################################################################################

#define CLAIM_NUMBER_HELP_MESSAGE @"Don't Have a Claim Number?"
#define CLAIM_NUMBER_HELP_SUBMESSAGE [NSString stringWithFormat:@"Please contact a Safeco agent at %@ to obtain one.",SAFECO_AGENT_PHONE]
#define SAFECO_CONTACT_AGENT_MESSAGE [NSString stringWithFormat:@"Feel free to call %@ if you have any further questions.",SAFECO_AGENT_PHONE]

//###################################################### CALL SAFECO ALERT MESSAGES STARTS #######################################################################################

#define CCC_PHOTO_CAPTURE_HELP_THUMBNAIL                        @"nav_btn_help"



#define PERSIST_LOGIN_DATE_KEY @"loginDate"
#define PERSIST_LOGIN_STATE_KEY @"loggedIn"
#define PERSIST_CLAIM_KEYCHAIN_KEY @"claimId"
#define PERSIST_LAST_NAME_KEYCHAIN_KEY @"lastName"
#define PERSIST_IMAGE_SET_KEY @"imageSet"
#define PERSIST_INSURANCE_COMPANY_CODE_KEY @"insuranceCompanyCode"

#define TEST_LOGIN_CREDENTIALS_PLIST_FILE_NAME @"TestLoginCredentials"

#define SESSION_TIMEOUT_DURATION 7


enum {
    UserNotLoggedIn = 0,
    UserLoggedIn = 1
};
typedef NSNumber * UserLoginStatus;



#define TERMS_LINK @"http://www.safeco.com/terms-and-conditions"
#define PRIVACY_LINK @"http://www.safeco.com/privacy-policy"
#define SECURITY_LINK @"http://www.libertymutualgroup.com/omapps/ContentServer?pagename=LMGroup/Views/lmgDisclosure&cid=1240002784964"


#define TERMS_TEXT @"Terms"
#define PRIVACY_TEXT @"Privacy"
#define SECURITY_TEXT @"Security"

#define PHOTOS_SUBMITTED_TEXT @"Your photos have been submitted.  A Safeco Appraiser will be in contact to review and discuss your estimate within one business day. Once the estimate is completed you will be able to view and download your estimate through this application.  Thank you for using Safeco Insurance Express Estimate."


static NSString *reviewVCIdentifier = @"reviewPhotoIdentifier";
//static NSString *reviewVCIdentifier = @"reviewPhotoIdentifier";

static NSString *loginVCIdentifier = @"loginIdentifier";
static NSString *dashVCIdentifier = @"dashIdentifier";
static NSString *dashStoryboardIdentifier = @"dashStoryboardIdentifier";
static NSString *PermissionVCIdentifier = @"PermissionScreenIdentifier";
static NSString *estimatePDFVCIdentifier = @"estimatepdfIdentifier";




#endif
