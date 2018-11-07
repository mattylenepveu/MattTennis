#pragma once

// Includes from various files
#include <vector>
#include "Matrix3.h"
#include "Collider.h"
using namespace std;

class Entity
{
public:
	//--------------------------------------------------------------------------------------
	// Default Constructor.
	//--------------------------------------------------------------------------------------
	Entity();

	//--------------------------------------------------------------------------------------
	// Default Destructor.
	//--------------------------------------------------------------------------------------
	~Entity();

	//--------------------------------------------------------------------------------------
	// Sets the parent of a particular in game object
	//
	// Parameters:
	//		parent: An entity pointer that passes in an object that'll act as the parent
	//--------------------------------------------------------------------------------------
	void SetParent(Entity* parent);

	//--------------------------------------------------------------------------------------
	// Sets the child of a particular in game object
	//
	// Parameters:
	//		child: An entity pointer that passes in an object that'll act as the child
	//--------------------------------------------------------------------------------------
	void SetChildren(Entity* child);

	//--------------------------------------------------------------------------------------
	// Updates an objects status each frame
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
	//		x: A float that gives the x coordinate of an object
	//		y: A float that gives the y coordinate of an object
	//--------------------------------------------------------------------------------------
	void SetPosition(float x, float y);

	//--------------------------------------------------------------------------------------
	// Allows other functions to get the position of an object
	//
	// Return:
	//		Returns the position as a Vector2
	//--------------------------------------------------------------------------------------
	Vector2 GetPosition();

	//--------------------------------------------------------------------------------------
	// Sets the localTransform variable as the globalTransform variable
	//--------------------------------------------------------------------------------------
	void LocalToGlobal();

	//--------------------------------------------------------------------------------------
	// Sets an object to bActive if an object is in game (used for object pool)
	//
	// Parameters:
	//		bActive: Set to true, if an object is drawn on screen in game
	//--------------------------------------------------------------------------------------
	void SetActive(bool active);

	//--------------------------------------------------------------------------------------
	// Allows other functions to check if an object is active
	//
	// Return:
	//		Returns a boolean
	//--------------------------------------------------------------------------------------
	bool GetActive();

protected:
	// Sets the parent as an entity pointer
	Entity* Parent;

	// Makes a list of children, all as entity pointers
	vector<Entity*> children;

	// Transforms an object locally as a Matrix3
	Matrix3 localTransform;

	// Transforms an object gloabally as a Matrix3
	Matrix3 globalTransform;

	// Sets the collider variable as a collider
	Collider collider;

	// Used for "SetActive" and "GetActive" functions
	bool bActive;
};