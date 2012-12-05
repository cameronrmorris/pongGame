/*
 * Entity.h
 *
 *  Created on: Nov 5, 2012
 *      Author: Cam
 */

#ifndef ENTITY_H_
#define ENTITY_H_

#include "SDL/SDL.h"
#include <string>
#include <sstream>


class Entity {
public:
	Entity( std::string image);
	virtual ~Entity();
	virtual void draw( SDL_Surface* screen );
	virtual void update( SDL_Event* event, Uint32 ticks );
	virtual std::string toString();
	SDL_Surface* getImage() ;
	void setImage( SDL_Surface* image);

private:

	SDL_Surface* image;
};

#endif /* ENTITY_H_ */
