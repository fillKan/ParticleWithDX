#include "DXUT.h"
#include "Math.h"

int Math::Random(int min, int max)
{
	return min + (rand() | rand() << 16) % (max - min + 1);
}

float Math::Random(float min, float max)
{
	return Random(min * 1000, max * 10000) * 0.0001f;
}

float Math::Random()
{
	return Random(-1.0f, 1.0f);
}

float Math::Sign(float value)
{
	if (value > 0) return  1;
	if (value < 0) return -1;
	return 0.0f;
}

float Math::Clamp(float value, float min, float max)
{
	if (value > max) return max;
	if (value < min) return min;
	return value;
}

Vector2 Math::Rotate(Vector2 vector, float rot)
{
	rot = D3DXToRadian(rot);

	float x = vector.x * cos(rot) + vector.y * -sin(rot);
	float y = vector.x * sin(rot) + vector.y * -cos(rot);

	return Vector2(x, y);
}

float Math::Distance(Vector2 vector)
{
	return D3DXVec2Length(&vector);
}

float Math::Distance(Vector2 from, Vector2 to)
{
	Vector2 detween = to - from;

	return sqrt(pow(detween.x, 2) + pow(detween.y, 2));
}

float Math::Direction(Vector2 from, Vector2 to)
{
	Vector2 detween = to - from;

	return atan2(detween.y, detween.x);
}

void Math::SetAlpha(D3DCOLOR& color, float alpha)
{
	color = (color & 0x00ffffff) | (D3DCOLOR(255 * alpha) << 24);
}
