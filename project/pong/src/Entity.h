/*
 * Entity.h
 *
 *  Created on: Nov 5, 2012
 *      Author: Cam
 */

#ifndef ENTITY_H_
#define ENTITY_H_

#include "SDL/SDL.h"
#include <string>
#include <sstream>
#include <vector>

class Entity {
public:
	Entity( std::string image);
	virtual ~Entity();
	virtual void draw( SDL_Surface* screen ) = 0;
	virtual void update( SDL_Event* event, Uint32 ticks ) = 0;
	virtual std::string toString();
	SDL_Surface* getImage() ;
	void updateImage( SDL_Surface* image);
	void setImage( SDL_Surface* image);

	virtual std::vector<SDL_Rect> getBox();

	bool checkCollision(Entity* entity);

	float getX() const;
	void setX(float x);
	float getY() const;
	void setY(float y);
	void addBox(int x, int y, int h, int w);
	void addBox();

protected:

	std::vector<SDL_Rect> getBoundingBox();



private:

	// The bounding box(es) of the entity
	std::vector<SDL_Rect> boundingBox ;

	SDL_Surface* image;

	float x ;
	float y ;

};

#endif /* ENTITY_H_ */
