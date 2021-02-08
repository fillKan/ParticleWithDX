#pragma once
struct Schedule
{
	float Time;
	bool IsOnce;
	function<bool()> Function;
};
class ScheduleManager : public Singleton<ScheduleManager>
{
public:
	void Init();
	void Update ();
	void Render ();
	void Release();

	void StartSchedule(float time, bool isOnce, function<bool()> func);

private:
	list<Schedule*> _ScheduleList;
};
#define SCHEDULE ScheduleManager::Instance()
