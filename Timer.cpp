#include "DXUT.h"
#include "Timer.h"

Timer::Timer(float time, bool looping) : m_LifeTime(time), IsLooping(looping)
{
}

Timer::~Timer()
{
}

void Timer::Start()
{
	m_RestTime = m_LifeTime;
}

void Timer::Start(float time)
{
	m_LifeTime = time;
	m_RestTime = m_LifeTime;
}

void Timer::Start(function<void()> timeOverFunc)
{
	TimeOverFunc = timeOverFunc;
}

void Timer::Start(float time, function<void()> timeOverFunc)
{
	m_LifeTime = time;
	m_RestTime = m_LifeTime;

	TimeOverFunc = timeOverFunc;
}

void Timer::Update()
{
	if (m_RestTime > 0)
	{
		m_RestTime -= DeltaTime;

		if (m_RestTime <= 0)
		{
			TimeOverFunc();

			if (IsLooping)
			{
				m_RestTime = m_LifeTime;
			}
		}
	}
}

bool Timer::IsOver()
{
	return m_RestTime <= 0;
}

float Timer::Percent()
{
	return (m_LifeTime - m_RestTime) / m_LifeTime;
}
