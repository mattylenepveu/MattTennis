#pragma once
#include "BehaviourNode.h"
#include <vector>
using namespace std;

// Class inherits from BehaviourNode class
class Composite : public BehaviourNode
{
public:
	// Uses a Vector list of the roots children (branches)
	vector<BehaviourNode*> children;
};