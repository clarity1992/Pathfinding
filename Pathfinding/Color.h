#pragma once
struct Color
{
	int r, g, b;
	Color()
	{
		this->r = 0;
		this->b = 0;
		this->g = 0;
	}
	Color(int r, int g, int b)
	{
		this->r = r;
		this->b = b;
		this->g = g;
	}
};