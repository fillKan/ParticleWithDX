#include "DXUT.h"
#include "MostimaBoom.h"

void MostimaBoom::Init()
{
	m_ParticleTimer = new Timer(0.1, false);
	m_ParticleTimer->Start(0.1f, 4);

	m_ImpactTimer = new Timer(0.35f, false);
	m_ImpactTimer->Start(0.35f, 1);
}
void MostimaBoom::Update()
{
	m_ParticleTimer->Update();

	if (m_ParticleTimer->IsOver())
	{
		PARTICLE->CreateParticle(ParticleName::Mostima, false, Owner->GetTransform()->Position, 3);

		if (m_ParticleTimer->Invoke == 0)
		{
			Owner->IsDestroyed = true;
		}
	}
	m_ImpactTimer->Update();

	if (m_ImpactTimer->IsOver())
	{
		CAMERA->Shake(1, 0.5f);
	}
}

void MostimaBoom::Render()
{
}

void MostimaBoom::Release()
{
	RELEASE(m_ParticleTimer);
	RELEASE(m_ImpactTimer);
}

void MostimaBoom::OnAlarm(string key)
{
}

void MostimaBoom::OnCollision(Object* other)
{
}

void MostimaBoom::OnAnimationEnd(string key)
{
}
