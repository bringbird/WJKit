//
//  UIView+WJAdd.h
//  WJCategory
//
//  Created by bringbird on 16/8/20.
//  Copyright © 2016年 韦明杰. All rights reserved.
//

#import <UIKit/UIKit.h>

/// 圆角类型
typedef NS_ENUM(NSInteger,WJCornerType) {
    WJCornerType_Top = 0,       ///<  顶部
    WJCornerType_Left,          ///<  左边
    WJCornerType_Bottom,        ///<  底部
    WJCornerType_Right,         ///<  右边
    WJCornerType_TopLeft,       ///<  左上
    WJCornerType_TopRight,      ///<  右上
    WJCornerType_BottomLeft,    ///<  左下
    WJCornerType_BottomRight,   ///<  右下
    WJCornerType_All,           ///<  全部
};

/// 屏幕的尺寸
static inline CGSize  screenSize() {
    static CGSize size;
    static dispatch_once_t onceToken;
    dispatch_once(&onceToken, ^{
        size = [UIScreen mainScreen].bounds.size;
    });
    return size;
}

/// 屏幕的高
static inline CGFloat screenHeight() {
    static CGFloat height;
    static dispatch_once_t onceToken;
    dispatch_once(&onceToken, ^{
        height = screenSize().height;
    });
    return height;
}

/// 屏幕的宽
static inline CGFloat screenWidth() {
    static CGFloat width;
    static dispatch_once_t onceToken;
    dispatch_once(&onceToken, ^{
        width = screenSize().width;
    });
    return width;
}

NS_ASSUME_NONNULL_BEGIN

@interface UIView (WJAdd)

@property (nonatomic) CGFloat wj_left;
@property (nonatomic) CGFloat wj_top;
@property (nonatomic) CGFloat wj_right;
@property (nonatomic) CGFloat wj_bottom;
@property (nonatomic) CGFloat wj_width;
@property (nonatomic) CGFloat wj_height;
@property (nonatomic) CGFloat wj_centerX;
@property (nonatomic) CGFloat wj_centerY;
@property (nonatomic) CGPoint wj_origin;
@property (nonatomic) CGSize  wj_size;

/**
 Returns the view's view controller (may be nil).
 */
@property (nullable, nonatomic, readonly) UIViewController *viewController;

/**
 Returns the visible alpha on screen, taking into account superview and window.
 */
@property (nonatomic, readonly) CGFloat visibleAlpha;

/// 从 nib 文件加载 View
+ (instancetype)viewFromXib;

/// 设置 View 圆角，type   圆角类型，radius 圆角角度
- (void)cornerType:(WJCornerType)type withCornerRadius:(CGFloat)radius;

/**
 Create a snapshot image of the complete view hierarchy.
 */
- (nullable UIImage *)snapshotImage;

/**
 Create a snapshot image of the complete view hierarchy.
 @discussion It's faster than "snapshotImage", but may cause screen updates.
 See -[UIView drawViewHierarchyInRect:afterScreenUpdates:] for more information.
 */
- (nullable UIImage *)snapshotImageAfterScreenUpdates:(BOOL)afterUpdates;

/**
 Create a snapshot PDF of the complete view hierarchy.
 */
- (nullable NSData *)snapshotPDF;

/**
 Shortcut to set the view.layer's shadow
 
 @param color  Shadow Color
 @param offset Shadow offset
 @param radius Shadow radius
 */
- (void)setLayerShadow:(nullable UIColor*)color offset:(CGSize)offset radius:(CGFloat)radius;

/**
 Remove all subviews.
 
 @warning Never call this method inside your view's drawRect: method.
 */
- (void)removeAllSubviews;

/**
 Converts a point from the receiver's coordinate system to that of the specified view or window.
 
 @param point A point specified in the local coordinate system (bounds) of the receiver.
 @param view  The view or window into whose coordinate system point is to be converted.
 If view is nil, this method instead converts to window base coordinates.
 @return The point converted to the coordinate system of view.
 */
- (CGPoint)convertPoint:(CGPoint)point toViewOrWindow:(nullable UIView *)view;

/**
 Converts a point from the coordinate system of a given view or window to that of the receiver.
 
 @param point A point specified in the local coordinate system (bounds) of view.
 @param view  The view or window with point in its coordinate system.
 If view is nil, this method instead converts from window base coordinates.
 @return The point converted to the local coordinate system (bounds) of the receiver.
 */
- (CGPoint)convertPoint:(CGPoint)point fromViewOrWindow:(nullable UIView *)view;

/**
 Converts a rectangle from the receiver's coordinate system to that of another view or window.
 
 @param rect A rectangle specified in the local coordinate system (bounds) of the receiver.
 @param view The view or window that is the target of the conversion operation. If view is nil, this method instead converts to window base coordinates.
 @return The converted rectangle.
 */
- (CGRect)convertRect:(CGRect)rect toViewOrWindow:(nullable UIView *)view;

/**
 Converts a rectangle from the coordinate system of another view or window to that of the receiver.
 
 @param rect A rectangle specified in the local coordinate system (bounds) of view.
 @param view The view or window with rect in its coordinate system.
 If view is nil, this method instead converts from window base coordinates.
 @return The converted rectangle.
 */
- (CGRect)convertRect:(CGRect)rect fromViewOrWindow:(nullable UIView *)view;

@end

NS_ASSUME_NONNULL_END