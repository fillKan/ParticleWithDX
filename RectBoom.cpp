#include "DXUT.h"
#include "RectBoom.h"

void RectBoom::Init()
{
	m_Renderer = Owner->TryAddComponent<Renderer>();

	m_Renderer->Init();
	m_Renderer->Image = IMAGE->AddImage("RectBoom", "./Assets/RectBoom/WhiteBoom.png");
}

void RectBoom::Update()
{
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
