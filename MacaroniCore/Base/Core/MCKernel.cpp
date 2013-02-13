//
//  MCKernel.cpp
//  MacaroniCore
//
//  Created by Johannes Ekberg on 2013-01-14.
//  Copyright (c) 2013 MacaroniCode. All rights reserved.
//

#include "MCKernel.h"
#include "MCLogger.h"
#include "../States/MCState.h"

MCKernel::MCKernel():
	m_stopping(false)
{
	
}

MCKernel::~MCKernel() { this->shutdown(); }

void MCKernel::stop() { m_stopping = true; }

void MCKernel::tick(bool render)
{
	//TODO: Rewrite this function to use Iterators rather than indices
	unsigned int firstOpaque = 0;
	for(unsigned int i = m_stateStack.size() - 1; i >= 0; i--)
		if(m_stateStack[i]->isOpaque()) firstOpaque = i;
	
	for(unsigned int i = firstOpaque; i < m_stateStack.size(); i++)
		m_stateStack[i]->update();
	for(unsigned int i = firstOpaque; i < m_stateStack.size(); i++)
		m_stateStack[i]->render();
}

bool MCKernel::isRunning() { return m_stopping; }

void MCKernel::pushState(MCState *state) { m_stateStack.push_back(state); }

void MCKernel::popState() { m_stateStack.pop_back(); }

void MCKernel::setStates(std::deque<MCState *> states) { m_stateStack = states; }

void MCKernel::startup() { }

void MCKernel::shutdown() { }
