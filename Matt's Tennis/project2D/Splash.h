#pragma once
#include "State.h"
#include "StateMachine.h"
#include "Renderer2D.h"
#include "Texture.h"
#include "ResourceManager.h"
#include "Font.h"

class Splash : public State
{
public:
	//--------------------------------------------------------------------------------------
	// Default Constructor.
	//--------------------------------------------------------------------------------------
	Splash();

	//--------------------------------------------------------------------------------------
	// Default Destructor.
	//--------------------------------------------------------------------------------------
	~Splash();

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
	//		pStateMachine: Is used to access the state machine
	//		m_2dRenderer: Is used for access to the renderer class
	//--------------------------------------------------------------------------------------
	void OnUpdate(float fDeltaTime, StateMachine* pStateMachine, Renderer2D* m_2dRenderer);

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
	// Texture pointer used to store picture in
	Texture* m_pMatt;

	// Pointer used to store the font in
	Font* m_pFont;

	// Represents the amount of time the splash screen will be displayed
	float m_fTimer;

	// Float keeps track of the alpha of the state
	float m_fAlpha;
};
