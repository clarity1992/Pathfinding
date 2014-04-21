#include "Graph.h"
#include <assert.h>
int main()
{
	Graph graph;

	Vertex nodeA("nodeA");
	Vertex nodeB("nodeB");
	Vertex nodeC("nodeC");
	Vertex nodeD("nodeD");
	Vertex nodeE("nodeE");
	Vertex nodeF("nodeF");

	graph.addNode(&nodeA);
	graph.addNode(&nodeB);
	graph.addNode(&nodeC);
	graph.addNode(&nodeD);
	graph.addNode(&nodeE);
	graph.addNode(&nodeF);

	graph.addEdge(nodeA, nodeB, 1);
	graph.addEdge(nodeA, nodeC, 2);

	graph.addEdge(nodeB, nodeF, 3);
	graph.addEdge(nodeB, nodeD, 1);
	

	graph.addEdge(nodeC, nodeD, 1);

	graph.addEdge(nodeD, nodeE, 3);
	
	graph.addEdge(nodeF, nodeE, 3);

	assert(graph.isReachable(&nodeA, &nodeB));
	assert(graph.isReachable(&nodeA, &nodeC));
	assert(graph.isReachable(&nodeA, &nodeD));
	assert(graph.isReachable(&nodeA, &nodeE));
	assert(graph.isReachable(&nodeA, &nodeF));

	assert(graph.isReachable(&nodeC, &nodeD));

	assert(graph.isReachable(&nodeC, &nodeE));

	return 0;
} 