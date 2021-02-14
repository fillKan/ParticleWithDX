#include "DXUT.h"
#include "Fragment.h"

void Fragment::Init()
{
	m_Transform = new Transform();
	m_Transform->Init();

	m_Renderer = new ParticleRenderer();
	m_Renderer->Init(m_Transform);
	m_Renderer->Image = IMAGE->AddImage("Rhombus_Light", "./Assets/Particle/Doom/Rhombus_Light.png");

	m_RotationDir = Random() * 6.0f;

	m_LifeTimer = new Timer(2.5f, false);
	m_LifeTimer->Start();
}

void Fragment::Update(float deltaTime)
{
	m_Transform->Position += Direction * deltaTime * Speed;
	m_Transform->Rotation += m_RotationDir * deltaTime;

	m_LifeTimer->Update();

	switch (AnimationLevel)
	{
		case 0:
		{
			if (m_LifeTimer->IsOver())
			{
				AnimationLevel++;
				m_LifeTimer->Start(1.5f);
			}
		}
		break;

		case 1:
		{
			float percent = m_LifeTimer->TimePercent();
			float alpha = 1 - percent;

			SetAlpha(m_Renderer->Color, alpha);
		}
		break;
	}
}

void Fragment::Render()
{
	m_Renderer->Render();
}

void Fragment::Release()
{
	RELEASE(m_LifeTimer);
}

bool Fragment::IsDestroy()
{
	return m_LifeTimer->IsCompletelyOver();
}

Particle* Fragment::Instantiat(Vector2 position, float scale)
{
	Fragment* instance = new Fragment();
	instance->Init();

	Transform* transform = instance->m_Transform;

	transform->Position = position;
	transform->Scale *= scale;

	return instance;
}
