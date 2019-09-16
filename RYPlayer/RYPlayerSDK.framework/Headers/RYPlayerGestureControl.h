

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(NSUInteger, RYPlayerGestureType) {
    RYPlayerGestureTypeUnknown,
    RYPlayerGestureTypeSingleTap,
    RYPlayerGestureTypeDoubleTap,
    RYPlayerGestureTypePan,
    RYPlayerGestureTypePinch
};

typedef NS_ENUM(NSUInteger, RYPanDirection) {
    RYPanDirectionUnknown,
    RYPanDirectionV,
    RYPanDirectionH,
};

typedef NS_ENUM(NSUInteger, RYPanLocation) {
    RYPanLocationUnknown,
    RYPanLocationLeft,
    RYPanLocationRight,
};

typedef NS_ENUM(NSUInteger, RYPanMovingDirection) {
    RYPanMovingDirectionUnkown,
    RYPanMovingDirectionTop,
    RYPanMovingDirectionLeft,
    RYPanMovingDirectionBottom,
    RYPanMovingDirectionRight,
};

/// This enumeration lists some of the gesture types that the player has by default.
typedef NS_OPTIONS(NSUInteger, RYPlayerDisableGestureTypes) {
    RYPlayerDisableGestureTypesNone         = 0,
    RYPlayerDisableGestureTypesSingleTap    = 1 << 0,
    RYPlayerDisableGestureTypesDoubleTap    = 1 << 1,
    RYPlayerDisableGestureTypesPan          = 1 << 2,
    RYPlayerDisableGestureTypesPinch        = 1 << 3,
    RYPlayerDisableGestureTypesAll          = (RYPlayerDisableGestureTypesSingleTap | RYPlayerDisableGestureTypesDoubleTap | RYPlayerDisableGestureTypesPan | RYPlayerDisableGestureTypesPinch)
};

/// This enumeration lists some of the pan gesture moving direction that the player not support.
typedef NS_OPTIONS(NSUInteger, RYPlayerDisablePanMovingDirection) {
    RYPlayerDisablePanMovingDirectionNone         = 0,       /// Not disable pan moving direction.
    RYPlayerDisablePanMovingDirectionVertical     = 1 << 0,  /// Disable pan moving vertical direction.
    RYPlayerDisablePanMovingDirectionHorizontal   = 1 << 1,  /// Disable pan moving horizontal direction.
    RYPlayerDisablePanMovingDirectionAll          = (RYPlayerDisablePanMovingDirectionVertical | RYPlayerDisablePanMovingDirectionHorizontal)  /// Disable pan moving all direction.
};

@interface RYPlayerGestureControl : NSObject

/// Gesture condition callback.
@property (nonatomic, copy, nullable) BOOL(^triggerCondition)(RYPlayerGestureControl *control, RYPlayerGestureType type, UIGestureRecognizer *gesture, UITouch *touch);

/// Single tap gesture callback.
@property (nonatomic, copy, nullable) void(^singleTapped)(RYPlayerGestureControl *control);

/// Double tap gesture callback.
@property (nonatomic, copy, nullable) void(^doubleTapped)(RYPlayerGestureControl *control);

/// Begin pan gesture callback.
@property (nonatomic, copy, nullable) void(^beganPan)(RYPlayerGestureControl *control, RYPanDirection direction, RYPanLocation location);

/// Pan gesture changing callback.
@property (nonatomic, copy, nullable) void(^changedPan)(RYPlayerGestureControl *control, RYPanDirection direction, RYPanLocation location, CGPoint velocity);

/// End the Pan gesture callback.
@property (nonatomic, copy, nullable) void(^endedPan)(RYPlayerGestureControl *control, RYPanDirection direction, RYPanLocation location);

/// Pinch gesture callback.
@property (nonatomic, copy, nullable) void(^pinched)(RYPlayerGestureControl *control, float scale);

/// The single tap gesture.
@property (nonatomic, strong, readonly) UITapGestureRecognizer *singleTap;

/// The double tap gesture.
@property (nonatomic, strong, readonly) UITapGestureRecognizer *doubleTap;

/// The pan tap gesture.
@property (nonatomic, strong, readonly) UIPanGestureRecognizer *panGR;

/// The pinch tap gesture.
@property (nonatomic, strong, readonly) UIPinchGestureRecognizer *pinchGR;

/// The pan gesture direction.
@property (nonatomic, readonly) RYPanDirection panDirection;

@property (nonatomic, readonly) RYPanLocation panLocation;

@property (nonatomic, readonly) RYPanMovingDirection panMovingDirection;

/// The gesture types that the player not support.
@property (nonatomic) RYPlayerDisableGestureTypes disableTypes;

/// The pan gesture moving direction that the player not support.
@property (nonatomic) RYPlayerDisablePanMovingDirection disablePanMovingDirection;

/**
 Add gestures to the view.
 */
- (void)addGestureToView:(UIView *)view;

/**
 Remove gestures form the view.
 */
- (void)removeGestureToView:(UIView *)view;

@end

NS_ASSUME_NONNULL_END
