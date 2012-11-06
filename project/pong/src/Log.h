/*
 * Log.h
 *
 *  Created on: Nov 5, 2012
 *      Author: Cam
 */

#ifndef LOG_H_
#define LOG_H_

#include <iostream>
#include <fstream>
#include <string>
class Log {

public:
	Log();
	virtual ~Log();

	void write( std::string text );

private:

	std::ofstream file;

};

#endif /* LOG_H_ */
