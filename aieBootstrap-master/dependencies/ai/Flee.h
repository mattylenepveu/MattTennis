#pragma once
#include "IBehaviour.h"
#include "Vector2.h"
#include "Agent.h"
#include "Player.h"

class Flee : public IBehaviour
{
public:
	//--------------------------------------------------------------------------------------
	// An additional constructor.
	//
	// Parameters:
	//		fWeighting: A float used for weighting allbehaviours
	//--------------------------------------------------------------------------------------
	Flee(float fWeighting);

	//--------------------------------------------------------------------------------------
	// Default Constructor.
	//--------------------------------------------------------------------------------------
	Flee();

	//--------------------------------------------------------------------------------------
	// Default Destructor.
	//--------------------------------------------------------------------------------------
	~Flee();

	//--------------------------------------------------------------------------------------
	// Function updates the behaviour per frame
	//
	// Parameters:
	//		pAgent: An agent pointer that allows for access to the Agent class
	//		fDeltaTime: A float that is used to keep track of real time
	// Return:
	//		Returns flee result as a Vector2
	//--------------------------------------------------------------------------------------
	Vector2 Update(Agent* pAgent, float fDeltaTime);

	//--------------------------------------------------------------------------------------
	// Function allows a target to be set for agents using Flee
	//
	// Parameters:
	//		pAgent: An agent pointer that allows for access to the Agent class
	//--------------------------------------------------------------------------------------
	void SetTarget(Agent* pAgent);

private:
	// Agent pointer used to allow access to Agent class
	Agent* m_pPlayer;
};

