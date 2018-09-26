#import <UIKit/UIKit.h>

#import "TGModernGalleryItem.h"

@class TGModernGalleryItemView;

@protocol TGModernGalleryInterfaceView <NSObject>

- (void)setClosePressed:(void (^)())closePressed;
- (void)setScrollViewOffsetRequested:(void (^)(CGFloat offset))scrollViewOffsetRequested;

- (void)itemFocused:(id<TGModernGalleryItem>)item itemView:(TGModernGalleryItemView *)itemView;

- (void)addItemHeaderView:(UIView *)itemHeaderView;
- (void)removeItemHeaderView:(UIView *)itemHeaderView;
- (void)addItemFooterView:(UIView *)itemFooterView;
- (void)removeItemFooterView:(UIView *)itemFooterView;
- (void)addItemLeftAcessoryView:(UIView *)itemLeftAcessoryView;
- (void)removeItemLeftAcessoryView:(UIView *)itemLeftAcessoryView;
- (void)addItemRightAcessoryView:(UIView *)itemRightAcessoryView;
- (void)removeItemRightAcessoryView:(UIView *)itemRightAcessoryView;

- (void)animateTransitionInWithDuration:(NSTimeInterval)dutation;
- (void)animateTransitionOutWithDuration:(NSTimeInterval)dutation;
- (void)setTransitionOutProgress:(CGFloat)transitionOutProgress manual:(bool)manual;

- (bool)allowsDismissalWithSwipeGesture;
- (bool)prefersStatusBarHidden;
- (bool)allowsHide;

@property (nonatomic, assign) UIEdgeInsets safeAreaInset;

@optional

- (bool)showHiddenInterfaceOnScroll;
- (bool)shouldAutorotate;

- (void)willRotateToInterfaceOrientation:(UIInterfaceOrientation)toInterfaceOrientation duration:(NSTimeInterval)duration;

@end