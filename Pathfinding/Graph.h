#pragma once
#include "Vertex.h"
#include <vector>
#include "Path.h"
#include <queue>
class Graph
{
public:
	Graph(void);
	~Graph(void);

	std::vector<Vertex*> getNodes() const {return this->nodes;}


	void addNode(Vertex* vertex);

	void addEdge(Vertex& vertexA, Vertex& vertexB, int weight);

	//Is there a uninterupted connetion between the two given vertexs.
	int isReachable(Vertex* startingVertex, Vertex* endingVertex, std::vector<Vertex*>& path);
	int isReachableBFS(Vertex* startingVertex, Vertex* endingVertex, std::queue<Vertex*>& path);
	
	Path* findPath(Vertex* startingVertex, Vertex* endingVertex);
	//Path* findBestPath(Vertex* startingVertex, Vertex* endingVertex);

	void dijkstra(Vertex* start);

	Path* breadthFirstSearch(Vertex* source, Vertex* target);

private:
	std::vector<Vertex*> nodes;
	
	bool isReachableRec(Vertex* startingVertex, Vertex* endingVertex, int& cost, std::vector<Vertex*>& path);
	bool isReachableRecBFS(Vertex* startingVertex, Vertex* endingVertex, int& cost, std::queue<Vertex*>& path);

};

