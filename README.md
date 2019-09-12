大洋融云播放器 -- RYPlayerSDK
基于ijkplayer开发，集点播、直播、VR播放功能于一体，与融云云平台绑定，支持播放数据统计。
集成方式：
1.使用cocoapods
请将下面代码加入到您的 Podfile 中：
pod 'RYPlayer'

2.手动集成
下载RYPlayerSDK、IJKMediaFramework.framework;
将RYPlayerSDK.framework和IJKMediaFramework.framework复制到项目中；

.添加依赖库：
在Build Phases中的Link Bainary With Libraries中添加：
RYPlayerSDK.framework、
IJKMediaFramework.framework、
Libiconv.tbd、
libsqlite3.tbd、
libz.tbd、
libz2.tbd、
libc++.tbd、
libxml2.tbd、
libresolve.9.tbd

