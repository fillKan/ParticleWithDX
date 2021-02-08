#include "DXUT.h"
#include "CircleCollider.h"
#include "Transform.h"

void CircleCollider::UpdateCollider()
{
	Transform* owner = Owner->GetTransform();
	WorldPosition = owner->Position + Rotate(LocalPosition, owner->Rotation);
}

bool CircleCollider::IsContactTo(const CircleCollider& other)
{
	float otherRadius = other.Radius * other.Owner->GetTransform()->Scale.x;
	float thisRadius  = this->Radius *		 Owner->GetTransform()->Scale.x;

	return (Distance(this->WorldPosition - other.WorldPosition) <= otherRadius + thisRadius);
}

bool CircleCollider::IsContactTo(const BoxCollider& other)
{
    RECT worldRect =
    {
        other.Rect.left   * abs(other.Owner->GetTransform()->Scale.x),
        other.Rect.top    * abs(other.Owner->GetTransform()->Scale.y),
        other.Rect.right  * abs(other.Owner->GetTransform()->Scale.x),
        other.Rect.bottom * abs(other.Owner->GetTransform()->Scale.y)
    };
    Vector2 point, pos;
    pos = other.Owner->GetTransform()->Position;

    point = Vector2(
        Clamp(WorldPosition.x, pos.x + worldRect.left, pos.x + worldRect.right),
        Clamp(WorldPosition.y, pos.y + worldRect.top,  pos.y + worldRect.bottom));

    float thisRadius = Radius * Owner->GetTransform()->Scale.x;

	return (Distance(WorldPosition - point) <= thisRadius);
}

void CircleCollider::Update()
{
	UpdateCollider();
}