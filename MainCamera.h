#pragma once
class MainCamera : public Singleton<MainCamera>
{
public:
	void Init();
	void Update();
	void Render();
	void Release();

	Vector2 m_Position;
	float m_Scale;
	float m_Rot;
	float m_ShakeForcePerFrame;
	float m_ShakeForce;
	Vector2 m_ShakePosition;

	Matrix m_Matrix;
	Matrix m_InversedMatrix;

	void Shake(float force, float time);
	Matrix GetVlewMatrix();

private:
	Vector2 m_FixedPosition;
};
#define CAMERA MainCamera::Instance()