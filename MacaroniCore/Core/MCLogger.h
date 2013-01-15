//
//  MCLogger.h
//  MacaroniCore
//
//  Created by Johannes Ekberg on 2013-01-15.
//  Copyright (c) 2013 MacaroniCode. All rights reserved.
//

#ifndef __MacaroniCore__MCLogger__
#define __MacaroniCore__MCLogger__

#include <iostream>

class MCLogger
{
public:
	MCLogger(std::ostream& output = std::cout, const char* prefix = "") : m_output(output) { m_output << prefix; }
	~MCLogger() { m_output << std::endl; }
	
	template <typename T> MCLogger & operator<< (const T &thing) { m_output << thing; return *this; }
	
private:
	std::ostream& m_output;
};

inline MCLogger mclDebug() { return MCLogger(std::cout, "[DEBUG] "); }
inline MCLogger mclInfo() { return MCLogger(std::cout, "> "); }
inline MCLogger mclWarning() { return MCLogger(std::cout, "[!] "); }
inline MCLogger mclError() { return MCLogger(std::cout, "[ERROR] "); }

#endif /* defined(__MacaroniCore__MCLogger__) */
