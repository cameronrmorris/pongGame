/*
 * TwoPlayer.cpp
 *
 *  Created on: Feb 8, 2013
 *      Author: cam
 */

#include "TwoPlayer.h"
#include "util.h"
#include "HumanPaddle.h"
#include "Ball.h"


TwoPlayer::TwoPlayer( SDL_Surface *screen ) : Singleplayer( screen) {


  setState(INIT) ;


}

bool TwoPlayer::init() {

  setBackground( load_image("images/background.png" ));

  apply_surface( 0, 0, getBackground(), getScreen() );

  setScore( 0 , 0) ;
  setCollisionSound( "sounds/pong.wav");
  
  setScoreMessage(new Text((SCREEN_WIDTH / 2) - 100, 0, "Score : 0 - 0","fonts/Allcaps.ttf", 28, 255, 255, 255));
  // Left - right                                                                                     
  addBall( new Ball(SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2, 200.0, 10, "images/ball.png"));
  addPaddle( new HumanPaddle(5, SCREEN_HEIGHT / 2, 0, 0, 10, 10,"images/paddle.png", SDLK_w, SDLK_s));
  addPaddle( new HumanPaddle(615, SCREEN_HEIGHT / 2, 0, 0, 10, 10,"images/paddle.png", SDLK_UP, SDLK_DOWN));


  setState(PLAYING) ;

  return true ;
  


}


TwoPlayer::~TwoPlayer() {

}

