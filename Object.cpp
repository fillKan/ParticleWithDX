#include "DXUT.h"
#include "Object.h"

void Object::Init()
{
	_Transform = new Transform();
	_Transform->Init();
}

void Object::Update()
{
	for (auto& iter : _Components) 
	{
		if (iter->IsEnable) {
			iter->Update();
		}
	}
	float deltaTime = DeltaTime;
	for (auto& iter = _Alarm.begin(); iter != _Alarm.end();)
	{
		if (((*iter).first -= deltaTime) <= 0)
		{
			string Key = (*iter).second;
			iter = _Alarm.erase(iter);
			for (auto& Component : _Components)
			{
				Component->OnAlarm(Key);
			}
		}
		else
		{
			iter++;
		}
	}
}

void Object::Render()
{
	for (auto& iter : _Components)
	{
		if (iter->IsEnable) {
			iter->Render();
		}
	}
}

void Object::Release()
{
	for (auto& iter : _Components)
	{
		iter->Release();
		delete iter;
	}
}

void Object::SetAlarm(float time, string key)
{
	_Alarm.push_back(make_pair(time, key));
}

void Object::OnCollision(Object* other)
{
	for(auto iter : _Components)
	{
		iter->OnCollision(other);
	}
}

Transform* Object::GetTransform()
{
	return _Transform;
}
