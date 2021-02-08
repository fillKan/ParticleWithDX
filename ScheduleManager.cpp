#include "DXUT.h"
#include "ScheduleManager.h"

void ScheduleManager::Init()
{
}

void ScheduleManager::Update()
{
	float deltaTime = DeltaTime;

	for (auto iter = _ScheduleList.begin(); iter != _ScheduleList.end(); ) 
	{
		(*iter)->Time -= deltaTime;

		if ((*iter)->IsOnce)
		{
			if ((*iter)->Time <= 0)
			{
				(*iter)->Function();
				delete (*iter);
				iter = _ScheduleList.erase(iter);
			}
			else
			{
				iter++;
			}
		}
		else
		{
			if ((*iter)->Time <= 0 || !(*iter)->Function())
			{
				delete (*iter);
				iter = _ScheduleList.erase(iter);
			}
			else
			{
				iter++;
			}
		}
	}
}

void ScheduleManager::Render()
{
}

void ScheduleManager::Release()
{
	for (auto iter : _ScheduleList) {
		delete iter;
	}
}

void ScheduleManager::StartSchedule(float time, bool isOnce, function<bool()> func)
{
	_ScheduleList.push_back(new Schedule{ time, isOnce, func });
}