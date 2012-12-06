/*
 * game.h
 *
 *  Created on: Oct 27, 2012
 *      Author: Cam
 */

#ifndef GAME_H_
#define GAME_H_

#include "SDL/SDL.h"
#include "menu.h"
#include <string>
#include <sstream>

#define SCREEN_WIDTH 640
#define SCREEN_HEIGHT 480
#define BIT_DEPTH 32
#define FRAMES_PER_SECOND 60

enum gamestate {

	INIT,
	MENU,
	SINGLEPLAYER,
	MULT_LOCAL,
	MULT_ONLINE,
	QUIT

};

class Game {

public:

	Game(SDL_Surface *screen);
	virtual ~Game();

	virtual bool init();  // This will setup everything before the game actually loads
	virtual void run(); // This will initially open the menu and go from there

	void displayMenu();

	void startSinglePlayer();

	int getState();
	void setState( int state );

	virtual std::string toString() ;
	Game* getCurrentGame() ;
	void setCurrentGame(Game* currentGame);
	SDL_Surface* getBackground() ;
	void setBackground(SDL_Surface* background);
	menu getGamemenu() ;
	void setGamemenu(menu gamemenu);
	SDL_Surface* getScreen() ;
	void setScreen(SDL_Surface* screen);

private:

	int state ;
	SDL_Surface* screen ;
	SDL_Surface* background ;

	menu gamemenu ;

	// Instance of the playable game being run
	Game *currentGame;



};


#endif /* GAME_H_ */
