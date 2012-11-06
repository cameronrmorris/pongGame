/*
 * Entity.cpp
 *
 *  Created on: Nov 5, 2012
 *      Author: Cam
 */

#include "Entity.h"
#include "util.h"

Entity::Entity( std::string image) {

	this->image = load_image( image );

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

std::string Entity::toString() {

	std::stringstream output ;

	output  << " Image=" << getImage();

	return output.str();

}
