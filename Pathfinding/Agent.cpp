#include "Agent.h"
#include "Pathfinder.h"
#include <SDL.h>
#include <SDL_opengl.h>
#include <GL\GLU.h>
#include <iostream>
#include "Constants.h"
#include "AgentSteeringBehaviour.h"

Agent::Agent(Vertex* startingPosition):
	currentGraphPosition(startingPosition),
	size(TILE_WIDTH/2, TILE_HEIGHT/1.5),
	color(0,0,0)
{
	this->velocity = Vector2D(0,0);
	this->maxAcceleration = 1;
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
		if(this->position == this->path->getEndNode()->getPosition())
		{
			delete path;
			path = 0;
			//TODO:Ask for new path			
		}
		else if (this->position == this->path->getCurrentTarget()->getPosition())
		{
			this->path->setNextTarget();		
			this->velocity = AgentSteeringBehaviour::seek(this->position, this->path->getCurrentTarget()->getPosition(), this->maxAcceleration);
			this->position += this->velocity;	
			this->orientation = AgentSteeringBehaviour::orientation(this->velocity, this->orientation);
		}
		else
		{			
			this->velocity = AgentSteeringBehaviour::seek(this->position, this->path->getCurrentTarget()->getPosition(), this->maxAcceleration);
			this->position += this->velocity;	
			this->orientation = AgentSteeringBehaviour::orientation(this->velocity, this->orientation);
		}
		
	}
}

void Agent::render(SDL_Window* window)
{    
	glLoadIdentity();
	float x = this->position.x,
		  y = this->position.y,
		  width = this->size.width,
		  height = this->size.height;
	glTranslatef( x, y , 0);
	glRotatef(this->orientation, 0, 0, 1);
	glBegin( GL_QUADS );		
		glColor3f(float(this->color.r)/255, float(this->color.g)/255, float(this->color.b)/255);
		
		glVertex2f( -width/2, -height/2);
        glVertex2f( width/2, -height/2 );
        glVertex2f( width/2, height/2);
        glVertex2f( -width/2, height/2 );
    glEnd();
	GLenum error = glGetError();
	if( error != GL_NO_ERROR )
    {
        printf( "Error OpenGL! %s\n", gluErrorString( error ) );
    }
}

