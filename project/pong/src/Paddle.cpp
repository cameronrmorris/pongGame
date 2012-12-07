/*
 * Paddle.cpp
 *
 *  Created on: Dec 5, 2012
 *      Author: cam
 */

#include "Paddle.h"
#include "SDL/SDL.h"
#include "util.h"
#include "game.h"

Paddle::Paddle(float x, float y, float velx, float vely, float accx, float accy,
		std::string image) :
		Entity(image) {

	setX(x);
	setY(y);
	setVelx(velx);
	setVely(vely);
	setAccx(accx);
	setAccy(accy);

}

Paddle::~Paddle() {
	// TODO Auto-generated destructor stub
}

float Paddle::getAccx() const {
	return accx;
}

void Paddle::setAccx(float accx) {
	this->accx = accx;
}

float Paddle::getAccy() const {
	return accy;
}

void Paddle::setAccy(float accy) {
	this->accy = accy;
}

float Paddle::getVelx() const {
	return velx;
}

void Paddle::setVelx(float velx) {
	this->velx = velx;
}

float Paddle::getVely() const {
	return vely;
}

void Paddle::setVely(float vely) {
	this->vely = vely;
}

float Paddle::getX() const {
	return x;
}

void Paddle::setX(float x) {
	this->x = x;
}

float Paddle::getY() const {
	return y;
}

void Paddle::draw(SDL_Surface* screen) {

	apply_surface(getX(), getY(), getImage(), screen, NULL);

}

void Paddle::update(SDL_Event* event, Uint32 ticks) {

	setX(getX() + (getVelx() * (ticks / 1000.f)));
	setY(getY() + (getVely() * (ticks / 1000.f)));

	if (getX() < 0) {
		setX(0);
		setVelx(0);
	}

	if (getX() + getImage()->w > SCREEN_WIDTH) {
		setX(SCREEN_WIDTH - getImage()->w);
		setVelx(0);
	}

	if (getY() < 0) {
		setY(0);
		setVely(0);
	}

	if (getY() + getImage()->h > SCREEN_HEIGHT) {
		setY(SCREEN_HEIGHT - getImage()->h);
		setVely(0);
	}

	// Handle the acceleration
	// X direction
	if (getVelx() != 0.0) {

		if (getVelx() > 0) {

			if (getVelx() - getAccx() > 0)
				setVelx(getVelx() - getAccx());
			else
				setVelx(0.0);

		} else {

			if (getVelx() + getAccx() < 0)
				setVelx(getVelx() + getAccx());
			else
				setVelx(0.0);

		}

	}
	// Y direction
	if (getVely() != 0.0) {

		if (getVely() > 0) {

			if (getVely() + getAccy() > 0)
				setVely(getVely() + getAccy() * (ticks / 1000.f));
			else
				setVely(5.0);

		} else {

			if (getVely() - getAccy() < 0)
				setVely(getVely() - getAccy() * (ticks / 1000.f));
			else
				setVely(5.0);

		}

	}

	// Handle key presses

	if (event->type == SDL_KEYDOWN) {

		switch (event->key.keysym.sym) {

		case SDLK_UP:
			setVely(getVely() - getAccy());
			break;
		case SDLK_DOWN:
			setVely(getVely() + getAccy());
			break;

		default:
			break;

		}

	}

	if (getVelx() > MAX_VEL)
		setVelx(MAX_VEL);
	if (getVelx() < -MAX_VEL)
		setVelx(-MAX_VEL);

	if (getVely() > MAX_VEL)
		setVely(MAX_VEL);
	if (getVely() < -MAX_VEL)
		setVely(-MAX_VEL);

}

std::string Paddle::toString() {

	std::stringstream output;

	output << Entity::toString();

	output << " X=" << getX() << " Y=" << getY() << " VelX=" << getVelx()
			<< " VelY=" << getVely() << " AccX=" << getAccx() << " AccY="
			<< getAccy();

	return output.str();

}

void Paddle::setY(float y) {
	this->y = y;
}

std::vector<SDL_Rect> Paddle::getBox() {

	return getBoundingBox();
}
