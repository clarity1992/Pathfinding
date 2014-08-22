#pragma once
#include "Constants.h"
#include "Size.h"
#include "Color.h"
#include "Vertex.h"
#include "GraphicsEngine.h"
class Tile
{
public:
	Tile(Point2D position, Size size, Color color, TerrianType terrianType);
	~Tile(void);

	Vertex* getNode()
	{
		return &node;
	}

	void render(GraphicsEngine* graphicsEngine) const;

private:
	Vertex node;
	Point2D position;
	Size size;
	Color color;	
};

