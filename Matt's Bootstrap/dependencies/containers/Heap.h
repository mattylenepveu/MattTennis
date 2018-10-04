#pragma once
#include "DynamicArray.h"
#include "AStarNode.h"
#include <math.h>
#include <vector>
using namespace std;

class Heap
{
public:
	//--------------------------------------------------------------------------------------
	// Default Constructor
	//--------------------------------------------------------------------------------------
	Heap() {}

	//--------------------------------------------------------------------------------------
	// Default Destructor
	//--------------------------------------------------------------------------------------
	~Heap() {}

	//--------------------------------------------------------------------------------------
	// Pushes an AStarNode onto the heap
	//
	// Parameters:
	//		data: An AStarNode which is pushed onto the heap
	//--------------------------------------------------------------------------------------
	void Push(AStarNode* data)
	{
		// Add data to end of array.
		m_Data.push_back(data);

		// Loop through and swap value if data is smaller.
		int current = m_Data.size() - 1;

		// Loops through while loop until it breaks
		while (true)
		{
			// Breaks loop if the size of data array is less than or equal to zero
			if (current <= 0)
				break;

			// Sets parent node
			int parent = GetParentIndex(current);

			// Swaps the current node with parent node if the currents F score is greater than the parents
			if (m_Data[current]->m_nFScore < m_Data[parent]->m_nFScore)
			{
				AStarNode* swap = m_Data[current];
				m_Data[current] = m_Data[parent];
				m_Data[parent] = swap;

				current = parent;
			}
			// If not, it breaks out of while loop
			else
				break;
		}
	}

	//--------------------------------------------------------------------------------------
	// Function pops an AStarNode off of the heap
	//
	// Return:
	//		Returns the popped off AStarNode
	//--------------------------------------------------------------------------------------
	AStarNode* Pop()
	{
		// Sets the result as first AStarNode in vector list to begin with
		AStarNode* result = m_Data[0];

		// Replace first element with last element.
		int last = m_Data.size() - 1;
		m_Data[0] = m_Data[last];

		// Swap first element with smaller child if shild is smaller
		int current = 0;

		// Runs while loop until being asked to break
		while (true)
		{
			// Work out which child is smaller
			int child0 = GetChildIndex(current, 1);

			// If child is less than the last, then break out of while loop
			if (child0 > last)
				break;

			// Gets child1 then assign's child0 as smaller child by default
			int child1 = GetChildIndex(current, 2);
			int smallerChild = child0;

			// Assign's child1 as smaller child if is less than last child and it's F score is also lower than last childs
			if (child1 <= last && m_Data[child1]->m_nFScore < m_Data[smallerChild]->m_nFScore)
				smallerChild = child1;

			// Check if smaller than parent, if so swap
			if (m_Data[smallerChild]->m_nFScore < m_Data[current]->m_nFScore)
			{
				AStarNode* swap = m_Data[current];
				m_Data[current] = m_Data[smallerChild];
				m_Data[smallerChild] = swap;

				current = smallerChild;
			}
			// Otherwise it breaks loop
			else
				break;
		}

		// Pops off AStarNode off of the list
		m_Data.pop_back();

		// Returns popped off node
		return result;
	}

	//--------------------------------------------------------------------------------------
	// Clears the heap entirely
	//--------------------------------------------------------------------------------------
	void Clear()
	{
		m_Data.clear();
	}

	//--------------------------------------------------------------------------------------
	// Function allows other functions to get the size of the heap
	//
	// Return:
	//		Returns the size of heap as an integer
	//--------------------------------------------------------------------------------------
	int GetSize()
	{
		return (int)m_Data.size();
	}

	//--------------------------------------------------------------------------------------
	// Function allows other functions to get the parent index
	//
	// Parameters:
	//		childIndex: Refers to the child index in the heap
	// Return:
	//		Returns the parent index as an interger
	//--------------------------------------------------------------------------------------
	int GetParentIndex(int childIndex)
	{
		return (childIndex - 1) / 2;
	}

	//--------------------------------------------------------------------------------------
	// Function allows other functions to get the child index
	//
	// Parameters:
	//		parentIndex: Refers to the parent index in the heap
	//		whichChild: Refers to any specifiedd child
	// Return:
	//		Returns the child index as an interger
	//--------------------------------------------------------------------------------------
	int GetChildIndex(int parentIndex, int whichChild)
	{
		return (2 * parentIndex) + whichChild;
	}

	//--------------------------------------------------------------------------------------
	// Function checks if the node passed through is in the heap
	//
	// Parameters:
	//		pData: Refers to the AStarNode that is being checked if it's in heap
	// Return:
	//		Returns the indexed AStarNode as an integer
	//--------------------------------------------------------------------------------------
	int Contains(AStarNode* pData)
	{
		// Runs for loop until data size is reached
		for (int i = 0; i < m_Data.size(); ++i)
		{
			// If data is in heap, return the index
			if (m_Data[i] == pData)
				return i;
		}

		// If data not in list, return -1 by default
		return -1;
	}

	//--------------------------------------------------------------------------------------
	// Resort's the heap making a passed through index being at the top
	//
	// Parameters:
	//		index: Refers to the index which is placed at top of the heap
	//--------------------------------------------------------------------------------------
	void Resort(int index)
	{
		// If index is at top of the heap, the don't resort
		if (index == 0)
			return;

		// Passes the passed in index into a local variable
		int nNodeIndex = index;

		// Gets the parent of certain index
		int nParent = GetParentIndex(index);

		// Runs while parent is greater than 0 and its F score is greater than the indexed F score
		while (nParent >= 0 && m_Data[nNodeIndex]->m_nFScore < m_Data[nParent]->m_nFScore)
		{
			// Swaps parent index with passed in index
			AStarNode* temp = m_Data[nParent];
			m_Data[nParent] = m_Data[nNodeIndex];
			m_Data[nNodeIndex] = temp;

			// Sets the passed in index as the parent
			nNodeIndex = nParent;
			nParent = GetParentIndex(nNodeIndex);
		}
	}

private:
	// Heap uses a vector list
	vector<AStarNode*> m_Data;
};

