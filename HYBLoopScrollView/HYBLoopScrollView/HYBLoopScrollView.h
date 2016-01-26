//
//  HYBLoopScrollView.h
//  HYBLoopScrollView
//
//  Created by huangyibiao on 15/4/1.
//  Copyright (c) 2015年 huangyibiao. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "HYBPageControl.h"
#import "HYBLoadImageView.h"
#import "UIView+HYBUIViewCommon.h"

/**
 *  The alignment type of page control. Only has two types.
 *  That is: center and right.
 */
typedef NS_ENUM(NSInteger, HYBPageControlAlignment) {
  /**
   *  For the center type, only show the page control without any text
   */
  kPageControlAlignCenter = 1 << 1,
  /**
   *  For the align right type, will show the page control and show the ad text
   */
  kPageControlAlignRight  = 1 << 2
};

@class HYBLoopScrollView;

/**
 *  Call back method when an item was clicked at some time.
 *
 *  @param atIndex  The index of the clicked item in the loop scroll view
 */
typedef void (^HYBLoopScrollViewDidSelectItemBlock)(NSInteger atIndex, HYBLoadImageView *sender);

/**
 *  Call back method when scroll to an item at index.
 *
 *  @param toIndex The index of page
 */
typedef void (^HYBLoopScrollViewDidScrollBlock)(NSInteger toIndex, HYBLoadImageView *sender);

/**
 *  @blog   http://www.henishuo.com/ios-open-source-hybloopscrollview/
 *
 */
@interface HYBLoopScrollView : UIView

/**
 *  The holder image for the image view. Default is nil
 */
@property (nonatomic, strong) UIImage *placeholder;

/**
 *  Get the page control
 */
@property (nonatomic, strong, readonly) HYBPageControl *pageControl;

/**
 *  The alignment type of the page control.
 * 
 *  @note The default type is kPageControlAlignCenter
 */
@property (nonatomic, assign) HYBPageControlAlignment alignment;

/**
 *  The interval time for the timer call. It means that you can
 *  specify a real time for the interval of ad.
 *
 *  @note The default time interval is 5.0
 */
@property (nonatomic, assign) NSTimeInterval timeInterval;

/**
 *  The call back method of item clicked
 */
@property (nonatomic, copy) HYBLoopScrollViewDidSelectItemBlock didSelectItemBlock;

/**
 *  The call back method when scroll to a new item
 */
@property (nonatomic, copy) HYBLoopScrollViewDidScrollBlock didScrollBlock;

/**
 *  The image urls.It can be absolute urls or main bundle image names, even a real UIImage object.
 */
@property (nonatomic, strong) NSArray *imageUrls;

/**
 *  Get/Set whether page control can handle value changed event.
 * 
 *  @note Set to YES, page control will change to relevant page when clicked.
 *        Set to NO, page control is not enabled.
 *        Default is YES.
 */
@property (nonatomic, assign) BOOL pageControlEnabled;

/**
 *  The ad titles. Only for the alignment kPageControlAlignRight type.
 *
 *  @note If alignment == kPageControlAlignRight, it should be not nil. 
 *        Otherwise it will be ignored whatever it is.
 */
@property (nonatomic, strong) NSArray *adTitles;

/**
 *  The only created method for creating an object.
 *
 *  @param frame     The frame for the loop scroll view
 *  @param imageUrls image urls or image names or a real image object, you can mix together.
 *
 *  @return The HYBLoopScrollView object.
 */
+ (instancetype)loopScrollViewWithFrame:(CGRect)frame imageUrls:(NSArray *)imageUrls;
+ (instancetype)loopScrollViewWithFrame:(CGRect)frame
                              imageUrls:(NSArray *)imageUrls
                           timeInterval:(NSTimeInterval)timeInterval
                              didSelect:(HYBLoopScrollViewDidSelectItemBlock)didSelect
                              didScroll:(HYBLoopScrollViewDidScrollBlock)didScroll;

/**
 * 暂停循环
 */
- (void)pauseTimer;

/**
 *  开始循环
 */
- (void)startTimer;

@end
