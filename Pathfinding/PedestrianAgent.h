#pragma once
#include "agent.h"
class PedestrianAgent :
	public Agent
{
public:
	PedestrianAgent(Vertex* startingPosition);
	~PedestrianAgent(void);

	static const std::vector<TerrianType> getTraversableTerrianTypes();
	static void setTraversableTerrianTypes(std::vector<TerrianType> traversableTerrianTypes);

	void moveToLocationOnGraph(Graph* graph, Vertex* location);
private:
	static std::vector<TerrianType> traversableTerrianTypes;
};

