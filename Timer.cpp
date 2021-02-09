#include "DXUT.h"
#include "Timer.h"

Timer::Timer(float time, bool looping) : LifeTime(time), IsLooping(looping)
{
}

Timer::~Timer()
{
}

void Timer::Start()
{
	RestTime = LifeTime;

	RestInvoke = Invoke;
}

void Timer::Start(float time)
{
	LifeTime = time;
	RestTime = LifeTime;

	RestInvoke = Invoke;
}

void Timer::Start(float time, int invoke)
{
	LifeTime = time;
	RestTime = LifeTime;

	Invoke = invoke;
	RestInvoke = invoke;
}

void Timer::Update()
{
	if (IsLooping && RestInvoke <= 0) 
	{
		RestInvoke = Invoke; 
	}
	if (RestInvoke > 0) 
	{
		if (RestTime <= 0) {
			RestTime = LifeTime;
		}
		RestTime -= DeltaTime;

		if (RestTime <= 0)
		{
			RestInvoke--;
			RestTime = 0;
		}
	}
}

bool Timer::IsOver()
{
	return RestTime <= 0 && RestInvoke > 0;
}

float Timer::Percent()
{
	return (LifeTime - RestTime) / LifeTime;
}
