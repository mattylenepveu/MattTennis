#include "Application2D.h"
#include "Texture.h"
#include "Font.h"
#include "Input.h"
#include "ResourceManager.h"
#include "Splash.h"
#include "Game.h"

//--------------------------------------------------------------------------------------
// Default Constructor.
//--------------------------------------------------------------------------------------
Application2D::Application2D() {}

//--------------------------------------------------------------------------------------
// Default Destructor.
//--------------------------------------------------------------------------------------
Application2D::~Application2D() {}

//--------------------------------------------------------------------------------------
// Acts as our constructor and creates the renderer and state machine
//
// Return:
//		A bool returns true upon startup
//--------------------------------------------------------------------------------------
bool Application2D::startup() 
{
	// Creates the resource manager and uses it for textures
	ResourceManager<Texture>::Create();

	// Makes a "new" renderer
	m_p2dRenderer = new Renderer2D();

	// Makes a "new" state machine
	m_pStateMachine = new StateMachine();

	// Creates "new" states for the application to cycle between
	m_pStateMachine->AddState(0, new Splash());
	m_pStateMachine->AddState(1, new Game());

	// Starts on the first state when the application boots up
	m_pStateMachine->PushState(0);

	// Returns true to indicate application started up correctly
	return true;
}

//--------------------------------------------------------------------------------------
// Acts as our destructor and deletes the renderer and state machine
//--------------------------------------------------------------------------------------
void Application2D::shutdown() 
{
	// Deletes both the renderer and state machine pointers
	delete m_p2dRenderer;
	delete m_pStateMachine;
}

//--------------------------------------------------------------------------------------
// Updates the state machine and the renderer by frame
//
// Parameters:
//		deltaTime: A float the keeps track of real time
//--------------------------------------------------------------------------------------
void Application2D::update(float deltaTime) 
{
	// Updates the state machine by frame
	m_pStateMachine->Update(deltaTime, m_p2dRenderer);
}

//--------------------------------------------------------------------------------------
// Draws the state machine and renderer to work in game
//--------------------------------------------------------------------------------------
void Application2D::draw() 
{
	// wipe the screen to the background colour
	clearScreen();

	// begin drawing sprites
	m_p2dRenderer->begin();

	// draws states
	m_pStateMachine->Draw(m_p2dRenderer);

	// done drawing sprites
	m_p2dRenderer->end();
}