#pragma once
#include "../Library/Point2D.h"
#include <vector>
#include "Edge.h"
#include <string>
#include "Constants.h"

class Vertex
{
public:
	Vertex(Point2D point, TerrianType type);
	~Vertex();

	Point2D getPosition() const;

	void addEdge(Edge edge);
	bool operator==(const Vertex& lhs)
	{ 
		if (this->position == lhs.getPosition())
		{
			return true;
		}
		return false;
	}

	bool visited;
	std::string vertexID;
	//The edges that connect this vertex to other vertex's in a graph.
	std::vector<Edge> edges;
	TerrianType type;	
private:
	//The vertex's position in the world
	Point2D position;
		
};