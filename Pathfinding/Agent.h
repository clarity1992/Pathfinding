#pragma once
#include <vector>
#include "Path.h"
#include "Color.h"
#include "Size.h"
#include <SDL.h>
#include "Graph.h"
class Agent
{
public:
	Agent(Vertex* startingPosition);
	Agent(Vertex* startingPosition, AgentType agentType);
	~Agent(void);

	void update();
	void render(SDL_Window* window);

	void moveToLocationOnGraph(Graph* graph, Vertex* location);

	static std::vector<TerrianType> getValidTerrianTypesByAgentType(AgentType agentType);

private:
	std::vector<TerrianType> traversableTerrianTypes;
	Point2D position;
	Size size;
	Color color;
	Path* path;

	Vertex* currentGraphPosition;

	//Physics
	Vector2D velocity;
};

