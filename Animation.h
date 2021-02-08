#pragma once
struct Texture;

class Animation
{
public:
	 Animation(float framePerTime, bool looping = true);
	~Animation();

	void Init(string name, string path, int amount);
	void Update(float elapsedTime);
	void DaCapo();

	Texture* CurrentFrame();

public:
	float FramePerTime;
	function<void()> PlayOverAction;

private:

	bool _IsLooping;
	float _ElapsedTime;
	
	queue<Texture*> _FrameQueue;
	queue<Texture*> _Original;
};

