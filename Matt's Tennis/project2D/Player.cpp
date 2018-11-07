#include "Player.h"
#include "CollisionManager.h"
#include "Input.h"

Player::Player()
{
	m_texture = new aie::Texture("./textures/Player.png");

	Matrix3 m3ChangePos;
	m3ChangePos.setPos(600, 75);

	m_racquet = new Racquet();
	m_racquet->SetParent(this);
	SetChildren(m_racquet);

	m_racquet->SetPosition(75, 0);

	// Transforms its state per frame
	localTransform = localTransform * m3ChangePos;
	UpdateTransform();

	// Adds car to the collision list
	//CollisionManager::GetInstance()->AddObject(this);

	m_fSpeed = 200.0f;
	m_fMoveX = 0.0f;
	m_fMoveY = 0.0f;
}

Player::~Player()
{
	delete m_texture;
}

void Player::Update(float fDeltaTime)
{
	// Gets input so player can control car
	aie::Input* pInput = aie::Input::getInstance();

	// Sets default values for local variables
	float rot = 0;
	m_v2MoveDir = Vector2(0, 0);

	// Tests any collision between car and other objects per frame
	//Entity* collide = CollisionManager::GetInstance()->TestBoxCollision(this);

	// KEYUP
	// W
	if (pInput->isKeyUp(87))
		m_fMoveY = 0.0f;

	// S
	if (pInput->isKeyUp(83))
		m_fMoveY = 0.0f;

	// A
	if (pInput->isKeyUp(65))
		m_fMoveX = 0.0f;

	// D
	if (pInput->isKeyUp(68))
		m_fMoveX = 0.0f;

	// KEYDOWN
	// W
	if (pInput->isKeyDown(87))
		m_fMoveY = 1.0f;

	// S
	if (pInput->isKeyDown(83))
		m_fMoveY = -1.0f;

	// A
	if (pInput->isKeyDown(65))
		m_fMoveX = -1.0f;

	// D
	if (pInput->isKeyDown(68))
		m_fMoveX = 1.0f;

	m_v2MoveDir = Vector2(m_fMoveX, m_fMoveY);

	m_v2Position = m_v2MoveDir * m_fSpeed * fDeltaTime;

	Matrix3 m3ChangePos;
	m3ChangePos.setPos(m_v2Position);

	localTransform = localTransform * m3ChangePos;

	UpdateTransform();
}

void Player::Draw(aie::Renderer2D* m_2dRenderer)
{
	m_racquet->Draw(m_2dRenderer);

	m_2dRenderer->drawSpriteTransformed3x3(m_texture, globalTransform);
}
