/*
 * util.h
 *
 *  Created on: Oct 27, 2012
 *      Author: Cam
 */

#ifndef UTIL_H_
#define UTIL_H_
#include <string>


// SDL Image Functions
SDL_Surface *load_image( std::string filename );
void apply_surface( int x, int y, SDL_Surface* source, SDL_Surface* destination, SDL_Rect* snip = NULL );

// SDL TTF Functions


// Log functions
void LogWrite( std::string message, std::string file);
void LogInit( std::string file);


// Calculation functions
double distance( int x1, int y1, int x2, int y2 );


#endif /* UTIL_H_ */
