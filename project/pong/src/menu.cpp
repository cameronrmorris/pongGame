/*
 * menu.cpp
 *
 *  Created on: Oct 27, 2012
 *      Author: Cam
 */

#include "menu.h"
#include <iostream>

menu::menu() {
	// TODO Auto-generated constructor stub

}

menu::~menu() {
	for (vector<button*>::iterator it = buttons.begin(); it != buttons.end();
					++it) {


				delete *it;

			}
}

void menu::update(SDL_Event* event) {

	for (vector<button*>::iterator it = buttons.begin(); it != buttons.end();
				++it) {


			(*it)->update(event, NULL);

		}


}

void menu::draw(SDL_Surface* screen) {

	for (vector<button*>::iterator it = buttons.begin(); it != buttons.end();
			++it) {

		(*it)->draw(screen);

	}
}

void menu::addButton(int x, int y, int w, int h, std::string i, int code) {

	button* temp  = new button(x, y, w, h, i, code);

	buttons.push_back(temp);

}

std::string menu::toString() {

	std::stringstream output ;

	output << "Buttons = {";

	for (vector<button*>::iterator it = buttons.begin(); it != buttons.end();
				++it) {

			output << " " << (*it)->toString() << " ";

		}

	output << "}";

	return output.str();


}
