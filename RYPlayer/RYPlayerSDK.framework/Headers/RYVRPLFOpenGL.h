//
//  RYVRPLFOpenGL.h
//  RYVRPlatform
//
//  Created by Single on 2017/2/24.
//  Copyright © 2017年 single. All rights reserved.
//

#ifndef RYVRPLFOpenGL_h
#define RYVRPLFOpenGL_h

#import "RYVRPLFTargets.h"
#import <GLKit/GLKit.h>

#if SGPLATFORM_TARGET_OS_MAC


#import <Cocoa/Cocoa.h>
#import <OpenGL/OpenGL.h>
#import <OpenGL/gl.h>


#elif SGPLATFORM_TARGET_OS_IPHONE_OR_TV


#import <UIKit/UIKit.h>
#import <OpenGLES/ES2/gl.h>
#import <OpenGLES/ES2/glext.h>


#endif

#endif /* RYVRPLFOpenGL_h */
