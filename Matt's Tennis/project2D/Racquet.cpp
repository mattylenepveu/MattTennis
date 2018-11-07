#include "Racquet.h"

Racquet::Racquet()
{
	m_texture = new aie::Texture("./textures/Racquet.png");

	Matrix3 m3ChangePos;
	m3ChangePos.setPos(75, 0);
}

Racquet::~Racquet()
{
	delete m_texture;
}

void Racquet::Update(float fDeltaTime)
{

}

void Racquet::Draw(aie::Renderer2D* m_2dRenderer)
{
	m_2dRenderer->drawSpriteTransformed3x3(m_texture, globalTransform);
}
