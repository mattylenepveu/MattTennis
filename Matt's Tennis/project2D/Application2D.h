#pragma once
#include "Application.h"
#include "Renderer2D.h"
#include "StateMachine.h"
using namespace aie;

class Application2D : public aie::Application
{
public:
	//--------------------------------------------------------------------------------------
	// Default Constructor.
	//--------------------------------------------------------------------------------------
	Application2D();

	//--------------------------------------------------------------------------------------
	// Default Destructor.
	//--------------------------------------------------------------------------------------
	virtual ~Application2D();

	//--------------------------------------------------------------------------------------
	// Acts as our constructor and creates the renderer and state machine
	//
	// Return:
	//		A bool returns true upon startup
	//--------------------------------------------------------------------------------------
	virtual bool startup();

	//--------------------------------------------------------------------------------------
	// Acts as our destructor and deletes the renderer and state machine
	//--------------------------------------------------------------------------------------
	virtual void shutdown();

	//--------------------------------------------------------------------------------------
	// Updates the state machine and the renderer by frame
	//
	// Parameters:
	//		deltaTime: A float the keeps track of real time
	//--------------------------------------------------------------------------------------
	virtual void update(float deltaTime);

	//--------------------------------------------------------------------------------------
	// Draws the state machine and renderer to work in game
	//--------------------------------------------------------------------------------------
	virtual void draw();

protected:
	// Allows for access to the renderer class
	Renderer2D * m_p2dRenderer;

	// Pointers allows for access to the state machine
	StateMachine* m_pStateMachine;
};