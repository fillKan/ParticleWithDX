#include "DXUT.h"
#include "BoxCollider.h"

void BoxCollider::UpdateCollider()
{
	Transform* owner = Owner->GetTransform();
	WorldPosition = owner->Position + Rotate(LocalPosition, owner->Rotation);

	OnWorldRect = Rect;

	OnWorldRect.left   += WorldPosition.x * Owner->GetTransform()->Scale.x;
	OnWorldRect.right  += WorldPosition.x * Owner->GetTransform()->Scale.x;
	
	OnWorldRect.top	   += WorldPosition.y * Owner->GetTransform()->Scale.y;
	OnWorldRect.bottom += WorldPosition.y * Owner->GetTransform()->Scale.y;
}

bool BoxCollider::IsContactTo(const CircleCollider& other)
{
	Vector2 point =
	{
		Clamp(other.WorldPosition.x, OnWorldRect.left, OnWorldRect.right),
		Clamp(other.WorldPosition.y, OnWorldRect.top,  OnWorldRect.bottom)
	};
	float otherRadius = other.Radius * other.Owner->GetTransform()->Scale.x;

	// 사각형과 원의 중점까지의 거리가 원의 반지름보다 작은가?
	return (Distance(other.WorldPosition - point) <= otherRadius);
}
bool BoxCollider::IsContactTo(const BoxCollider& other)
{
	return (other.OnWorldRect.left <= OnWorldRect.right 
		 && other.OnWorldRect.right >= OnWorldRect.left 
		 && other.OnWorldRect.top <= OnWorldRect.bottom 
		 && other.OnWorldRect.bottom >= OnWorldRect.top);
}
void BoxCollider::Update()
{
	UpdateCollider();
}