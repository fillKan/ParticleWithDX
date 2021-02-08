#include "DXUT.h"
#include "SceneManager.h"

void SceneManager::Init()
{
	ActiveScene  = nullptr;
	StagingScene = nullptr;
}

void SceneManager::Update()
{
	if (StagingScene)
	{
		if (ActiveScene)
		{
			ActiveScene->Release();
		}
		ActiveScene = StagingScene;
		ActiveScene->Init();

		StagingScene = nullptr;
	}
	if (ActiveScene)
	{
		ActiveScene->Update();
	}
}

void SceneManager::Render()
{
	if (ActiveScene)
	{
		ActiveScene->Render();
	}
}

void SceneManager::Release()
{
	for (auto iter : SceneIndex)
	{
		iter.second->Release();
		delete iter.second;
	}
	SceneIndex.clear();
}

void SceneManager::AddScene(Scene* scene)
{
	if (scene) 
	{
		auto find = SceneIndex.find(scene->Name());
		if (find == SceneIndex.end()) 
		{
			SceneIndex.insert(make_pair(scene->Name(), scene));
		}
	}
}

void SceneManager::LoadScene(string name)
{
	auto find = SceneIndex.find(name);
	if (find != SceneIndex.end())
	{
		StagingScene = find->second;
	}
}
