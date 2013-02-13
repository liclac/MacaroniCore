/*
 * MCObject.cpp
 *
 *  Created on: 12 feb 2013
 *      Author: Johannes Ekberg
 */

#include "MCObject.h"
#include "MCKernel.h"

MCObject::MCObject(MCKernel *kernel):
	m_kernel(kernel)
{}

MCObject::~MCObject() {}

