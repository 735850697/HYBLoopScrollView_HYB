//
//  HYBLoadImageView.h
//
//  Created by 黄仪标 on 14/11/17.
//  Copyright (c) 2014年 黄仪标. All rights reserved.
//

#import <UIKit/UIKit.h>

@class HYBLoadImageView;

typedef void (^HYBTapImageViewBlock)(HYBLoadImageView *imageView);
typedef void (^HYBImageBlock)(UIImage *image);

/**
 *  @blog   http://www.henishuo.com/ios-open-source-hybloopscrollview/
 *
 */
@interface HYBLoadImageView : UIImageView

/**
 *  Set to YES and it will be animated when image is loaded from network.
 *  If it it loaded from disk, it will be ignored.
 *  Default is YES.
 */
@property (nonatomic, assign) BOOL animated;

/**
 *  Set the control to be circle.
 *  Default is NO.
 */
@property (nonatomic, assign) BOOL isCircle;

/**
 *  Get/Set the callback block when download the image finished.
 *
 *  @param image The image object from network or from disk.
 */
@property (nonatomic, copy) HYBImageBlock completion;

/**
 *  Get/Set the call back block when the image view is tapped.
 *  
 *  @note Only when property tapImageViewBlock is setted, will it add a tap gesture.
 *        When set it to be nil, the tap gesture will be removed automatically.
 *
 *  @param imageView The event receiver.
 */
@property (nonatomic, copy) HYBTapImageViewBlock tapImageViewBlock;

/**
 *  Use these methods to download image async.
 */

/**
 *  加载图片
 *
 *  @param url              图片Url
 *  @param placeholderImage 默认图片
 */
- (void)setImageWithURLString:(NSString *)url placeholderImage:(NSString *)placeholderImage;
- (void)setImageWithURLString:(NSString *)url placeholder:(UIImage *)placeholderImage;
- (void)setImageWithURLString:(NSString *)url
                  placeholder:(UIImage *)placeholderImage
                   completion:(void (^)(UIImage *image))completion;
- (void)setImageWithURLString:(NSString *)url
             placeholderImage:(NSString *)placeholderImage
                   completion:(void (^)(UIImage *image))completion;

/**
 *  取消加载
 */
- (void)cancelRequest;

@end
