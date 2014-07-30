#pragma once
#include "agent.h"
class VehicleAgent :
	public Agent
{
public:
	VehicleAgent(Vertex* startingPosition);
	~VehicleAgent(void);

	static const std::vector<TerrianType> getTraversableTerrianTypes();
	static void setTraversableTerrianTypes(std::vector<TerrianType> traversableTerrianTypes);
	
	
	void moveToLocationOnGraph(Graph* graph, Vertex* location);
private:
	static std::vector<TerrianType> traversableTerrianTypes;
};

