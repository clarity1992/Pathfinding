#pragma once
#include "Vertex.h"
#include "Graph.h"
#include <vector>
#include "Path.h"
#include "Constants.h"
class Pathfinder
{
public:
	static Path* breadthFirstSearch(Graph* graph, Vertex* source, Vertex* target, std::vector<TerrianType> terrianType);
};

