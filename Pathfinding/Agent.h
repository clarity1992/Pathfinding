#pragma once

#include "Path.h"
#include "Color.h"
#include "Size.h"
#include <SDL.h>

class Agent
{
public:
	Agent(Point2D startingPosition);
	~Agent(void);

	void update();
	void render(SDL_Window* window);

	void followPath(Path* path);

private:
	Point2D position;
	Size size;
	Color color;
	Path* path;

	//Physics
	Vector2D velocity;
};

