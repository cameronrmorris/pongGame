/*
 * Music.h
 *
 *  Created on: Feb 17, 2013
 *      Author: cam
 */

#ifndef MUSIC_H_
#define MUSIC_H_

#include "SDL/SDL.h"
#include "SDL/SDL_mixer.h"
#include <vector>

class Music {
 public:

  Music( char* filename );
  virtual ~Music();

  const Mix_Music* getMusic() ;

  // Music functions
  bool loadMusic( char *filename ) ;
  void playMusic( int loop);
  void stopMusic() ;

 private:
  Mix_Music *music ; 

};

#endif /* MUSIC_H_ */
