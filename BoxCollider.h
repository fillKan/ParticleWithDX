#pragma once
#include "Collider.h"
#include "CircleCollider.h"

class BoxCollider : public Collider
{
public:
	virtual void Update() override;
	virtual void UpdateCollider() override;

	bool IsContactTo(const CircleCollider& other);
	bool IsContactTo(const    BoxCollider& other);

public:
	RECT Rect;
	RECT OnWorldRect;

	Vector2 WorldPosition;
	Vector2 LocalPosition;
};

