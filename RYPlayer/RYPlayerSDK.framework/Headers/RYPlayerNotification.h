

#import <UIKit/UIKit.h>
#import <AVFoundation/AVFoundation.h>
#import <MediaPlayer/MPMusicPlayerController.h>

NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(NSUInteger, RYPlayerBackgroundState) {
    RYPlayerBackgroundStateForeground,  // Enter the foreground from the background.
    RYPlayerBackgroundStateBackground,  // From the foreground to the background.
};

@interface RYPlayerNotification : NSObject

@property (nonatomic, readonly) RYPlayerBackgroundState backgroundState;

@property (nonatomic, copy, nullable) void(^willResignActive)(RYPlayerNotification *registrar);

@property (nonatomic, copy, nullable) void(^didBecomeActive)(RYPlayerNotification *registrar);

@property (nonatomic, copy, nullable) void(^newDeviceAvailable)(RYPlayerNotification *registrar);

@property (nonatomic, copy, nullable) void(^oldDeviceUnavailable)(RYPlayerNotification *registrar);

@property (nonatomic, copy, nullable) void(^categoryChange)(RYPlayerNotification *registrar);

@property (nonatomic, copy, nullable) void(^volumeChanged)(float volume);

@property (nonatomic, copy, nullable) void(^audioInterruptionCallback)(AVAudioSessionInterruptionType interruptionType);

- (void)addNotification;

- (void)removeNotification;

@end

NS_ASSUME_NONNULL_END
