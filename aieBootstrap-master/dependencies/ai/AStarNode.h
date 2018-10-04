#pragma once
#include <vector>
using namespace std;

// Forward declares to avoid circular inclusion
struct AStarNode;

struct AStarEdge
{
	// Indicates the end node
	AStarNode* m_pEndNode;

	// Indicates the cost of going down a particular path
	int m_nCost;
};

struct AStarNode
{
	//--------------------------------------------------------------------------------------
	// Default Constructor
	//
	// Parameters:
	//		nIndex: An integer that refers to a node in the grid
	//--------------------------------------------------------------------------------------
	AStarNode(int nIndex)
	{
		// Sets default values for calculating the AStar path in AStar
		m_pPrev = nullptr;
		m_nGScore = 0;
		m_nHScore = 0;
		m_nFScore = 0;
		m_nIndex = nIndex;
		m_bBlocked = false;
	}

	//--------------------------------------------------------------------------------------
	// Default Destructor (virtual as it's used in inherited classes)
	//--------------------------------------------------------------------------------------
	virtual ~AStarNode()
	{
		// Runs a for loop to delete all "new'd" objects in adjacent list
		for (size_t i = 0; i < m_AdjacentList.size(); ++i)
		{
			delete m_AdjacentList[i];
		}
	}

	// Refers to previous node for calculating the AStar path
	AStarNode* m_pPrev;

	// Three integers used for calculating G score in AStar path
	int m_nGScore;
	int m_nHScore;
	int m_nFScore;

	// Index used for refering to a node in the grid
	int m_nIndex;

	// Indicates whether the grid position is blocked or not
	bool m_bBlocked;

	// A vector list of all adjacent node's to any node
	vector<AStarEdge*> m_AdjacentList;
};