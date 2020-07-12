

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

/*
 * The scroll direction of scrollView.
 */
typedef NS_ENUM(NSUInteger, RYPlayerScrollDirection) {
    RYPlayerScrollDirectionNone,
    RYPlayerScrollDirectionUp,         // Scroll up
    RYPlayerScrollDirectionDown,       // Scroll Down
    RYPlayerScrollDirectionLeft,       // Scroll left
    RYPlayerScrollDirectionRight       // Scroll right
};

/*
 * The scrollView direction.
 */
typedef NS_ENUM(NSInteger, RYPlayerScrollViewDirection) {
    RYPlayerScrollViewDirectionVertical,
    RYPlayerScrollViewDirectionHorizontal
};

/*
 * The player container type
 */
typedef NS_ENUM(NSInteger, RYPlayerContainerType) {
    RYPlayerContainerTypeCell,
    RYPlayerContainerTypeView
};

@interface UIScrollView (RYPlayer)

/// When the RYPlayerScrollViewDirection is RYPlayerScrollViewDirectionVertical,the property has value.
@property (nonatomic, readonly) CGFloat RY_lastOffsetY;

/// When the RYPlayerScrollViewDirection is RYPlayerScrollViewDirectionHorizontal,the property has value.
@property (nonatomic, readonly) CGFloat RY_lastOffsetX;

/// The indexPath is playing.
@property (nonatomic, nullable) NSIndexPath *RY_playingIndexPath;

/// The indexPath that should play, the one that lights up.
@property (nonatomic, nullable) NSIndexPath *RY_shouldPlayIndexPath;

/// WWANA networks play automatically,default NO.
@property (nonatomic, getter=RY_isWWANAutoPlay) BOOL RY_WWANAutoPlay;

/// The player should auto player,default is YES.
@property (nonatomic) BOOL RY_shouldAutoPlay;

/// The view tag that the player display in scrollView.
@property (nonatomic) NSInteger RY_containerViewTag;

/// The scrollView scroll direction, default is RYPlayerScrollViewDirectionVertical.
@property (nonatomic) RYPlayerScrollViewDirection RY_scrollViewDirection;

/// The scroll direction of scrollView while scrolling.
/// When the RYPlayerScrollViewDirection is RYPlayerScrollViewDirectionVertical，this value can only be RYPlayerScrollDirectionUp or RYPlayerScrollDirectionDown.
/// When the RYPlayerScrollViewDirection is RYPlayerScrollViewDirectionVertical，this value can only be RYPlayerScrollDirectionLeft or RYPlayerScrollDirectionRight.
@property (nonatomic, readonly) RYPlayerScrollDirection RY_scrollDirection;

/// The video contrainerView type.
@property (nonatomic, assign) RYPlayerContainerType RY_containerType;

/// The video contrainerView in normal model.
@property (nonatomic, strong) UIView *RY_containerView;

/// The currently playing cell stop playing when the cell has out off the screen，defalut is YES.
@property (nonatomic, assign) BOOL RY_stopWhileNotVisible;

/// Has stopped playing
@property (nonatomic, assign) BOOL RY_stopPlay;

/// The block invoked When the player did stop scroll.
@property (nonatomic, copy, nullable) void(^RY_scrollViewDidStopScrollCallback)(NSIndexPath *indexPath);

/// The block invoked When the player should play.
@property (nonatomic, copy, nullable) void(^RY_shouldPlayIndexPathCallback)(NSIndexPath *indexPath);

/// Filter the cell that should be played when the scroll is stopped (to play when the scroll is stopped).
- (void)RY_filterShouldPlayCellWhileScrolled:(void (^ __nullable)(NSIndexPath *indexPath))handler;

/// Filter the cell that should be played while scrolling (you can use this to filter the highlighted cell).
- (void)RY_filterShouldPlayCellWhileScrolling:(void (^ __nullable)(NSIndexPath *indexPath))handler;

/// Get the cell according to indexPath.
- (UIView *)RY_getCellForIndexPath:(NSIndexPath *)indexPath;

/// Scroll to indexPath with animations.
- (void)RY_scrollToRowAtIndexPath:(NSIndexPath *)indexPath completionHandler:(void (^ __nullable)(void))completionHandler;

/// add in 3.2.4 version.
/// Scroll to indexPath with animations.
- (void)RY_scrollToRowAtIndexPath:(NSIndexPath *)indexPath animated:(BOOL)animated completionHandler:(void (^ __nullable)(void))completionHandler;

/// add in 3.2.8 version.
/// Scroll to indexPath with animations duration.
- (void)RY_scrollToRowAtIndexPath:(NSIndexPath *)indexPath animateWithDuration:(NSTimeInterval)duration completionHandler:(void (^ __nullable)(void))completionHandler;

///------------------------------------
/// The following method must be implemented in UIScrollViewDelegate.
///------------------------------------

- (void)RY_scrollViewDidEndDecelerating;

- (void)RY_scrollViewDidEndDraggingWillDecelerate:(BOOL)decelerate;

- (void)RY_scrollViewDidScrollToTop;

- (void)RY_scrollViewDidScroll;

- (void)RY_scrollViewWillBeginDragging;

///------------------------------------
/// end
///------------------------------------


@end

@interface UIScrollView (RYPlayerCannotCalled)

/// The block invoked When the player appearing.
@property (nonatomic, copy, nullable) void(^RY_playerAppearingInScrollView)(NSIndexPath *indexPath, CGFloat playerApperaPercent);

/// The block invoked When the player disappearing.
@property (nonatomic, copy, nullable) void(^RY_playerDisappearingInScrollView)(NSIndexPath *indexPath, CGFloat playerDisapperaPercent);

/// The block invoked When the player will appeared.
@property (nonatomic, copy, nullable) void(^RY_playerWillAppearInScrollView)(NSIndexPath *indexPath);

/// The block invoked When the player did appeared.
@property (nonatomic, copy, nullable) void(^RY_playerDidAppearInScrollView)(NSIndexPath *indexPath);

/// The block invoked When the player will disappear.
@property (nonatomic, copy, nullable) void(^RY_playerWillDisappearInScrollView)(NSIndexPath *indexPath);

/// The block invoked When the player did disappeared.
@property (nonatomic, copy, nullable) void(^RY_playerDidDisappearInScrollView)(NSIndexPath *indexPath);

/// The current player scroll slides off the screen percent.
/// the property used when the `stopWhileNotVisible` is YES, stop the current playing player.
/// the property used when the `stopWhileNotVisible` is NO, the current playing player add to small container view.
/// 0.0~1.0, defalut is 0.5.
/// 0.0 is the player will disappear.
/// 1.0 is the player did disappear.
@property (nonatomic) CGFloat RY_playerDisapperaPercent;

/// The current player scroll to the screen percent to play the video.
/// 0.0~1.0, defalut is 0.0.
/// 0.0 is the player will appear.
/// 1.0 is the player did appear.
@property (nonatomic) CGFloat RY_playerApperaPercent;

/// The current player controller is disappear, not dealloc
@property (nonatomic) BOOL RY_viewControllerDisappear;

@end

NS_ASSUME_NONNULL_END
