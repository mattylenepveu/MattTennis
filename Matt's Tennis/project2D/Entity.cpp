// Includes from various files
#include "Entity.h"
#include "Vector2.h"
#include <iostream>
using namespace std;

//--------------------------------------------------------------------------------------
// Default Constructor.
//--------------------------------------------------------------------------------------
Entity::Entity()
{
	// Sets the parent as a nullptr by default
	Parent = nullptr;

	// Sets the top left and bottom right by default
	collider.bottomLeft = Vector2(-30, -30);
	collider.topRight = Vector2(30, 30);

	// Sets variable to false by default
	bActive = false;
}

//--------------------------------------------------------------------------------------
// Default Destructor.
//--------------------------------------------------------------------------------------
Entity::~Entity()
{
	// Empty as we do not need to delete anything
}

//--------------------------------------------------------------------------------------
// Sets the parent of a particular in game object
//
// Parameters:
//		parent: An entity pointer that passes in an object that'll act as the parent
//--------------------------------------------------------------------------------------
void Entity::SetParent(Entity* parent)
{
	Parent = parent;
}

//--------------------------------------------------------------------------------------
// Sets the child of a particular in game object
//
// Parameters:
//		child: An entity pointer that passes in an object that'll act as the child
//--------------------------------------------------------------------------------------
void Entity::SetChildren(Entity* child)
{
	// Adds child to the vector list
	children.push_back(child);
}

//--------------------------------------------------------------------------------------
// Updates an objects status each frame
//--------------------------------------------------------------------------------------
void Entity::UpdateTransform()
{
	// Checks if parent is not a nullptr
	if (Parent != nullptr)
		// If it isn't then make the childs globalTransform the same as the parents
		globalTransform = Parent->globalTransform * localTransform;
	else
		// If it is a nullptr, make its global the same as its localTransform
		globalTransform = localTransform;

	// Runs for every child in children list
	for (auto child : children)
		// Updates the childs transform
		child->UpdateTransform();
}

//--------------------------------------------------------------------------------------
// Allows other functions to get a collider
//
// Return:
//		Returns the address of a collider
//--------------------------------------------------------------------------------------
Collider& Entity::GetCollider()
{
	return collider;
}

//--------------------------------------------------------------------------------------
// Sets the position of a particular in game object
//
// Parameters:
//		x: A float that gives the x coordinate of an object
//		y: A float that gives the y coordinate of an object
//--------------------------------------------------------------------------------------
void Entity::SetPosition(float x, float y)
{
	// Sets the position locally then updates per frame
	localTransform.setPos(x, y);
	UpdateTransform();
}

//--------------------------------------------------------------------------------------
// Allows other functions to get the position of an object
//
// Return:
//		Returns the position as a Vector2
//--------------------------------------------------------------------------------------
Vector2 Entity::GetPosition()
{
	// Transforms the position globally
	Vector2 pos;
	pos.x = globalTransform.m[2][0];
	pos.y = globalTransform.m[2][1];

	// Returns the position after the position is transformed globally
	return pos;
}

//--------------------------------------------------------------------------------------
// Sets the localTransform variable as the globalTransform variable
//--------------------------------------------------------------------------------------
void Entity::LocalToGlobal()
{
	localTransform = globalTransform;
}

//--------------------------------------------------------------------------------------
// Sets the type of an object for ColliderManager class to know
//
// Parameters:
//		a: Passes in a type from the enum in "Entity.h"
//--------------------------------------------------------------------------------------
void Entity::SetType(Type a)
{
	type = a;
}

//--------------------------------------------------------------------------------------
// Allows other functions to get the type of an object
//
// Return:
//		Returns the type of an object
//--------------------------------------------------------------------------------------
Type Entity::GetType()
{
	return type;
}

//--------------------------------------------------------------------------------------
// Sets an object to bActive if an object is in game (used for object pool)
//
// Parameters:
//		bActive: Set to true, if an object is drawn on screen in game
//--------------------------------------------------------------------------------------
void Entity::SetActive(bool active)
{
	bActive = active;
}

//--------------------------------------------------------------------------------------
// Allows other functions to check if an object is active
//
// Return:
//		Returns a boolean
//--------------------------------------------------------------------------------------
bool Entity::GetActive()
{
	return bActive;
}