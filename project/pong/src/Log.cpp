/*
 * Log.cpp
 *
 *  Created on: Nov 5, 2012
 *      Author: Cam
 */

#include "Log.h"

Log::Log() {

	file.open("game.log", std::ios::out);

	write("Log opened.\n");


}

Log::~Log() {

	file.close();
}

void Log::write(std::string text) {

	if (file.is_open())
		file << text;

}
