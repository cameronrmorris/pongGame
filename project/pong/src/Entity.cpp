/*
 * Entity.cpp
 *
 *  Created on: Nov 5, 2012
 *      Author: Cam
 */

#include "Entity.h"
#include "util.h"
#include <vector>
#include <iostream>

using namespace std;
Entity::Entity(std::string image) {

	if( image != "")
		this->image = load_image(image);

	setX(0);
	setY(0);

}

Entity::~Entity() {
	SDL_FreeSurface(image);
}

SDL_Surface* Entity::getImage() {
	return image;
}

void Entity::setImage(SDL_Surface* image) {
	this->image = image;
}

std::string Entity::toString() {

	std::stringstream output;

	output << " Image=" << getImage();

	return output.str();

}

void Entity::updateImage(SDL_Surface* image) {

	delete this->image ;

	setImage(image);

}

std::vector<SDL_Rect> Entity::getBoundingBox() {

	if (boundingBox.empty()) {
		LogWrite("adding a default box", "game.log");
		addBox();
	}

	return boundingBox;
}

bool Entity::checkCollision(Entity* entity) {

	// Sides of the boxes
	int left1, right1, top1, bottom1;
	int left2, right2, top2, bottom2;

//	for (std::vector<SDL_Rect>::iterator it = this->getBoundingBox().begin();
//			it != this->getBoundingBox().end(); ++it) {

	left1 = this->getX();
	right1 = left1 + this->getImage()->w;
	top1 = this->getY();
	bottom1 = top1 + this->getImage()->h;

//		for (std::vector<SDL_Rect>::iterator it2 =
//				entity->getBoundingBox().begin();
//				it2 != entity->getBoundingBox().end(); ++it2) {

	left2 = entity->getX();
	right2 = left2 + entity->getImage()->w;
	top2 = entity->getY();
	bottom2 = top2 + entity->getImage()->h;

	if (((bottom1 <= top2) || (top1 >= bottom2) || (right1 <= left2)
			|| (left1 >= right2)) == false) {
		//collision

		return true;
	}

//		}

return false;
}

float Entity::getX() const {
return x;
}

void Entity::setX(float x) {
this->x = x;
}

float Entity::getY() const {
return y;
}

void Entity::setY(float y) {
this->y = y;
}

void Entity::addBox(int x, int y, int h, int w) {

SDL_Rect tmp;

tmp.x = x;
tmp.y = y;
tmp.h = h;
tmp.w = w;

this->boundingBox.push_back(tmp);

}

void Entity::addBox() {

SDL_Rect tmp;

tmp.x = this->getX();
tmp.y = this->getY();
tmp.h = this->getImage()->h;
tmp.w = this->getImage()->w;

this->boundingBox.push_back(tmp);

}


std::vector<SDL_Rect> Entity::getBox() {


	return getBoundingBox();
}
