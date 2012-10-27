/*
 * game.h
 *
 *  Created on: Oct 27, 2012
 *      Author: Cam
 */

#ifndef GAME_H_
#define GAME_H_

enum gamestate {

	MENU,
	SINGLEPLAYER,
	MULT_LOCAL,
	MULT_ONLINE

};

class Game {

public:

	int getState();
	void setState( int state );

private:

	int state ;

};


#endif /* GAME_H_ */
