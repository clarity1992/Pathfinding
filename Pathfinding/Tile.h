#pragma once

#include "Size.h"
#include "Color.h"
#include "Vertex.h"
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

	Tile(Point2D position, Size size, Color color);
	~Tile(void);

	Vertex* getNode()
	{
		return &node;
	}

	void render(SDL_Window* window);

private:
	Vertex node;
	Point2D position;
	Size size;
	Color color;
	Type type;
};

