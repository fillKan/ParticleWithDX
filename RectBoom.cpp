#include "DXUT.h"
#include "RectBoom.h"

void RectBoom::Init()
{
	m_Alpha = 1;
	
	m_Transform = new Transform();
	m_Transform->Init();

	m_Renderer = new Renderer();
	m_Renderer->OwnerTransform = m_Transform;
	m_Renderer->Init();

	m_Renderer->Image = IMAGE->AddImage("RectBoom", "./Assets/RectBoom/WhiteBoom.png");
	m_Transform->Scale = ONE * 3;
}

void RectBoom::Update(float deltaTime)
{
	m_Alpha = Clamp(m_Alpha - deltaTime * Speed, 0, 1);
	SetAlpha(m_Renderer->Color, m_Alpha);

	if (m_Transform->Scale.x < 0)
	{
		m_Transform->Scale -= deltaTime * ONE * 3;
	}
	else
		m_Transform->Scale -= deltaTime * ONE * 5;

	m_Transform->Rotation += deltaTime;
}

void RectBoom::Render()
{
	m_Renderer->Render();
}

void RectBoom::Release()
{
}

bool RectBoom::IsDestroy()
{
	return m_Alpha <= 0;
}

Particle* RectBoom::Instantiat(Vector2 position, float scale)
{
	RectBoom* instance = new RectBoom();
	instance->Init();

	instance->GetTransform()->Position = position;
	instance->GetTransform()->Scale = ONE * scale;

	return instance;
}
