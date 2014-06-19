#include "WorldBuilder.h"
#include "TileFactory.h"

World* WorldBuilder::createWorld(std::vector<std::vector<std::string>> rawWorldData)
{
	std::vector<std::vector<std::string>>::iterator i;
	std::vector<std::string>::iterator j;

	std::vector<std::vector<Tile>> tiles;

	int rowCount = 0, columnCount = 0;
	for (i = rawWorldData.begin(); i != rawWorldData.end(); ++i)
	{
		std::vector<Tile> tileRow;
		rowCount = 0;
		for (j = i->begin(); j != i->end(); ++j)
		{
			Tile* tile = TileFactory::createTile(*j, rowCount, columnCount);
			tileRow.push_back(*tile);
			rowCount++;
		}
		tiles.push_back(tileRow);
		columnCount++;
	}
	return new World(tiles);
}