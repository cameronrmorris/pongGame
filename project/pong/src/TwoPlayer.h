/*
 * TwoPlayer.h
 *
 *  Created on: Feb 8, 2013
 *      Author: cam
 */

#ifndef TWOPLAYER_H_
#define TWOPLAYER_H_

#include "Singleplayer.h"

class TwoPlayer: public Singleplayer {
public:
	TwoPlayer(SDL_Surface *screen);
	virtual ~TwoPlayer();
};

#endif /* TWOPLAYER_H_ */
