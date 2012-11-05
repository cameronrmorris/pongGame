/*
 * Ball.cpp
 *
 *  Created on: Nov 5, 2012
 *      Author: Cam
 */

#include "Ball.h"

Ball::Ball(int x, int y, float velx, float vely, std::string image) : Entity( image ) {

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

int Ball::getX() const {
	return x;
}

void Ball::setX(int x) {
	this->x = x;
}

int Ball::getY() const {
	return y;
}

void Ball::setY(int y) {
	this->y = y;
}