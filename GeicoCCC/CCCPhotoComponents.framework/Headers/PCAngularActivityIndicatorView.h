#import <UIKit/UIKit.h>

typedef NS_ENUM(NSInteger, PCAngularActivityIndicatorViewStyle) {
    PCAngularActivityIndicatorViewStyleSmall,
    PCAngularActivityIndicatorViewStyleDefault,
    PCAngularActivityIndicatorViewStyleLarge
};

/**
 Use an activity indicator to show that a task is in progress. An activity indicator appears as a “spiral” that is either spinning or stopped.
 
 You control when an activity indicator animates by calling the startAnimating and stopAnimating methods. To automatically hide the activity indicator when animation stops, set the hidesWhenStopped property to YES.
 */
@interface PCAngularActivityIndicatorView : UIView

/**
 The color of the activity indicator.
 */
@property (nonatomic, strong) UIColor *color;

/**
 Returns whether the receiver is animating.
 */
@property (nonatomic, readonly, getter = isAnimating) BOOL animating;

/**
 The basic appearance of the activity indicator.
 */
@property (nonatomic, assign) PCAngularActivityIndicatorViewStyle activityIndicatorViewStyle;

/**
 A Boolean value that controls whether the receiver is hidden when the animation is stopped.
 */
@property (nonatomic, assign) BOOL hidesWhenStopped;

/**
 Initializes and returns an activity-indicator object.
 @param style An enum that specifies the style of the object to be created.
*/
- (id)initWithActivityIndicatorStyle:(PCAngularActivityIndicatorViewStyle)style;

/**
 Starts the animation of the progress indicator.
 */
- (void)startAnimating;

/**
 Stops the animation of the progress indicator.
 */
- (void)stopAnimating;

@end
