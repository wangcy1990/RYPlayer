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
-(void)viewDidLoad {
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






