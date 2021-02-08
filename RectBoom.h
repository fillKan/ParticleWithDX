#pragma once
class RectBoom : public Component
{
public:
	virtual void Init   () override;
	virtual void Update () override;
	virtual void Render () override;
	virtual void Release() override;

	virtual void OnAlarm(string key) override;
	virtual void OnCollision(Object* other) override;
	virtual void OnAnimationEnd(string key) override;

private:
	Renderer* m_Renderer;
	Texture* m_Texture;

	float m_Alpha;
};

