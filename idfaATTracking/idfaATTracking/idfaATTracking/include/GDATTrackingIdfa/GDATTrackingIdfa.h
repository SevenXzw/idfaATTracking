//
//  GDATTrackingIdfa.h
//  GameDreamer
//
//  Created by 许振文 on 2020/12/20.
//  Copyright © 2020 许振文. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN
typedef NS_ENUM(NSInteger, GDATTrackingStatus) {
    GDATTrackingStatusNotDetermined = 0, //ATTrackingManagerAuthorizationStatusNotDetermined
    GDATTrackingStatusRestricted,        //ATTrackingManagerAuthorizationStatusRestricted
    GDATTrackingStatusDenied,            //ATTrackingManagerAuthorizationStatusDenied
    GDATTrackingStatusAuthorized,        //ATTrackingManagerAuthorizationStatusAuthorized
    GDATTrackingStatusNeedSetting,       //请前往info.plist增加NSUserTrackingUsageDescription的配置
    GDATTrackingStatusNone               //系统不支持ios14idfa
};

typedef NS_ENUM(NSInteger, GDATTrackingAlertIndex) {
    GDATTrackingAlertIndexNone = 0,
    GDATTrackingAlertIndexSure,
    GDATTrackingAlertIndexCancel
};

@interface GDATTrackingIdfa : NSObject

/**
 *  ios14 idfa授权流程 --》注意项，当前模拟器默认是没有AppTrackingTransparency.framework的，所以idfa授权只能在真机中进行授权，但是如果有做模拟器的需求的话，可以自行在模拟器环境中增加AppTrackingTransparency.framework
 *
 *  @param alert                  是否使用内部方法弹框提示，弹框只在ATTrackingManagerAuthorizationStatusDenied的时候进行弱提示并前往设置添加权限
 *  @param message             如果alert=true时，显示alert提示信息
 *  @param complete           回调
 */
+ (void)makeIdfaPermission:(BOOL)alert alertMessage:(NSString *)message complete:(void(^)(GDATTrackingStatus status))complete;

/**
 *  授权弱提示
 *
 *  @param message             信息显示
 *  @param complete           回调
 */
+ (void)showAlert:(NSString *)message complete:(void(^)(GDATTrackingAlertIndex status))complete;

@end

NS_ASSUME_NONNULL_END
