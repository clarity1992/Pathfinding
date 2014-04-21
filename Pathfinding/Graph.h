#pragma once
#include "Vertex.h"
#include <vector>
class Graph
{
public:
	Graph(void);
	~Graph(void);

	void addNode(Vertex* vertex);

	void addEdge(Vertex& vertexA, Vertex& vertexB, int weight);

	//Is there a uninterupted connetion between the two given vertexs.
	bool isReachable(Vertex* startingVertex, Vertex* endingVertex);

private:
	std::vector<Vertex*> nodes;

	bool isReachableRec(Vertex* startingVertex, Vertex* endingVertex);
};

