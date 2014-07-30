#include "Agent.h"
#include "Pathfinder.h"
#include <SDL.h>
#include <iostream>
#include "Constants.h"

Agent::Agent(Vertex* startingPosition):
	currentGraphPosition(startingPosition),
	size(TILE_WIDTH/1.5, TILE_HEIGHT/1.5),
	color(0,0,0)
{
	this->velocity = Vector2D(0,0);
	this->position = this->currentGraphPosition->getPosition();	
}

Agent::Agent(Vertex* startingPosition, AgentType agentType):
	currentGraphPosition(startingPosition),
	size(TILE_WIDTH/1.5, TILE_HEIGHT/1.5)
{
	this->velocity = Vector2D(0,0);
	this->position = this->currentGraphPosition->getPosition();	
}

Agent::~Agent(void)
{

}

void Agent::update()
{
	if (path)
	{
		this->velocity = Vector2D(0,0);

		if(this->position == this->path->getEndNode()->getPosition())
		{
			delete path;
			path = 0;
			//TODO:Ask for new path
			//this->position = Point2D(-100,-100);
		}
		else if (this->position == this->path->getCurrentTarget()->getPosition())
		{
			this->path->setNextTarget();
			Vector2D velocity = Vector2D(path->getCurrentTarget()->getPosition() - this->position).normalize();
			this->velocity = ( velocity - this->velocity );
			this->position += this->velocity;	
		}
		else
		{
			Vector2D velocity = Vector2D(path->getCurrentTarget()->getPosition() - this->position).normalize();
			this->velocity = ( velocity - this->velocity );
			this->position += this->velocity;	
		}
		
	}
}

void Agent::render(SDL_Window* window)
{
	//std::cout << this->position.toCoordinate() << std::endl;
	//std::cout << this->velocity.toString() << std::endl;
	//The surface contained by the window
    SDL_Surface* screenSurface = NULL;

	//Get window surface
	screenSurface = SDL_GetWindowSurface(window);

	//Tile Rectangle
	SDL_Rect tileRect;
	tileRect.x = position.x;
	tileRect.y = position.y;
	tileRect.w = size.width;
	tileRect.h = size.height;

	//Fill the surface white
	SDL_FillRect(screenSurface, &tileRect, SDL_MapRGB( screenSurface->format, color.r, color.g, color.b ) );
}

