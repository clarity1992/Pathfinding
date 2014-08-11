#include "AgentSteeringBehaviour.h"
#include "Constants.h"
Vector2D AgentSteeringBehaviour::seek(Vector2D agentPosition,
									  Vector2D targetPosition,
									  float agentMaxAcceleration)
{
	return Vector2D(targetPosition - agentPosition).normalize() * agentMaxAcceleration;	
}

Vector2D AgentSteeringBehaviour::flee(Vector2D agentPosition,
									  Vector2D targetPosition,
									  float agentMaxAcceleration)
{
	Vector2D velocity = Vector2D(agentPosition - targetPosition);
	velocity.normalize();
	velocity *= agentMaxAcceleration;
	return velocity;
}

Vector2D AgentSteeringBehaviour::arrive(Vector2D agentPosition,
										Vector2D targetPosition,
										Vector2D agentVelocity,
										float agentMaxAcceleration,
										float agentMaxSpeed)
{
	Vector2D direction = Vector2D(targetPosition - agentPosition);
	float distance = direction.length();
	//Holds the time over which to achieve target speed
	float timeToTarget = 0.1;
	float agentSpeed = 0;	
	float speed = agentVelocity.length();
	if (distance < (speed/2))
	{
		//The agent has arrived.	
		return Vector2D(0,0);
	}	

	//Slow Radius
	if (distance > 10*3)
	{
		agentSpeed = agentMaxSpeed;
	}
	else 
	{
		agentSpeed = (agentMaxSpeed * distance)/30;
	}

	Vector2D targetVelocity = direction;

	targetVelocity.normalize();
	targetVelocity *= agentMaxSpeed;
	
	Vector2D velocity = targetVelocity - agentVelocity;
	velocity /= timeToTarget;

	if (velocity.length() > agentMaxAcceleration)
	{
		velocity.normalize();
		velocity *= agentMaxAcceleration;
	}	
	return velocity;
}

float AgentSteeringBehaviour::orientation (Vector2D agentVelocity,
										   float agentOrientation)
{
	if (agentVelocity.length() > 0)
	{
		return atan2 (agentVelocity.y, agentVelocity.x) * 180 / PI;
	}
	else
	{
		return agentOrientation;
	}	
}