/*
 * menu.h
 *
 *  Created on: Oct 27, 2012
 *      Author: Cam
 */

#ifndef MENU_H_
#define MENU_H_

#include <vector>
#include "SDL/SDL.h"

using namespace std;

class menu {

public:

	menu();

	void draw();

private:
	vector<SDL_Surface*> items;



};


#endif /* MENU_H_ */
