#pragma once

const unsigned TILE_WIDTH = 15;
const unsigned TILE_HEIGHT = 15;
const int SCREEN_FPS = 30;
const int SCREEN_TICKS_PER_FRAME = 1000 / SCREEN_FPS;

enum TerrianType
{
	ROAD,
	INTERSECTION,
	PAVEMENT,
	BUILDING,
	GRASS, 
	WATER,
	CROSSING
};

enum AgentType
{
	
	PEDESTRIAN,
	CAR
};