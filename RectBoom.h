#pragma once
class RectBoom : public Particle
{
public:
	virtual void Init  (float  lifeTime) override;
	virtual void Update(float deltaTime) override;

	virtual void Render   () override;
	virtual void Release  () override;
	virtual bool IsDestroy() override;

private:
	float m_Alpha;
};

