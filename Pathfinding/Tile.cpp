#include "Tile.h"
#include <SDL.h>
#include <SDL_opengl.h>
#include <GL\GLU.h>
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

void Tile::render(SDL_Window* window) const
{
	glLoadIdentity();
	float x = this->position.x,
		  y = this->position.y,
		  width = this->size.width,
		  height = this->size.height;
	glTranslatef( x, y , 0);
	
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