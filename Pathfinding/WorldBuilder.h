#pragma once
#include "World.h"
#include <vector>

class WorldBuilder
{
public:
	static World* createWorld(std::vector<std::vector<std::string>> rawWorldData);
	static void WorldBuilder::cleanWorldData(std::vector<std::vector<std::string>>& rawWorldData);
};

