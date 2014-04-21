#include "Graph.h"
#include <iostream>

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

bool Graph::isReachable(Vertex* startingVertex, Vertex* endingVertex)
{
	Vertex* vertP;
	Vertex* startP = NULL;

	/*
	* Go through each vertex, mark them
	* as "not visited" and also record
	* where the start vertex is.
	*/

	unsigned i = 0;
	for (vertP = this->nodes.at(0); i < this->nodes.size(); )
	{
		vertP->visited = false;
		if (vertP == startingVertex)
		{
			startP = vertP;
		}			
		++i;

		if (i < this->nodes.size())
		{
			vertP = nodes.at(i);
		}
	}

	/* Make sure the starting point exists. */

	if (startP == NULL)
	return false;
	 
	/* Now see if we can get there from here. */

	return isReachableRec(startP, endingVertex);
}

bool Graph::isReachableRec(Vertex* startingVertex, Vertex* endingVertex)
{
	
	Edge *edgeP;

	/* Have we been here already? */

	if (startingVertex->visited)
		return false;

	/*
	* Is this the destination?  If so,
	* we've reached it!
	*/

	if (startingVertex == endingVertex)
		return true;

	/* Don't come here again. */
	startingVertex->visited = true;

	/*
	* See if we can get there from each
	* of the vertices we connect to.
	* If we can get there from at least
	* one of them, it is reachable.
	*/

	unsigned i = 0;
	if (startingVertex->edges.size() == 0)
		return false;

	for (edgeP = &startingVertex->edges.at(0); i < startingVertex->edges.size(); )
	{
		if (isReachableRec(edgeP->getLinkedVertex(), endingVertex))
		{
			cout << startingVertex->vertexID << " is on the path to : " << endingVertex->vertexID << endl;
			return true;
		}

		++i;

		if (i < startingVertex->edges.size())
		{
			edgeP = &startingVertex->edges.at(i);
		}			
	}

	/*
	* Couldn't get there from any of our
	* neighbors, so it is unreachable from
	* here.
	*/
	return false;
}