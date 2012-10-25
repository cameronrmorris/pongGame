/*
 * main.cpp
 *
 *  Created on: Oct 25, 2012
 *      Author: Cam
 */

#include <iostream>
#include "SDL/SDL.h"


int main( int argc, char *argv[]) {

	SDL_Init( SDL_INIT_EVERYTHING );


	std::cout << "Hello world" << std::endl;

	SDL_Quit();

	return 0;

}

