#include "DXUT.h"
#include "Renderer.h"

void Renderer::Init()
{
	_RenderingForm =
	{
		Owner->GetTransform()->Position,
		Owner->GetTransform()->Scale,
		Owner->GetTransform()->Rotation,
		Owner->GetTransform()->Depth,

		Pivot, Color, IsVlew
	};
}

void Renderer::Update()
{
	_RenderingForm =
	{
		Owner->GetTransform()->Position,
		Owner->GetTransform()->Scale,
		Owner->GetTransform()->Rotation,
		Owner->GetTransform()->Depth,

		Pivot, Color, IsVlew
	};
}

void Renderer::Render()
{
	if (Image == nullptr)
	{
		RenderingForm form
		{
			//Vector2(WINSIZE_X / 2, WINSIZE_Y / 2), ONE, 0, 0
		};
		IMAGE->RenderText("PPAP", _RenderingForm);
	}
	else
	{
		IMAGE->Render(Image, _RenderingForm);
	}
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
