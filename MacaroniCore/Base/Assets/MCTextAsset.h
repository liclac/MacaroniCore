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
	/// Initializes a Text Asset with the contents of the file at the given path
	MCTextAsset(std::string &source);
	
	virtual std::string text();			///< Returns the file's contents
	
	virtual void load();				///< Loads the file into memory
	virtual void unload();				///< Unloads the file from memory
	
protected:
	std::string m_data;					///< The file's contents
};

#endif /* defined(__MacaroniCore__MCTextAsset__) */
