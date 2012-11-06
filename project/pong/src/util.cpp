/*
 * util.cpp
 *
 *  Created on: Oct 27, 2012
 *      Author: Cam
 */

#include "SDL/SDL.h"
#include "SDL/SDL_image.h"
#include "util.h"
#include <iostream>
#include <fstream>
#include <time.h>


SDL_Surface *load_image( std::string filename )
{
	LogWrite("loading image: " + filename, "game.log");
    //The image that's loaded
    SDL_Surface* loadedImage = NULL;

    //The optimized image that will be used
    SDL_Surface* optimizedImage = NULL;

    //Load the image using SDL_image
    loadedImage = IMG_Load( filename.c_str() );

    //If the image loaded
    if( loadedImage != NULL )
    {
        //Create an optimized image
        optimizedImage = SDL_DisplayFormat( loadedImage );

        //Free the old image
        SDL_FreeSurface( loadedImage );
    }

    if( !loadedImage )
    	LogWrite("...failed to load","game.log");
    else
    	LogWrite("...loaded", "game.log");


    //Return the optimized image
    return optimizedImage;
}

void apply_surface( int x, int y, SDL_Surface* source, SDL_Surface* destination, SDL_Rect* snip ){
    //Make a temporary rectangle to hold the offsets
    SDL_Rect offset;

    //Give the offsets to the rectangle
    offset.x = x;
    offset.y = y;

    //Blit the surface
    SDL_BlitSurface( source, snip, destination, &offset );
}

void LogWrite(std::string message, std::string file) {

	std::ofstream f;

	f.open(file.c_str(), std::ios::app);

	if (f.is_open()) {
		f << message << std::endl;
	}
	f.close();

}

void LogInit(std::string file) {

	std::ofstream f;

	time_t ltime; /* calendar time */
	ltime=time(NULL); /* get current cal time */
	f.open(file.c_str(), std::ios::out);

	if (f.is_open())
		f << "Log opened :" << asctime( localtime(&ltime) ) << std::endl;

	f.close();

}
