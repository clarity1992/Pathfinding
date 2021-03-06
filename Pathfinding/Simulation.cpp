#include "Simulation.h"
#include "VehicleAgent.h"
#include "PedestrianAgent.h"
#include "WorldBuilder.h"
#include "WorldFileReader.h"
#include <stdio.h>
#include <stdlib.h>     
#include <time.h>
#include "OpenGLGraphicsEngine.h"
Simulation::Simulation(int SCREEN_WIDTH, int SCREEN_HEIGHT)
{	
	graphicsEngine = new OpenGLGraphicsEngine(SCREEN_WIDTH, SCREEN_HEIGHT);	
	std::vector<TerrianType> t;
	t.push_back(TerrianType::INTERSECTION);
	t.push_back(TerrianType::CROSSING);
	t.push_back(TerrianType::ROAD);
	VehicleAgent::setTraversableTerrianTypes(t);

	std::vector<TerrianType> p;
	p.push_back(TerrianType::GRASS);
	p.push_back(TerrianType::CROSSING);
	p.push_back(TerrianType::PAVEMENT);
	PedestrianAgent::setTraversableTerrianTypes(p);

	srand (time(0));

	world = WorldBuilder::createWorld(WorldFileReader::readFile("testWorld3.txt", ' '));
	world->createPathNetwork();
	
	spawnNewAgent(AgentType::CAR);

	isRunning = true;	
}


Simulation::~Simulation(void)
{
    

    //Quit SDL subsystems
    SDL_Quit();
}

void Simulation::input()
{
	SDL_Event event;

	/* Poll for events. SDL_PollEvent() returns 0 when there are no  */
	/* more events on the event queue, our while loop will exit when */
	/* that occurs.                                                  */
	while( SDL_PollEvent( &event ) )
	{
		/* We are only worried about SDL_KEYDOWN and SDL_KEYUP events */
		switch( event.type )
		{
			case SDL_KEYDOWN:
					/* Check the SDLKey values and move change the coords */
					switch( event.key.keysym.sym )
					{
						case SDLK_a:
							spawnNewAgent(AgentType::CAR);
							break;	
						case SDLK_s:
							spawnNewAgent(AgentType::PEDESTRIAN);
							break;	
						default:
							break;
					}				

			case SDL_KEYUP:			
			break;

			default:
			break;
		}
	}
}

void Simulation::update()
{
	world->update();
	for (unsigned i = 0; i < agents.size(); ++i)
	{
		agents.at(i)->update();
	}
}

void Simulation::render() const
{	
	this->world->render(this->graphicsEngine);
	for (unsigned i = 0; i < agents.size(); ++i)
	{
		agents.at(i)->render(this->graphicsEngine);
	}
	this->graphicsEngine->refreshFrame();
}

/**
 * TODO: AGENT FACTORY
 */
void Simulation::spawnNewAgent(AgentType agentType)
{	
	unsigned originNodeIndex = rand() % this->world->getGraph()->getNodes().size();
	unsigned destNodeIndex = rand() % this->world->getGraph()->getNodes().size();
	
	std::vector<TerrianType> validTerrianTypes;
	if (agentType == AgentType::CAR)
	{
		validTerrianTypes = VehicleAgent::getTraversableTerrianTypes();
	}
	else if (agentType == AgentType::PEDESTRIAN)
	{
		validTerrianTypes = PedestrianAgent::getTraversableTerrianTypes();
	}
	

	while( true )
	{
		if(std::find(validTerrianTypes.begin(),
			validTerrianTypes.end(),
			world->getGraph()->getNodes().at(originNodeIndex)->type) != validTerrianTypes.end())
		{
			break;
		}
		else
		{
			originNodeIndex = rand() % this->world->getGraph()->getNodes().size();
		}
	}

	while( true )
	{
		if(std::find(validTerrianTypes.begin(),
			validTerrianTypes.end(),
			world->getGraph()->getNodes().at(destNodeIndex)->type) != validTerrianTypes.end())
		{
			break;
		}
		else
		{
			destNodeIndex = rand() % this->world->getGraph()->getNodes().size();
		}
	}
	
	if (agentType == AgentType::CAR)
	{
		VehicleAgent* newAgent = new VehicleAgent(world->getGraph()->getNodes().at( originNodeIndex));
		agents.push_back(newAgent);
		agents.back()->moveToLocationOnGraph(world->getGraph(), world->getGraph()->getNodes().at(destNodeIndex));
	}
	else if (agentType == AgentType::PEDESTRIAN)
	{
		PedestrianAgent* newAgent = new PedestrianAgent(world->getGraph()->getNodes().at( originNodeIndex));
		agents.push_back(newAgent);
		agents.back()->moveToLocationOnGraph(world->getGraph(), world->getGraph()->getNodes().at(destNodeIndex));
	}
}