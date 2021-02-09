#pragma once
class Renderer;
class Transform;

class Particle
{
public:
			 Particle();
	virtual ~Particle();

	virtual void Init   () PURE;
	virtual void Update (float deltaTime) PURE;
	virtual void Render () PURE;
	virtual void Release() PURE;

	virtual bool IsDestroy() PURE;
	virtual Particle* Instantiat(Vector2 position = ZERO, float scale = 1) PURE;

	Transform* GetTransform();
	ParticleRenderer* GetRenderer();

protected:
	Transform* m_Transform;
	ParticleRenderer* m_Renderer;

	Timer m_Timer;
};

