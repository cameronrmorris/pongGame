/*
 * ComputerPaddle.h
 *
 *  Created on: Dec 31, 2012
 *      Author: cam
 */

#ifndef COMPUTERPADDLE_H_
#define COMPUTERPADDLE_H_

#include "Paddle.h"
#include "Ball.h"

class ComputerPaddle: public Paddle {
public:

	ComputerPaddle(float x, float y, float velx, float vely, float accx,
				float accy, std::string image, int difficulty);

	virtual void draw(SDL_Surface *screen);
	virtual void update(SDL_Event* event, Uint32 ticks);
	virtual void update(SDL_Event* event, Uint32 ticks, std::vector<Ball*> *balls );
	ComputerPaddle();
	virtual ~ComputerPaddle();
	int getDifficulty() const;
	void setDifficulty(int difficulty);

private:

	int difficulty ;


};

#endif /* COMPUTERPADDLE_H_ */
