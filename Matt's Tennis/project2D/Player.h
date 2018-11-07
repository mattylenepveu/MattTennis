#pragma once
#include "Vector2.h"
#include "Entity.h"
#include "Texture.h"
#include "Renderer2D.h"
#include "Racquet.h"

class Player : public Entity
{
public:
	Player();
	~Player();

	void Update(float fDeltaTime);
	void Draw(aie::Renderer2D* m_2dRenderer);

private:
	aie::Texture* m_texture;
	Racquet* m_racquet;

	Vector2 m_v2Position;
	Vector2 m_v2MoveDir;

	float m_fSpeed;
	float m_fMoveX;
	float m_fMoveY;
};

