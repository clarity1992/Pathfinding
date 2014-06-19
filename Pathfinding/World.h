#pragma once
#include <vector>
#include "Tile.h"
#include <SDL.h>
class World
{
public:
	World(std::vector<std::vector<Tile>> tiles);
	~World(void);

	void update();
	void render(SDL_Window* window);
private:
	std::vector<std::vector<Tile>> tiles;
};

