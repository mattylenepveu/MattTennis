#pragma once
#include "Entity.h"
#include "Renderer2D.h"
#include "Texture.h"
#include "Vector2.h"

class Ball : public Entity
{
public:
	Ball(Vector2 v2Pos);
	~Ball();

	void Update(float fDeltaTime);
	void Draw(aie::Renderer2D* p2dRenderer);

private:
	aie::Texture* m_pTexture;
};

