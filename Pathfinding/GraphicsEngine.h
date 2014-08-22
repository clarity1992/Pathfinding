#pragma once
#include "Size.h"
#include "Color.h"
#include "../Library/Point2D.h"
class GraphicsEngine
{
public:
	GraphicsEngine(void);
	~GraphicsEngine(void);

	virtual bool init(unsigned screenWidth, unsigned screenHeight) = 0;
	virtual void refreshFrame() = 0;
	virtual void render(const Size& size, const Color& color, const Point2D& position, const float& orientation) = 0;
};

