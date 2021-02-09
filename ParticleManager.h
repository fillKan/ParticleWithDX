#pragma once
enum class ParticleName
{
	Mostima, Twinkle
};

class ParticleManager : public Singleton<ParticleManager>
{
public:
	void Init();
	void Update();
	
	void FrontRender();
	void BackRender();

	void Release();

	void RegisteParticle(ParticleName name, Particle* particle);
	Particle* CreateParticle(ParticleName name, bool isFront, Vector2 position = ZERO, float scale = 1);

private:
	void ParticleUpdate(list<Particle*>& list);

private:
	map<ParticleName, Particle*> m_ParticleDic;

	list<Particle*> m_FrontParticles;
	list<Particle*> m_BackParticles;
};
#define PARTICLE ParticleManager::Instance()