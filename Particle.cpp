#include "DXUT.h"
#include "Particle.h"

Particle::Particle() : 
	m_Transform(nullptr), m_Renderer(nullptr), m_Timer(0, false)
{
	
}

Particle::~Particle()
{
	RELEASE(m_Transform);
	RELEASE( m_Renderer);
}

Transform* Particle::GetTransform()
{
	return m_Transform;
}

ParticleRenderer* Particle::GetRenderer()
{
	return m_Renderer;
}
