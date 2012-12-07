/*
 * Singleplayer.cpp
 *
 *  Created on: Nov 1, 2012
 *      Author: Cam
 */

#include "Singleplayer.h"
#include "Ball.h"
#include "Paddle.h"
#include "HumanPaddle.h"
#include "util.h"
#include "Timer.h"

Singleplayer::Singleplayer(SDL_Surface *screen) : Game(screen){

	setState(INIT);

	if (!this->init()) {
		LogWrite("Something bad happened in singleplayer init", "game.log");

	}

}

Singleplayer::~Singleplayer() {
	for (vector<Entity*>::iterator it = entities.begin(); it != entities.end();
			++it) {

		delete *it;

	}
}

bool Singleplayer::init() {

	setBackground(load_image("images/background.png"));

	apply_surface(0, 0, getBackground(), getScreen());

	entities.push_back(new Ball(0, SCREEN_HEIGHT/2, 500.0, 0, "images/ball.png"));
	entities.push_back(new HumanPaddle(0,0,0,0,10,10, "images/ball.png", SDLK_UP, SDLK_DOWN));
	entities.push_back(new HumanPaddle(640,0,0,0,10,10, "images/ball.png", SDLK_w, SDLK_a));
	setState(PLAYING);

	return true;
}

void Singleplayer::run() {

	SDL_Event event;

	LogWrite(toString(), "game.log");

	// FPS test
	int frame = 0;
	Timer fps;
	Timer update;
	Timer delta;

	update.start();
	fps.start();
	delta.start();
	//While there's an event to handle
	while (state == PLAYING) {

		SDL_PollEvent(&event);

		//If the user has Xed out the window
		if (event.type == SDL_QUIT) {
			//Quit the program
			setState(QUIT);
		}

		switch (event.user.code) {

		case QUIT:
			setState(QUIT);
			break;
		default:
			break;

		}


		this->update(&event, delta.get_ticks());
		delta.start();
		draw();

		//Update the screen
		if (SDL_Flip(getScreen()) == -1) {
			return;
		}

		frame++;

		//If a second has passed since the caption was last updated
		if (update.get_ticks() > 1000) {
			//The frame rate as a string
			std::stringstream caption;

			//Calculate the frames per second and create the string
			caption << "Pong - FPS: " << frame / (fps.get_ticks() / 1000.f);
			//Reset the caption
			SDL_WM_SetCaption(caption.str().c_str(), NULL);

			//Restart the update timer
			update.start();
		}

	}

}

void Singleplayer::draw() {

	apply_surface(0, 0, getBackground(), getScreen());

	for (vector<Entity*>::iterator it = entities.begin(); it != entities.end();
			++it) {

		(*it)->draw(getScreen());

	}

}

void Singleplayer::update(SDL_Event *event, Uint32 ticks) {

	for (vector<Entity*>::iterator it = entities.begin(); it != entities.end();
			++it) {

		(*it)->update(event, ticks);

	}

}

int Singleplayer::getState() const {
	return state;
}

void Singleplayer::setState(int state) {
	this->state = state;
}
