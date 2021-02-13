#pragma once
class DoomCutting : public Component
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
	Timer* m_CutTimer;
	Timer* m_TxtTimer;

	Texture * m_HexagonLight;
	Renderer* m_Renderer;

	float m_Alpha;
	bool m_TxtTimerStart;
};

