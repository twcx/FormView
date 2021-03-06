//
//  UIScrollView+XYEmptyView.h
//  DZNEmptyDataSet
//  https://github.com/dzenbot/DZNEmptyDataSet
//
//  Created by Ignacio Romero Zurbuchen on 6/20/14.
//  Copyright (c) 2016 DZN Labs. All rights reserved.
//  Licence: MIT-Licence
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@protocol XYEmptyDataSetSource;
@protocol XYEmptyDataSetDelegate;


@interface UIScrollView (XYEmptyView)

/** The empty datasets data source. */
@property (nonatomic, weak, nullable) id <XYEmptyDataSetSource> emptyDataSetSource;
/** The empty datasets delegate. */
@property (nonatomic, weak, nullable) id <XYEmptyDataSetDelegate> emptyDataSetDelegate;
/** YES if any empty dataset is visible. */
@property (nonatomic, readonly, getter = isEmptyDataSetVisible) BOOL emptyDataSetVisible;

- (void)reloadEmptyDataSet;

@end


@protocol XYEmptyDataSetSource <NSObject>
@optional

/**
 提示文字
 */
- (nullable NSString *)titleForEmptyDataSet:(UIScrollView *)scrollView;

/**
 提示图片
 */
- (nullable UIImage *)imageForEmptyDataSet:(UIScrollView *)scrollView;

/**
 按钮的文字，如果复写会有一个默认样式的按钮
 */
- (nullable NSString *)buttonTitleForEmptyDataSet:(UIScrollView *)scrollView forState:(UIControlState)state;


/**
 背景颜色
 */
- (nullable UIColor *)backgroundColorForEmptyDataSet:(UIScrollView *)scrollView;

/**
 上面的间距
 默认100pt
 */
- (CGFloat)topIntervalForEmptyDataSet:(UIScrollView *)scrollView;

/**
 自定义按钮
 */
- (nullable UIButton *)customButtonForEmptyDataSet:(UIScrollView *)scrollView;

@end


@protocol XYEmptyDataSetDelegate <NSObject>
@optional

/**
 按钮点击回调
 */
- (void)emptyDataSet:(UIScrollView *)scrollView didTapButton:(UIButton *)button;

/**
 强制显示，默认NO
 */
- (BOOL)emptyDataSetShouldBeForcedToDisplay:(UIScrollView *)scrollView;

/**
 应该显示，默认YES
 */
- (BOOL)emptyDataSetShouldDisplay:(UIScrollView *)scrollView;

/**
 是否允许滚动，默认NO
 */
- (BOOL)emptyDataSetShouldAllowScroll:(UIScrollView *)scrollView;


/**
 将要显示回调
 */
- (void)emptyDataSetWillAppear:(UIScrollView *)scrollView;

/**
 已经显示回调
 */
- (void)emptyDataSetDidAppear:(UIScrollView *)scrollView;

/**
 将要消失回调
 */
- (void)emptyDataSetWillDisappear:(UIScrollView *)scrollView;

/**
 已经消失回调
 */
- (void)emptyDataSetDidDisappear:(UIScrollView *)scrollView;

@end


@interface XYEmptyViewDataSource : NSObject

- (instancetype)init UNAVAILABLE_ATTRIBUTE;

- (instancetype)initWithCoder:(NSCoder * _Nullable)aDecoder UNAVAILABLE_ATTRIBUTE;

- (instancetype)initWithNibName:(NSString * _Nullable)nibNameOrNil bundle:(NSBundle * _Nullable)nibBundleOrNil UNAVAILABLE_ATTRIBUTE;

- (instancetype)initWithScrollView:(UIScrollView *)scrollView NS_DESIGNATED_INITIALIZER;

@property (nonatomic, strong) UIImage *image;

@property (nonatomic, strong) NSString *text;

/// Default 背景色 F5F8FA
@property (nonatomic, strong) UIColor *backgroundColor;

// 这个变量在网络完成是一定要设置
@property (nonatomic, assign) BOOL didNetwork;

@end

NS_ASSUME_NONNULL_END
