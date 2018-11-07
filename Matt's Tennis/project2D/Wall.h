#pragma once
#include "Entity.h"
#include "Renderer2D.h"
#include "Texture.h"
#include "Vector2.h"

class Wall : public Entity
{
public:
	Wall(Vector2 v2Pos);
	~Wall();

	void Draw(aie::Renderer2D* p2dRenderer);

private:
	aie::Texture* m_pTexture;
};

