#include "World.h"
#include <iostream>

World::World(std::vector<std::vector<Tile>> tiles): tiles(tiles)
{

}


World::~World(void)
{

}


void World::update()
{

}

void World::render(SDL_Window* window)
{
	std::cout << "Frame" << std::endl;
	std::vector<std::vector<Tile>>::iterator tileRow;
	std::vector<Tile>::iterator tile;

	for (tileRow = tiles.begin(); tileRow != tiles.end(); ++tileRow)
	{		
		for (tile = tileRow->begin(); tile != tileRow->end(); ++tile)
		{
			tile->render(window);
		}
	}
}