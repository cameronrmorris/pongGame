/*
 * Ball.cpp
 *
 *  Created on: Nov 5, 2012
 *      Author: Cam
 */

#include "Ball.h"
#include "util.h"
#include "game.h"

Ball::Ball(float x, float y, float velx, float vely, std::string image) :
		Entity(image) {

	setX(x);
	setY(y);
	setVelx(velx);
	setVely(vely);

}

Ball::~Ball() {
	// TODO Auto-generated destructor stub
}

float Ball::getVelx() const {
	return velx;
}

void Ball::setVelx(float velx) {
	this->velx = velx;
}

float Ball::getVely() const {
	return vely;
}

void Ball::setVely(float vely) {
	this->vely = vely;
}

void Ball::draw(SDL_Surface* screen) {

	apply_surface(getX(), getY(), getImage(), screen, NULL);
}

void Ball::update(SDL_Event* event, Uint32 ticks) {

	setX(getX() + (getVelx() * (ticks / 1000.f)));
	setY(getY() + (getVely() * (ticks / 1000.f)));

	if (getX() < 0) {
		setX(0);
		setVelx(-getVelx());
	}

	if (getX() + getImage()->w > SCREEN_WIDTH) {
		setX(SCREEN_WIDTH - getImage()->w);
		setVelx(-getVelx());
	}

	if (getY() < 0) {
		setY(0);
		setVely(-getVely());
	}

	if (getY() + getImage()->h > SCREEN_HEIGHT) {
		setY(SCREEN_HEIGHT - getImage()->h);
		setVely(-getVely());
	}



}

std::string Ball::toString() {

	std::stringstream output;

	output << Entity::toString();

	output << " X=" << getX() << " Y=" << getY() << " VelX=" << getVelx()
			<< " VelY=" << getVely();

	return output.str();

}

std::vector<SDL_Rect> Ball::getBox() {


	return getBoundingBox();
}
