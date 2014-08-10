#pragma once

#include "Size.h"
#include "Color.h"
#include "Vertex.h"
#include <SDL.h>
#include "Constants.h"

class Tile
{
public:
	Tile(Point2D position, Size size, Color color, TerrianType terrianType);
	~Tile(void);

	Vertex* getNode()
	{
		return &node;
	}

	void render(SDL_Window* window) const;

private:
	Vertex node;
	Point2D position;
	Size size;
	Color color;	
};

