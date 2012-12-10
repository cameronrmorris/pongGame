/*
 * Paddle.h
 *
 *  Created on: Dec 5, 2012
 *      Author: cam
 */

#ifndef PADDLE_H_
#define PADDLE_H_

#include "Entity.h"

#define MAX_VEL 500

enum paddleDirections {

	UP,
	DOWN,
	LEFT,
	RIGHT,
	NONE

};


class Paddle: public Entity {
public:
	Paddle(float x, float y, float velx, float vely, float accx, float accy, std::string image);
	virtual ~Paddle();

	virtual void draw( SDL_Surface *screen) = 0;
	virtual void update( SDL_Event* event, Uint32 ticks ) = 0;
	virtual void move(int direction);

	virtual std::string toString() ;
	float getAccx() const;
	void setAccx(float accx);
	float getAccy() const;
	void setAccy(float accy);
	float getVelx() const;
	void setVelx(float velx);
	float getVely() const;
	void setVely(float vexy);
	virtual std::vector<SDL_Rect> getBox();

private:

	float velx ;
	float vely ;

	float accx ;
	float accy ;

};

#endif /* PADDLE_H_ */
