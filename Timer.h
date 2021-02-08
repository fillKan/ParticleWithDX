#pragma once
class Timer
{
public:
	 Timer(float time, bool looping);
	~Timer();

	void Start();
	void Start(float time);
	void Start(function<void()> timeOverFunc);
	void Start(float time, function<void()> timeOverFunc);

	void Update();
	bool IsOver();

	float Percent();

public:
	bool IsLooping;
	function<void()> TimeOverFunc;

private:
	float m_LifeTime;
	float m_RestTime;
};

