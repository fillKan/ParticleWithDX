#include "DXUT.h"
#include "ImageManager.h"

void ImageManager::Init()
{
	D3DXCreateSprite(Device, &MainSprite);
	D3DXCreateFont(Device, 64, 0, 0, 1, 0, DEFAULT_CHARSET, 0, 0, 0, L"µ¸¿ò", &MainFont);
}

void ImageManager::Release()
{
	for (auto& iter : Images)
	{
		iter.second->Image->Release();
		delete iter.second;
	}
	for (auto& iter : Animations)
	{
		delete iter.second;
	}
	MainSprite->Release();
	MainFont->Release();
}

void ImageManager::Begin()
{
	MainSprite->Begin(D3DXSPRITE_ALPHABLEND | D3DXSPRITE_SORT_DEPTH_FRONTTOBACK);
	Device->SetSamplerState(0, D3DSAMP_MINFILTER, D3DX_FILTER_NONE);
	Device->SetSamplerState(0, D3DSAMP_MIPFILTER, D3DX_FILTER_NONE);
	Device->SetSamplerState(0, D3DSAMP_MAGFILTER, D3DX_FILTER_NONE);
}

void ImageManager::End()
{
	MainSprite->End();
}

void ImageManager::OnLostDevice()
{
	MainSprite->OnLostDevice();
}

void ImageManager::OnResetDevice()
{
	MainSprite->OnResetDevice();
}

Texture* ImageManager::AddImage(string key, string path)
{
	auto find = Images.find(key);
	if (find == Images.end())
	{
		Texture* Tex = new Texture;

		if (D3DXCreateTextureFromFileExA(Device, path.c_str(), D3DX_DEFAULT_NONPOW2, D3DX_DEFAULT_NONPOW2, 0, 0,
			D3DFMT_UNKNOWN, D3DPOOL_MANAGED, D3DX_FILTER_POINT, D3DX_FILTER_POINT, 0, &Tex->Info, 0, &Tex->Image) == S_OK)
		{
			Images.insert(make_pair(key, Tex));
			return Tex;
		}
		delete Tex;
		return nullptr;
	}
	return Images[key];
}

Texture* ImageManager::Find(string key)
{
	auto find = Images.find(key);
	if (find != Images.end())
	{
		return Images[key];
	}
	return nullptr;
}

void ImageManager::AddAnimation(string key, Animation& anim)
{
	auto find = Animations.find(key);
	if (find == Animations.end())
	{
		Animations.insert(make_pair(key, &anim));
	}
}

Animation* ImageManager::FindAnimation(string key)
{
	auto find = Animations.find(key);
	if (find != Animations.end())
	{
		return Animations[key];
	}
	return nullptr;
}

void ImageManager::Render(Texture* image, const RenderingForm& form)
{
	Vector2 center = Vector2(form.Pivot.x * (float)image->Info.Width, form.Pivot.y * (float)image->Info.Height);
	ReadyRendering(form, center);

	MainSprite->Draw(image->Image, nullptr, nullptr, nullptr, form.Color);
}

void ImageManager::RenderRect(Texture* image, const RenderingForm& form, RECT rect)
{
	Vector2 center = Vector2(form.Pivot.x * (float)image->Info.Width, form.Pivot.y * (float)image->Info.Height);
	ReadyRendering(form, center);

	MainSprite->Draw(image->Image, &rect, nullptr, nullptr, form.Color);
}

void ImageManager::RenderText(string text, const RenderingForm& form)
{
	RECT rect = RECT{ 0, 0, 0, 0 };
	MainFont->DrawTextA(MainSprite, text.c_str(), -1, &rect, DT_NOCLIP | DT_CENTER | DT_VCENTER | DT_CALCRECT, 0xffffffff);

	Vector2 center = Vector2(form.Pivot.x * (float)rect.right, form.Pivot.y * (float)rect.bottom) * 2;
	ReadyRendering(form, center);

	MainFont->DrawTextA(MainSprite, text.c_str(), -1, nullptr, DT_NOCLIP | DT_CENTER | DT_VCENTER, form.Color);
}

void ImageManager::ReadyRendering(const RenderingForm& form, Vector2 center)
{
	Matrix mat;
	D3DXMatrixTransformation2D(&mat, &center, 0, &form.Scale, &center, form.Rotation, &(form.Position - center));

	if (form.IsVlew)
	{
		mat *= CAMERA->GetVlewMatrix();
	}
	mat._43 = form.Depth;
	MainSprite->SetTransform(&mat);
}
