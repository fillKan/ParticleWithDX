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

	void SetValue(int animationLevel);
	void SetValue(float speed);
	void SetValue(Vector2 direction);
	void SetValue(float speed, int animationLevel);
	void SetValue(float speed, Vector2 direction);

	virtual bool IsDestroy() PURE;
	virtual Particle* Instantiat(Vector2 position = ZERO, float scale = 1) PURE;

	Transform* GetTransform();
	ParticleRenderer* GetRenderer();

public:
	float Speed;
	int AnimationLevel;
	Vector2 Direction;

protected:
	float m_Ratio;

	Transform* m_Transform;
	ParticleRenderer* m_Renderer;

	Timer m_Timer;
};

