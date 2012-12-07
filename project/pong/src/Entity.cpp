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

const std::vector<SDL_Rect>& Entity::getBoundingBox() const {
	return boundingBox;
}

void Entity::setBoundingBox(const std::vector<SDL_Rect>& boundingBox) {
	this->boundingBox = boundingBox;
}
