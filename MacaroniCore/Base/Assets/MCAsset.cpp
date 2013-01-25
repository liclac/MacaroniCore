//
//  MCAsset.cpp
//  MacaroniCore
//
//  Created by Johannes Ekberg on 2013-01-15.
//  Copyright (c) 2013 MacaroniCode. All rights reserved.
//

#include "MCAsset.h"

MCAsset::MCAsset(std::string &source) :
	m_source(source), m_retainCount(1)
{ }

MCAsset::~MCAsset() { this->unload(); }

void MCAsset::load() { m_loaded = true; }

void MCAsset::unload() { m_loaded = false; }

bool MCAsset::isLoaded() const { return m_loaded; }

unsigned int MCAsset::retainCount() const { return m_retainCount; }

void MCAsset::retain() { m_retainCount++; }

void MCAsset::release() { m_retainCount--; }
