#pragma once
class Transform;
class Component;

class Object
{
public:
	void Init();
	void Update();
	void Render();
	void Release();
	void SetAlarm(float time, string key);
	void OnCollision(Object* other);

	Transform* GetTransform();


	template<class T>
	T* AddComponent()
	{
		T* component = new T;
		component->Owner = this;
		component->Init();

		_Components.push_back(component);
		return component;
	}

	template<class T>
	T* GetComponent()
	{
		for (auto& iter : _Components)
		{
			if (typeid(iter) == typeid(T*))
			{
				return static_cast<T*>(iter);
			}
		}
		T* Cast = nullptr;
		for (auto& iter : _Components)
		{
			Cast = dynamic_cast<T*>(iter);
			if (Cast != nullptr)
			{
				return Cast;
			}
		}
		return nullptr;
	}

public:
	string Name = "";
	Tag Tag = Tag::Default;
	bool IsDestroyed = false;

private:
	Transform* _Transform;

	list<pair<float, string>> _Alarm;
	list<Component*> _Components;
};

