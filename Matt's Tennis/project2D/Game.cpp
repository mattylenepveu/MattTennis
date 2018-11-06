#include "Game.h"
#include "Input.h"

//--------------------------------------------------------------------------------------
// Default Constructor.
//--------------------------------------------------------------------------------------
Game::Game()
{
	m_p2dRenderer = new aie::Renderer2D();

	// Manages the textures in the resource manager
	ResourceManager<Texture>* pTextureManager = ResourceManager<Texture>::GetInstance();

	m_pBackground = pTextureManager->LoadResource("./textures/Background.png");

	// Loads the texture from resource manager and stores in texture pointer
	m_pCourt = pTextureManager->LoadResource("./textures/Grass Court.png");

	m_pWall = pTextureManager->LoadResource("./textures/Wall.png");

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
	aie::Input* pInput = aie::Input::getInstance();

	// use arrow keys to move camera
	if (pInput->isKeyDown(aie::INPUT_KEY_UP))
		m_fCameraY += 500.0f * fDeltaTime;

	if (pInput->isKeyDown(aie::INPUT_KEY_DOWN))
		m_fCameraY -= 500.0f * fDeltaTime;

	if (pInput->isKeyDown(aie::INPUT_KEY_LEFT))
		m_fCameraX -= 500.0f * fDeltaTime;

	if (pInput->isKeyDown(aie::INPUT_KEY_RIGHT))
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

	m_2dRenderer->drawSprite(m_pBackground, 640, 360);

	// output some text, uses the last used colour
	m_2dRenderer->drawText(m_pFont, "Score", 20, 680);

	// output some text, uses the last used colour
	m_2dRenderer->drawText(m_pFont, "11", 20, 640);

	// output some text, uses the last used colour
	m_2dRenderer->drawText(m_pFont, "Best", 1180, 680);

	// output some text, uses the last used colour
	m_2dRenderer->drawText(m_pFont, "56", 1180, 640);

	// Draws the image at a position which is passed in to function
	m_2dRenderer->drawSprite(m_pCourt, 640, 355);

	m_2dRenderer->drawSprite(m_pWall, 640, 675);

	//// draw a thin line
	//m_2dRenderer->drawLine(300, 300, 600, 400, 2, 1);

	//// draw a moving purple circle
	//m_2dRenderer->setRenderColour(1, 0, 1, 1);
	//m_2dRenderer->drawCircle(sin(m_fTimer) * 100 + 600, 150, 50);

	//// draw a rotating red box
	//m_2dRenderer->setRenderColour(1, 0, 0, 1);
	//m_2dRenderer->drawBox(600, 500, 60, 20, m_fTimer);

	//// draw a slightly rotated sprite with no texture, coloured yellow
	//m_2dRenderer->setRenderColour(1, 1, 0, 1);
	//m_2dRenderer->drawSprite(nullptr, 400, 400, 50, 50, 3.14159f * 0.25f, 1);

	//// output some text, uses the last used colour
	//m_2dRenderer->drawText(m_pFont, "Press ESC to quit!", 0, 720 - 64);

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
