//
//  ViewController.m
//  HYBLoopScrollView
//
//  Created by huangyibiao on 15/4/1.
//  Copyright (c) 2015年 huangyibiao. All rights reserved.
//

#import "ViewController.h"
#import "HYBLoopScrollView.h"

@interface ViewController ()

@end

@implementation ViewController

- (void)viewDidLoad {
  [super viewDidLoad];
  
  NSString *url = @"http://test.meirongzongjian.com/imageServer/user/3/42ccb9c75ccf5e910cd6f5aaf0cd1200.jpg";
  NSArray *images = @[@"h1.jpg",
                      [UIImage imageNamed:@"h2.jpg"],
                      [UIImage imageNamed:@"h3.jpg"],
                      url
                      ];
  
  NSArray *titles = @[@"Thank you for your support!",
                      @"Contact me if any quetion.",
                      @"Email me huangyibiao520@163.com.",
                      @"Thank you again."
                      ];
  
  //有图有标题ScrollView
  HYBLoopScrollView *loop = [HYBLoopScrollView loopScrollViewWithFrame:CGRectMake(0, 40, 320, 120) imageUrls:images];
  loop.timeInterval = 2;
  loop.placeholder = [UIImage imageNamed:@"h1.jpg"];
  __weak __typeof(loop) weakLoop = loop;
    
    //点击那个图片执行事件
  loop.didSelectItemBlock = ^(NSInteger atIndex, HYBLoadImageView *sender) {
    NSLog(@"clicked item at index: %ld", atIndex);
    [weakLoop pauseTimer];
  };
   
    //滚到当前位置自动执行事件
  loop.didScrollBlock = ^(NSInteger atIndex, HYBLoadImageView *sender) {
    NSLog(@"scroll to index: %ld", atIndex);
  };
    
  loop.alignment = kPageControlAlignRight;
  loop.adTitles = titles;

  [self.view addSubview:loop];
  
  
    
    
  //只有图片的ScrollView
  HYBLoopScrollView *loop1 = [HYBLoopScrollView loopScrollViewWithFrame:CGRectMake(0, loop.hyb_bottomY + 100, 320, 120) imageUrls:images timeInterval:10.0 didSelect:^(NSInteger atIndex, HYBLoadImageView *sender) {
      //点击图片执行此事件
    NSLog(@"clicked item at index: %ld", (long)atIndex);
    
    [loop startTimer];
  } didScroll:^(NSInteger toIndex, HYBLoadImageView *sender) {
      //滚到当前位置自动执行事件
    NSLog(@"scroll to index: %ld", (long)toIndex);
  }];
  

  [self.view addSubview:loop1];
  
}


@end
