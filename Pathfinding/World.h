#pragma once
#include <vector>
#include "Tile.h"
#include <SDL.h>
#include "Graph.h"
class World
{
public:
	World(std::vector<std::vector<Tile>> tiles);
	~World(void);

	Graph* getGraph() {return graph;}

	void update();
	void render(SDL_Window* window);

	void createPathNetwork();
private:
	std::vector<std::vector<Tile>> tiles;

	Graph* graph;

};

