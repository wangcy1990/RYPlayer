大洋融云播放器 -- RYPlayerSDK
====
基于ijkplayer开发，集点播、直播、VR播放功能于一体，与融云云平台绑定，支持播放数据统计。

集成方式：
-----
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

.在Embed Frameworks中添加RYPlayerSDK.framework

.在Build Settings中找到Other Linker Flags ，添加 -ObjC

.如需支持后台播放，需要打开Background Modes并勾选Audio,airplay,andPciture in Picture

.播放器使用大观云平台统计播放数据，需要在plist中添加App Transport Security Settings，并设置Allow Arbitrary Loads为YES

播放器的使用：
引用RYPlayerSDK



