#pragma once
#include "Entity.h"
#include "Renderer2D.h"
#include "Texture.h"

class Racquet : public Entity
{
public:
	Racquet();
	~Racquet();

	void Update(float fDeltaTime);
	void Draw(aie::Renderer2D* m_2dRenderer);

	void Swing(float fDeltaTime);

private:
	enum SwingState 
	{
		BACK,
		FORTH
	};

	SwingState m_currentState;
	aie::Texture* m_texture;

	float m_fRotation;
	float m_fSwingTimer;
	float m_fSwingRotation;
	float m_fSwingTime;
	float m_fTotalTime;
	float m_fBackRotation;
};
