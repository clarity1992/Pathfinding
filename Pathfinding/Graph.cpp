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

int Graph::isReachable(Vertex* startingVertex, Vertex* endingVertex, std::vector<Vertex*>& path)
{
	cout << "Finding path from vertex: " << startingVertex->vertexID << " to: " << endingVertex->vertexID << endl; 
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
	{
		return false;
	}
	int cost = 0;

	/* Now see if we can get there from here. */
	isReachableRec(startP, endingVertex, cost, path);
	cout << "Path Cost: " << cost << endl;
	return cost;
}

bool Graph::isReachableRec(Vertex* startingVertex, Vertex* endingVertex, int& cost, std::vector<Vertex*>& path)
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

	//Check that this vertex has edges
	if (startingVertex->edges.size() == 0)
	{
		return false;
	}

	/*
	* See if we can get there from each
	* of the vertices we connect to.
	* If we can get there from at least
	* one of them, it is reachable.
	*/	
	unsigned i = 0;
	for (edgeP = &startingVertex->edges.at(0); i < startingVertex->edges.size(); )
	{		
		if (isReachableRec(edgeP->getLinkedVertex(), endingVertex, cost, path))
		{
			cost += edgeP->getWeight();
			path.push_back(edgeP->getLinkedVertex());
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

int Graph::isReachableBFS(Vertex* startingVertex, Vertex* endingVertex, std::queue<Vertex*>& path)
{
	cout << "Finding path from vertex: " << startingVertex->vertexID << " to: " << endingVertex->vertexID << endl; 
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
	{
		return false;
	}
	int cost = 0;

	/* Now see if we can get there from here. */
	isReachableRecBFS(startP, endingVertex, cost, path);
	cout << "Path Cost: " << cost << endl;
	return cost;
}

bool Graph::isReachableRecBFS(Vertex* startingVertex, Vertex* endingVertex, int& cost, std::queue<Vertex*>& path)
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

	//Check that this vertex has edges
	if (startingVertex->edges.size() == 0)
	{
		return false;
	}

	/*
	* See if we can get there from each
	* of the vertices we connect to.
	* If we can get there from at least
	* one of them, it is reachable.
	*/	
	unsigned i = 0;
	for (edgeP = &startingVertex->edges.at(0); i < startingVertex->edges.size(); )
	{		
		if (isReachableRecBFS(edgeP->getLinkedVertex(), endingVertex, cost, path))
		{
			cost += edgeP->getWeight();
			path.push(edgeP->getLinkedVertex());
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

Path* Graph::findPath(Vertex* startingVertex, Vertex* endingVertex)
{
	std::queue<Vertex*> path;

	return breadthFirstSearch(startingVertex, endingVertex);
}
void Graph::dijkstra(Vertex* start)
{
	/*std::list<std::pair<Vertex*,int>> working;
	std::vector<std::pair<Vertex*,int>> finished;
	working.push_back(std::pair<Vertex*,int>(start,0)); // No cost to get to start.

	std::list<std::pair<Vertex*,int>>::iterator it;

	for( *it = working.front; *it != working.end; *it = working.front)
	{
		working.pop_front();
		// If we have already processed this node ignore it.
		if (std::find(finished.front().first, finished.back().first, it->first))
		{   
			continue;
		}

		// We have just removed a node from working.
		// Because it is the top of the list it is guaranteed to be the shortest route to
		// the node. If there is another route to the node it must go through one of the
		// other nodes in the working list which means the cost to reach it will be higher
		// (because working is sorted). Thus we have found the shortest route to the node.

		// As we have found the shortest route to the node save it in finished
		finished.push_back(*it);

		// For each arc leading from this node we need to find where we can get to.
		std::vector<Edge>::iterator edges;
		for (edges = it->first->edges.begin(); edges != it->first->edges.end(); ++edges)
		{
			Vertex* destination = edges->getLinkedVertex();
			if (!(std::find(finished.front().first,finished.back().first, *destination)))
			{
				// If the node is already in finished then we don't need to worry about it
				// as that will be the shortest route other wise calculate the cost and add
				// this new node to the working list.
				int destCost = edges->getWeight() + it->second;
				working.push_back(std::pair<Vertex*, int>(destination, destCost));
			}
		}
		working.pop_front();
	}

	finished;
	working;*/
}

Path* Graph::breadthFirstSearch(Vertex* source, Vertex* target)
{	
	unsigned layerDepth = 0;
	std::map<Vertex*, int> distances;
	distances.insert(std::pair<Vertex*, int>(source, 0));
	//create a queue Q
	std::queue<Vertex*> q;
	//enqueue source onto Q
	q.push(source);
	// mark source
	source->visited = true;

	//while Q is not empty:
	while (q.size() > 0)
	{
		//dequeue an item from Q into v
		Vertex* v = q.front();
		

		if (v == target)
		{

			std::vector<Vertex*> path;
			path.push_back(target);
			std::map<Vertex*, int>::iterator it;			
			unsigned i = layerDepth;
			while (i > 0)
			{			
				for (it = distances.begin(); it != distances.end(); ++it)
				{
					Vertex* vertexA = path.at(path.size()-1);
					Vertex* vertexB = it->first;

					for (unsigned  j = 0; j < vertexA->edges.size(); ++j)
					{
						if (vertexA->edges.at(j).getLinkedVertex() == vertexB)
						{
							int a = distances[vertexA];
							int b = (distances[vertexB] + 1);
							if ((a == b))
							{
								path.push_back(it->first);					
							}
						}
					}
				}				
				--i;	
			}	
			
			std::reverse(path.begin(), path.end());

			return new Path(path);
		}

		q.pop();

		//for each edge e incident on v in Graph:
		std::vector<Edge>::iterator edge;
		for (edge = v->edges.begin(); edge != v->edges.end(); ++edge)
		{
			//let w be the other end of e
			Vertex* w = edge->getLinkedVertex();
			// if w is not marked:
			if (!w->visited)
			{
				//mark w
				w->visited = true;
				//enqueue w onto Q
				q.push(w);				
				distances.insert(std::pair<Vertex*, int>(w, distances[v]+1));
				if (distances[v]+1 > layerDepth)
				{
					layerDepth = distances[v]+1;
				}				
			}				
		}
	}
	return NULL;	
}