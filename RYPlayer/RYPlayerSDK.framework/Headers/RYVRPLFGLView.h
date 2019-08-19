//
//  RYVRPLFGLView.h
//  RYVRPlatform
//
//  Created by Single on 2017/2/23.
//  Copyright © 2017年 single. All rights reserved.
//

#import "RYVRPLFOpenGL.h"

#import "RYVRPLFGLContext.h"
#import "RYVRPLFImage.h"

#if SGPLATFORM_TARGET_OS_MAC


@interface RYVRPLFGLView : NSOpenGLView

@end

@protocol RYVRPLFGLViewDelegate <NSObject>
- (void)glkView:(RYVRPLFGLView *)view drawInRect:(CGRect)rect;
@end


#elif SGPLATFORM_TARGET_OS_IPHONE_OR_TV


typedef GLKView RYVRPLFGLView;

@protocol RYVRPLFGLViewDelegate <GLKViewDelegate>
- (void)glkView:(RYVRPLFGLView *)view drawInRect:(CGRect)rect;
@end


#endif

void RYVRPLFGLViewDisplay(RYVRPLFGLView * view);
void RYVRPLFGLViewSetDrawDelegate(RYVRPLFGLView * view, id <RYVRPLFGLViewDelegate> drawDelegate);
void RYVRPLFGLViewSetContext(RYVRPLFGLView * view, RYVRPLFGLContext * context);
RYVRPLFGLContext * RYVRPLFGLViewGetContext(RYVRPLFGLView * view);
void RYVRPLFGLViewPrepareOpenGL(RYVRPLFGLView * view);
void RYVRPLFGLViewFlushBuffer(RYVRPLFGLView * view);
void RYVRPLFGLViewBindFrameBuffer(RYVRPLFGLView * view);
RYVRPLFImage * RYVRPLFGLViewGetCurrentSnapshot(RYVRPLFGLView * view);
