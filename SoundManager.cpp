#include "DXUT.h"
#include "SoundManager.h"

void SoundManager::Init()
{
	_Manager.Initialize(DXUTGetHWND(), 0);
}

void SoundManager::Update()
{
	DWORD status;
	for (auto& iter = _PlayingList.begin(); iter != _PlayingList.end();)
	{
		(*iter)->GetStatus(&status);

		if ((status & DSBSTATUS_PLAYING) == 0)
		{
			(*iter)->Release();
			iter = _PlayingList.erase(iter);
		}
		else
		{
			iter++;
		}
	}
}

void SoundManager::Render()
{
}

void SoundManager::Release()
{
	StopAll();
	for (auto iter : _SoundSources)
	{
		delete iter.second;
	}
}

void SoundManager::AddSound(string name, string path)
{
	CSound* temp;
	wstring _path = wstring(path.begin(), path.end());

	_Manager.Create(&temp, (LPWSTR)_path.c_str());
	_SoundSources.insert(make_pair(name, temp));
}

Sound SoundManager::Play(string name, float volume, bool isLoop)
{
	Sound sound;
	_Manager.GetDirectSound()->DuplicateSoundBuffer(_SoundSources[name]->GetBuffer(0), &sound);
	sound->Play(0, 0, isLoop ? DSBPLAY_LOOPING : 0);
	sound->SetVolume(volume);
	_PlayingList.push_back(sound);

	return sound;
}

void SoundManager::StopAll()
{
	for (auto iter : _PlayingList)
	{
		iter->Release();
	}
}
