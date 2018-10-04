#include "Patrol.h"
#include "Follow.h"
#include "Agent.h"

//--------------------------------------------------------------------------------------
// Default Constructor.
//--------------------------------------------------------------------------------------
Patrol::Patrol()
{
	// Defines a "new" follow instance
	m_pFollow = new Follow();

	// Pushes follow into the behaviours list
	m_behaviours.push_back(m_pFollow);
}

//--------------------------------------------------------------------------------------
// Default Destructor.
//--------------------------------------------------------------------------------------
Patrol::~Patrol()
{
	delete m_pFollow;
}

//--------------------------------------------------------------------------------------
// Runs when the state is first pushed back 
//
// Paramaters:
//		pStateMachine: A pointer to the StateMachine for use in function
//--------------------------------------------------------------------------------------
void Patrol::OnEnter(StateMachine* pStateMachine) {}

//--------------------------------------------------------------------------------------
// Updates the state when it is running 
//
// Paramaters:
//		fDeltaTime: Keeps track of real time, used for movement and waiting periods
//		pAgent: Is used to access the Agent class
//		pStateMachine: Is used to access the state machine
//--------------------------------------------------------------------------------------
void Patrol::OnUpdate(float fDeltaTime, Agent* pAgent, StateMachine* pStateMachine)
{
	// Updates each behaviour in the behaviours list
	for (int i = 0; i < m_behaviours.size(); ++i)
	{
		m_behaviours[i]->Update(pAgent, fDeltaTime);
	}
}

//--------------------------------------------------------------------------------------
// Updates the state when it is running 
//
// Paramaters:
//		fDeltaTime: Keeps track of real time, used for movement and waiting periods
//		pAgent: Is used to access the Agent class
//		pStateMachine: Is used to access the state machine
//--------------------------------------------------------------------------------------
void Patrol::OnDraw(Renderer2D* m_2dRenderer) {}

//--------------------------------------------------------------------------------------
// Runs when the state is being exited
//
// Paramaters:
//		pStateMachine: A pointer to the StateMachine for use in function
//--------------------------------------------------------------------------------------
void Patrol::OnExit(StateMachine* pStateMachine) {}
