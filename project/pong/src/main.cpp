/*
 * main.cpp
 *
 *  Created on: Oct 25, 2012
 *      Author: Cam
 */

#include <iostream>
#include "SDL/SDL.h"
#include "game.h"
#include "util.h"

int main( int argc, char *argv[]) {

	LogInit("game.log");

	Game game;

	game.run();

	return 0;

}

