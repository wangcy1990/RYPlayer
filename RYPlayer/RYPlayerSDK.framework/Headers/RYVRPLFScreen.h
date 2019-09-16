//
//  RYVRPLFScreen.h
//  RYVRPlatform
//
//  Created by Single on 2017/2/24.
//  Copyright © 2017年 single. All rights reserved.
//

#import "RYVRPLFObject.h"

#if SGPLATFORM_TARGET_OS_MAC


typedef NSScreen RYVRPLFScreen;


#elif SGPLATFORM_TARGET_OS_IPHONE_OR_TV


typedef UIScreen RYVRPLFScreen;


#endif

CGFloat RYVRPLFScreenGetScale();
