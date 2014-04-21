#pragma once
#include "../Library/Point2D.h"
#include <vector>
#include "Edge.h"
#include <string>

class Vertex
{
public:
	Vertex(std::string vertexID);
	~Vertex();

	void addEdge(Edge edge);

	bool visited;
	std::string vertexID;
	//The edges that connect this vertex to other vertex's in a graph.
	std::vector<Edge> edges;
private:
	//The vertex's position in the world
	//Point2D position;

		
};