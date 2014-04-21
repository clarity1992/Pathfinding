#include "Graph.h"
#include <assert.h>
int main()
{
	Graph graph;

	Vertex nodeA;
	Vertex nodeB;
	Vertex nodeC;
	Vertex nodeD;
	Vertex nodeE;

	graph.addNode(&nodeA);
	graph.addNode(&nodeB);
	graph.addNode(&nodeC);
	graph.addNode(&nodeD);
	graph.addNode(&nodeE);

	graph.addEdge(nodeA, nodeB, 1);
	graph.addEdge(nodeA, nodeC, 2);

	graph.addEdge(nodeB, nodeD, 1);
	graph.addEdge(nodeC, nodeD, 1);

	graph.addEdge(nodeD, nodeE, 3);

	//assert(graph.isReachable(&nodeA, &nodeE));

	return 0;
}