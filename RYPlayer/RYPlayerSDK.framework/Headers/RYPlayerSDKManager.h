//
//  RYPlayerSDK.h
//  RYPlayer
//
//  Created by wangcy on 2020/7/9.
//  Copyright © 2020 dayang. All rights reserved.
//

#import <Foundation/Foundation.h>


@interface RYPlayerSDKManager : NSObject


+(RYPlayerSDKManager*)shareRYPlayerSDKManager;

-(BOOL)setLicence:(NSString *)lisence;

-(void)setMsgReportOn:(BOOL)on;

@end

