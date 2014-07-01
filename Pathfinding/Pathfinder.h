#pragma once
#include "Vertex.h"
#include <vector>
#include "Path.h"
#include "Constants.h"
class Pathfinder
{
public:
	static Path* breadthFirstSearch(Vertex* source, Vertex* target, std::vector<TerrianType> terrianType);
};

