#pragma once
class Transform : public Component
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
	Vector2 Position;
	Vector2 Scale;
	float Rotation;
	float Depth;
};

