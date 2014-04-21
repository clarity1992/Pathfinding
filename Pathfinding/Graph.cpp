#include "Graph.h"


Graph::Graph(void)
{

}


Graph::~Graph(void)
{
	for (unsigned i = 0; i < this->nodes.size(); ++i)
	{
		delete nodes.at(i);
	}
}

void Graph::addNode(Vertex* vertex)
{
	this->nodes.push_back(vertex);
}

void Graph::addEdge(Vertex& vertexA, Vertex& vertexB, int weight)
{
	vertexA.addEdge(Edge(vertexB, weight));
}