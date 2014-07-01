#include "Pathfinder.h"
#include <map>
#include <algorithm>
#include <queue>
#include <iostream>

Path* Pathfinder::breadthFirstSearch(Vertex* source, Vertex* target, std::vector<TerrianType> terrianTypes)
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
							if ((a == b) && (std::find(terrianTypes.begin(), terrianTypes.end(), it->first->type) != terrianTypes.end()))			
							{
								std::cout << "(" << it->first->getPosition().x/40 << "," << it->first->getPosition().y/40 << ")" << std::endl;
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
						
				
				if (std::find(terrianTypes.begin(), terrianTypes.end(), w->type) != terrianTypes.end())
				{
					q.push(w);
					distances.insert(std::pair<Vertex*, int>(w, distances[v]+1));
				}				
				
				if (distances[v]+1 > layerDepth)
				{
					layerDepth = distances[v]+1;
				}
				
			}				
		}
	}
	return NULL;	
}