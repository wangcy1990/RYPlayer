//
//  RYVRPLFGLContext.h
//  RYVRPlatform
//
//  Created by Single on 2017/2/23.
//  Copyright © 2017年 single. All rights reserved.
//

#import "RYVRPLFOpenGL.h"

#if SGPLATFORM_TARGET_OS_MAC


typedef NSOpenGLContext RYVRPLFGLContext;

NSOpenGLPixelFormat * RYVRPLFGLContextGetPixelFormat(RYVRPLFGLContext * context);


#elif SGPLATFORM_TARGET_OS_IPHONE_OR_TV


typedef EAGLContext RYVRPLFGLContext;


#endif

RYVRPLFGLContext * RYVRPLFGLContextAllocInit();
void SGPLGLContextSetCurrentContext(RYVRPLFGLContext * context);
