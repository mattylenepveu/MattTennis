#pragma once
#include "Composite.h"
#include "BehaviourNode.h"

// Class inherits from Composite class
class Sequence : public Composite
{
public:
	//--------------------------------------------------------------------------------------
	// Function executes Flee behaviour when called
	//
	// Parameters:
	//		pAgent: An Agent pointer used to access Agent class.
	//		fDeltaTime: A float that keeps track of real time.
	// Return:
	//		An EBehaviourResult (either failure or success)
	//--------------------------------------------------------------------------------------
	EBehaviourResult Execute(Agent* pAgent, float fDeltaTime)
	{
		// Goes through all of the children in vector list
		for (unsigned int i = 0; i < children.size(); ++i)
		{
			// Checks if any child has returned a failure
			if (children[i]->Execute(pAgent, fDeltaTime) == EBEHAVIOUR_FAILURE)
				// If so, then return the result as a failure
				return EBEHAVIOUR_FAILURE;
		}

		// If no children failed, the return a success result
		return EBEHAVIOUR_SUCCESS;
	}
};