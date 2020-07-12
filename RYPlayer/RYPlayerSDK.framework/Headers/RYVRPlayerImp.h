//
//  RYVRPlayer.h
//  RYVRPlayer
//
//  Created by Single on 16/6/28.
//  Copyright © 2016年 single. All rights reserved.
//

#import "RYVRPlatform.h"
#import "RYVRPlayerTrack.h"
#import "RYVRPlayerDecoder.h"

// video type
typedef NS_ENUM(NSUInteger, SGVideoType) {
    SGVideoTypeNormal,  // normal
    SGVideoTypeVR,      // virtual reality
};

// player state
typedef NS_ENUM(NSUInteger, RYVRPlayerState) {
    RYVRPlayerStateNone = 0,          // none
    RYVRPlayerStateBuffering = 1,     // buffering
    RYVRPlayerStateReadyToPlay = 2,   // ready to play
    RYVRPlayerStatePlaying = 3,       // playing
    RYVRPlayerStateSuspend = 4,       // pause
    RYVRPlayerStateFinished = 5,      // finished
    RYVRPlayerStateFailed = 6,        // failed
};

// display mode
typedef NS_ENUM(NSUInteger, SGDisplayMode) {
    SGDisplayModeNormal,    // default
    SGDisplayModeBox,
};

// video content mode
typedef NS_ENUM(NSUInteger, SGGravityMode) {
    SGGravityModeResize,
    SGGravityModeResizeAspect,
    SGGravityModeResizeAspectFill,
};

// background mode
typedef NS_ENUM(NSUInteger, RYVRPlayerBackgroundMode) {
    RYVRPlayerBackgroundModeNothing,
    RYVRPlayerBackgroundModeAutoPlayAndPause,     // default
    RYVRPlayerBackgroundModeContinue,
};


#pragma mark - RYVRPlayer

@class SGError;

NS_ASSUME_NONNULL_BEGIN

@interface RYVRPlayer : NSObject

+ (instancetype)new NS_UNAVAILABLE;
- (instancetype)init NS_UNAVAILABLE;

+ (instancetype)player;

@property (nonatomic, strong) RYVRPlayerDecoder * decoder;      // default is [RYVRPlayerDecoder defaultDecoder]

@property (nonatomic, copy, readonly) NSURL * contentURL;
@property (nonatomic, assign, readonly) SGVideoType videoType;

@property (nonatomic, strong, readonly, nullable) SGError * error;

- (void)replaceVideoWithURL:(nullable NSURL *)contentURL;
- (void)replaceVideoWithURL:(nullable NSURL *)contentURL videoType:(SGVideoType)videoType;

// preview
@property (nonatomic, assign) SGDisplayMode displayMode;
@property (nonatomic, strong, readonly) RYVRPLFView * view;      // graphics view
@property (nonatomic, assign) BOOL viewAnimationHidden;     // default is YES;
@property (nonatomic, assign) SGGravityMode viewGravityMode;       // default is SGGravityModeResizeAspect;
@property (nonatomic, copy) void (^viewTapAction)(RYVRPlayer * player, RYVRPLFView * view);
- (RYVRPLFImage *)snapshot;
//旋转画面
-(void)rotationWithX:(double)x andY:(double)y;

// control
@property (nonatomic, assign, readonly) RYVRPlayerState state;
@property (nonatomic, assign, readonly) CGSize presentationSize;
@property (nonatomic, assign, readonly) NSTimeInterval bitrate;
@property (nonatomic, assign, readonly) NSTimeInterval progress;
@property (nonatomic, assign, readonly) NSTimeInterval duration;
@property (nonatomic, assign, readonly) NSTimeInterval playableTime;

@property (nonatomic, assign) RYVRPlayerBackgroundMode backgroundMode;    // background mode
@property (nonatomic, assign) NSTimeInterval playableBufferInterval;    // default is 2s
@property (nonatomic, assign) CGFloat volume;       // default is 1

- (void)play;
- (void)pause;
- (void)stop;

@property (nonatomic, assign, readonly) BOOL seekEnable;
@property (nonatomic, assign, readonly) BOOL seeking;
- (void)seekToTime:(NSTimeInterval)time;
- (void)seekToTime:(NSTimeInterval)time completeHandler:(nullable void(^)(BOOL finished))completeHandler;

@end


#pragma mark - Tracks Category

@interface RYVRPlayer (Tracks)

@property (nonatomic, assign, readonly) BOOL videoEnable;
@property (nonatomic, assign, readonly) BOOL audioEnable;

@property (nonatomic, strong, readonly) RYVRPlayerTrack * videoTrack;
@property (nonatomic, strong, readonly) RYVRPlayerTrack * audioTrack;

@property (nonatomic, strong, readonly) NSArray <RYVRPlayerTrack *> * videoTracks;
@property (nonatomic, strong, readonly) NSArray <RYVRPlayerTrack *> * audioTracks;

- (void)selectAudioTrack:(RYVRPlayerTrack *)audioTrack;
- (void)selectAudioTrackIndex:(int)audioTrackIndex;

@end


#pragma mark - Thread Category

@interface RYVRPlayer (Thread)

@property (nonatomic, assign, readonly) BOOL videoDecodeOnMainThread;
@property (nonatomic, assign, readonly) BOOL audioDecodeOnMainThread;

@end

NS_ASSUME_NONNULL_END

#import "RYVRPlayerAction.h"
