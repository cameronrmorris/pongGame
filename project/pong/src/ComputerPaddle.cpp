/*
 * ComputerPaddle.cpp
 *
 *  Created on: Dec 31, 2012
 *      Author: cam
 */

#include "ComputerPaddle.h"
#include "util.h"
#include <vector>

ComputerPaddle::ComputerPaddle(float x, float y, float velx, float vely,
		float accx, float accy, std::string image, int difficulty) :
		Paddle(x, y, velx, vely, accx, accy, image) {

	setDifficulty(difficulty);

}

void ComputerPaddle::draw(SDL_Surface* screen) {

	apply_surface(getX(), getY(), getImage(), screen, NULL);
}

void ComputerPaddle::update(SDL_Event* event, Uint32 ticks,
		std::vector<Ball*>* balls) {

	setX(getX() + (getVelx() * (ticks / 1000.f)));
	setY(getY() + (getVely() * (ticks / 1000.f)));

	// Balls
	for (std::vector<Ball*>::iterator it = balls->begin(); it != balls->end();
			++it) {

		if ((*it)->getY() > getY()) {
			setVely(getVely() + getAccy());

		} else if ((*it)->getY() < getY()) {

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
}

void ComputerPaddle::setDifficulty(int difficulty) {
	this->difficulty = difficulty;
}
