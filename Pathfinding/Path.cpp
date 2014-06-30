#include "Path.h"


Path::Path(std::vector<Vertex*> pathNodes):
	pathNodes(pathNodes),
	currentTarget(pathNodes.at(0)),
	endNode(pathNodes.at(pathNodes.size()-1))
{
	currentTargetIndex = 0;
}

Path::Path(std::queue<Vertex*> pathNodes):	
	currentTarget(pathNodes.back()),
	endNode(pathNodes.front())
{
	currentTargetIndex = 0;
	std::vector<Vertex*> nodes;

	while(pathNodes.size() > 0)
	{
		nodes.push_back(pathNodes.front());
		pathNodes.pop();
	}

	this->pathNodes = nodes;
}



Path::~Path(void)
{
}

void Path::setNextTarget()
{
	if (currentTargetIndex < pathNodes.size())
	{
		currentTargetIndex++;
	}
	currentTarget = pathNodes.at(currentTargetIndex);
}