#pragma once
#include "State.h"
#include "StateMachine.h"
#include "Agent.h"
#include "Renderer2D.h"
#include "Follow.h"

// Class inherits from State class
class Patrol : public State
{
public:
	//--------------------------------------------------------------------------------------
	// Default Constructor.
	//--------------------------------------------------------------------------------------
	Patrol();

	//--------------------------------------------------------------------------------------
	// Default Destructor.
	//--------------------------------------------------------------------------------------
	~Patrol();

	//--------------------------------------------------------------------------------------
	// Runs when the state is first pushed back 
	//
	// Paramaters:
	//		pStateMachine: A pointer to the StateMachine for use in function
	//--------------------------------------------------------------------------------------
	void OnEnter(StateMachine* pStateMachine);

	//--------------------------------------------------------------------------------------
	// Updates the state when it is running 
	//
	// Paramaters:
	//		fDeltaTime: Keeps track of real time, used for movement and waiting periods
	//		pAgent: Is used to access the Agent class
	//		pStateMachine: Is used to access the state machine
	//--------------------------------------------------------------------------------------
	void OnUpdate(float fDeltaTime, Agent* pAgent, StateMachine* pStateMachine);

	//--------------------------------------------------------------------------------------
	// Draws the state when it is pushed on the stack 
	//
	// Parameters:
	//		m_2dRenderer: Accesses the renderer class to allow the state to be drawn
	//--------------------------------------------------------------------------------------
	void OnDraw(Renderer2D* m_2dRenderer);

	//--------------------------------------------------------------------------------------
	// Runs when the state is being exited
	//
	// Paramaters:
	//		pStateMachine: A pointer to the StateMachine for use in function
	//--------------------------------------------------------------------------------------
	void OnExit(StateMachine* pStateMachine);

private:
	// Follow pointer used to access the behaviours class
	Follow* m_pFollow;
};

