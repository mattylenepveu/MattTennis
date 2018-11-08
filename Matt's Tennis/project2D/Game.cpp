#include "Game.h"
#include "Input.h"
#include "CollisionManager.h"

//--------------------------------------------------------------------------------------
// Default Constructor.
//--------------------------------------------------------------------------------------
Game::Game()
{
	// Creates the collision manager
	CollisionManager::Create();

	m_p2dRenderer = new aie::Renderer2D();

	// Manages the textures in the resource manager
	ResourceManager<Texture>* pTextureManager = ResourceManager<Texture>::GetInstance();

	m_pBackground = pTextureManager->LoadResource("./textures/Background.png");

	// Loads the texture from resource manager and stores in texture pointer
	m_pCourt = pTextureManager->LoadResource("./textures/Clay Court.png");

	m_pBall = new Ball(Vector2(640, 360));

	m_pPlayer = new Player();

	m_pWall = new Wall(Vector2(640, 675));

	m_pFont = new aie::Font("./font/consolas_bold.ttf", 32);
}

//--------------------------------------------------------------------------------------
// Default Destructor.
//--------------------------------------------------------------------------------------
Game::~Game()
{
	delete m_p2dRenderer;
	delete m_pFont;

	delete m_pPlayer;
	delete m_pBall;
	delete m_pWall;
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
	//aie::Input* pInput = aie::Input::getInstance();

	m_pPlayer->Update(fDeltaTime);

	m_pBall->Update(fDeltaTime);
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

	m_pBall->Draw(m_2dRenderer);

	m_pWall->Draw(m_2dRenderer);

	m_pPlayer->Draw(m_2dRenderer);

	

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
