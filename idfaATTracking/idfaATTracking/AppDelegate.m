//
//  AppDelegate.m
//  idfaATTracking
//
//  Created by 许振文 on 2021/1/22.
//

#import "AppDelegate.h"
#import "ViewController.h"
#import "GDATTrackingIdfa.h"
    
@interface AppDelegate ()

@end

@implementation AppDelegate


- (BOOL)application:(UIApplication *)application didFinishLaunchingWithOptions:(NSDictionary *)launchOptions {
    self.window = [[UIWindow alloc] initWithFrame:[UIScreen mainScreen].bounds];
    self.window.rootViewController = [[UINavigationController alloc] initWithRootViewController:[[ViewController alloc] init]];
    [self.window makeKeyAndVisible];
    
    // Override point for customization after application launch.
    [GDATTrackingIdfa makeIdfaPermission:true alertMessage:@"请给予idfa权限～" complete:^(GDATTrackingStatus status) {
        //具体请看api说明
    }];
    
    return YES;
}

@end
