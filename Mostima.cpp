#include "DXUT.h"
#include "Mostima.h"

void Mostima::Init()
{
	m_Alpha = 1;
	
	m_Transform = new Transform();
	m_Transform->Init();

	m_Renderer = new ParticleRenderer();
	m_Renderer->Init(m_Transform);

	m_Renderer->Image = IMAGE->AddImage("WhiteSquare_Hollow", "./Assets/Particle/WhiteSquare_Hollow.png");

	Speed = 0.5f;
}

void Mostima::Update(float deltaTime)
{
	m_Alpha = Clamp(m_Alpha - deltaTime * Speed, 0, 1);
	SetAlpha(m_Renderer->Color, m_Alpha);

	if (m_Transform->Scale.x < 0)
	{
		m_Transform->Scale -= deltaTime * ONE * 3;
	}
	else
		m_Transform->Scale -= deltaTime * ONE * 7;

	m_Transform->Rotation += deltaTime;
}

void Mostima::Render()
{
	m_Renderer->Render();
}

void Mostima::Release()
{
}

bool Mostima::IsDestroy()
{
	return m_Alpha <= 0;
}

Particle* Mostima::Instantiat(Vector2 position, float scale)
{
	Mostima* instance = new Mostima();
	instance->Init();

	instance->GetTransform()->Position = position;
	instance->GetTransform()->Scale = ONE * scale;

	return instance;
}
