/*
 * Singleplayer.h
 *
 *  Created on: Nov 1, 2012
 *      Author: Cam
 */

#ifndef SINGLEPLAYER_H_
#define SINGLEPLAYER_H_
#include "game.h"
#include "Entity.h"
#include <vector>

enum singleStates {

	PLAYING,
	PAUSE

};


class Singleplayer : public Game {
public:

	Singleplayer(SDL_Surface *screen);
	virtual ~Singleplayer();
	virtual bool init();  // This will setup everything before the game actually loads
	virtual void run(); // This will initially open the menu and go from there
	virtual void draw(); // This will redraw the window
	virtual void update(SDL_Event* event, Uint32 ticks); // This will update eveyrthing in the game
	int getState() const;
	void setState(int state);

private:

	int state ;

	std::vector<Entity*> entities ;
};

#endif /* SINGLEPLAYER_H_ */
