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
	Ball( int x, int y, float velx, float vely, std::string image);
	virtual ~Ball();
	float getVelx() const;
	void setVelx(float velx);
	float getVely() const;
	void setVely(float vely);
	int getX() const;
	void setX(int x);
	int getY() const;
	void setY(int y);

private:
	int x ;
	int y ;
	float velx ;
	float vely ;


};

#endif /* BALL_H_ */
