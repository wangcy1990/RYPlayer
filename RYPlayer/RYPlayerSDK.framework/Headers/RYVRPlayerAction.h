//
//  RYVRPlayerAction.h
//  RYVRPlayer
//
//  Created by Single on 2017/2/13.
//  Copyright © 2017年 single. All rights reserved.
//

#import "RYVRPlayerImp.h"

@class SGState;
@class SGProgress;
@class SGPlayable;
@class SGError;

NS_ASSUME_NONNULL_BEGIN

// extern
#if defined(__cplusplus)
#define SGPLAYER_EXTERN extern "C"
#else
#define SGPLAYER_EXTERN extern
#endif

// notification name
SGPLAYER_EXTERN NSString * const RYVRPlayerErrorNotificationName;             // player error
SGPLAYER_EXTERN NSString * const RYVRPlayerStateChangeNotificationName;       // player state change
SGPLAYER_EXTERN NSString * const RYVRPlayerProgressChangeNotificationName;    // player play progress change
SGPLAYER_EXTERN NSString * const RYVRPlayerPlayableChangeNotificationName;    // player playable progress change

// notification userinfo key
SGPLAYER_EXTERN NSString * const RYVRPlayerErrorKey;              // error

SGPLAYER_EXTERN NSString * const RYVRPlayerStatePreviousKey;      // state
SGPLAYER_EXTERN NSString * const RYVRPlayerStateCurrentKey;       // state

SGPLAYER_EXTERN NSString * const RYVRPlayerProgressPercentKey;    // progress
SGPLAYER_EXTERN NSString * const RYVRPlayerProgressCurrentKey;    // progress
SGPLAYER_EXTERN NSString * const RYVRPlayerProgressTotalKey;      // progress

SGPLAYER_EXTERN NSString * const RYVRPlayerPlayablePercentKey;    // playable
SGPLAYER_EXTERN NSString * const RYVRPlayerPlayableCurrentKey;    // playable
SGPLAYER_EXTERN NSString * const RYVRPlayerPlayableTotalKey;      // playable


#pragma mark - RYVRPlayer Action Category

@interface RYVRPlayer (RYVRPlayerAction)

- (void)registerPlayerNotificationTarget:(id)target
                             stateAction:(nullable SEL)stateAction
                          progressAction:(nullable SEL)progressAction
                          playableAction:(nullable SEL)playableAction;      // object's class is NSNotification

- (void)registerPlayerNotificationTarget:(id)target
                             stateAction:(nullable SEL)stateAction
                          progressAction:(nullable SEL)progressAction
                          playableAction:(nullable SEL)playableAction
                             errorAction:(nullable SEL)errorAction;

- (void)removePlayerNotificationTarget:(id)target;

@end


#pragma mark - RYVRPlayer Action Models

@interface SGModel : NSObject

+ (SGState *)stateFromUserInfo:(NSDictionary *)userInfo;
+ (SGProgress *)progressFromUserInfo:(NSDictionary *)userInfo;
+ (SGPlayable *)playableFromUserInfo:(NSDictionary *)userInfo;
+ (SGError *)errorFromUserInfo:(NSDictionary *)userInfo;

@end

@interface SGState : SGModel
@property (nonatomic, assign) RYVRPlayerState previous;
@property (nonatomic, assign) RYVRPlayerState current;
@end

@interface SGProgress : SGModel
@property (nonatomic, assign) CGFloat percent;
@property (nonatomic, assign) CGFloat current;
@property (nonatomic, assign) CGFloat total;
@end

@interface SGPlayable : SGModel
@property (nonatomic, assign) CGFloat percent;
@property (nonatomic, assign) CGFloat current;
@property (nonatomic, assign) CGFloat total;
@end

@interface SGErrorEvent : SGModel
@property (nonatomic, copy, nullable) NSDate * date;
@property (nonatomic, copy, nullable) NSString * URI;
@property (nonatomic, copy, nullable) NSString * serverAddress;
@property (nonatomic, copy, nullable) NSString * playbackSessionID;
@property (nonatomic, assign) NSInteger errorStatusCode;
@property (nonatomic, copy) NSString * errorDomain;
@property (nonatomic, copy, nullable) NSString * errorComment;
@end

@interface SGError : SGModel
@property (nonatomic, copy) NSError * error;
@property (nonatomic, copy, nullable) NSData * extendedLogData;
@property (nonatomic, assign) NSStringEncoding extendedLogDataStringEncoding;
@property (nonatomic, copy, nullable) NSArray <SGErrorEvent *> * errorEvents;
@end

NS_ASSUME_NONNULL_END
