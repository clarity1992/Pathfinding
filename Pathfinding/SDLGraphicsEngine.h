#pragma once
#include "GraphicsEngine.h"
class SDLGraphicsEngine :
	public GraphicsEngine
{
public:
	SDLGraphicsEngine(unsigned screenWidth, unsigned screenHeight);
	~SDLGraphicsEngine(void);	
	
	virtual void refreshFrame();
	void render(const Size& size, const Color& color, const Point2D& position, const float& orientation);

private:
	bool init(unsigned screenWidth, unsigned screenHeight);
};

