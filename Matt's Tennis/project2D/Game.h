#pragma once
#include "State.h"
#include "StateMachine.h"
#include "Renderer2D.h"
#include "Texture.h"
#include "ResourceManager.h"
#include "Font.h"

class Game : public State
{
public:
	//--------------------------------------------------------------------------------------
	// Default Constructor.
	//--------------------------------------------------------------------------------------
	Game();

	//--------------------------------------------------------------------------------------
	// Default Destructor.
	//--------------------------------------------------------------------------------------
	~Game();

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
	// Gives the game screen access to the renderer
	aie::Renderer2D* m_p2dRenderer;

	aie::Texture* m_pCourt;

	aie::Texture* m_pWall;

	aie::Texture* m_pBackground;

	// Allows for access to the font class to draw font
	aie::Font* m_pFont;

	// Indicates the x and y position of the camera
	float m_fCameraX;
	float m_fCameraY;

	// Works as a timer to allow for delta time to work
	float m_fTimer;
};
