//
//  MCKernel.h
//  MacaroniCore
//
//  Created by Johannes Ekberg on 2013-01-14.
//  Copyright (c) 2013 MacaroniCode. All rights reserved.
//

#ifndef __MacaroniCore__MCKernel__
#define __MacaroniCore__MCKernel__

#include <deque>

class MCState;

class MCKernel
{
public:
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
	
	/**
	 * "Shuts Down" the Kernel.
	 * 
	 * This will guarantee that MCKernel::isRunning() returns false,
	 * the main loop is then expected to return as soon as
	 * possible.
	 * 
	 * @see MCKernel::start()
	 */
	void stop();
	
	/**
	 * "Ticks" once. This should be called for each frame in your main loop.
	 * 
	 * You should measure the time this function takes, and determine whether
	 * there is enough time to redraw the screen from that. Pass false to `render`
	 * to "drop" the next frame.
	 * 
	 * @param tick Whether the screen should be redrawn
	 */
	virtual void tick(bool render);
	
	/**
	 * Returns whether the main loop should continue past the current iteration.
	 * The default implementation merely checks `m_stopping`.
	 * 
	 * Future versions may check other conditions, so if overriding this to
	 * add your own checks, make sure you check the return value of this function
	 * rather than m_stopping directly.
	 */
	virtual bool isRunning();
	
	/**
	 * Pushes a state onto the top of the State Stack.
	 */
	void pushState(MCState *state);
	
	/**
	 * Pops the topmost state off the state stack.
	 */
	void popState();
	
	/**
	 * Replaces the current state stack with the given array.
	 */
	void setStates(std::deque<MCState *> states);
	
protected:
	/// Abstract function for custom initialization.
	virtual void startup();
	
	/// Abstract function for custom cleanup.
	virtual void shutdown();
	
protected:
	bool m_stopping;
	std::deque<MCState *> m_stateStack;
};

#endif /* defined(__MacaroniCore__MCKernel__) */
