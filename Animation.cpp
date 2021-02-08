#include "DXUT.h"
#include "Animation.h"

Animation::Animation(float framePerTime, bool looping)
{
	_IsLooping = looping;
	FramePerTime = framePerTime;
}

Animation::~Animation()
{
}

void Animation::Init(string name, string path, int amount)
{
	char _path[64];
	char _name[64];
	for (int i = 1; i <= amount; i++)
	{
		sprintf(_path, "%s%d.png", path.c_str(), i);
		sprintf(_name, "%s%d.png", name.c_str(), i);
		_Original.push(IMAGE->AddImage(_name, _path));
	}
	_FrameQueue = _Original;
}

void Animation::Update(float elapsedTime)
{
	_ElapsedTime -= elapsedTime;

	if (_ElapsedTime <= 0 && _FrameQueue.size() > 1)
	{
		_ElapsedTime = FramePerTime;

		Texture* current = _FrameQueue.front();
		_FrameQueue.pop();

		if (_IsLooping)
		{
			_FrameQueue.push(current);
		}
	}
}

void Animation::DaCapo()
{
	_ElapsedTime = FramePerTime;
	_FrameQueue  = _Original;
}

Texture* Animation::CurrentFrame()
{
	return _FrameQueue.front();
}
