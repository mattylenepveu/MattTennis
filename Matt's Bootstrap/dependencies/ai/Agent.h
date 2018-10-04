#pragma once
#include "IBehaviour.h"
#include "Renderer2D.h"
#include "Vector2.h"
#include "Matrix3.h"
#include "DynamicArray.h"
#include "Collider.h"
using namespace aie;

// Forward declare used to avoid circular inclusion
class StateMachine;

class Agent
{
public:
	//--------------------------------------------------------------------------------------
	// Default Constructor.
	//--------------------------------------------------------------------------------------
	Agent();

	//--------------------------------------------------------------------------------------
	// Default Destructor.
	//--------------------------------------------------------------------------------------
	virtual ~Agent();

	//--------------------------------------------------------------------------------------
	// Assigns the globalTransform variable as the localTransform variable
	//--------------------------------------------------------------------------------------
	void UpdateTransform();

	//--------------------------------------------------------------------------------------
	// Allows other functions to get a collider
	//
	// Return:
	//		Returns the address of a collider
	//--------------------------------------------------------------------------------------
	Collider& GetCollider();

	//--------------------------------------------------------------------------------------
	// Sets the position of a particular in game object
	//
	// Parameters:
	//		pos: A Vector2 that refers to an object's location
	//--------------------------------------------------------------------------------------
	void SetPos(Vector2 pos);

	//--------------------------------------------------------------------------------------
	// Sets the speed of a particular in game object
	//
	// Parameters:
	//		speed: A float that refers to how fast an object can go
	//--------------------------------------------------------------------------------------
	void SetSpeed(float speed);

	//--------------------------------------------------------------------------------------
	// Function sets which way an agent is facing
	//
	// Parameters:
	//		facing: A Vector2 that refers to which way the Agent faces
	//--------------------------------------------------------------------------------------
	void SetFacing(Vector2 facing);

	//--------------------------------------------------------------------------------------
	// Allows other functions to get the position of an object
	//
	// Return:
	//		Returns the position as a Vector2
	//--------------------------------------------------------------------------------------
	Vector2 GetPos();

	//--------------------------------------------------------------------------------------
	// Allows other functions to get the speed of an object
	//
	// Return:
	//		Returns the speed as a float
	//--------------------------------------------------------------------------------------
	float GetSpeed();

	//--------------------------------------------------------------------------------------
	// Allows other functions to get the direction an object is facing
	//
	// Return:
	//		Returns the facing direction as a Vector2
	//--------------------------------------------------------------------------------------
	Vector2 GetFacing();

protected:
	// A StateMachine pointer that allows access to StateMachine class
	StateMachine* m_pStateMachine;

	// Facing is a Vector2 whilst speed as a float
	Vector2 m_v2Facing;
	float m_fSpeed;

	// Local and Global transform used to update agent
	Matrix3 localTransform;
	Matrix3 globalTransform;

	// Collider variable used to set collision
	Collider collider;
};
