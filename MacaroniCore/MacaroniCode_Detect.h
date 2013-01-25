//
//  MacaroniCode_Detect.h
//  MacaroniCore
//
//  Created by Johannes Ekberg on 2013-01-25.
//  Copyright (c) 2013 MacaroniCode. All rights reserved.
//

#ifndef MacaroniCore_MacaroniCode_Detect_h
#define MacaroniCore_MacaroniCode_Detect_h

#include "MacaroniCore_Internal.h"

// According to the C++0x specification, __cplusplus should hold the C++ language version
// ...but GCC (g++) took until v4.7 to do this right, so, override time
#define MC_USE_CPP_11	(__cplusplus >= 201103L || __GNUC__ > 4 || (__GNUC__ == 4 && __GNUC_MINOR__ >= 3))
#define MC_USE_OpenGL	(defined(__gl_h_) || defined(__gl3_h_))

#endif
