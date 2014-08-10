#pragma once
#include "World.h"
#include "Agent.h"
class GraphicsEngine
{
public:
	GraphicsEngine(void);
	~GraphicsEngine(void);

	virtual bool init(unsigned screenWidth, unsigned screenHeight) = 0;
	virtual void render(const World* world, const std::vector<Agent*> agents) = 0;
};

