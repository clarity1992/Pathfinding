#pragma once

#include "Tile.h"
#include <string>

class TileFactory
{
public:
	static Tile* createTile(std::string, int rowCount, int columnCount);
};

