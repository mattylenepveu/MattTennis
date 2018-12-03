#include "Racquet.h"
#include "Input.h"
#include "Matrix3.h"
#include "CollisionManager.h"

Racquet::Racquet()
{
	m_texture = new aie::Texture("./textures/Racquet.png");

	SetType(RACQUET);

	collider.bottomLeft = Vector2(0, 0);
	collider.topRight = Vector2(90, 21);

	// Adds car to the collision list
	CollisionManager::GetInstance()->AddObject(this);

	m_currentState = BACK;

	m_fSwingTimer = 0.0f;

	m_fSwingRotation = 3.1415f * 0.2f;
	m_fRotation = -m_fSwingRotation;
	m_fSwingTime = 0.1f;
}

Racquet::~Racquet()
{
	delete m_texture;
}

void Racquet::Update(float fDeltaTime)
{
	// Gets input so player can control car
	aie::Input* pInput = aie::Input::getInstance();

	// Tests any collision between car and other objects per frame
	Entity* collide = CollisionManager::GetInstance()->TestBoxCollision(this);

	if (pInput->isKeyDown(32))
	{
		m_currentState = FORTH;
	}
	else if (pInput->isKeyUp(32))
	{
		m_currentState = BACK;
	}

	Swing(fDeltaTime);
}

void Racquet::Draw(aie::Renderer2D* m_2dRenderer)
{
	m_2dRenderer->drawSpriteTransformed3x3(m_texture, globalTransform, 
										   0, 0, 0, 0.0f, 0.5f);
}

void Racquet::Swing(float fDeltaTime)
{
	if (m_currentState == BACK)
	{
		m_fSwingTimer += fDeltaTime;
		m_fTotalTime = m_fSwingTimer / m_fSwingTime;
		m_fTotalTime *= m_fTotalTime;

		if (m_fRotation <= -m_fSwingRotation)
		{
			m_fRotation = -m_fSwingRotation;
			m_fSwingTimer = 0.0f;
		}
		else
		{
			m_fRotation = (m_fTotalTime * -m_fSwingRotation) + m_fSwingRotation;
		}
	}
	else if (m_currentState == FORTH)
	{
		m_fSwingTimer += fDeltaTime;
		m_fTotalTime = m_fSwingTimer / m_fSwingTime;
		m_fTotalTime *= m_fTotalTime;

		if (m_fRotation >= m_fSwingRotation)
		{
			m_fRotation = m_fSwingRotation;
			m_fSwingTimer = 0.0f;
		}
		else
		{
			m_fRotation = (m_fTotalTime * m_fSwingRotation) - m_fSwingRotation;
		}
	}

	localTransform.setRotateZ(m_fRotation);
	localTransform[2].x = 30;
	UpdateTransform();
}
