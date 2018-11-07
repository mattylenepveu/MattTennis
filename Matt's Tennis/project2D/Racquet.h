#pragma once
#include "Entity.h"
#include "Vector2.h"
#include "Renderer2D.h"
#include "Texture.h"

class Racquet : public Entity
{
public:
	Racquet();
	~Racquet();

	void Update(float fDeltaTime);
	void Draw(aie::Renderer2D* m_2dRenderer);

private:
	aie::Texture* m_texture;
};

