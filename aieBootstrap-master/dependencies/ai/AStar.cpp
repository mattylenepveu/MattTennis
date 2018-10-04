#include "AStar.h"
#include "GridNode.h"
#include "Grid.h"
#include <math.h>

//--------------------------------------------------------------------------------------
// Default Constructor
//
// Parameters:
//		nMaxNode: An integer that indicates the last node of the AStar path
//--------------------------------------------------------------------------------------
AStar::AStar(int nMaxNode)
{
	// Makes the grid size equal to the max node
	m_nGridSize = nMaxNode;

	// Creates a "new" closed list of bools
	m_ClosedList = new bool[nMaxNode];
}

//--------------------------------------------------------------------------------------
// Default Destructor
//--------------------------------------------------------------------------------------
AStar::~AStar()
{
	delete[] m_ClosedList;
}

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
bool AStar::CalcPath(AStarNode* pStart, AStarNode* pEnd, vector<AStarNode*>* finPath)
{
	// Clear everything in case a previous path was found.
	m_OpenList.Clear();

	// Set all elements in closed list to false.
	memset(m_ClosedList, 0, sizeof(bool) * m_nGridSize);

	// Set start node's G score to zero
	pStart->m_nGScore = 0;

	// Calculate the H score (for now set H score to zero)
	pStart->m_nHScore = CallFunction(pStart, pEnd);

	// Calculate start node's F score
	pStart->m_nFScore = pStart->m_nGScore + pStart->m_nHScore;

	// Set start node's m_pPrev to null
	pStart->m_pPrev = nullptr;

	// Add start node to open list.
	m_OpenList.Push(pStart);

	// While there are still nodes in open list
	while (m_OpenList.GetSize() > 0)
	{
		// Get the node from the open list with the lowest F score, call it currentNode.
		AStarNode* pCurrentNode = m_OpenList.Pop();

		// Add that node to the closed list.
		m_ClosedList[pCurrentNode->m_nIndex] = true;

		// If currentNode is the end node, we are finished.
		if (pCurrentNode == pEnd)
		{
			// Build path (remember it's backwards so we need to fix that).
			AStarNode* pNode = pEnd;

			// Do while there is a previous node
			do
			{
				finPath->insert(finPath->begin(), pNode);
				pNode = pNode->m_pPrev;
			} while (pNode);

			// Return that we found a valid path.
			return true;
		}

		// Loop through all of currentNode's neighbours
		for (int i = 0; i < pCurrentNode->m_AdjacentList.size(); ++i)
		{
			// Storing neighbour in a local pointer
			AStarNode* pNeighbour = pCurrentNode->m_AdjacentList[i]->m_pEndNode;

			// Storing the cost in a local variable
			int nCost = pCurrentNode->m_AdjacentList[i]->m_nCost;

			// Skip Walls
			if (pNeighbour->m_bBlocked)
				continue;

			// Skip neighbours that are already in the closed list.
			if (m_ClosedList[pNeighbour->m_nIndex])
				continue;

			// Makes a heap index to pass through the resort function
			int heapIndex = m_OpenList.Contains(pNeighbour);

			// If neighbour is already in open list...
			if (heapIndex != -1)
			{
				// Check if this current path is better than old path (lower F score)
				if (pCurrentNode->m_nFScore + nCost < pNeighbour->m_nFScore)
				{
					// Update G score.
					pNeighbour->m_nGScore = pCurrentNode->m_nGScore + nCost;

					// Update F score.
					pNeighbour->m_nFScore = pNeighbour->m_nGScore + pNeighbour->m_nHScore;

					// Update Prev node.
					pNeighbour->m_pPrev = pCurrentNode;

					// Sort Heap
					m_OpenList.Resort(i);
				}
			}
			// Else (neighbour not in open list)
			else
			{
				// Calculate G Score.
				pNeighbour->m_nGScore = pCurrentNode->m_nGScore + nCost;

				// Calculate H Score.
				pNeighbour->m_nHScore = CallFunction(pNeighbour, pEnd);

				// Calculate F Score.
				pNeighbour->m_nFScore = pNeighbour->m_nGScore + pNeighbour->m_nHScore;

				// Set Prev node pointer.
				pNeighbour->m_pPrev = pCurrentNode;

				// Add neighbour to open list.
				m_OpenList.Push(pNeighbour);
			}
		}
	}

	// No path found if we get to here, so return false.
	return false;
}

//--------------------------------------------------------------------------------------
// Function used set a function as part of function pointers
//
// Parameters:
//		func: Takes in a function which will be set
//--------------------------------------------------------------------------------------
void AStar::SetFunction(MyFunction func)
{
	myFunc = func;
}

//--------------------------------------------------------------------------------------
// Allows other functions to call the function
//
// Parameters:
//		pNode: Indicates a node in an AStar path
//		pEnd: Indicates the end node of the AStar path
// Return:
//		Returns the integer which is the result of calculating the heuristic
//--------------------------------------------------------------------------------------
int AStar::CallFunction(AStarNode* pNode, AStarNode* pEnd)
{
	// Returns the function if there is an instance
	if (myFunc)
		return myFunc(pNode, pEnd);

	return 0;
}