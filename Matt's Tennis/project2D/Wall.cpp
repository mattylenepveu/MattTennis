#include "Wall.h"
#include "Texture.h"
#include "Matrix3.h"
#include "CollisionManager.h"
#include <crtdbg.h>

Wall::Wall(Vector2 v2Pos)
{
	m_pTexture = new aie::Texture("./textures/Wall.png");
	_ASSERT(m_pTexture);

	collider.bottomLeft = Vector2(0, 0);
	collider.topRight = Vector2(975, 70);

	Matrix3 m3ChangePos;
	m3ChangePos.setPos(v2Pos);

	SetType(WALL);

	localTransform = localTransform * m3ChangePos;
	UpdateTransform();

	CollisionManager::GetInstance()->AddObject(this);
}

Wall::~Wall()
{
	delete m_pTexture;
}

void Wall::Draw(aie::Renderer2D* p2dRenderer)
{
	p2dRenderer->drawSpriteTransformed3x3(m_pTexture, globalTransform);
}
