#pragma once
namespace Math
{
	int Random(int min, int max);
	float Random(float min, float max);
	float Random();
	float RandomRadian();
	float Sign(float value);
	float Clamp(float value, float min, float max);

	Vector2 Rotate(Vector2 vector, float rot);
	float Distance(Vector2 vector);
	float Distance(Vector2 from, Vector2 to);
	float Direction(Vector2 from, Vector2 to);

	void SetAlpha(D3DCOLOR& color, float alpha);
	Vector2 Lerp(Vector2 a, Vector2 b, float ratio);
	float Lerp(float a, float b, float ratio);
}