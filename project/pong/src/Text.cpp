/*
 * Text.cpp
 *
 *  Created on: Jan 1, 2013
 *      Author: cam
 */

#include "Text.h"
#include "util.h"

Text::Text(int x, int y, std::string text, std::string font, int size, int r,
		int g, int b) :
		Entity("") {

	setX(x);
	setY(y);
	setText(text);
	this->font = TTF_OpenFont(font.c_str(), size);
	textColor.r = r;
	textColor.g = g;
	textColor.b = b;

	setImage(TTF_RenderText_Solid(this->font, getText().c_str(), textColor));

	LogWrite(TTF_GetError(),"game.log");

}

Text::~Text() {
	// TODO Auto-generated destructor stub
}

const std::string& Text::getText() const {
	return text;
}

void Text::draw(SDL_Surface* screen) {

	apply_surface(getX(), getY(), getImage(), screen, NULL);
}

void Text::update(SDL_Event* event, Uint32 ticks) {

	updateImage(TTF_RenderText_Solid(this->font, getText().c_str(), textColor));

}

void Text::setText(const std::string& text) {
	this->text = text;
}

std::string Text::toString() {

	std::stringstream output;

	output << Entity::toString();

	output << " X=" << getX() << " Y=" << getY() << " Text=" << getText()
			<< " Font=" << font << " Color=" << (int)textColor.r << (int)textColor.g << (int)textColor.b;

	return output.str();

}
