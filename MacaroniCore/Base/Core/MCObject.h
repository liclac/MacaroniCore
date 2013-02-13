/*
 * MCObject.h
 *
 *  Created on: 12 feb 2013
 *      Author: Johannes Ekberg
 */

#ifndef MCOBJECT_H_
#define MCOBJECT_H_

class MCKernel;

class MCObject
{
public:
	MCObject(MCKernel *kernel);
	virtual ~MCObject();
	
protected:
	MCKernel *m_kernel;
};

#endif /* MCOBJECT_H_ */
