#include "DXUT.h"
#include "DoomCutting.h"

void DoomCutting::Init()
{
	m_Alpha = 1.0f;

	m_Renderer = Owner->TryAddComponent<Renderer>();
	m_Renderer->Image = IMAGE->AddImage("Doom", "./Assets/Particle/Doom/Doom.png");
	m_Renderer->IsEnable = false;

	m_CutTimer = new Timer(0.05f, false);
	m_CutTimer->Start(0.1f, 16);

	m_TxtTimer = new Timer(1.0f, false);
	m_TxtTimerStart = false;

	m_HexagonLight = IMAGE->AddImage("Hexagon_Light", "./Assets/Particle/Doom/Hexagon_Light.png");
}

void DoomCutting::Update()
{
	m_CutTimer->Update();

	if (m_CutTimer->IsOver())
	{
		float rot = RandomRadian();
		float length = 2.00f;
		float speed  = 1.75f;

		Vector2 position = (Vector2(cosf(rot), sinf(rot)) * 36) + Owner->GetTransform()->Position;

		Particle* particle = PARTICLE->CreateParticle(ParticleName::CutEffect, true, position, length);
		particle->GetRenderer()->Image = m_HexagonLight;
		particle->GetTransform()->Rotation = RandomRadian();
		particle->Speed *= speed;

		Particle* particle2 = PARTICLE->CreateParticle(ParticleName::CutEffect, true, position, length);
		particle2->GetTransform()->Rotation = particle->GetTransform()->Rotation;
		particle2->Speed *= speed;

		if (m_CutTimer->IsCompletelyOver())
		{
			float scale = 3.5f;
			float rots[12];
			Vector2 positions[12];

			CAMERA->Shake(45, 0.5f);
			m_Renderer->IsEnable = true;

			speed  = 0.4f;
			length = 2.0f;

			for (int i = 0; i < 12; i++)
			{
				rots[i] = RandomRadian();
				positions[i] = Vector2(D3DXToDegree(cosf(rots[i])), D3DXToDegree(sinf(rots[i]))) * 3.0f;
				positions[i] += Owner->GetTransform()->Position;

				Particle* particle = PARTICLE->CreateParticle(ParticleName::CutEffect, true, positions[i], length);
				particle->GetRenderer()->Image = m_HexagonLight;

				particle->Speed *= speed;
				particle->GetTransform()->Rotation = rots[i];
				particle->GetTransform()->Scale *= scale;
			}
			for (int i = 0; i < 12; i++)
			{
				Particle* particle = PARTICLE->CreateParticle(ParticleName::CutEffect, true, positions[i], length);
				particle->Speed *= speed;
				particle->GetTransform()->Rotation = rots[i];
				particle->GetTransform()->Scale *= scale;
			}
			m_TxtTimerStart = true;
		}
	}
	else if (m_TxtTimerStart)
	{
		m_TxtTimer->Update();

		if (m_TxtTimer->IsCompletelyOver())
		{
			m_Alpha = Clamp(m_Alpha - DeltaTime * 0.7f, 0, 1);
			SetAlpha(m_Renderer->Color, m_Alpha);

			Owner->IsDestroyed = m_Alpha <= 0.1f;
		}
	}
}

void DoomCutting::Render()
{
}

void DoomCutting::Release()
{
	RELEASE(m_CutTimer);
	RELEASE(m_TxtTimer);
}

void DoomCutting::OnAlarm(string key)
{
}

void DoomCutting::OnCollision(Object* other)
{
}

void DoomCutting::OnAnimationEnd(string key)
{
}