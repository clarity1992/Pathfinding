#pragma once

#include "Vertex.h"
#include <vector>
#include <queue>
class Path
{
public:
	Path(std::vector<Vertex*> pathNodes);
	Path(std::queue <Vertex*> pathNodes);
	~Path(void);

	Vertex* getCurrentTarget(){return currentTarget;}
	Vertex* getEndNode(){return endNode;}

	void setNextTarget();

private:
	unsigned currentTargetIndex;
	std::vector<Vertex*> pathNodes;
	Vertex* currentTarget;
	Vertex* endNode;
};

