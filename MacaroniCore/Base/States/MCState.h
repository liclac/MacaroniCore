//
//  MCState.h
//  MacaroniCore
//
//  Created by Johannes Ekberg on 2013-01-15.
//  Copyright (c) 2013 MacaroniCode. All rights reserved.
//

#ifndef __MacaroniCore__MCState__
#define __MacaroniCore__MCState__

#include "../Core/MCObject.h"

class MCState : public MCObject
{
public:
	MCState(MCKernel *kernel);
	virtual ~MCState();
	
	virtual bool isOpaque();
	virtual void update();
	virtual void render();
};

#endif /* defined(__MacaroniCore__MCState__) */
