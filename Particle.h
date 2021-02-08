#pragma once
class Renderer;
class Transform;

class Particle
{
public:
			 Particle();
	virtual ~Particle();

	virtual void Init   (float  lifeTime) PURE;
	virtual void Update (float deltaTime) PURE;
	virtual void Render () PURE;
	virtual void Release() PURE;

	virtual bool IsDestroy() PURE;

	Transform* GetTransform();
	Renderer * GetRenderer();

public:
	float Speed;

protected:
	Transform* m_Transform;
	Renderer * m_Renderer;

	Timer m_Timer;
};

