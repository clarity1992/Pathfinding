#pragma once
#include "Vertex.h"
#include <vector>
#include "Path.h"
#include <queue>
class Graph
{
public:
	Graph(void);
	~Graph(void);

	std::vector<Vertex*> getNodes() const {return this->nodes;}

	void addNode(Vertex* vertex);
	void addEdge(Vertex& vertexA, Vertex& vertexB, int weight);
private:
	std::vector<Vertex*> nodes;
};

