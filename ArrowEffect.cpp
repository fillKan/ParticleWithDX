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
		(LONG)(m_Renderer->Image->Info.Width  * m_Transform->Scale.x),
		(LONG)(m_Renderer->Image->Info.Height * m_Transform->Scale.y)
	};
	m_Ratio = 0;

	m_AnimationLevel = 0;
}

void ArrowEffect::Update(float deltaTime)
{
	m_Ratio = Clamp(m_Ratio + deltaTime, 0, 1);
	switch (m_AnimationLevel)
	{
	case 0:
		m_Transform->Position = Lerp(m_Transform->Position, GoalPoint(80), m_Ratio);

		if (m_Ratio >= 0.35f)
		{
			m_Ratio = 0;
			m_AnimationLevel++;
		}
		break;

	case 1:
		m_Rect.bottom = Lerp(m_Rect.bottom, 0, m_Ratio);

		if (m_Ratio == 1)
		{
			m_Ratio = 0;
			m_AnimationLevel++;
		}
		break;

	default:
		break;
	}
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
	return m_AnimationLevel == 2;
}

Particle* ArrowEffect::Instantiat(Vector2 position, float scale)
{
	ArrowEffect* instance = new ArrowEffect();
	instance->Init();

	instance->m_StartPoint = position;

	instance->GetTransform()->Position = position;
	instance->GetTransform()->Scale = ONE * scale;

	return instance;
}

Vector2 ArrowEffect::GoalPoint(float length)
{
	float rot = m_Transform->Rotation - D3DXToRadian(90);

	return m_StartPoint + Vector2(cosf(rot), sinf(rot)) * length;
}
