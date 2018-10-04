#pragma once
#include "Heap.h"
#include "AStarNode.h"
using namespace std;

// Used for a Function pointer
typedef int(*MyFunction)(AStarNode*, AStarNode*);

class AStar
{
public:
	//--------------------------------------------------------------------------------------
	// Default Constructor
	//
	// Parameters:
	//		nMaxNode: An integer that indicates the last node of the AStar path
	//--------------------------------------------------------------------------------------
	AStar(int nMaxNode);

	//--------------------------------------------------------------------------------------
	// Default Destructor
	//--------------------------------------------------------------------------------------
	~AStar();

	//--------------------------------------------------------------------------------------
	// Allows other functions to get the position of an object
	//
	// Parameters:
	//		pStart: Indicates the starting node of the AStar path
	//		pEnd: Indicates the end node of the AStar path
	//		finPath: A vector list of AStarNode's that layout the final AStar path
	// Return:
	//		Returns the boolean checking if a path has been found or not
	//--------------------------------------------------------------------------------------
	bool CalcPath(AStarNode* pStart, AStarNode* pEnd, vector<AStarNode*>* finPath);

	//--------------------------------------------------------------------------------------
	// Function used set a function as part of function pointers
	//
	// Parameters:
	//		func: Takes in a function which will be set
	//--------------------------------------------------------------------------------------
	void SetFunction(MyFunction func);

	//--------------------------------------------------------------------------------------
	// Allows other functions to call the function
	//
	// Parameters:
	//		pNode: Indicates a node in an AStar path
	//		pEnd: Indicates the end node of the AStar path
	// Return:
	//		Returns the integer which is the result of calculating the heuristic
	//--------------------------------------------------------------------------------------
	int CallFunction(AStarNode* pNode, AStarNode* pEnd);

private:
	// Open List uses a custom heap
	Heap m_OpenList;

	// Closed list uses a bunch of booleans
	bool* m_ClosedList;

	// Refers to the total grid size
	int m_nGridSize;

	// Assigns the function pointer to nullptr by default
	MyFunction myFunc = nullptr;
};
