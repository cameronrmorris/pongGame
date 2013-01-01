/*
 * Text.h
 *
 *  Created on: Jan 1, 2013
 *      Author: cam
 */

#ifndef TEXT_H_
#define TEXT_H_

#include "Entity.h"
#include "SDL/SDL_ttf.h"
#include <string>

class Text: public Entity {
public:
	Text(int x, int y, std::string text, std::string font, int size, int r, int g, int b);
	virtual ~Text();

	virtual void draw(SDL_Surface *screen);
	virtual void update(SDL_Event* event, Uint32 ticks);

	const std::string& getText() const;
	void setText(const std::string& text);

	virtual std::string toString() ;

private:

	std::string text;
	TTF_Font *font;
	SDL_Color textColor;

};

#endif /* TEXT_H_ */
