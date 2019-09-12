大洋融云播放器 -- RYPlayerSDK
====
基于ijkplayer开发，集点播、直播、VR播放功能于一体，与融云云平台绑定，支持播放数据统计。

集成方式：
-----
1.使用cocoapods<br>
请将下面代码加入到您的 Podfile 中：<br>
pod 'RYPlayer'<br>

2.手动集成<br>
下载RYPlayerSDK、IJKMediaFramework.framework;<br>
将RYPlayerSDK.framework和IJKMediaFramework.framework复制到项目中；<br>
.添加依赖库：<br>
在Build Phases中的Link Bainary With Libraries中添加：<br>
RYPlayerSDK.framework、<br>
IJKMediaFramework.framework、<br>
Libiconv.tbd、<br>
libsqlite3.tbd、<br>
libz.tbd、<br>
libz2.tbd、<br>
libc++.tbd、<br>
libxml2.tbd、<br>
libresolve.9.tbd<br>

.在Embed Frameworks中添加RYPlayerSDK.framework<br>

.在Build Settings中找到Other Linker Flags ，添加 -ObjC<br>

.如需支持后台播放，需要打开Background Modes并勾选Audio,airplay,andPciture in Picture<br>

.播放器使用大观云平台统计播放数据，需要在plist中添加App Transport Security Settings，并设置Allow Arbitrary Loads为YES<br>

播放器的使用：
======
引用RYPlayerSDK<br>
#import <RYPlayerSDK/RYPlayerSDK.h> <br>

@implementation ViewController

-(void)viewDidLoad 
{
    [super viewDidLoad];
    //添加播放器视图
    [self.view addSubview:self.containerView];
    //播放器管理器
    NSObject<RYPlayerMediaPlayback> *playerManager;
    //选择播放器类型
    int type;
    if(self.type == 0)
    {
        //直播
        playerManager = [[RYIJKPlayerManager alloc] init];
        //软解/硬解码
        //[playerManager setGPUCodeMode:NO];
    }else if (self.type == 1)
    {
        //点播
        playerManager = [[RYAVPlayerManager alloc]init];
	
    }else if(self.type == 2)
    {
        //全景VR直播
        playerManager = [[RYVRPlayerManager alloc]initWithDecoderType:2];

    }else if (self.type == 3)
    {
        //全景VR点播
        playerManager = [[RYVRPlayerManager alloc]init];
    }
   // 播放器初始化
    self.player = [RYPlayerController playerWithPlayerManager:playerManager containerView:self.containerView];
   //设置不同分辨率播放地址
    self.player.assetURLs = self.assetURLs;
	//开始播放
    [self.player playTheIndex:0]; 
}

@end

定制化开发接口说明
1.使用播放器自带UI（如需自定义开发UI,不调用此接口）
self.controlView = [RYPlayerControlView new];
self.player.controlView = self.controlView;
//设置不同分辨率显示名称
[self.controlView setDefaultUIWithURLNames:URLNamesArr];

2.设置画面填充模式(VR播放器暂不支持)
playerManager.scalingMode = RYPlayerScalingModeAspectFit;

3.倍速播放（0.5～2倍）
playerManager.rate = 1;

4.播放器自动播放
playerManager.shouldAutoPlay = YES;

5.支持后台播放
(需要打开Background Modes并勾选Audio,airplay,andPciture in Picture)
self.player.pauseWhenAppResignActive = YES;

6.暂停播放
[self.player.currentPlayerManager pause];

7.恢复播放
[self.player.currentPlayerManager play];

8.切换不同分辨率
[self.player playTheIndex:x];

9.切换不同视频
Self.player.assetURLs = URLSArr; 

10.播放器静音
[self.player.currentPlayerManager setMuted:YES];

11.截图(VR暂不支持截图功能)
[self.player.currentPlayerManager thumbnailImageAtCurrentTime];

12.销毁播放器
[self.player stop]; 

13.播放器索引时间点
[self.player seekToTime:time completionHandler:^(BOOL finished) {   }];

播放器回调接口
1.播放器准备播放
 self.player.playerPrepareToPlay = ^(id<RYPlayerMediaPlayback>  _Nonnull asset, NSURL * _Nonnull assetURL) {  };

2.播放器准备好播放
 self.player.playerReadyToPlay = ^(id<RYPlayerMediaPlayback>  _Nonnull asset, NSURL * _Nonnull assetURL) {  };

3.播放器播放播放时间回调
self.player.playerPlayTimeChanged = ^(id<RYPlayerMediaPlayback>  _Nonnull asset, NSTimeInterval currentTime, NSTimeInterval duration){   };

4.播放器缓冲时间回调
self.playe.playerBufferTimeChanged = ^(id<RYPlayerMediaPlayback>  _Nonnull asset, NSTimeInterval bufferTime) {   };

5.播放器播放状态回调
self.player.playerPlayStateChanged = = ^(id<RYPlayerMediaPlayback>  _Nonnull asset, RYPlayerPlaybackState playState) {   };

6.播放器加载状态回调
self.player.playerLoadStateChanged = = ^(id<RYPlayerMediaPlayback>  _Nonnull asset, RYPlayerLoadState loadState) {   };

7.播放器播放失败回调
self.player.playerPlayFailed = ^(id<RYPlayerMediaPlayback>  _Nonnull asset, id _Nonnull error) {   };

8.播放器播放完毕回调
self.player.playerDidToEnd = ^(id<RYPlayerMediaPlayback>  _Nonnull asset) {   };





