
#import <Foundation/Foundation.h>
#import "RYPlayerMediaPlayback.h"
#import <AVFoundation/AVFoundation.h>

@interface RYAVPlayerManager : NSObject <RYPlayerMediaPlayback>

@property (nonatomic, strong, readonly) AVURLAsset *asset;
@property (nonatomic, strong, readonly) AVPlayerItem *playerItem;
@property (nonatomic, strong, readonly) AVPlayer *player;
@property (nonatomic, assign) NSTimeInterval timeRefreshInterval;
/// 视频请求头
@property (nonatomic, strong) NSDictionary *requestHeader;

@end
