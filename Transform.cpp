#include "DXUT.h"
#include "Transform.h"

void Transform::Init()
{
	Position = ZERO;
	Scale = ONE;
	Rotation = 0.0f;
	Depth = 0.0f;
}

void Transform::Update()
{
}

void Transform::Render()
{
}

void Transform::Release()
{
}

void Transform::OnAlarm(string key)
{
}

void Transform::OnCollision(Object* other)
{
}

void Transform::OnAnimationEnd(string key)
{
}
