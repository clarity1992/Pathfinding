#pragma once
#include <SDL.h>
#include "World.h"



class Simulation
{
public:
	Simulation(int SCREEN_WIDTH, int SCREEN_HEIGHT);
	~Simulation(void);

	bool isRunning;

	void update();
	void render();

private:
	//The window we'll be rendering to
    SDL_Window* window;

	World* world;
};

