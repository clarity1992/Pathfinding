#pragma once
#include <vector>
#include "Path.h"
#include "Color.h"
#include "Size.h"
#include <SDL.h>
#include "Graph.h"
#include "../Library/Point2D.h"
#include "GraphicsEngine.h"
class Agent
{
public:
	Agent(Vertex* startingPosition);
	Agent(Vertex* startingPosition, AgentType agentType);
	~Agent(void);

	virtual void update();
	virtual void render(GraphicsEngine* graphicsEngine);

	virtual void moveToLocationOnGraph(Graph* graph, Vertex* location) = 0;	
protected:
	
	Size size;
	Color color;
	Path* path;

	float maxAcceleration;
	float maxSpeed;
	Vertex* currentGraphPosition;
	
	//Physics
	Vector2D velocity;
	Point2D position;
	float orientation;
	float rotation;
};

