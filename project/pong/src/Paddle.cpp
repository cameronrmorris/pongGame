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
