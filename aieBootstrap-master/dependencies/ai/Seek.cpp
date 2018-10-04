#include "Seek.h"
#include "Agent.h"
#include "Input.h"
#include "Defines.h"
using namespace aie;

//--------------------------------------------------------------------------------------
// An additional constructor.
//
// Parameters:
//		fWeighting: A float used for weighting allbehaviours
//--------------------------------------------------------------------------------------
Seek::Seek(float fWeighting)
{
	// Assigns passed in weighting to a new variable
	m_fWeighting = fWeighting;
}

//--------------------------------------------------------------------------------------
// Default Constructor.
//--------------------------------------------------------------------------------------
Seek::Seek() {}

//--------------------------------------------------------------------------------------
// Default Destructor.
//--------------------------------------------------------------------------------------
Seek::~Seek() {}

//--------------------------------------------------------------------------------------
// Function updates the behaviour per frame
//
// Parameters:
//		pAgent: An agent pointer that allows for access to the Agent class
//		fDeltaTime: A float that is used to keep track of real time
// Return:
//		Returns seek result as a Vector2
//--------------------------------------------------------------------------------------
Vector2 Seek::Update(Agent* pAgent, float fDeltaTime)
{
	// Sets the direction to go towards the player
	Vector2 v2Dir = m_pPlayer->GetPos() - pAgent->GetPos();

	// Normalises the direction
	v2Dir.Normalise();

	// Returns the position each frame
	return v2Dir * SPEED * fDeltaTime;
}

//--------------------------------------------------------------------------------------
// Function allows a target to be set for agents using Seek
//
// Parameters:
//		pAgent: An agent pointer that allows for access to the Agent class
//--------------------------------------------------------------------------------------
void Seek::SetTarget(Agent* pAgent)
{
	// Sets the passed in target to be the player
	m_pPlayer = pAgent;
}