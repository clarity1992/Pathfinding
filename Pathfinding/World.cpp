#include "World.h"
#include <iostream>
#include <SDL.h>
#include <SDL_opengl.h>
#include <GL\GLU.h>

World::World(std::vector<std::vector<Tile>> tiles): tiles(tiles)
{
	graph = new Graph();
}


World::~World(void)
{

}


void World::update()
{

}

void World::render(SDL_Window* window) const
{
	//std::cout << "Frame" << std::endl;
	std::vector<std::vector<Tile>>::const_iterator tileRow;
	std::vector<Tile>::const_iterator tile;

	for (tileRow = tiles.begin(); tileRow != tiles.end(); ++tileRow)
	{		
		
		for (tile = tileRow->begin(); tile != tileRow->end(); ++tile)
		{
			tile->render(window);
		}
	}
}

void World::createPathNetwork()
{
	std::vector<std::vector<Tile>>::iterator tileRow;
	std::vector<Tile>::iterator tile;

	for (tileRow = tiles.begin(); tileRow != tiles.end(); ++tileRow)
	{		
		for (tile = tileRow->begin(); tile != tileRow->end(); ++tile)
		{
			graph->addNode(tile->getNode());
		}
	}

	for (unsigned i = 0; i < tiles.size(); ++i)
	{		
		std::vector<Tile>& tileRow = tiles.at(i);
		for (unsigned j = 0; j < tileRow.size(); ++j)
		{
			Tile& currentTile = tileRow.at(j);

			if (j + 1 < tileRow.size())
			{
				Tile& nextTileInRow = tileRow.at(j+1);
				graph->addEdge(*currentTile.getNode(), *nextTileInRow.getNode(), 1);				
			}

			if (j >= 1)
			{
				Tile& previousTileInRow = tileRow.at(j-1);
				graph->addEdge(*currentTile.getNode(), *previousTileInRow.getNode(), 1);				
			}
			
			if (i + 1 < tiles.size())
			{
				Tile& nextTileInColumn = tiles.at(i+1).at(j);
				graph->addEdge(*currentTile.getNode(), *nextTileInColumn.getNode(), 1);
			}

			if(i >= 1)
			{
				Tile& previousTileInColumn = tiles.at(i-1).at(j);
				graph->addEdge(*currentTile.getNode(), *previousTileInColumn.getNode(), 1);
				
			}			
		}
	}
	std::cout << "Number of Nodes" << graph->getNodes().size() << std::endl;
	unsigned numberOfEdges = 0;

	for (unsigned i = 0; i < graph->getNodes().size(); ++i)
	{
		numberOfEdges += graph->getNodes().at(i)->edges.size();
		std::cout << "Number of Edges:" << graph->getNodes().at(i)->edges.size() << std::endl;
	}

	std::cout << "Totaol Number of Edges:" << numberOfEdges << std::endl;
}