#include "DXUT.h"
#include "MainGame.h"

#include "SampleScene.h"

void MainGame::Init()
{
	IMAGE->CreateInstance();
	SCENE->CreateInstance();
	SOUND->CreateInstance();
	INPUT->CreateInstance();

	CAMERA->CreateInstance();
	OBJECT->CreateInstance();
	
	SCHEDULE->CreateInstance();

	SCENE->AddScene(new SampleScene);
	SCENE->LoadScene("SampleScene");
}

void MainGame::Update()
{
	INPUT->Update();
	SCENE->Update();
	OBJECT->Update();
	SOUND->Update();
	CAMERA->Update();
	SCHEDULE->Update();
}

void MainGame::Render()
{
	IMAGE->Begin();

	CAMERA->Render();
	SCENE->Render();
	OBJECT->Render();

	IMAGE->End();
}

void MainGame::Release()
{
	IMAGE->ReleaseInstance();
	SCENE->ReleaseInstance();
	SOUND->ReleaseInstance();
	INPUT->ReleaseInstance();

	CAMERA->ReleaseInstance();
	OBJECT->ReleaseInstance();

	SCHEDULE->ReleaseInstance();
}

void MainGame::OnLostDevice()
{
	IMAGE->OnLostDevice();
}

void MainGame::OnResetDevice()
{
	IMAGE->OnResetDevice();
}
