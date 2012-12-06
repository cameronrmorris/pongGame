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

int main(int argc, char *argv[]) {

	Game *game;
	SDL_Surface *screen;

	//Initialize all SDL subsystems
	if (SDL_Init(SDL_INIT_EVERYTHING) == -1) {
		return false;
	}

	//Set up the screen
	screen = SDL_SetVideoMode(SCREEN_WIDTH, SCREEN_HEIGHT, BIT_DEPTH,
			SDL_SWSURFACE);

	//If there was an error in setting up the screen
	if (screen == NULL) {
		return false;
	}

	//Set the window caption
	SDL_WM_SetCaption("Pong", NULL);

	LogInit("game.log");

	game = new Game(screen);

	game->run();

	SDL_FreeSurface(screen);

	SDL_Quit();


	return 0;

}

