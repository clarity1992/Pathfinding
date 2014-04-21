#include "Vertex.h"


Vertex::Vertex()
{

}

Vertex::~Vertex()
{

}

void Vertex::addEdge(Edge edge)
{
	this->edges.push_back(edge);
}