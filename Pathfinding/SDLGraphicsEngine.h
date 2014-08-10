#pragma once
#include "GraphicsEngine.h"
class SDLGraphicsEngine :
	public GraphicsEngine
{
public:
	SDLGraphicsEngine(unsigned screenWidth, unsigned screenHeight);
	~SDLGraphicsEngine(void);	
	
	void render(const World* world, const std::vector<Agent*> agents);

private:
	SDL_Window* window;
	SDL_GLContext context;

	bool init(unsigned screenWidth, unsigned screenHeight);
	bool initGL();
};

