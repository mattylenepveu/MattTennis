#include "Game.h"
#include "Input.h"

//--------------------------------------------------------------------------------------
// Default Constructor.
//--------------------------------------------------------------------------------------
Game::Game()
{
	m_p2dRenderer = new aie::Renderer2D();

	m_pFont = new aie::Font("./font/consolas_bold.ttf", 32);
}

//--------------------------------------------------------------------------------------
// Default Destructor.
//--------------------------------------------------------------------------------------
Game::~Game()
{
	delete m_p2dRenderer;
	delete m_pFont;
}

//--------------------------------------------------------------------------------------
// Runs when the state is first pushed back
//
// Paramaters:
//		pStateMachine: A pointer to the StateMachine for use in function
//--------------------------------------------------------------------------------------
void Game::OnEnter(StateMachine* pStateMachine)
{
	m_fCameraX = 0.0f;
	m_fCameraY = 0.0f;
	m_fTimer = 0.0f;
}
//--------------------------------------------------------------------------------------
// Updates the state when it is running
//
// Paramaters:
//		fDeltaTime: Keeps track of real time, used for movement and waiting periods
//		pStateMachine: Is used to access the state machine
//		m_2dRenderer: Is used for access to the renderer class
//--------------------------------------------------------------------------------------
void Game::OnUpdate(float fDeltaTime, StateMachine* pStateMachine, 
					Renderer2D* m_2dRenderer)
{
	m_fTimer += fDeltaTime;

	// input example
	aie::Input* input = aie::Input::getInstance();

	// use arrow keys to move camera
	if (input->isKeyDown(aie::INPUT_KEY_UP))
		m_fCameraY += 500.0f * fDeltaTime;

	if (input->isKeyDown(aie::INPUT_KEY_DOWN))
		m_fCameraY -= 500.0f * fDeltaTime;

	if (input->isKeyDown(aie::INPUT_KEY_LEFT))
		m_fCameraX -= 500.0f * fDeltaTime;

	if (input->isKeyDown(aie::INPUT_KEY_RIGHT))
		m_fCameraX += 500.0f * fDeltaTime;
}

//--------------------------------------------------------------------------------------
// Draws the state when it is pushed on the stack
//
// Parameters:
//		m_2dRenderer: Accesses the renderer class to allow the state to be drawn
//--------------------------------------------------------------------------------------
void Game::OnDraw(Renderer2D* m_2dRenderer)
{
	// set the camera position before we begin rendering
	m_2dRenderer->setCameraPos(m_fCameraX, m_fCameraY);

	// begin drawing sprites
	m_2dRenderer->begin();

	// draw a thin line
	m_2dRenderer->drawLine(300, 300, 600, 400, 2, 1);

	// draw a moving purple circle
	m_2dRenderer->setRenderColour(1, 0, 1, 1);
	m_2dRenderer->drawCircle(sin(m_fTimer) * 100 + 600, 150, 50);

	// draw a rotating red box
	m_2dRenderer->setRenderColour(1, 0, 0, 1);
	m_2dRenderer->drawBox(600, 500, 60, 20, m_fTimer);

	// draw a slightly rotated sprite with no texture, coloured yellow
	m_2dRenderer->setRenderColour(1, 1, 0, 1);
	m_2dRenderer->drawSprite(nullptr, 400, 400, 50, 50, 3.14159f * 0.25f, 1);

	// output some text, uses the last used colour
	m_2dRenderer->drawText(m_pFont, "Press ESC to quit!", 0, 720 - 64);

	// done drawing sprites
	m_2dRenderer->end();
}

//--------------------------------------------------------------------------------------
// Runs when the state is being exited
//
// Paramaters:
//		pStateMachine: A pointer to the StateMachine for use in function
//--------------------------------------------------------------------------------------
void Game::OnExit(StateMachine* pStateMachine)
{
	m_fCameraX = 0.0f;
	m_fCameraY = 0.0f;
	m_fTimer = 0.0f;
}
