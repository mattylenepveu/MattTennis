#include "Start.h"
#include "Input.h"

//--------------------------------------------------------------------------------------
// Default Constructor.
//--------------------------------------------------------------------------------------
Start::Start()
{
	//// Adds textures to the resource manager
	//ResourceManager<Texture>* pTextureManager = ResourceManager<Texture>::GetInstance();

	//// Creates a new logo and background via loading them from resource manager
	//m_pLogo = pTextureManager->LoadResource("./textures/GameLogo.png");
	//m_pBackground = pTextureManager->LoadResource("./textures/BackgroundCol.png");

	// Creates a new font
	m_pFont = new Font("./font/consolas_bold.ttf", 32);
	_ASSERT(m_pFont);
}

//--------------------------------------------------------------------------------------
// Default Destructor.
//--------------------------------------------------------------------------------------
Start::~Start()
{
	delete m_pFont;
}

//--------------------------------------------------------------------------------------
// Runs when the state is first pushed back
//
// Paramaters:
//		pStateMachine: A pointer to the StateMachine for use in function
//--------------------------------------------------------------------------------------
void Start::OnEnter(StateMachine* pStateMachine)
{
	m_fAlpha = 1.0;
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
void Start::OnUpdate(float fDeltaTime, StateMachine* pStateMachine, Renderer2D* m_2dRenderer)
{
	// Allows user to input keys
	Input* pInput = Input::getInstance();

	// If "enter" key is pressed, then push to choose car screen
	if (pInput->wasKeyPressed(INPUT_KEY_ENTER))
		pStateMachine->PushState(2);

	// Adds timer by deltaTime
	m_fTimer += fDeltaTime;

	// If timer is greater than 3.0, then don't let text appear
	if (m_fTimer > 3.0f)
		m_fAlpha = 0.0f;

	// If timer is greater than 3.5, then let text appear and reset timer
	if (m_fTimer > 3.5f)
	{
		m_fAlpha = 1.0f;
		m_fTimer = 0.0f;
	}
}

//--------------------------------------------------------------------------------------
// Draws the state when it is pushed on the stack
//
// Parameters:
//		m_2dRenderer: Accesses the renderer class to allow the state to be drawn
//--------------------------------------------------------------------------------------
void Start::OnDraw(Renderer2D* m_2dRenderer)
{
	// Draws the first line of text
	m_2dRenderer->setRenderColour(1, 0, 0, m_fAlpha);
	m_2dRenderer->drawText(m_pFont, "Press Enter to Play!", 920, 80);

	// Draws the second line of text
	m_2dRenderer->setRenderColour(1, 0, 0, 1);
	m_2dRenderer->drawText(m_pFont, "(C) 2018 Matthew Le Nepveu Productions", 600, 30);
}

//--------------------------------------------------------------------------------------
// Runs when the state is being exited
//
// Paramaters:
//		pStateMachine: A pointer to the StateMachine for use in function
//--------------------------------------------------------------------------------------
void Start::OnExit(StateMachine* pStateMachine)
{
	m_fAlpha = 1.0;
	m_fTimer = 0.0f;
}
