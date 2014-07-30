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

	virtual void update();
	virtual void render(SDL_Window* window);

	virtual void moveToLocationOnGraph(Graph* graph, Vertex* location) = 0;	
protected:
	Point2D position;
	Size size;
	Color color;
	Path* path;

	

	Vertex* currentGraphPosition;
	
	//Physics
	Vector2D velocity;
};

