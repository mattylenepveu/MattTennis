#pragma once
#include "Composite.h"
#include "BehaviourNode.h"
#include "Agent.h"

// Class inherits from Composite class
class Selector : public Composite
{
public:
	//--------------------------------------------------------------------------------------
	// Function executes an if statement to see if any children are a success
	//
	// Parameters:
	//		pAgent: An Agent pointer used to access Agent class.
	//		fDeltaTime: A float that keeps track of real time.
	// Return:
	//		An EBehaviourResult (either failure or success)
	//--------------------------------------------------------------------------------------
	EBehaviourResult Execute(Agent* pAgent, float fDeltaTime)
	{
		// Goes through all children in vector list
		for (unsigned int i = 0; i < children.size(); ++i)
		{
			// Checks if a child is a success
			if (children[i]->Execute(pAgent, fDeltaTime) == EBEHAVIOUR_SUCCESS)
				// If they are, return a success result
				return EBEHAVIOUR_SUCCESS;
		}

		// If none are a success, then return failure
		return EBEHAVIOUR_FAILURE;
	}
};