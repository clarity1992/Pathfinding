#pragma once
class Vertex;
class Edge
{
public:
	Edge();
	Edge(Vertex& linkedVertex, int weight);
	~Edge();

	Vertex* getLinkedVertex();

private:
	//The vertex that is connected to the host vertex via this edge.
	Vertex* linkedVertex;

	//The weight or cost of taking this edge in a given path
	int weight;
};

