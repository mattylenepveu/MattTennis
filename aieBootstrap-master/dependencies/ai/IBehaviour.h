#pragma once
#include "Vector2.h"

// Forward declare used to avoid circular inheritance
class Agent;

class IBehaviour
{
public:
	//--------------------------------------------------------------------------------------
	// An additional constructor.
	//
	// Parameters:
	//		fWeighting: A float used for weighting allbehaviours
	//--------------------------------------------------------------------------------------
	IBehaviour(float fWeighting)
	{
		// Assigns weighting to a Local variable
		m_fWeighting = fWeighting;
	}

	//--------------------------------------------------------------------------------------
	// Default Constructor.
	//--------------------------------------------------------------------------------------
	IBehaviour() {}

	//--------------------------------------------------------------------------------------
	// Default Destructor (virtual as it's not used here but is in inherited classes)
	//--------------------------------------------------------------------------------------
	virtual ~IBehaviour() {}

	//--------------------------------------------------------------------------------------
	// Function updates the behaviour per frame (Pure virtual)
	//
	// Parameters:
	//		pAgent: An agent pointer that allows for access to the Agent class
	//		fDeltaTime: A float that is used to keep track of real time
	// Return:
	//		Returns behaviour result as a Vector2
	//--------------------------------------------------------------------------------------
	virtual Vector2 Update(Agent* pAgent, float fDeltaTime) = 0;

	// Local float variable for weighting 
	float m_fWeighting;
};
