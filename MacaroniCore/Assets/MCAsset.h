//
//  MCAsset.h
//  MacaroniCore
//
//  Created by Johannes Ekberg on 2013-01-15.
//  Copyright (c) 2013 MacaroniCode. All rights reserved.
//

#ifndef __MacaroniCore__MCAsset__
#define __MacaroniCore__MCAsset__

#include <iostream>

class MCKernel;
class MCState;

/**
 * MCAsset represents a single on-disc asset.
 * 
 * All assets are considered lazy-loaded, and may be loaded or unloaded at
 * any time with the load() and unload() functions.
 */
class MCAsset
{
public:
	/**
	 * Initializes a lazy-loaded asset for the given path.
	 * @param source the source (implementation-dependent, usually a path) to load the data from.
	 */
	MCAsset(std::string &source);
	
	/**
	 * Destructor.
	 * The default implementation simply calls unload(),
	 * where you should be doing all your unloading anyways.
	 */
	virtual ~MCAsset();
	
	/**
	 * Abstract: Loads the asset's data into memory.
	 * If the data is already loaded, does nothing.
	 */
	virtual void load();
	
	/**
	 * Abstract: Unloads the asset's data.
	 * If the data is not already loaded, does nothing.
	 */
	virtual void unload();
	
	/**
	 * Returns whether the asset has its data in memory or not.
	 */
	virtual bool isLoaded() const;
	
	/**
	 * Returns the current retain count for the asset.
	 * A retain count refers to how many users the object currently has.
	 * An object with retain count of 0 may be deleted at any time.
	 * 
	 * An asset's retain count should NEVER change by any other means than retain() and release().
	 */
	virtual unsigned int retainCount() const;
	
	/**
	 * Retains the asset, increasing its retain count by 1.
	 *
	 * An asset's retain count should NEVER change by any other means than retain() and release().
	 */
	virtual void retain();
	
	/**
	 * Releases the asset, decreasing its retain count by 1.
	 *
	 * An asset's retain count should NEVER change by any other means than retain() and release().
	 */
	virtual void release();
	
private:
	std::string m_source;
	unsigned int m_retainCount;
};

#endif /* defined(__MacaroniCore__MCAsset__) */
