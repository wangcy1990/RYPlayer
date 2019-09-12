大洋融云IOS播放器 -- RYPlayerSDK
====
基于ijkplayer开发，集点播、直播、VR播放功能于一体，可支持播放数据统计。

集成方式：
-----
1.使用cocoapods<br>
请将下面代码加入到您的 Podfile 中：<br>
pod 'RYPlayer'<br>

2.手动集成<br>
下载RYPlayerSDK、IJKMediaFramework.framework;<br>
将RYPlayerSDK.framework和IJKMediaFramework.framework复制到项目中；<br>
* 添加依赖库：<br>
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

* 在Embed Frameworks中添加RYPlayerSDK.framework<br>

* 在Build Settings中找到Other Linker Flags ，添加 -ObjC<br>

* 如需支持后台播放，需要打开Background Modes并勾选Audio,airplay,andPciture in Picture<br>

* 播放器使用大观云平台统计播放数据，需要在plist中添加App Transport Security Settings，并设置Allow Arbitrary Loads为YES<br>

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
=

1.使用播放器自带UI（如需自定义开发UI,不调用此接口）<br>
self.controlView = [RYPlayerControlView new];<br>
self.player.controlView = self.controlView;<br>
//设置不同分辨率显示名称<br>
[self.controlView setDefaultUIWithURLNames:URLNamesArr];<br>

2.设置画面填充模式(VR播放器暂不支持)<br>
playerManager.scalingMode = RYPlayerScalingModeAspectFit;<br>

3.倍速播放（0.5～2倍）<br>
playerManager.rate = 1;<br>

4.播放器自动播放<br>
playerManager.shouldAutoPlay = YES;<br>

5.支持后台播放<br>
(需要打开Background Modes并勾选Audio,airplay,andPciture in Picture)<br>
self.player.pauseWhenAppResignActive = YES;<br>

6.暂停播放<br>
[self.player.currentPlayerManager pause];<br>

7.恢复播放<br>
[self.player.currentPlayerManager play];<br>

8.切换不同分辨率<br>
[self.player playTheIndex:x];<br>

9.切换不同视频<br>
Self.player.assetURLs = URLSArr; <br>

10.播放器静音<br>
[self.player.currentPlayerManager setMuted:YES];<br>

11.截图(VR暂不支持截图功能)<br>
[self.player.currentPlayerManager thumbnailImageAtCurrentTime];<br>

12.销毁播放器<br>
[self.player stop]; <br>

13.播放器索引时间点<br>
[self.player seekToTime:time completionHandler:^(BOOL finished) {   }];<br>

播放器回调接口<br>
------
1.播放器准备播放<br>
 self.player.playerPrepareToPlay = ^(id<RYPlayerMediaPlayback>  _Nonnull asset, NSURL * _Nonnull assetURL) {  };<br>

2.播放器准备好播放<br>
 self.player.playerReadyToPlay = ^(id<RYPlayerMediaPlayback>  _Nonnull asset, NSURL * _Nonnull assetURL) {  };<br>

3.播放器播放播放时间回调<br>
self.player.playerPlayTimeChanged = ^(id<RYPlayerMediaPlayback>  _Nonnull asset, NSTimeInterval currentTime, NSTimeInterval duration){   };<br>

4.播放器缓冲时间回调<br>
self.playe.playerBufferTimeChanged = ^(id<RYPlayerMediaPlayback>  _Nonnull asset, NSTimeInterval bufferTime) {   };<br>

5.播放器播放状态回调<br>
self.player.playerPlayStateChanged = = ^(id<RYPlayerMediaPlayback>  _Nonnull asset, RYPlayerPlaybackState playState) {   };<br>

6.播放器加载状态回调<br>
self.player.playerLoadStateChanged = = ^(id<RYPlayerMediaPlayback>  _Nonnull asset, RYPlayerLoadState loadState) {   };<br>

7.播放器播放失败回调<br>
self.player.playerPlayFailed = ^(id<RYPlayerMediaPlayback>  _Nonnull asset, id _Nonnull error) {   };<br>

8.播放器播放完毕回调<br>
self.player.playerDidToEnd = ^(id<RYPlayerMediaPlayback>  _Nonnull asset) {   };<br>





