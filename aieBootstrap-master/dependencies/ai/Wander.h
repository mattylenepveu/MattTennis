#pragma once
#include "IBehaviour.h"
#include "Vector2.h"
#include "Agent.h"

class Wander : public IBehaviour
{
public:
	//--------------------------------------------------------------------------------------
	// An additional constructor.
	//
	// Parameters:
	//		fWeighting: A float used for weighting allbehaviours
	//--------------------------------------------------------------------------------------
	Wander(float fWeighting);

	//--------------------------------------------------------------------------------------
	// Default Constructor.
	//--------------------------------------------------------------------------------------
	Wander();

	//--------------------------------------------------------------------------------------
	// Default Destructor.
	//--------------------------------------------------------------------------------------
	~Wander();

	//--------------------------------------------------------------------------------------
	// Function updates the behaviour per frame
	//
	// Parameters:
	//		pAgent: An agent pointer that allows for access to the Agent class
	//		fDeltaTime: A float that is used to keep track of real time
	// Return:
	//		Returns seek result as a Vector2
	//--------------------------------------------------------------------------------------
	Vector2 Update(Agent* pAgent, float fDeltaTime);

	//--------------------------------------------------------------------------------------
	// Generates a random number for wander calculations to use
	//
	// Return:
	//		Returns the random number as a float
	//--------------------------------------------------------------------------------------
	float RandNumber();

private:
	// All floats used for calculating wander
	float m_fWanderRadius;
	float m_fWanderDistance;
	float m_fWanderJitter;
};

