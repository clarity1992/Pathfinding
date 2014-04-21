#pragma once
#include "../Library/Point2D.h"
#include <vector>
#include "Edge.h"

class Vertex
{
public:
	Vertex();
	~Vertex();

	void addEdge(Edge edge);

private:
	//The vertex's position in the world
	//Point2D position;

	//The edges that connect this vertex to other vertex's in a graph.
	std::vector<Edge> edges;
};