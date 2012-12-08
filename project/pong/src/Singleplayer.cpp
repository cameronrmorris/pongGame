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

Singleplayer::Singleplayer(SDL_Surface *screen) :
		Game(screen) {

	setState(INIT);

	if (!this->init()) {
		LogWrite("Something bad happened in singleplayer init", "game.log");

	}

}

Singleplayer::~Singleplayer() {

	// Paddles
	for (vector<Paddle*>::iterator it = paddles.begin(); it != paddles.end();
			++it) {

		delete *it;

	}

	// Balls
	for (vector<Ball*>::iterator it = balls.begin(); it != balls.end(); ++it) {

		delete *it;

	}

}

bool Singleplayer::init() {

	setBackground(load_image("images/background.png"));

	apply_surface(0, 0, getBackground(), getScreen());

	balls.push_back(
			new Ball(SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2, 500.0, 0, "images/ball.png"));
	paddles.push_back(
			new HumanPaddle(5, SCREEN_HEIGHT / 2, 0, 0, 10, 10, "images/paddle.png", SDLK_UP,
					SDLK_DOWN));
	paddles.push_back(
			new HumanPaddle(615, SCREEN_HEIGHT / 2, 0, 0, 10, 10, "images/paddle.png", SDLK_w,
					SDLK_a));
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
	while (getState() == PLAYING) {

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

	// Draw paddles
	for (vector<Paddle*>::iterator it = paddles.begin(); it != paddles.end();
			++it) {

		(*it)->draw(getScreen());

	}
	// Draw balls
	for (vector<Ball*>::iterator it = balls.begin(); it != balls.end(); ++it) {

		(*it)->draw(getScreen());

	}

}

void Singleplayer::update(SDL_Event *event, Uint32 ticks) {

	// Update paddles
	for (vector<Paddle*>::iterator it = paddles.begin(); it != paddles.end();
			++it) {

		(*it)->update(event, ticks);

	}
	// Update balls
	for (vector<Ball*>::iterator it = balls.begin(); it != balls.end(); ++it) {

		(*it)->update(event, ticks);

	}

	// Check if balls collide with any paddle
	for (vector<Ball*>::iterator it = balls.begin(); it != balls.end(); ++it) {

		for (vector<Paddle*>::iterator it2 = paddles.begin();
				it2 != paddles.end(); ++it2) {

			if( (*it)->checkCollision(*it2) ) {

				(*it)->setVelx(-(*it)->getVelx());

			}

		}

	}

}

