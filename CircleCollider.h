#pragma once
#include "Collider.h"

class BoxCollider;

class CircleCollider : public Collider
{
public:
	virtual void Update() override;
	virtual void UpdateCollider();

	bool IsContactTo(const CircleCollider& other);
	bool IsContactTo(const    BoxCollider& other);

public:
	Vector2 WorldPosition;
	Vector2 LocalPosition;
	float Radius;
};

