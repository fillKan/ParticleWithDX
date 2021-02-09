#pragma once
class Transform;

class ParticleRenderer
{
public:
	 ParticleRenderer();
	~ParticleRenderer();

	void Init(Transform* transform);
	void Render ();
	void Release();

public:
	Texture* Image;

	D3DCOLOR Color = 0xffffffff;
	Vector2 Pivot = HALF;

	bool IsVlew = false;

private: 
	Transform* m_Transform;
	RenderingForm m_RenderingForm;
};

