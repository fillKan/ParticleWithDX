#include "DXUT.h"
#include "Particle.h"

Particle::Particle() :
	m_Transform(nullptr), m_Renderer(nullptr), m_Timer(0, false), AnimationLevel(0), Speed(1.0f), m_Ratio(0.0f), Direction(ZERO)
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

void Particle::SetValue(int animationLevel)
{
	this->AnimationLevel = animationLevel;
}

void Particle::SetValue(float speed)
{
	this->Speed = speed;
}

void Particle::SetValue(Vector2 direction)
{
	this->Direction = direction;
}

void Particle::SetValue(float speed, int animationLevel)
{
	this->Speed = speed;
	this->AnimationLevel = animationLevel;
}

void Particle::SetValue(float speed, Vector2 direction)
{
	this->Speed = speed;
	this->Direction = direction;
}
