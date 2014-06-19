#include "Tile.h"
#include <SDL.h>

Tile::Tile(Position position, Size size, Color color):position(position), size(size), color(color)
{

}


Tile::~Tile(void)
{
}

void Tile::render(SDL_Window* window)
{
    //The surface contained by the window
    SDL_Surface* screenSurface = NULL;

	//Get window surface
	screenSurface = SDL_GetWindowSurface(window);

	//Tile Rectangle
	SDL_Rect tileRect;
	tileRect.x = position.x;
	tileRect.y = position.y;
	tileRect.w = size.width;
	tileRect.h = size.height;

	//Fill the surface white
	SDL_FillRect(screenSurface, &tileRect, SDL_MapRGB( screenSurface->format, color.r, color.g, color.b ) );
            
	//Update the surface
	SDL_UpdateWindowSurface( window );   
}