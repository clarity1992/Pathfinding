#pragma once
#include "graphicsengine.h"
class OpenGLGraphicsEngine :
	public GraphicsEngine
{
public:
	OpenGLGraphicsEngine(unsigned screenWidth, unsigned screenHeight);
	~OpenGLGraphicsEngine(void);

	void render(const World* world, const std::vector<Agent*> agents);

private: 
	SDL_Window* window;
	SDL_GLContext context;

	bool init(unsigned screenWidth, unsigned screenHeight);
	bool initOpenGL();
};

