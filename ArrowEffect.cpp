#include "DXUT.h"
#include "ArrowEffect.h"

void ArrowEffect::Init()
{
	m_Transform = new Transform();
	m_Transform->Init();

	m_Renderer = new ParticleRenderer();
	m_Renderer->Init(m_Transform);
	m_Renderer->Image = IMAGE->AddImage("UpArrow", "./Assets/Particle/UpArrow.png");

	m_Rect = 
	{
		0, 0, 
		(LONG)m_Renderer->Image->Info.Width, 
		(LONG)m_Renderer->Image->Info.Height
	};
}

void ArrowEffect::Update(float deltaTime)
{
}

void ArrowEffect::Render()
{
	m_Renderer->Render(m_Rect);
}

void ArrowEffect::Release()
{
}

bool ArrowEffect::IsDestroy()
{
	return false;
}

Particle* ArrowEffect::Instantiat(Vector2 position, float scale)
{
	ArrowEffect* instance = new ArrowEffect();
	instance->Init();

	instance->GetTransform()->Position = position;
	instance->GetTransform()->Scale = ONE * scale;

	return instance;
}
