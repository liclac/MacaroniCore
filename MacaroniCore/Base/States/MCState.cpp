//
//  MCState.cpp
//  MacaroniCore
//
//  Created by Johannes Ekberg on 2013-01-15.
//  Copyright (c) 2013 MacaroniCode. All rights reserved.
//

#include "MCState.h"

MCState::MCState(MCKernel *kernel):
	MCObject(kernel)
{}

MCState::~MCState() {}

bool MCState::isOpaque() { return true; }

void MCState::update() {}

void MCState::render() {}
