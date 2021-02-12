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
	m_Ratio = Clamp(m_Ratio + DeltaTime * Speed, 0, 1);

	switch (AnimationLevel)
	{
	case 0:
		m_Transform->Scale = Lerp(m_Transform->Scale, m_HighVector, m_Ratio);
		if (m_Ratio >= 0.4)
		{
			AnimationLevel = 1;
			m_Ratio = 0;
		}
		break;

	case 1:
		m_Transform->Scale = Lerp(m_Transform->Scale, m_GoalVector, m_Ratio);
		if (m_Ratio == 1)
		{
			AnimationLevel = 2;
			m_Ratio = 0;
		}
		break;
	}
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
	return AnimationLevel == 2;
}

Particle* Twinkle::Instantiat(Vector2 position, float scale)
{
	Twinkle* instance = new Twinkle();
	instance->Init();

	Transform* transform = instance->m_Transform;

	transform->Position = position;
	transform->Scale = ONE * scale;

	instance->m_HighVector = Vector2(transform->Scale.x * 0.1f, transform->Scale.y * 2);
	instance->m_GoalVector = Vector2(transform->Scale.x * 5, 0);

	return instance;
}
