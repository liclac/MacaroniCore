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
	/**
	 * Initializes a new Logger.
	 * @param output the output stream to use, defaults to standard output
	 * @param prefix optional prefix 
	 */
	MCLogger(std::ostream& output = std::cout, const char* prefix = "") : m_output(output) { m_output << prefix; }
	
	/// Destructor, which appends a newline to the output stream before termination
	~MCLogger() { m_output << std::endl; }
	
	/// Logs the given... thing
	template <typename T>
	MCLogger & operator<< (const T &thing) {
		m_output << thing; return *this;
	}
	MCLogger & operator<< (const std::string &string) { return this->operator<<(string.c_str()); }
	
private:
	std::ostream& m_output;
};

inline MCLogger mclDebug() { return MCLogger(std::cout, "[DEBUG] "); }		///< Returns a temporary Debug logger
inline MCLogger mclInfo() { return MCLogger(std::cout, "> "); }				///< Returns a temporary Info logger
inline MCLogger mclWarning() { return MCLogger(std::cout, "[!] "); }		///< Returns a temporary Warning logger
inline MCLogger mclError() { return MCLogger(std::cout, "[ERROR] "); }		///< Returns a temporary Error logger

#endif /* defined(__MacaroniCore__MCLogger__) */
