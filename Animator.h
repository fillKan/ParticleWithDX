#pragma once
#include "Component.h"
class Animator : public Component
{
public:
	virtual void Init() override;
	virtual void Update() override;
	virtual void Render() override;
	virtual void Release() override;
	virtual void OnAlarm(string key) override;
	virtual void OnCollision(Object* other) override;
	virtual void OnAnimationEnd(string key) override;

	void Add(string name, Animation* animation = nullptr);
	void Change(string name);

	Animation* PlayingAnimation();

public:
	Renderer* AttachRenderer;
	float PlaySpeed = 1;

private:
	map<string, Animation*> _Animations;
	
	string _PlayingAnimName;
	Animation* _PlayingAnim;
};

