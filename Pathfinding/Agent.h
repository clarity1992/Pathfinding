#pragma once

#include "Path.h"
#include "Color.h"
#include "Size.h"
#include <SDL.h>

class Agent
{
public:
	Agent(Vertex* startingPosition);
	~Agent(void);

	void update();
	void render(SDL_Window* window);

	void moveToLocation(Vertex* location);

private:
	std::vector<TerrianType> traversableTerrianTypes;
	Point2D position;
	Size size;
	Color color;
	Path* path;

	Vertex* currentGraphPosition;

	//Physics
	Vector2D velocity;
};

