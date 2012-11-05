/*
 * Entity.cpp
 *
 *  Created on: Nov 5, 2012
 *      Author: Cam
 */

#include "Entity.h"
#include "util.h"
#include <iostream>

Entity::Entity( std::string image) {

	std::cout << "loading image " << image << std::endl;

	if( !(this->image = load_image( image )) )  {

		std::cout << "error loading image: " << image << std::endl;

	}



}

Entity::~Entity() {
	SDL_FreeSurface(image);
}

void Entity::draw(SDL_Surface* screen) {

	apply_surface(0, 0, image, screen, NULL);
}

void Entity::update(SDL_Event* event) {
}

SDL_Surface* Entity::getImage()  {
	return image;
}

void Entity::setImage( SDL_Surface* image) {
	this->image = image;
}
