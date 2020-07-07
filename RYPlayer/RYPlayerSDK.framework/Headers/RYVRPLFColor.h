//
//  RYVRPLFColor.h
//  RYVRPlatform
//
//  Created by Single on 2017/2/24.
//  Copyright © 2017年 single. All rights reserved.
//

#import "RYVRPLFObject.h"

#if SGPLATFORM_TARGET_OS_MAC


typedef NSColor RYVRPLFColor;


#elif SGPLATFORM_TARGET_OS_IPHONE_OR_TV


typedef UIColor RYVRPLFColor;


#endif
