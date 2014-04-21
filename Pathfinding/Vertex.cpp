#include "Vertex.h"

using std::string;

Vertex::Vertex(string vertexID): vertexID(vertexID)
{
	visited = false;
}

Vertex::~Vertex()
{

}

void Vertex::addEdge(Edge edge)
{
	this->edges.push_back(edge);
}