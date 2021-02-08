#pragma once
template<typename T>
class Singleton
{
public:
			 Singleton() {};
	virtual ~Singleton() {};

private:
	static T* _Instance;

public:
	static void CreateInstance()
	{
		_Instance = new T;
		_Instance->Init();
	}
	static void ReleaseInstance()
	{
		_Instance->Release();
		delete _Instance;
	}
	static T* Instance()
	{
		return _Instance;
	}
};
template<typename T>
T* Singleton<T>::_Instance = nullptr;