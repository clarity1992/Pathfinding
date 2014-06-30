#pragma once
#include <SDL.h>
#include "World.h"
#include "Agent.h"

class Simulation
{
public:
	Simulation(int SCREEN_WIDTH, int SCREEN_HEIGHT);
	~Simulation(void);

	bool isRunning;

	void input();
	void update();
	void render();

private:
	//The window we'll be rendering to
    SDL_Window* window;
	Agent* agent;
	World* world;
};

