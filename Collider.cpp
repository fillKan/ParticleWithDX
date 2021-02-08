#include "DXUT.h"
#include "Collider.h"

void Collider::Init()
{
	Tags = new TagCollection();
}

void Collider::Update()
{
}

void Collider::Render()
{
}

void Collider::Release()
{
	RELEASE(Tags);
}

void Collider::OnAlarm(string key)
{
}

void Collider::OnCollision(Object* other)
{
}

void Collider::OnAnimationEnd(string key)
{
}
