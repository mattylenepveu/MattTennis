#pragma once

// Forward declares to avoid circular inclusions
class Agent;

class BaseDecision
{
public:
	//--------------------------------------------------------------------------------------
	// Pure Virtual function allows a decision to be made and executed
	//
	// Parameters:
	//		pAgent: An Agent pointer used to access the Agent class
	//		fDeltaTime: A float used to keep track of real time
	//--------------------------------------------------------------------------------------
	virtual void MakeDecision(Agent* pAgent, float fDeltaTime) = 0;

	//--------------------------------------------------------------------------------------
	// Pure Virtual Function allows a target to be set for seek and arrive behaviours
	//
	// Parameters:
	//		pAgent: Target is passed through as an Agent pointer 
	//--------------------------------------------------------------------------------------
	virtual void SetTarget(Agent* pAgent) = 0;
};