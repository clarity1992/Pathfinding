#include "SDLGraphicsEngine.h"
#include <assert.h>

SDLGraphicsEngine::SDLGraphicsEngine(unsigned screenWidth, unsigned screenHeight)
{
	init(screenWidth, screenHeight);
}


SDLGraphicsEngine::~SDLGraphicsEngine(void)
{

}

bool SDLGraphicsEngine::init(unsigned screenWidth, unsigned screenHeight)
{
	assert(false);
	return false;
}

void SDLGraphicsEngine::render(const World* world, const std::vector<Agent*> agents)
{
	assert(false);
}