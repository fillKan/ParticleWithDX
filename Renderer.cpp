#include "DXUT.h"
#include "Renderer.h"

void Renderer::Init()
{
	OwnerTransform = Owner->GetTransform();

	_RenderingForm =
	{
		OwnerTransform->Position,
		OwnerTransform->Scale,
		OwnerTransform->Rotation,
		OwnerTransform->Depth,

		Pivot, Color, IsVlew
	};
}

void Renderer::Update()
{
	_RenderingForm =
	{
		OwnerTransform->Position,
		OwnerTransform->Scale,
		OwnerTransform->Rotation,
		OwnerTransform->Depth,

		Pivot, Color, IsVlew
	};
}

void Renderer::Render()
{
	IMAGE->Render(Image, _RenderingForm);
}

void Renderer::Release()
{
}

void Renderer::OnAlarm(string key)
{
}

void Renderer::OnCollision(Object* other)
{
}

void Renderer::OnAnimationEnd(string key)
{
}
