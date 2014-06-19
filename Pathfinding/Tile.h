#pragma once

#include "Position.h"
#include "Size.h"
#include "Color.h"
#include <SDL.h>

class Tile
{
public:

	static enum Type
	{
		ROAD,
		GRASS, 
		WATER
	};

	Tile(Position position, Size size, Color color);
	~Tile(void);

	void render(SDL_Window*);

private:
	Position position;
	Size size;
	Color color;
	Type type;
};

