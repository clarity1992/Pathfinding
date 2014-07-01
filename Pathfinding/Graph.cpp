#include "Graph.h"
#include <iostream>
#include <limits.h>
#include <set>
#include <list> // for pair
#include <algorithm>
#include <iterator>
#include <vector>
#include <map>
#include <queue>
using std::cout;
using std::endl;

Graph::Graph(void)
{

}


Graph::~Graph(void)
{
	for (unsigned i = 0; i < this->nodes.size(); ++i)
	{
		//delete nodes.at(i);
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