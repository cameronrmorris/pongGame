/*
 * button.h
 *
 *  Created on: Oct 27, 2012
 *      Author: Cam
 */

#ifndef BUTTON_H_
#define BUTTON_H_

#include "SDL/SDL.h"
#include <string>
#include "Entity.h"

enum BUTTON_STATES {

	MOUSE_OVER, MOUSE_OUT, MOUSE_DOWN, MOUSE_UP

};

class button : public Entity {

public:

	button(int x, int y, int w, int h, std::string i, int code = 0);
	~button();

	void update(SDL_Event* event);
	void draw(SDL_Surface* screen);
	void setRegions( int w, int h);

private:

	// Button clips
	SDL_Rect regions[4];

	// Bounding box of the button
	SDL_Rect box;

	// Current clip of the button

	SDL_Rect* frame;

	// Event code
	int code ;

};

#endif /* BUTTON_H_ */
