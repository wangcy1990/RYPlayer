

#import <UIKit/UIKit.h>
#import "RYLoadingView.h"

@interface RYSpeedLoadingView : UIView

@property (nonatomic, strong) RYLoadingView *loadingView;

@property (nonatomic, strong) UILabel *speedTextLabel;

/**
 *  Starts animation of the spinner.
 */
- (void)startAnimating;

/**
 *  Stops animation of the spinnner.
 */
- (void)stopAnimating;

@end
