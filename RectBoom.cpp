#include "DXUT.h"
#include "RectBoom.h"

void RectBoom::Init()
{
	m_Alpha = 1;
	m_Renderer = Owner->TryAddComponent<Renderer>();

	m_Renderer->Init();
	m_Renderer->Image = IMAGE->AddImage("RectBoom", "./Assets/RectBoom/WhiteBoom.png");
	Owner->GetTransform()->Scale = ONE * 3;
}

void RectBoom::Update()
{
	float deltaTime = DeltaTime;

	m_Alpha = Clamp(m_Alpha - deltaTime * 0.5f, 0, 1);
	SetAlpha(m_Renderer->Color, m_Alpha);

	if (Owner->GetTransform()->Scale.x < 0)
	{
		Owner->GetTransform()->Scale -= deltaTime * ONE * 3;
	}
	else
		Owner->GetTransform()->Scale -= deltaTime * ONE * 5;

	Owner->GetTransform()->Rotation += deltaTime;

	if (m_Alpha == 0)
	{
		Owner->IsDestroyed = true;
	}
}

void RectBoom::Render()
{
	m_Renderer->Render();
}

void RectBoom::Release()
{
}

void RectBoom::OnAlarm(string key)
{
}

void RectBoom::OnCollision(Object* other)
{
}

void RectBoom::OnAnimationEnd(string key)
{
}
