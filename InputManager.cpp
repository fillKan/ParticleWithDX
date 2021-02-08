#include "DXUT.h"
#include "InputManager.h"

void InputManager::Init()
{
}

void InputManager::Update()
{
	memcpy(_PreivousInput, _PresentInput, 128);

	for (int i = 0; i < 128; i++) 
	{
		_PresentInput[i] = (GetAsyncKeyState(i) & 0x8000);
	}
	POINT point;
	GetCursorPos(&point);
	ScreenToClient(DXUTGetHWND(), &point);

	_MousePoint = Vector2(point.x, point.y);
}

void InputManager::Render()
{
}

void InputManager::Release()
{
}

bool InputManager::GetKeyDown(int keyCode)
{
	return _PresentInput[keyCode] && !_PreivousInput[keyCode];
}

bool InputManager::GetKey(int keyCode)
{
	return _PresentInput[keyCode] && _PreivousInput[keyCode];;
}

bool InputManager::GetKeyUp(int keyCode)
{
	return !_PresentInput[keyCode] && _PreivousInput[keyCode];;
}

Vector2 InputManager::GetMousePoint()
{
	return _MousePoint;
}

void InputManager::SetMousePoint(Vector2 point)
{
	POINT newPoint = { point.x, point.y };
	ClientToScreen(DXUTGetHWND(), &newPoint);
	SetCursorPos(newPoint.x, newPoint.y);
}
