#pragma once
#include <math.h>
#include "../Library/Vector2D.h"
class AgentSteeringBehaviour
{
public:
	static Vector2D seek(Vector2D agentPosition,
						 Vector2D targetPosition,
						 float agentMaxAcceleration);

	static Vector2D flee(Vector2D agentPosition,
						 Vector2D targetPosition,
						 float agentMaxAcceleration);

	static Vector2D arrive(Vector2D agentPosition,
						   Vector2D targetPosition,
						   Vector2D agentVelocity,
						   float agentMaxAcceleration,
						   float agentMaxSpeed);

	static float orientation(Vector2D agentVelocity,
							 float currentOrientation);


};

