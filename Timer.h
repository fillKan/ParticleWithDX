#pragma once
class Timer
{
public:
	 Timer(float time, bool looping);
	~Timer();

	void Start();
	void Start(float time);
	void Start(float time, int invoke);

	void Update();
	bool IsOver();

	float Percent();

public:
	bool IsLooping;

	int Invoke;
	int RestInvoke;

	float LifeTime;
	float RestTime;
};

