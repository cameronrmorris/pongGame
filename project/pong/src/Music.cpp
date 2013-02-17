/*
 * Music.cpp
 *
 *  Created on: Feb 17, 2013
 *      Author: cam
 */

#include "Music.h"

Music::Music( char *filename ) {

  music = NULL ;

  loadMusic( filename ) ;

}

Music::~Music() {

}


bool Music::loadMusic( char *filename  ) {

  stopMusic();

  music = Mix_LoadMUS( filename ) ;
  
  return true ;


}

void Music::playMusic( int loop ) {

  if ( music == NULL )
    return ;

  Mix_PlayMusic( music, loop ) ; 

  // Mix_HookMusicFinished( Music::finished ) ;

}

void Music::stopMusic() {

  if( music != NULL ) {

    Mix_HaltMusic() ;
    Mix_FreeMusic( music ) ;
    music = NULL ;

  }
}
