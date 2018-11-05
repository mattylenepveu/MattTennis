#include "Splash.h"

//--------------------------------------------------------------------------------------
// Default Constructor.
//--------------------------------------------------------------------------------------
Splash::Splash()
{
	// Manages the textures in the resource manager
	ResourceManager<Texture>* pTextureManager = ResourceManager<Texture>::GetInstance();

	// Loads the texture from resource manager and stores in texture pointer
	m_pMatt = pTextureManager->LoadResource("./textures/Me.png");

	// Creates a "new" font with the font directory and size passed in constructor
	m_pFont = new Font("./font/consolas_bold.ttf", 32);
}

//--------------------------------------------------------------------------------------
// Default Destructor.
//--------------------------------------------------------------------------------------
Splash::~Splash()
{
	// Deletes the font pointer to prevent memory leaks
	delete m_pFont;
}

//--------------------------------------------------------------------------------------
// Runs when the state is first pushed back
//
// Paramaters:
//		pStateMachine: A pointer to the StateMachine for use in function
//--------------------------------------------------------------------------------------
void Splash::OnEnter(StateMachine* pStateMachine)
{
	// Initialises floats once the state is entered
	m_fTimer = 0.0f;
	m_fAlpha = 0.0f;
}

//--------------------------------------------------------------------------------------
// Updates the state when it is running
//
// Paramaters:
//		fDeltaTime: Keeps track of real time, used for movement and waiting periods
//		pStateMachine: Is used to access the state machine
//		m_2dRenderer: Is used for access to the renderer class
//--------------------------------------------------------------------------------------
void Splash::OnUpdate(float fDeltaTime, StateMachine* pStateMachine,
	Renderer2D* m_2dRenderer)
{
	// Keeps updating timer via real time
	m_fTimer += fDeltaTime;

	// Allows variable to be used for a fade in
	m_fAlpha += fDeltaTime * 0.5f;

	// Does not let alpha become greater than one
	if (m_fAlpha >= 1.0f)
	{
		m_fAlpha = 1.0f;
	}

	// If timer is greater or equal to five, then move on to next state on stack
	if (m_fTimer >= 5.0f)
	{
		pStateMachine->PushState(1);
	}
}

//--------------------------------------------------------------------------------------
// Draws the state when it is pushed on the stack
//
// Parameters:
//		m_2dRenderer: Accesses the renderer class to allow the state to be drawn
//--------------------------------------------------------------------------------------
void Splash::OnDraw(Renderer2D* m_2dRenderer)
{
	// Renders the fade in for the state
	m_2dRenderer->setRenderColour(1, 1, 1, m_fAlpha);

	// Draws the image at a position which is passed in to function
	m_2dRenderer->drawSprite(m_pMatt, 640, 420);

	// Draws the text below the image with the font, text and position passed in
	m_2dRenderer->drawText(m_pFont, "Matthew Le Nepveu Productions", 380, 170);
}

//--------------------------------------------------------------------------------------
// Runs when the state is being exited
//
// Paramaters:
//		pStateMachine: A pointer to the StateMachine for use in function
//--------------------------------------------------------------------------------------
void Splash::OnExit(StateMachine* pStateMachine)
{
	// Resets float values once the state is exited
	m_fTimer = 0.0f;
	m_fAlpha = 0.0f;
}
