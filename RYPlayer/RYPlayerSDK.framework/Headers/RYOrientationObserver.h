

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

/// Full screen mode
typedef NS_ENUM(NSUInteger, RYFullScreenMode) {
    RYFullScreenModeAutomatic,  // Determine full screen mode automatically
    RYFullScreenModeLandscape,  // Landscape full screen mode
    RYFullScreenModePortrait    // Portrait full screen Model
};

/// Full screen mode on the view
typedef NS_ENUM(NSUInteger, RYRotateType) {
    RYRotateTypeNormal,         // Normal
    RYRotateTypeCell,           // Cell
    RYRotateTypeCellOther       // Cell mode add to other view
};

/**
 Rotation of support direction
 */
typedef NS_OPTIONS(NSUInteger, RYInterfaceOrientationMask) {
    RYInterfaceOrientationMaskPortrait = (1 << 0),
    RYInterfaceOrientationMaskLandscapeLeft = (1 << 1),
    RYInterfaceOrientationMaskLandscapeRight = (1 << 2),
    RYInterfaceOrientationMaskPortraitUpsideDown = (1 << 3),
    RYInterfaceOrientationMaskLandscape = (RYInterfaceOrientationMaskLandscapeLeft | RYInterfaceOrientationMaskLandscapeRight),
    RYInterfaceOrientationMaskAll = (RYInterfaceOrientationMaskPortrait | RYInterfaceOrientationMaskLandscapeLeft | RYInterfaceOrientationMaskLandscapeRight | RYInterfaceOrientationMaskPortraitUpsideDown),
    RYInterfaceOrientationMaskAllButUpsideDown = (RYInterfaceOrientationMaskPortrait | RYInterfaceOrientationMaskLandscapeLeft | RYInterfaceOrientationMaskLandscapeRight),
};

@interface RYOrientationObserver : NSObject

- (void)updateRotateView:(UIView *)rotateView
           containerView:(UIView *)containerView;

/// list play
- (void)cellModelRotateView:(UIView *)rotateView
           rotateViewAtCell:(UIView *)cell
              playerViewTag:(NSInteger)playerViewTag;

/// cell other view rotation
- (void)cellOtherModelRotateView:(UIView *)rotateView
                   containerView:(UIView *)containerView;

/// Container view of a full screen state player.
@property (nonatomic, strong) UIView *fullScreenContainerView;

/// Container view of a small screen state player.
@property (nonatomic, weak) UIView *containerView;

/// If the full screen.
@property (nonatomic, readonly, getter=isFullScreen) BOOL fullScreen;

/// Use device orientation, default NO.
@property (nonatomic, assign) BOOL forceDeviceOrientation;

/// Lock screen orientation
@property (nonatomic, getter=isLockedScreen) BOOL lockedScreen;

/// The block invoked When player will rotate.
@property (nonatomic, copy, nullable) void(^orientationWillChange)(RYOrientationObserver *observer, BOOL isFullScreen);

/// The block invoked when player rotated.
@property (nonatomic, copy, nullable) void(^orientationDidChanged)(RYOrientationObserver *observer, BOOL isFullScreen);

/// Full screen mode, the default landscape into full screen
@property (nonatomic) RYFullScreenMode fullScreenMode;

/// rotate duration, default is 0.30
@property (nonatomic) float duration;

/// The statusbar hidden.
@property (nonatomic, getter=isStatusBarHidden) BOOL statusBarHidden;

/// The current orientation of the player.
/// Default is UIInterfaceOrientationPortrait.
@property (nonatomic, readonly) UIInterfaceOrientation currentOrientation;

/// Whether allow the video orientation rotate.
/// default is YES.
@property (nonatomic) BOOL allowOrentitaionRotation;

/// The support Interface Orientation,default is RYInterfaceOrientationMaskAllButUpsideDown
@property (nonatomic, assign) RYInterfaceOrientationMask supportInterfaceOrientation;

/// Add the device orientation observer.
- (void)addDeviceOrientationObserver;

/// Remove the device orientation observer.
- (void)removeDeviceOrientationObserver;

/// Enter the fullScreen while the RYFullScreenMode is RYFullScreenModeLandscape.
- (void)enterLandscapeFullScreen:(UIInterfaceOrientation)orientation animated:(BOOL)animated;

/// Enter the fullScreen while the RYFullScreenMode is RYFullScreenModePortrait.
- (void)enterPortraitFullScreen:(BOOL)fullScreen animated:(BOOL)animated;

- (void)exitFullScreenWithAnimated:(BOOL)animated;

@end

NS_ASSUME_NONNULL_END


