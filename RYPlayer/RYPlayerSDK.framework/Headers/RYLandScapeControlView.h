

#import <UIKit/UIKit.h>
#import "RYPlayerController.h"
#import "RYSliderView.h"

NS_ASSUME_NONNULL_BEGIN

@interface RYLandScapeControlView : UIView

//分辨率名称
@property (nonatomic,strong)NSMutableArray *URLNamesArr;

/// 顶部工具栏
@property (nonatomic, strong, readonly) UIView *topToolView;

/// 返回按钮
@property (nonatomic, strong, readonly) UIButton *backBtn;

/// 标题
@property (nonatomic, strong, readonly) UILabel *titleLabel;

/// 底部工具栏
@property (nonatomic, strong, readonly) UIView *bottomToolView;

/// 播放或暂停按钮 
@property (nonatomic, strong, readonly) UIButton *playOrPauseBtn;

@property (nonatomic, strong, readonly) UIButton *replayBtn;
/// 播放的当前时间
@property (nonatomic, strong, readonly) UILabel *currentTimeLabel;

/// 滑杆
@property (nonatomic, strong, readonly) RYSliderView *slider;

/// 视频总时间
@property (nonatomic, strong, readonly) UILabel *totalTimeLabel;

/// 锁定屏幕按钮
@property (nonatomic, strong, readonly) UIButton *lockBtn;

//投屏按钮
@property (nonatomic, strong, readonly) UIButton *airplayBtn;
//拉伸按钮
@property (nonatomic, strong, readonly) UIButton *fillTypeChangeBtn;
//截图按钮
@property (nonatomic, strong, readonly) UIButton *screenShotBtn;
//倍速按钮
@property (nonatomic, strong, readonly) UIButton *speedButton;
//VR切换按钮
@property (nonatomic, strong, readonly) UIButton *VRTypeChangeButton;


/// 播放器
@property (nonatomic, weak) RYPlayerController *player;

/// slider滑动中
@property (nonatomic, copy, nullable) void(^sliderValueChanging)(CGFloat value,BOOL forward);

/// slider滑动结束
@property (nonatomic, copy, nullable) void(^sliderValueChanged)(CGFloat value);

/// 返回按钮点击回调
@property (nonatomic, copy) void(^backBtnClickCallback)(void);

//截图按钮点击回调
@property (nonatomic,copy) void(^screenShotBtnClickCallback)(UIImage *image);


/// 如果是暂停状态，seek完是否播放，默认YES
@property (nonatomic, assign) BOOL seekToPlay;

/// 重置控制层
- (void)resetControlView;

/// 显示控制层
- (void)showControlView;

/// 隐藏控制层
- (void)hideControlView;

/// 设置播放时间
- (void)videoPlayer:(RYPlayerController *)videoPlayer currentTime:(NSTimeInterval)currentTime totalTime:(NSTimeInterval)totalTime;

/// 设置缓冲时间
- (void)videoPlayer:(RYPlayerController *)videoPlayer bufferTime:(NSTimeInterval)bufferTime;

/// 是否响应该手势
- (BOOL)shouldResponseGestureWithPoint:(CGPoint)point withGestureType:(RYPlayerGestureType)type touch:(nonnull UITouch *)touch;

/// 视频尺寸改变
- (void)videoPlayer:(RYPlayerController *)videoPlayer presentationSizeChanged:(CGSize)size;

/// 标题和全屏模式
- (void)showTitle:(NSString *_Nullable)title fullScreenMode:(RYFullScreenMode)fullScreenMode;

/// 根据当前播放状态取反
- (void)playOrPause;

/// 播放按钮状态
- (void)playBtnSelectedState:(BOOL)selected;

/// 调节播放进度slider和当前时间更新
- (void)sliderValueChanged:(CGFloat)value currentTimeString:(NSString *)timeString;

/// 滑杆结束滑动
- (void)sliderChangeEnded;

//修改当前码率名称
-(void)setCurrentResolutionBtnTitleIndex:(int)currentIndex;

@end

NS_ASSUME_NONNULL_END
