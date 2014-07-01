#include "TileFactory.h"
#include "Constants.h"

Tile* TileFactory::createTile(std::string tileType, int rowCount, int columnCount)
{
	Tile* tile;
	if (tileType == "R")
	{		
		tile = new Tile(Point2D(rowCount * TILE_WIDTH, columnCount * TILE_HEIGHT), Size(TILE_WIDTH, TILE_HEIGHT), Color(128,128,128), TerrianType::ROAD);
	}
	else if(tileType == "W")
	{
		tile = new Tile(Point2D(rowCount * TILE_WIDTH, columnCount * TILE_HEIGHT), Size(TILE_WIDTH, TILE_HEIGHT), Color(0,0,255), TerrianType::WATER);
	}
	else if(tileType == "G")
	{		
		tile = new Tile(Point2D(rowCount * TILE_WIDTH, columnCount * TILE_HEIGHT), Size(TILE_WIDTH, TILE_HEIGHT), Color(0,255,0), TerrianType::GRASS);
	}
	else
	{
		tile = new Tile(Point2D(rowCount * TILE_WIDTH, columnCount * TILE_HEIGHT), Size(TILE_WIDTH, TILE_HEIGHT), Color(255,255,255), TerrianType::GRASS);
	}
	return tile;
}