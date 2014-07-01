#include "Vertex.h"

using std::string;

Vertex::Vertex(Point2D position, TerrianType type): position(position), type(type)
{
	this->vertexID = position.toCoordinate();
	visited = false;
}

Vertex::~Vertex()
{

}

Point2D Vertex::getPosition() const
{
	return position;
}

void Vertex::addEdge(Edge edge)
{
	this->edges.push_back(edge);
}