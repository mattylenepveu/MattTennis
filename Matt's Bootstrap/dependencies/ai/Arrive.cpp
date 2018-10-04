#include "Arrive.h"
#include "Defines.h"

//--------------------------------------------------------------------------------------
// An additional constructor.
//
// Parameters:
//		fWeighting: A float used for weighting allbehaviours
//--------------------------------------------------------------------------------------
Arrive::Arrive(float fWeighting)
{
	// Assigns passed in weighting to a new variable
	m_fWeighting = fWeighting;
}

//--------------------------------------------------------------------------------------
// Default Constructor.
//--------------------------------------------------------------------------------------
Arrive::Arrive() {}

//--------------------------------------------------------------------------------------
// Default Destructor.
//--------------------------------------------------------------------------------------
Arrive::~Arrive() {}

//--------------------------------------------------------------------------------------
// Function updates the behaviour per frame
//
// Parameters:
//		pAgent: An agent pointer that allows for access to the Agent class
//		fDeltaTime: A float that is used to keep track of real time
// Return:
//		Returns arrive result as a Vector2
//--------------------------------------------------------------------------------------
Vector2 Arrive::Update(Agent* pAgent, float fDeltaTime)
{
	// Assigns a Vector2 towards the target
	Vector2 v2ToTarget = m_pPlayer->GetPos() - pAgent->GetPos();

	// Finds the distance between current pos and target
	float fDist = v2ToTarget.CalcDist(m_pPlayer->GetPos(), pAgent->GetPos());

	// Checks if distance is greater than zero
	if (fDist > 0)
	{
		// Decelerates as distance decreases
		float fSpeed = fDist / DECELERATION;

		// Checks speed does not exceed max amount
		if (fSpeed > SPEED)
			fSpeed = SPEED;

		// Returns the position
		return v2ToTarget * (fSpeed / fDist) * fDeltaTime;
	}

	// Returns (0, 0) by default
	return Vector2(0, 0);
}

//--------------------------------------------------------------------------------------
// Function allows a target to be set for agents using Arrive
//
// Parameters:
//		pAgent: An agent pointer that allows for access to the Agent class
//--------------------------------------------------------------------------------------
void Arrive::SetTarget(Agent* pAgent)
{
	// Assigns the passed in target as the player
	m_pPlayer = pAgent;
}