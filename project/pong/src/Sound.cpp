/*
 * Sound.cpp
 *
 *  Created on: Feb 17, 2013
 *      Author: cam
 */

#include "Sound.h"

Sound::Sound( char *filename ) {

  channel = -1 ;
  sound = NULL ;
  loadSound( filename ) ;

}

Sound::~Sound() {

}


bool Sound::loadSound( char *filename  ) {

  stopSound();

  sound = Mix_LoadWAV(filename);

  return true ;


}

void Sound::playSound( int loop ) {

  if ( sound == NULL )
    return ;

  channel = Mix_PlayChannel( -1, sound, loop ) ; 

}

void Sound::stopSound() {

  if( sound != NULL ) {

    Mix_HaltChannel( channel ) ;
    channel = -1 ; 

  }
}
