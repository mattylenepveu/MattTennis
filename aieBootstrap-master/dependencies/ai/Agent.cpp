#include "Agent.h"
#include "StateMachine.h"
#include "Collider.h"
#include "VectorCast.h"
#include "Defines.h"

//--------------------------------------------------------------------------------------
// Default Constructor.
//--------------------------------------------------------------------------------------
Agent::Agent()
{
	// Creates a "new" instance of the StateMachine
	m_pStateMachine = new StateMachine();

	// Sets the top left and bottom right of all 4 boxes
	collider.topLeft = Vector2(-NODESIZE * 0.5f, -NODESIZE * 0.5f);
	collider.bottomRight = Vector2(-NODESIZE * 0.5f, -NODESIZE * 0.5f);
}

//--------------------------------------------------------------------------------------
// Default Destructor.
//--------------------------------------------------------------------------------------
Agent::~Agent()
{
	delete m_pStateMachine;
}

//--------------------------------------------------------------------------------------
// Assigns the globalTransform variable as the localTransform variable
//--------------------------------------------------------------------------------------
void Agent::UpdateTransform()
{
	globalTransform = localTransform;
}

//--------------------------------------------------------------------------------------
// Allows other functions to get a collider
//
// Return:
//		Returns the address of a collider
//--------------------------------------------------------------------------------------
Collider& Agent::GetCollider()
{
	return collider;
}

//--------------------------------------------------------------------------------------
// Sets the position of a particular in game object
//
// Parameters:
//		pos: A Vector2 that refers to an object's location
//--------------------------------------------------------------------------------------
void Agent::SetPos(Vector2 pos)
{
	localTransform.setPos(pos);
	UpdateTransform();
}

//--------------------------------------------------------------------------------------
// Sets the speed of a particular in game object
//
// Parameters:
//		speed: A float that refers to how fast an object can go
//--------------------------------------------------------------------------------------
void Agent::SetSpeed(float speed)
{
	m_fSpeed = speed;
}

//--------------------------------------------------------------------------------------
// Function sets which way an agent is facing
//
// Parameters:
//		facing: A Vector2 that refers to which way the Agent faces
//--------------------------------------------------------------------------------------
void Agent::SetFacing(Vector2 facing)
{
	m_v2Facing = facing;
}

//--------------------------------------------------------------------------------------
// Allows other functions to get the position of an object
//
// Return:
//		Returns the position as a Vector2
//--------------------------------------------------------------------------------------
Vector2 Agent::GetPos()
{
	return CastTo<Vector2>(globalTransform.getPos());
}

//--------------------------------------------------------------------------------------
// Allows other functions to get the speed of an object
//
// Return:
//		Returns the speed as a float
//--------------------------------------------------------------------------------------
float Agent::GetSpeed()
{
	return m_fSpeed;
}

//--------------------------------------------------------------------------------------
// Allows other functions to get the direction an object is facing
//
// Return:
//		Returns the facing direction as a Vector2
//--------------------------------------------------------------------------------------
Vector2 Agent::GetFacing()
{
	return m_v2Facing;
}