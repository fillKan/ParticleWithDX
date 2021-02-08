#include "DXUT.h"
#include "MainCamera.h"

void MainCamera::Init()
{
	m_Position = Vector2(WINSIZE_X, WINSIZE_Y) * 0.5f;
	m_Scale = 1;
	m_Rot = 0;
	m_ShakeForce = 0;
	m_ShakePosition = ZERO;
}

void MainCamera::Update()
{
	if (m_ShakeForce != 0)
	{
		m_ShakePosition = Vector2(m_ShakeForce * Random(), m_ShakeForce * Random());
		m_ShakeForce -= m_ShakeForcePerFrame * DeltaTime;

		if (m_ShakeForce <= 0) {

			m_ShakeForce = 0;
			m_ShakePosition = ZERO;
		}
	}
	Matrix P, S, R;
	Vector2 inversePos = m_Position * -1;
	
	D3DXMatrixTranslation(&P, 
		inversePos.x + WINSIZE_X * 0.5f, 
		inversePos.y + WINSIZE_Y * 0.5f, 0);

	D3DXMatrixRotationZ(&R, m_Rot);
	D3DXMatrixScaling(&S, m_Scale, m_Scale, 1);
	m_Matrix = R * S * P;
	D3DXMatrixInverse(&m_InversedMatrix, NULL, &m_Matrix);
}

void MainCamera::Render()
{
	Device->SetTransform(D3DTRANSFORMSTATETYPE::D3DTS_VIEW, &m_Matrix);
}

void MainCamera::Release()
{
}

void MainCamera::Shake(float force, float time)
{
	m_ShakeForce = force;
	m_ShakeForcePerFrame = force / time;
}

Matrix MainCamera::GetVlewMatrix()
{
	return m_InversedMatrix;
}
