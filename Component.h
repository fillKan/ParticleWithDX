#pragma once
#include "Object.h"
class Object;
class Component
{
public:
	Component();
	virtual ~Component();

	virtual void Init() PURE;
	virtual void Update() PURE;
	virtual void Render() PURE;
	virtual void Release() PURE;

	virtual void OnAlarm(string key) PURE;
	virtual void OnCollision(Object* other) PURE;
	virtual void OnAnimationEnd(string key) PURE;

public:
	Object* Owner;
	bool IsEnable = true;
};

