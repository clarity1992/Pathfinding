#include "OpenGLGraphicsEngine.h"

#include <SDL_image.h>
#include <stdio.h>
#include "Constants.h"

OpenGLGraphicsEngine::OpenGLGraphicsEngine(unsigned screenWidth, unsigned screenHeight)
{
	init(screenWidth, screenHeight);
}


OpenGLGraphicsEngine::~OpenGLGraphicsEngine(void)
{

}

bool OpenGLGraphicsEngine::init(unsigned screenWidth, unsigned screenHeight)
{
	//Initialization flag
    bool success = true;

    //Initialize SDL
    if( SDL_Init( SDL_INIT_VIDEO ) < 0 )
    {
        printf( "SDL could not initialize! SDL Error: %s\n", SDL_GetError() );
        success = false;
    }
    else
    {
        //Use OpenGL 2.1
        SDL_GL_SetAttribute( SDL_GL_CONTEXT_MAJOR_VERSION, 2 );
        SDL_GL_SetAttribute( SDL_GL_CONTEXT_MINOR_VERSION, 1 );

        //Create window
		this->window = SDL_CreateWindow("Pathfinding",
			SDL_WINDOWPOS_UNDEFINED,
			SDL_WINDOWPOS_UNDEFINED,
			screenWidth, screenHeight,
			SDL_WINDOW_OPENGL | SDL_WINDOW_SHOWN );
        if(  this->window == NULL )
        {
            printf( "Window could not be created! SDL Error: %s\n", SDL_GetError() );
            success = false;
        }
		else
        {
            //Create context
            this->context = SDL_GL_CreateContext( this->window );
            if( this->context == NULL )
            {
                printf( "OpenGL context could not be created! SDL Error: %s\n", SDL_GetError() );
                success = false;
            }
            else
            {
                //Use Vsync
                if( SDL_GL_SetSwapInterval( 1 ) < 0 )
                {
                    printf( "Warning: Unable to set VSync! SDL Error: %s\n", SDL_GetError() );
                }

                //Initialize OpenGL
                if( !initOpenGL() )
                {
                    printf( "Unable to initialize OpenGL!\n" );
                    success = false;
                }
            }
        }
    }
    return success;
}

bool OpenGLGraphicsEngine::initOpenGL()
{
    //Initialize Projection Matrix
    glMatrixMode( GL_PROJECTION );
    glLoadIdentity();
    glOrtho( 10.0, SCREEN_WIDTH, SCREEN_HEIGHT, 10.0, 1.0, -1.0 );	
    //Initialize Modelview Matrix
    glMatrixMode( GL_MODELVIEW );
    glLoadIdentity();

    //Initialize clear color
    glClearColor( 0.f, 0.f, 0.f, 1.f );

    //Check for error
    GLenum error = glGetError();
    if( error != GL_NO_ERROR )
    {
        printf( "Error initializing OpenGL! %s\n", gluErrorString( error ) );
        return false;
    }

    return true;
}

void OpenGLGraphicsEngine::refreshFrame()
{
	glFlush();
	//Update screen
    SDL_GL_SwapWindow( this->window );
	//Clear color buffer
    glClear( GL_COLOR_BUFFER_BIT );

    //Reset modelview matrix
    glMatrixMode( GL_MODELVIEW );
    glLoadIdentity();
}

void OpenGLGraphicsEngine::render(const Size& size, const Color& color, const Point2D& position, const float& orientation)
{
	glLoadIdentity();
	float x = position.x,
		  y = position.y,
		  width = size.width,
		  height = size.height;
	glTranslatef( x, y , 0);
	
	glBegin( GL_QUADS );		
		glColor3f(float(color.r)/255, float(color.g)/255, float(color.b)/255);
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