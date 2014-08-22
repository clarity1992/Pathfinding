#pragma once
#include "GraphicsEngine.h"
#include <SDL.h>
#include <SDL_opengl.h>
#include <GL\GLU.h>
class OpenGLGraphicsEngine :
	public GraphicsEngine
{
public:
	OpenGLGraphicsEngine(unsigned screenWidth, unsigned screenHeight);
	~OpenGLGraphicsEngine(void);

	virtual void refreshFrame();
	void render(const Size& size, const Color& color, const Point2D& position, const float& orientation);

private: 
	SDL_Window* window;
	SDL_GLContext context;

	bool init(unsigned screenWidth, unsigned screenHeight);
	bool initOpenGL();
};

