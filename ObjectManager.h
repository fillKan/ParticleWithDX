#pragma once
#include "Object.h"

class CircleCollider;
class BoxCollider;

class ObjectManager : public Singleton<ObjectManager>
{
public:
	void Init();
	void Update();
	void Render();
	void Release();
	void CheckCollisionCircle(CircleCollider* circle);
	void CheckCollisionBox(BoxCollider* box);

	Object* NewObject(string name, Vector2 position, Tag tag);
	void ReleaseAllObject();

public:
	list<Object*> m_ObjectList[Tag::End];
};
#define OBJECT ObjectManager::Instance()
