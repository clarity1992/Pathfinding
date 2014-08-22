#include "Tile.h"
Tile::Tile(Point2D position, Size size, Color color, TerrianType terrianType):
	position(position),
	size(size),
	color(color),
	node(position, terrianType)
{

}


Tile::~Tile(void)
{
}

void Tile::render(GraphicsEngine* graphicsEngine) const
{
	graphicsEngine->render(this->size, this->color, this->position, 0);
}