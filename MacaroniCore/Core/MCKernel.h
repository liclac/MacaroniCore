//
//  MCKernel.h
//  MacaroniCore
//
//  Created by Johannes Ekberg on 2013-01-14.
//  Copyright (c) 2013 MacaroniCode. All rights reserved.
//

#ifndef __MacaroniCore__MCKernel__
#define __MacaroniCore__MCKernel__

#include <iostream>

class MCKernel
{
public:
	MCKernel();
	virtual ~MCKernel();
	
protected:
	virtual void startup();
	virtual void shutdown();
};

#endif /* defined(__MacaroniCore__MCKernel__) */
