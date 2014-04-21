#include "Edge.h"
#include "Vertex.h"

Edge::Edge(void)
{

}

Edge::Edge(Vertex& linkedVertex, int weight): linkedVertex(&linkedVertex), weight(weight)
{
	
}

Edge::~Edge(void)
{

}

Vertex* Edge::getLinkedVertex()
{
	return linkedVertex;
}
