#include "Wander.h"
#include <stdlib.h>     
#include <time.h>  
#include "Defines.h"

//--------------------------------------------------------------------------------------
// An additional constructor.
//
// Parameters:
//		fWeighting: A float used for weighting allbehaviours
//--------------------------------------------------------------------------------------
Wander::Wander(float fWeighting)
{
	// Assigns passed in weighting to a new variable
	m_fWeighting = fWeighting;

	// Sets default values to variables
	m_fWanderRadius = 80.0f;
	m_fWanderDistance = 120.0f;
	m_fWanderJitter = 1.0f;
}

//--------------------------------------------------------------------------------------
// Default Constructor.
//--------------------------------------------------------------------------------------
Wander::Wander() {}

//--------------------------------------------------------------------------------------
// Default Destructor.
//--------------------------------------------------------------------------------------
Wander::~Wander() {}

//--------------------------------------------------------------------------------------
// Function updates the behaviour per frame
//
// Parameters:
//		pAgent: An agent pointer that allows for access to the Agent class
//		fDeltaTime: A float that is used to keep track of real time
// Return:
//		Returns seek result as a Vector2
//--------------------------------------------------------------------------------------
Vector2 Wander::Update(Agent* pAgent, float fDeltaTime)
{
	// Assigns a target to be any position in a casted out circle
	Vector2 m_v2WanderTarget;
	m_v2WanderTarget += Vector2(RandNumber() * m_fWanderJitter, RandNumber() * m_fWanderJitter);
	m_v2WanderTarget.Normalise();

	// Multiple's wander target by radius
	m_v2WanderTarget = m_v2WanderTarget * m_fWanderRadius;
	
	// Casts the Vector2 back towards player
	Vector2 targetWorld;
	targetWorld = m_v2WanderTarget + pAgent->GetFacing() * m_fWanderDistance;

	// Returns the position per frame
	return targetWorld * fDeltaTime * 10;
}

//--------------------------------------------------------------------------------------
// Generates a random number for wander calculations to use
//
// Return:
//		Returns the random number as a float
//--------------------------------------------------------------------------------------
float Wander::RandNumber()
{
	// Defines and returns a random float between 0 and 1
	float r = (static_cast <float>(rand() / static_cast <float>(RAND_MAX))) * 2 - 1;
	return r;
}