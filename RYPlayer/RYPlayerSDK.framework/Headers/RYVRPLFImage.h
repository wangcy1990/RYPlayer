//
//  RYVRPLFImage.h
//  RYVRPlatform
//
//  Created by Single on 2017/2/24.
//  Copyright © 2017年 single. All rights reserved.
//

#import "RYVRPLFObject.h"

#import <CoreVideo/CoreVideo.h>
#import <CoreImage/CoreImage.h>

#if SGPLATFORM_TARGET_OS_MAC


typedef NSImage RYVRPLFImage;


#elif SGPLATFORM_TARGET_OS_IPHONE_OR_TV


typedef UIImage RYVRPLFImage;


#endif

RYVRPLFImage * RYVRPLFImageWithCGImage(CGImageRef image);

// CVPixelBufferRef
RYVRPLFImage * RYVRPLFImageWithCVPixelBuffer(CVPixelBufferRef pixelBuffer);
CIImage * RYVRPLFImageCIImageWithCVPexelBuffer(CVPixelBufferRef pixelBuffer);
CGImageRef RYVRPLFImageCGImageWithCVPexelBuffer(CVPixelBufferRef pixelBuffer);

// RGB data buffer
RYVRPLFImage * RYVRPLFImageWithRGBData(UInt8 * rgb_data, int linesize, int width, int height);
CGImageRef RYVRPLFImageCGImageWithRGBData(UInt8 * rgb_data, int linesize, int width, int height);
