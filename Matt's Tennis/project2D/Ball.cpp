#include "Ball.h"
#include "Texture.h"
#include "Matrix3.h"
#include "CollisionManager.h"
#include <crtdbg.h>

Ball::Ball(Vector2 v2Pos)
{
	m_pTexture = new aie::Texture("./textures/Ball.png");
	_ASSERT(m_pTexture);

	Matrix3 m3ChangePos;
	m3ChangePos.setPos(v2Pos);

	localTransform = localTransform * m3ChangePos;
	UpdateTransform();

	CollisionManager::GetInstance()->AddObject(this);
}

Ball::~Ball()
{
	delete m_pTexture;
}

void Ball::Update(float fDeltaTime)
{
	// Tests any collision between car and other objects per frame
	Entity* collide = CollisionManager::GetInstance()->TestBoxCollision(this);
}

void Ball::Draw(aie::Renderer2D* p2dRenderer)
{
	p2dRenderer->drawSpriteTransformed3x3(m_pTexture, globalTransform);
}
