#pragma once

#include "Scene.h"
class SceneManager : public Singleton<SceneManager>
{
public:
	void Init();
	void Update();
	void Render();
	void Release();

	void  AddScene(Scene* scene);
	void LoadScene(string name);

private:
	map<string, Scene*> SceneIndex;
	
	Scene*  ActiveScene;
	Scene* StagingScene;
};
#define SCENE SceneManager::Instance()