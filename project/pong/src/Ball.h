/*
 * Ball.h
 *
 *  Created on: Nov 5, 2012
 *      Author: Cam
 */

#ifndef BALL_H_
#define BALL_H_

#include "Entity.h"
#include <string>

class Ball: public Entity {

public:
	Ball( float x, float y, float velx, float vely, std::string image);
	virtual ~Ball();
	float getVelx() const;
	void setVelx(float velx);
	float getVely() const;
	void setVely(float vely);
	float getX() const;
	void setX(float x);
	float getY() const;
	void setY(float y);

	virtual void draw( SDL_Surface *screen);
	virtual void update( SDL_Event* event, Uint32 ticks );
	virtual std::string toString() ;
	

private:
	float x ;
	float y ;
	float velx ;
	float vely ;


};

#endif /* BALL_H_ */
