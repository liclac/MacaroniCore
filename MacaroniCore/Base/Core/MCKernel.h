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
#pragma mark -
public:
#pragma mark Lifecycle
	/**
	 * Initializes the Kernel.
	 * Note that you must call MCKernel::start() to actually start execution.
	 */
	MCKernel();
	
	/**
	 * Destructor for the Kernel.
	 * The default implementation simply calls MCKernel::shutdown()
	 */
	virtual ~MCKernel();
	
#pragma mark State Alteration
	/**
	 * "Boots Up" the Kernel.
	 * 
	 * This will perform internal initialization and call startup(),
	 * then call MCKernel::run().
	 * Once MCKernel::run() returns, the shutdown process will begin,
	 * regardless of MCKernel::isStopping().
	 * 
	 * @see MCKernel::shutdown()
	 * @see MCKernel::run()
	 */
	void start();
	
	/**
	 * "Shuts Down" the Kernel.
	 * 
	 * This will guarantee that MCKernel::isStopping() returns true,
	 * the MCKernel::run() loop is then expected to return as soon as
	 * possible.
	 * 
	 * @see MCKernel::start()
	 */
	void stop();
	
#pragma mark Setters
	/// Attempt to keep to the specified framerate, by sleeping between loops; 0 = no limit
	void setTargetFPS(int targetFPS);
	
#pragma mark -
protected:
#pragma mark Main loop
	/**
	 * Runs a Main Loop.
	 *
	 * You can override this function if you'd prefer to do your
	 * main loop in a nonstandard way, to skip unused steps or if
	 * your platform requires it.
	 */
	virtual void run();
	
	/// Abstract function for custom initialization.
	virtual void startup();
	
	/// Abstract function for custom cleanup.
	virtual void shutdown();
	
	/**
	 * Returns whether the main loop should continue past the current iteration.
	 * The default implementation merely checks `m_stopping`.
	 * 
	 * Future versions may check other conditions, so if overriding this to
	 * add your own checks, make sure you check the return value of this function
	 * rather than m_stopping directly.
	 */
	virtual bool isRunning();
	
protected:
	bool m_stopping;
	int m_targetFPS;
};

#endif /* defined(__MacaroniCore__MCKernel__) */
