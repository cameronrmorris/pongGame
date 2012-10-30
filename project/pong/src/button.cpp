/*
 * button.cpp
 *
 *  Created on: Oct 27, 2012
 *      Author: Cam
 */

#include "button.h"
#include "util.h"
#include <iostream>

void button::setRegions( int w, int h) {

	int xoffset = w / 2 ;
	int yoffset = h / 2 ;

	regions[MOUSE_OVER].x = 0;
	regions[MOUSE_OVER].y = 0;
	regions[MOUSE_OVER].w = xoffset;
	regions[MOUSE_OVER].h = yoffset;

	regions[MOUSE_OUT].x = xoffset;
	regions[MOUSE_OUT].y = 0;
	regions[MOUSE_OUT].w = xoffset;
	regions[MOUSE_OUT].h = yoffset;

	regions[MOUSE_DOWN].x = 0;
	regions[MOUSE_DOWN].y = yoffset;
	regions[MOUSE_DOWN].w = xoffset;
	regions[MOUSE_DOWN].h = yoffset;

	regions[MOUSE_UP].x = xoffset;
	regions[MOUSE_UP].y = yoffset;
	regions[MOUSE_UP].w = xoffset;
	regions[MOUSE_UP].h = yoffset;

}

button::button(int x, int y, int w, int h, std::string i, int code) {

	// Load image

	this->image = load_image(i);

	std::cout << image-w << std::endl;

	this->setRegions( image->w, image->h);

	//Set the button's attributes
	box.x = x;
	box.y = y;
	box.w = w;
	box.h = h;

	this->code = code ;
	//Set the default sprite

	frame = &regions[MOUSE_OUT];

}

void button::draw(SDL_Surface* screen) {

	//Show the button

	apply_surface(box.x, box.y, image, screen, frame);

}

void button::update(SDL_Event* event) {

	//The mouse offsets
	int x = 0, y = 0;

	//If the mouse moved
	if (event->type == SDL_MOUSEMOTION) {
		//Get the mouse offsets
		x = event->motion.x;
		y = event->motion.y;

		//If the mouse is over the button
		if ((x > box.x) && (x < box.x + box.w) && (y > box.y)
				&& (y < box.y + box.h)) {
			//Set the button sprite
			frame = &regions[MOUSE_OVER];
		}
		//If not
		else {
			//Set the button sprite
			frame = &regions[MOUSE_OUT];
		}
	}
	//If a mouse button was pressed
	if (event->type == SDL_MOUSEBUTTONDOWN) {
		//If the left mouse button was pressed
		if (event->button.button == SDL_BUTTON_LEFT) {
			//Get the mouse offsets
			x = event->button.x;
			y = event->button.y;

			//If the mouse is over the button
			if ((x > box.x) && (x < box.x + box.w) && (y > box.y)
					&& (y < box.y + box.h)) {
				//Set the button sprite
				frame = &regions[MOUSE_DOWN];

				SDL_Event user_event;

				user_event.type=SDL_USEREVENT;
				user_event.user.code= this->code;
				user_event.user.data1=NULL;
				user_event.user.data2=NULL;
				SDL_PushEvent(&user_event);


			}
		}
	}
	//If a mouse button was released
	if (event->type == SDL_MOUSEBUTTONUP) {
		//If the left mouse button was released
		if (event->button.button == SDL_BUTTON_LEFT) {
			//Get the mouse offsets
			x = event->button.x;
			y = event->button.y;

			//If the mouse is over the button
			if ((x > box.x) && (x < box.x + box.w) && (y > box.y)
					&& (y < box.y + box.h)) {
				//Set the button sprite
				frame = &regions[MOUSE_UP];
			}
		}
	}

}
