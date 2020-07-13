//
//  RYVRPLFView.h
//  RYVRPlatform
//
//  Created by Single on 2017/2/24.
//  Copyright © 2017年 single. All rights reserved.
//

#import "RYVRPLFObject.h"

#import "RYVRPLFImage.h"
#import "RYVRPLFColor.h"

#if SGPLATFORM_TARGET_OS_MAC


typedef NSView RYVRPLFView;


#elif SGPLATFORM_TARGET_OS_IPHONE_OR_TV


typedef UIView RYVRPLFView;


#endif

void RYVRPLFViewSetBackgroundColor(RYVRPLFView * view, RYVRPLFColor * color);
void RYVRPLFViewInsertSubview(RYVRPLFView * superView, RYVRPLFView * subView, NSInteger index);

RYVRPLFImage * RYVRPLFViewGetCurrentSnapshot(RYVRPLFView * view);
