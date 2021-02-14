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
	bool IsCompletelyOver();

	float TimePercent();
	float InvokePercent();

public:
	bool IsLooping;

	int Invoke;
	float LifeTime;

private:
	int RestInvoke;
	float RestTime;
};

