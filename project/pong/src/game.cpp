/*
 * game.cpp
 *
 *  Created on: Oct 27, 2012
 *      Author: Cam
 */

#include "game.h"
#include "Singleplayer.h"
#include "SDL/SDL.h"
#include "util.h"
#include "Ball.h"
#include "Timer.h"

Game::Game() {

	LogInit("game.log");

	setState(INIT);


}

Game::~Game() {

	//Free the surface
	SDL_FreeSurface(screen);
	SDL_FreeSurface(background);

	//Quit SDL
	SDL_Quit();

}

bool Game::init() {

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


	// Load background image

	background = load_image( "images/background.png") ;

	apply_surface( 0, 0, background, screen );

	gamemenu.addButton( 170, 120, 300, 40, "images/SinglePlayer.png", SINGLEPLAYER);
	gamemenu.addButton( 170, 175, 300, 40, "images/TwoPlayer.png", MULT_LOCAL);
	gamemenu.addButton( 170, 230, 300, 40, "images/Online.png", MULT_ONLINE);
	gamemenu.addButton( 170, 285, 300, 40, "images/Highscore.png", MENU);
	gamemenu.addButton( 10, 430, 100, 40, "images/Credits.png", MENU);
	gamemenu.addButton( 530, 430, 100, 40, "images/Quit.png", QUIT);

	//If everything initialized fine

	setState(MENU);

	return true;

}

void Game::run() {

	while (getState() != QUIT) {

		switch (getState()) {


		case INIT:
			init();
			break ;

		case SINGLEPLAYER:
			startSinglePlayer();
			break;
		case MENU:

			displayMenu();

			break;

		case QUIT:
			break;

		}

	}

}

void Game::displayMenu() {

	SDL_Event event;

	LogWrite(toString(), "game.log");
	LogWrite(gamemenu.toString(), "game.log");

	// FPS test
	int frame = 0 ;
	Timer fps ;
	Timer update ;


	 update.start();

	 //Start the frame timer
	 fps.start();


	//While there's an event to handle
	while (state == MENU) {

		SDL_PollEvent(&event);

		//If the user has Xed out the window
		if (event.type == SDL_QUIT) {
			//Quit the program
			setState(QUIT);
		}


		switch (event.user.code) {

		case QUIT:
			setState(QUIT);
			break;
		case SINGLEPLAYER:
			setState(SINGLEPLAYER);
			break;
		default:
			break;

		}

		gamemenu.update( &event);
		gamemenu.draw( screen) ;


		//Update the screen
		if (SDL_Flip(screen) == -1) {
			return;
		}

		frame++;

		//If a second has passed since the caption was last updated
		if( update.get_ticks() > 1000 )
		{
			//The frame rate as a string
			std::stringstream caption;

			//Calculate the frames per second and create the string
			caption << "Pong - FPS: " << frame / ( fps.get_ticks() / 1000.f );

			//Reset the caption
			SDL_WM_SetCaption( caption.str().c_str(), NULL );

			//Restart the update timer
			update.start();
		}


	}

}

void Game::startSinglePlayer() {

	LogWrite("Starting singleplayer...", "game.log");

	currentGame = new Singleplayer(screen);


	currentGame->run();


	free(currentGame);

	// Game ended?
	setState(MENU);


}


int Game::getState() {

	return this->state;

}

void Game::setState(int state) {

	this->state = state;
}

std::string stateToString( int s ) {


	switch (s) {

	case INIT:
		return "INIT";
	case MENU:
		return "MENU";
	case SINGLEPLAYER:
		return "SINGLEPLAYER";
	case MULT_LOCAL:
		return "MULT_LOCAL";
	case MULT_ONLINE:
		return "MULT_ONLINE";
	case QUIT:
		return "QUIT";
	default:
		return "INVALID";

	}

	return "INVALID";

}

std::string Game::toString() {

	std::stringstream output ;

	output  << "State= " << stateToString(getState())
			<< " Background= " << this->background
			<< " Screen= " << this->screen;

	return output.str();


}
