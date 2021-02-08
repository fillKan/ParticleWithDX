#pragma once
class InputManager : public Singleton<InputManager>
{
public:
	void Init();
	void Update();
	void Render();
	void Release();

	bool GetKeyDown(int keyCode);
	bool GetKey(int keyCode);
	bool GetKeyUp(int keyCode);

	Vector2 GetMousePoint();
	void SetMousePoint(Vector2 point);

private:
	Vector2 _MousePoint;

	bool _PreivousInput[128];
	bool  _PresentInput[128];
};
#define INPUT InputManager::Instance()
