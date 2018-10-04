#include "Flee.h"
#include "Input.h"
#include "Defines.h"
using namespace aie;

//--------------------------------------------------------------------------------------
// An additional constructor.
//
// Parameters:
//		fWeighting: A float used for weighting allbehaviours
//--------------------------------------------------------------------------------------
Flee::Flee(float fWeighting)
{
	// Assigns passed in weighting to a new variable
	m_fWeighting = fWeighting;
}

//--------------------------------------------------------------------------------------
// Default Constructor.
//--------------------------------------------------------------------------------------
Flee::Flee() {}

//--------------------------------------------------------------------------------------
// Default Destructor.
//--------------------------------------------------------------------------------------
Flee::~Flee() {}

//--------------------------------------------------------------------------------------
// Function updates the behaviour per frame
//
// Parameters:
//		pAgent: An agent pointer that allows for access to the Agent class
//		fDeltaTime: A float that is used to keep track of real time
// Return:
//		Returns flee result as a Vector2
//--------------------------------------------------------------------------------------
Vector2 Flee::Update(Agent* pAgent, float fDeltaTime)
{
	// Sets the direction to go away from the target
	Vector2 v2Dir = pAgent->GetPos() - m_pPlayer->GetPos();

	// Normalises the direction
	v2Dir.Normalise();

	// Returns the position
	return v2Dir * SPEED * fDeltaTime;
}

//--------------------------------------------------------------------------------------
// Function allows a target to be set for agents using Flee
//
// Parameters:
//		pAgent: An agent pointer that allows for access to the Agent class
//--------------------------------------------------------------------------------------
void Flee::SetTarget(Agent* pAgent)
{
	// Assigns the target passed in to be the player
	m_pPlayer = pAgent;
}