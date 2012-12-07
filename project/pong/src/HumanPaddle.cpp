/*
 * HumanPaddle.cpp
 *
 *  Created on: Dec 7, 2012
 *      Author: cam
 */

#include "HumanPaddle.h"
#include "game.h"
#include "util.h"

HumanPaddle::HumanPaddle(float x, float y, float velx, float vely, float accx,
		float accy, std::string image, int keyup, int keydown) :
		Paddle(x, y, velx, vely, accx, accy, image) {

	setKeyup(keyup);
	setKeydown(keydown);

}

HumanPaddle::~HumanPaddle() {
	// TODO Auto-generated destructor stub
}

void HumanPaddle::draw(SDL_Surface* screen) {

	apply_surface(getX(), getY(), getImage(), screen, NULL);

}

void HumanPaddle::update(SDL_Event* event, Uint32 ticks) {

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

		if (event->key.keysym.sym == getKeyup())
			setVely(getVely() - getAccy());
		else if (event->key.keysym.sym == getKeydown())
			setVely(getVely() + getAccy());
		else
			;

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

int HumanPaddle::getKeydown() const {
	return keydown;
}

void HumanPaddle::setKeydown(int keydown) {
	this->keydown = keydown;
}

int HumanPaddle::getKeyup() const {
	return keyup;
}

void HumanPaddle::setKeyup(int keyup) {
	this->keyup = keyup;
}
