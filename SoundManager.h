#pragma once
class SoundManager : public Singleton<SoundManager>
{
public:
	void Init();
	void Update ();
	void Render ();
	void Release();

	void AddSound(string name, string path);
	Sound Play(string name, float volume, bool isLoop);
	void StopAll();

private:
	CSoundManager _Manager;

	list<Sound> _PlayingList;
	map<string, CSound*> _SoundSources;
};
#define SOUND SoundManager::Instance()
