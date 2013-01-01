/*
 * ComputerPaddle.cpp
 *
 *  Created on: Dec 31, 2012
 *      Author: cam
 */

#include "ComputerPaddle.h"
#include "util.h"
#include "game.h"
#include <vector>

ComputerPaddle::ComputerPaddle(float x, float y, float velx, float vely,
		float accx, float accy, std::string image, int difficulty,
		std::vector<Ball*> *handle) :
		Paddle(x, y, velx, vely, accx, accy, image) {

	balls = handle ;

	setDifficulty(difficulty);

}

void ComputerPaddle::draw(SDL_Surface* screen) {

	apply_surface(getX(), getY(), getImage(), screen, NULL);
}

void ComputerPaddle::update(SDL_Event* event, Uint32 ticks,
		std::vector<Ball*>* balls) {

	setX(getX() + (getVelx() * (ticks / 1000.f)));
	setY(getY() + (getVely() * (ticks / 1000.f)));

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

	// Balls
	for (std::vector<Ball*>::iterator it = balls->begin(); it != balls->end();
			++it) {

		if (((*it)->getY() > getY() + (getImage()->h / 2))
				&& ((*it)->getY() - getY() + (getImage()->h / 2)) > 10) {

			setVely(getVely() + getAccy());

		} else if (((*it)->getY() < getY() + (getImage()->h / 2))
				&& (getY() + (getImage()->h / 2) - (*it)->getY()) > 10) {

			setVely(getVely() - getAccy());
		} else {
			if (getVely() != 0) {

				if (getVely() < 0) {

					if (getVely() + getAccy() > 0)
						setVely(0);
					else
						setVely(getVely() + getAccy());
				} else {
					if (getVely() - getAccy() < 0)
						setVely(0);
					else
						setVely(getVely() - getAccy());
				}
			}
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

ComputerPaddle::~ComputerPaddle() {
// TODO Auto-generated destructor stub
}

int ComputerPaddle::getDifficulty() const {
	return difficulty;
}

void ComputerPaddle::update(SDL_Event* event, Uint32 ticks) {

	setX(getX() + (getVelx() * (ticks / 1000.f)));
	setY(getY() + (getVely() * (ticks / 1000.f)));

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

	// Balls
	for (std::vector<Ball*>::iterator it = balls->begin(); it != balls->end();
			++it) {

		if (((*it)->getY() > getY() + (getImage()->h / 2))
				&& ((*it)->getY() - getY() + (getImage()->h / 2)) > 10) {

			setVely(getVely() + getAccy());

		} else if (((*it)->getY() < getY() + (getImage()->h / 2))
				&& (getY() + (getImage()->h / 2) - (*it)->getY()) > 10) {

			setVely(getVely() - getAccy());
		} else {
			if (getVely() != 0) {

				if (getVely() < 0) {

					if (getVely() + getAccy() > 0)
						setVely(0);
					else
						setVely(getVely() + getAccy());
				} else {
					if (getVely() - getAccy() < 0)
						setVely(0);
					else
						setVely(getVely() - getAccy());
				}
			}
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

void ComputerPaddle::setDifficulty(int difficulty) {
	this->difficulty = difficulty;
}
