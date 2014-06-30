#include "TileFactory.h"
#include "Constants.h"

Tile* TileFactory::createTile(std::string tileType, int rowCount, int columnCount)
{
	Tile* tile;
	if (tileType == "R")
	{		
		tile = new Tile(Point2D(rowCount * TILE_WIDTH, columnCount * TILE_HEIGHT), Size(TILE_WIDTH, TILE_HEIGHT), Color(128,128,128));
	}
	else if(tileType == "W")
	{
		tile = new Tile(Point2D(rowCount * TILE_WIDTH, columnCount * TILE_HEIGHT), Size(TILE_WIDTH, TILE_HEIGHT), Color(0,0,255));
	}
	else if(tileType == "G")
	{		
		tile = new Tile(Point2D(rowCount * TILE_WIDTH, columnCount * TILE_HEIGHT), Size(TILE_WIDTH, TILE_HEIGHT), Color(0,255,0));
	}
	else
	{
		tile = new Tile(Point2D(rowCount * TILE_WIDTH, columnCount * TILE_HEIGHT), Size(TILE_WIDTH, TILE_HEIGHT), Color(255,255,255));
	}
	return tile;
}