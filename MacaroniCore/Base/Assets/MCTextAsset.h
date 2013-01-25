//
//  MCTextAsset.h
//  MacaroniCore
//
//  Created by Johannes Ekberg on 2013-01-15.
//  Copyright (c) 2013 MacaroniCode. All rights reserved.
//

#ifndef __MacaroniCore__MCTextAsset__
#define __MacaroniCore__MCTextAsset__

#include <iostream>
#include "MCAsset.h"

class MCTextAsset : MCAsset
{
public:
	MCTextAsset(std::string &source);
	
	virtual std::string text();
	
	virtual void load();
	virtual void unload();
	
private:
	std::string m_data;
};

#endif /* defined(__MacaroniCore__MCTextAsset__) */
