#include "DXUT.h"
#include "Timer.h"

Timer::Timer(float time, bool looping) : LifeTime(time), IsLooping(looping), RestInvoke(2), Invoke(1)
{
}

Timer::~Timer()
{
}

void Timer::Start()
{
	RestTime = LifeTime;

	RestInvoke = Invoke;
	RestInvoke++;
}

void Timer::Start(float time)
{
	LifeTime = time;
	RestTime = LifeTime;

	RestInvoke = Invoke;
	RestInvoke++;
}

void Timer::Start(float time, int invoke)
{
	LifeTime = time;
	RestTime = LifeTime;

	Invoke = invoke;
	RestInvoke = invoke;
	RestInvoke++;
}

void Timer::Update()
{
	if (IsLooping && RestInvoke <= 0) 
	{
		RestInvoke = Invoke + 1;
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

float Timer::TimePercent()
{
	return (LifeTime - RestTime) / LifeTime;
}

float Timer::InvokePercent()
{
	return (Invoke - RestInvoke + 1) / Invoke;
}
