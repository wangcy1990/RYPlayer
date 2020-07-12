//
//  RYVRPlayerManager.h
//  RYPlayer
//
//  Created by wangcy on 2019/6/21.
//  Copyright © 2019 dayang. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "RYPlayerMediaPlayback.h"
#import <AVFoundation/AVFoundation.h>
#import "RYVRPlayer.h"


@interface RYVRPlayerManager : NSObject<RYPlayerMediaPlayback>


@property (nonatomic, strong) RYVRPlayer *player;


- (instancetype)initWithDecoderType:(int)decoderType;

-(void)changeVRType:(BOOL)isVR;


@end

