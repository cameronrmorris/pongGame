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

class Paddle: public Entity {
public:
	Paddle(float x, float y, float velx, float vely, float accx, float accy, std::string image);
	virtual ~Paddle();

	virtual void draw( SDL_Surface *screen);
	virtual void update( SDL_Event* event, Uint32 ticks );

	virtual std::string toString() ;
	float getAccx() const;
	void setAccx(float accx);
	float getAccy() const;
	void setAccy(float accy);
	float getVelx() const;
	void setVelx(float velx);
	float getVely() const;
	void setVely(float vexy);
	float getX() const;
	void setX(float x);
	float getY() const;
	void setY(float y);

private:

	float x ;
	float y ;
	float velx ;
	float vely ;

	float accx ;
	float accy ;

};

#endif /* PADDLE_H_ */
