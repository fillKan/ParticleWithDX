#include "DXUT.h"
#include "Playable.h"

void Playable::Init()
{
}

void Playable::Update()
{
	Vector2 direction = ZERO;

	if (INPUT->GetKey(VK_LEFT))
	{
		direction += LEFT;
	}
	if (INPUT->GetKey(VK_RIGHT))
	{
		direction += RIGHT;
	}
	if (INPUT->GetKey(VK_UP))
	{
		direction += UP;
	}
	if (INPUT->GetKey(VK_DOWN))
	{
		direction += DOWN;
	}
	Owner->GetTransform()->Position +=  direction;
}

void Playable::Render()
{
}

void Playable::Release()
{
}

void Playable::OnAlarm(string key)
{
}

void Playable::OnCollision(Object* other)
{
}

void Playable::OnAnimationEnd(string key)
{
}
