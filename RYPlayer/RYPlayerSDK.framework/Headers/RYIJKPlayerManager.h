
#import <Foundation/Foundation.h>
#import "RYPlayerMediaPlayback.h"
//#if __has_include(<IJKMediaFramework/IJKMediaFramework.h>)
#import <IJKMediaFramework/IJKMediaFramework.h>

@interface RYIJKPlayerManager : NSObject <RYPlayerMediaPlayback>

@property (nonatomic, strong, readonly) IJKFFMoviePlayerController *player;

@property (nonatomic, strong, readonly) IJKFFOptions *options;

@property (nonatomic, assign) NSTimeInterval timeRefreshInterval;


//设置解码方式,默认硬解码
-(void)setGPUCodeMode:(BOOL)GPUCodeMode;





@end

//#endif
