#include "DXUT.h"
#include "Twinkle.h"

void Twinkle::Init()
{
	m_Transform = new Transform();
	m_Transform->Init();

	m_Renderer = new ParticleRenderer();
	m_Renderer->Init(m_Transform);

	m_Renderer->Image = IMAGE->AddImage("WhiteSquare", "./Assets/Particle/WhiteSquare.png");
}

void Twinkle::Update(float deltaTime)
{
}

void Twinkle::Render()
{
	m_Renderer->Render();
}

void Twinkle::Release()
{
}

bool Twinkle::IsDestroy()
{
	return false;
}

Particle* Twinkle::Instantiat(Vector2 position = ZERO, float scale = 1)
{
	return nullptr;
}
