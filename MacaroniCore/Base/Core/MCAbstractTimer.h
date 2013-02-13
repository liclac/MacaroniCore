//
//  MCAbstractTimer.h
//  MacaroniCore
//
//  Created by Johannes Ekberg on 2013-01-25.
//  Copyright (c) 2013 MacaroniCode. All rights reserved.
//

#ifndef __MacaroniCore__MCAbstractTimer__
#define __MacaroniCore__MCAbstractTimer__

/**
 * The MCAbstractTimer class is used to time sections of
 * code.
 * 
 * Since accurate timing is a platform-specific thing
 * (Windows, I'm looking at you), this class is left
 * abstract, with actual work left up to platform-specific
 * subclasses in the Additions module.
 * 
 * @see MC11Timer
 */
class MCAbstractTimer
{
	MCAbstractTimer();
	virtual ~MCAbstractTimer();
	
	/**
	 * Starts timing a section.
	 * 
	 * Forgetting to stop a timer generally doesn't hurt, but
	 * just in case you ever get one that actually /counts/ something,
	 * you should probably make sure to stop your timers properly.
	 */
	virtual void begin() {}
	
	/**
	 * Stops the timer.
	 * @returns the time the section took to complete, in seconds
	 */
	virtual double end() { return 0; }
};

#endif /* defined(__MacaroniCore__MCAbstractTimer__) */
