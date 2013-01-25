//
//  MCKernel.cpp
//  MacaroniCore
//
//  Created by Johannes Ekberg on 2013-01-14.
//  Copyright (c) 2013 MacaroniCode. All rights reserved.
//

#include "MCKernel.h"
#include "MCLogger.h"

MCKernel::MCKernel():
	m_stopping(false), m_targetFPS(0)
{
	
}

MCKernel::~MCKernel() { this->shutdown(); }

void MCKernel::start()
{
	this->startup();
	this->run();
	this->shutdown();
}

void MCKernel::stop() { m_stopping = true; }

void MCKernel::setTargetFPS(int targetFPS) { m_targetFPS = targetFPS; }

void MCKernel::run()
{
	while(this->isRunning())
	{
		
	}
}

void MCKernel::startup() { }

void MCKernel::shutdown() { }

bool MCKernel::isRunning() { return m_stopping; }
