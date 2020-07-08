//
//  RYVRPLFGLViewController.h
//  RYVRPlatform
//
//  Created by Single on 2017/3/29.
//  Copyright © 2017年 single. All rights reserved.
//

#import "RYVRPLFOpenGL.h"

#import "RYVRPLFGLView.h"

#if SGPLATFORM_TARGET_OS_MAC


@interface RYVRPLFGLViewController : NSViewController <RYVRPLFGLViewDelegate>

@property (nonatomic, getter=isPaused) BOOL paused;

@property (nonatomic, assign) NSInteger preferredFramesPerSecond;

@end


#elif SGPLATFORM_TARGET_OS_IPHONE_OR_TV


typedef GLKViewController RYVRPLFGLViewController;


#endif

RYVRPLFGLView * RYVRPLFGLViewControllerGetGLView(RYVRPLFGLViewController * viewController);
