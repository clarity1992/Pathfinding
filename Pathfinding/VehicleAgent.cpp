#include "VehicleAgent.h"
#include "Pathfinder.h"


VehicleAgent::VehicleAgent(Vertex* startingPosition): Agent(startingPosition)
{	
	this->color = Color(255,255,255);
	this->maxAcceleration = 3;
	this->maxSpeed = 10;
	this->size = Size(TILE_WIDTH/2, TILE_HEIGHT/1.5);
}

VehicleAgent::~VehicleAgent(void)
{
}

std::vector<TerrianType> VehicleAgent::traversableTerrianTypes = std::vector<TerrianType>();

const std::vector<TerrianType> VehicleAgent::getTraversableTerrianTypes()
{
	return VehicleAgent::traversableTerrianTypes;
}

void VehicleAgent::setTraversableTerrianTypes(std::vector<TerrianType> traversableTerrianType)
{
	VehicleAgent::traversableTerrianTypes = traversableTerrianType;
}

void VehicleAgent::moveToLocationOnGraph(Graph* graph, Vertex* location)
{
	this->path = Pathfinder::breadthFirstSearch(
		graph,
		this->currentGraphPosition,
		location,
		VehicleAgent::traversableTerrianTypes);
}
