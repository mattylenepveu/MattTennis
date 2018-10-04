#pragma once
#include "IBehaviour.h"
#include "Agent.h"
#include "Vector2.h"
#include "Player.h"

class Arrive : public IBehaviour
{
public:
	//--------------------------------------------------------------------------------------
	// An additional constructor.
	//
	// Parameters:
	//		fWeighting: A float used for weighting allbehaviours
	//--------------------------------------------------------------------------------------
	Arrive(float fWeighting);

	//--------------------------------------------------------------------------------------
	// Default Constructor.
	//--------------------------------------------------------------------------------------
	Arrive();

	//--------------------------------------------------------------------------------------
	// Default Destructor.
	//--------------------------------------------------------------------------------------
	~Arrive();

	//--------------------------------------------------------------------------------------
	// Function updates the behaviour per frame
	//
	// Parameters:
	//		pAgent: An agent pointer that allows for access to the Agent class
	//		fDeltaTime: A float that is used to keep track of real time
	// Return:
	//		Returns arrive result as a Vector2
	//--------------------------------------------------------------------------------------
	Vector2 Update(Agent* pAgent, float fDeltaTime);

	//--------------------------------------------------------------------------------------
	// Function allows a target to be set for agents using Arrive
	//
	// Parameters:
	//		pAgent: An agent pointer that allows for access to the Agent class
	//--------------------------------------------------------------------------------------
	void SetTarget(Agent* pAgent);

private:
	// Agent pointer used to allow access to Agent class
	Agent* m_pPlayer;
};

