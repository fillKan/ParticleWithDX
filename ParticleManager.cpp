#include "DXUT.h"
#include "ParticleManager.h"

void ParticleManager::Init()
{
}

void ParticleManager::Update()
{
	ParticleUpdate(m_FrontParticles);
	ParticleUpdate( m_BackParticles);
}

void ParticleManager::FrontRender()
{
	for (auto iter : m_FrontParticles)
	{
		iter->Render();
	}
}

void ParticleManager::BackRender()
{
	for (auto iter : m_BackParticles)
	{
		iter->Render();
	}
}

void ParticleManager::Release()
{
	for (auto iter : m_FrontParticles)
	{
		iter->Release();
		delete iter;
	}
	m_FrontParticles.clear();

	for (auto iter : m_BackParticles)
	{
		iter->Release();
		delete iter;
	}
	m_BackParticles.clear();

	for (auto iter : m_ParticleDic)
	{
		delete iter.second;
	}
	m_ParticleDic.clear();
}

void ParticleManager::RegisteParticle(ParticleName name, Particle* particle)
{
	auto find = m_ParticleDic.find(name);
	if (find == m_ParticleDic.end())
	{
		m_ParticleDic.insert(make_pair(name, particle));
	}
}

Particle* ParticleManager::CreateParticle(ParticleName name, bool isFront, Vector2 position, float scale)
{
	Particle* instance = nullptr;

	auto find = m_ParticleDic.find(name);
	if (find != m_ParticleDic.end())
	{
		instance = find->second->Instantiat(position, scale);

		if (isFront)
		{
			m_FrontParticles.push_back(instance);
		}
		else
			m_BackParticles.push_back(instance);
	}
	return instance;
}

void ParticleManager::ParticleUpdate(list<Particle*>& list)
{
	float deltaTime = DeltaTime;

	for (auto particle = list.begin(); particle != list.end();)
	{
		if ((*particle)->IsDestroy())
		{
			(*particle)->Release();
			delete(*particle);
			particle = list.erase(particle);
		}
		else
		{
			(*particle)->Update(deltaTime);
			particle++;
		}
	}
}
