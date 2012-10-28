/*
 * menu.h
 *
 *  Created on: Oct 27, 2012
 *      Author: Cam
 */

#ifndef MENU_H_
#define MENU_H_

#include <vector>
#include "button.h"

using namespace std;

class menu {

public:

	menu();
	~menu();

	void draw();

private:
	vector<button> buttons;

};

#endif /* MENU_H_ */
