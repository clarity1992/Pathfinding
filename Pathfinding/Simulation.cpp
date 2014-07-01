#include "Simulation.h"
#include "WorldBuilder.h"
#include "WorldFileReader.h"
#include <stdio.h>

Simulation::Simulation(int SCREEN_WIDTH, int SCREEN_HEIGHT)
{	
	world = WorldBuilder::createWorld(WorldFileReader::readFile("testWorld1.txt", ' '));
	world->createPathNetwork();
	

	agent = new Agent(world->getGraph()->getNodes().at(0));

	agent->moveToLocation(world->getGraph()->getNodes().at(39));
	isRunning = true;
	window = NULL;

	//Initialize SDL
    if( SDL_Init( SDL_INIT_VIDEO ) < 0 )
    {
        printf( "SDL could not initialize! SDL_Error: %s\n", SDL_GetError() );
    }
	else
    {
        //Create window
        window = SDL_CreateWindow( "SDL Tutorial", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN );
        if( window == NULL )
        {
            printf( "Window could not be created! SDL_Error: %s\n", SDL_GetError() );
        }			
    }
}


Simulation::~Simulation(void)
{
	//Destroy window
    SDL_DestroyWindow( window );

    //Quit SDL subsystems
    SDL_Quit();
}

void Simulation::input()
{

}

void Simulation::update()
{
	world->update();
	agent->update();
}

void Simulation::render()
{
	world->render(window);	
	agent->render(window);

	//Update the surface
	SDL_UpdateWindowSurface( window );   
}
