#include "TileFactory.h"
#include "Constants.h"

Tile* TileFactory::createTile(std::string tileType, int rowCount, int columnCount)
{
	Tile* tile;
	if (tileType == "R")
	{		
		tile = new Tile(
			Point2D(rowCount * TILE_WIDTH, columnCount * TILE_HEIGHT),
			Size(TILE_WIDTH, TILE_HEIGHT),
			Color(90,90,90),
			TerrianType::ROAD);
	}
	else if(tileType == "W")
	{
		tile = new Tile(
			Point2D(rowCount * TILE_WIDTH, columnCount * TILE_HEIGHT),
			Size(TILE_WIDTH, TILE_HEIGHT),
			Color(0,0,255),
			TerrianType::WATER);
	}
	else if(tileType == "G")
	{		
		tile = new Tile(
			Point2D(rowCount * TILE_WIDTH, columnCount * TILE_HEIGHT),
			Size(TILE_WIDTH, TILE_HEIGHT),
			Color(0,255,0),
			TerrianType::GRASS);
	}
	else if(tileType == "P")
	{		
		tile = new Tile(
			Point2D(rowCount * TILE_WIDTH, columnCount * TILE_HEIGHT),
			Size(TILE_WIDTH, TILE_HEIGHT),
			Color(200,200, 200),
			TerrianType::PAVEMENT);
	}
	else if(tileType == "B")
	{		
		tile = new Tile(
			Point2D(rowCount * TILE_WIDTH, columnCount * TILE_HEIGHT),
			Size(TILE_WIDTH, TILE_HEIGHT),
			Color(255, 20, 0),
			TerrianType::BUILDING);
	}
	else if(tileType == "I")
	{		
		tile = new Tile(
			Point2D(rowCount * TILE_WIDTH, columnCount * TILE_HEIGHT),
			Size(TILE_WIDTH, TILE_HEIGHT),
			Color(90,90,90),
			TerrianType::INTERSECTION);
	}
	else if(tileType == "C")
	{		
		tile = new Tile(
			Point2D(rowCount * TILE_WIDTH, columnCount * TILE_HEIGHT),
			Size(TILE_WIDTH, TILE_HEIGHT),
			Color(150,150, 150),
			TerrianType::CROSSING);
	}
	else if(tileType == "N")
	{		
		tile = new Tile(
			Point2D(rowCount * TILE_WIDTH, columnCount * TILE_HEIGHT),
			Size(TILE_WIDTH, TILE_HEIGHT),
			Color(0,0, 0),
			TerrianType::WATER);
	}
	else
	{
		tile = new Tile(
			Point2D(rowCount * TILE_WIDTH, columnCount * TILE_HEIGHT),
			Size(TILE_WIDTH, TILE_HEIGHT),
			Color(255,255,255),
			TerrianType::GRASS);
	}
	return tile;
}