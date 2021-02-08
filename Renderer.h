#pragma once
#include "Component.h"

class Renderer : public Component
{
public:
	virtual void Init() override;
	virtual void Update() override;
	virtual void Render() override;
	virtual void Release() override;
	virtual void OnAlarm(string key) override;
	virtual void OnCollision(Object* other) override;
	virtual void OnAnimationEnd(string key) override;

public:
	Texture* Image;
	D3DCOLOR Color = 0xffffffff;
	Vector2 Pivot = HALF;

	bool IsVlew = false;

protected:
	RenderingForm _RenderingForm;
};

