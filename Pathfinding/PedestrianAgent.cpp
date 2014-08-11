#include "PedestrianAgent.h"
#include "Pathfinder.h"

PedestrianAgent::PedestrianAgent(Vertex* startingPosition): Agent(startingPosition)
{
	traversableTerrianTypes.push_back(TerrianType::GRASS);
	traversableTerrianTypes.push_back(TerrianType::PAVEMENT);		
	this->color = Color(0,0,0);
	this->size = Size(TILE_WIDTH/3, TILE_HEIGHT/3);
}


PedestrianAgent::~PedestrianAgent(void)
{
}

std::vector<TerrianType> PedestrianAgent::traversableTerrianTypes = std::vector<TerrianType>();

const std::vector<TerrianType> PedestrianAgent::getTraversableTerrianTypes()
{
	return PedestrianAgent::traversableTerrianTypes;
}

void PedestrianAgent::setTraversableTerrianTypes(std::vector<TerrianType> traversableTerrianType)
{
	PedestrianAgent::traversableTerrianTypes = traversableTerrianType;
}

void PedestrianAgent::moveToLocationOnGraph(Graph* graph, Vertex* location)
{
	this->path = Pathfinder::breadthFirstSearch(
		graph,
		this->currentGraphPosition,
		location,
		PedestrianAgent::traversableTerrianTypes);
}
