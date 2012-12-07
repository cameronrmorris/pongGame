/*
 * HumanPaddle.h
 *
 *  Created on: Dec 7, 2012
 *      Author: cam
 */

#ifndef HUMANPADDLE_H_
#define HUMANPADDLE_H_

#include "Paddle.h"

class HumanPaddle: public Paddle {
public:
	HumanPaddle(float x, float y, float velx, float vely, float accx,
			float accy, std::string image, int keyup, int keydown);
	virtual ~HumanPaddle();

	virtual void draw(SDL_Surface *screen);
	virtual void update(SDL_Event* event, Uint32 ticks);
	int getKeydown() const;
	void setKeydown(int keydown);
	int getKeyup() const;
	void setKeyup(int keyup);

private:

	int keyup;
	int keydown;

};

#endif /* HUMANPADDLE_H_ */
