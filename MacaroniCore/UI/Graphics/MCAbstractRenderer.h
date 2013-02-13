/*
 * MCAbstractRenderer.h
 *
 *  Created on: 12 feb 2013
 *      Author: Johannes Ekberg
 */

#ifndef MCABSTRACTRENDERER_H_
#define MCABSTRACTRENDERER_H_

#include "../../Base/Core/MCObject.h"

class MCRenderedThing;

class MCAbstractRenderer: public MCObject
{
public:
	MCAbstractRenderer(MCKernel *kernel) : MCObject(kernel) {};
	virtual ~MCAbstractRenderer() {};
	
	virtual void begin() {};
	virtual void end() {};
	
	virtual void draw(MCRenderedThing *thing) {};
};

#endif /* MCABSTRACTRENDERER_H_ */
