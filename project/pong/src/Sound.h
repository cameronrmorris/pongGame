/*
 * Sound.h
 *
 *  Created on: Feb 17, 2013
 *      Author: cam
 */

#ifndef SOUND_H_
#define SOUND_H_

#include "SDL/SDL.h"
#include "SDL/SDL_mixer.h"
#include <vector>

class Sound {
 public:

  Sound( char* filename );
  virtual ~Sound();

  // Sound functions
  bool loadSound( char *filename ) ;
  void playSound( int loop);
  void stopSound() ;

 private:

  int channel ;
  Mix_Chunk *sound ; 

};

#endif /* SOUND_H_ */
