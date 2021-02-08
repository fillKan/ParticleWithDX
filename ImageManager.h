#pragma once
#include "Animation.h"

struct Texture
{
	D3DXIMAGE_INFO Info;
	LPDIRECT3DTEXTURE9 Image;
};
struct RenderingForm
{
	// Owner
	Vector2 Position;
	Vector2 Scale;

	float Rotation;
	float Depth;

	Vector2 Pivot = HALF;
	D3DCOLOR Color = 0xffffffff;

	bool IsVlew = false;
};
class ImageManager : public Singleton<ImageManager>
{
public:
	void Init();
	void Release();
	void Begin();
	void End();
	void OnLostDevice();
	void OnResetDevice();

	map<string, Texture*> Images;
	map<string, Animation*> Animations;

	LPD3DXSPRITE MainSprite;
	LPD3DXFONT MainFont;

	Texture* AddImage(string key, string path);
	Texture* Find	 (string key);

	void AddAnimation(string key, Animation& anim);
	Animation* FindAnimation(string key);

	void Render(Texture* image, const RenderingForm& form);
	void RenderRect(Texture* image, const RenderingForm& form, RECT rect);
	void RenderText(string text, const RenderingForm& form);

private:
	void ReadyRendering(const RenderingForm& form, Vector2 center);
};
#define IMAGE ImageManager::Instance()
