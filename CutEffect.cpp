#include "DXUT.h"
#include "CutEffect.h"

void CutEffect::Init()
{
	m_Transform = new Transform();
	m_Transform->Init();

	m_Renderer = new ParticleRenderer();
	m_Renderer->Init(m_Transform);

	m_Renderer->Image = IMAGE->AddImage("Hexagon", "./Assets/Particle/Hexagon.png");

	Speed *= 1.75f;
}

void CutEffect::Update(float deltaTime)
{
	m_Ratio = Clamp(m_Ratio + deltaTime * Speed, 0, 1);

	m_Transform->Scale = Lerp(m_Transform->Scale, m_GoalVector, m_Ratio);
}

void CutEffect::Render()
{
	m_Renderer->Render();
}

void CutEffect::Release()
{
}

bool CutEffect::IsDestroy()
{
    return m_Ratio >= 0.9f;
}

Particle* CutEffect::Instantiat(Vector2 position, float scale)
{
	CutEffect* instance = new CutEffect();
	instance->Init();

	Transform* transform = instance->m_Transform;

	transform->Position = position;
	transform->Scale = HALF;

	instance->m_GoalVector = Vector2(scale * 8, 0);

	return instance;
}
