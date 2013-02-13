/*
 * MCAbstractShader.h
 *
 *  Created on: 13 feb 2013
 *      Author: Johannes Ekberg
 */

#ifndef MCABSTRACTSHADER_H_
#define MCABSTRACTSHADER_H_

#include "MCObject.h"

class MCAbstractShader: public MCObject
{
public:
	MCAbstractShader(MCKernel *kernel);
	virtual ~MCAbstractShader();
};

#endif /* MCABSTRACTSHADER_H_ */
