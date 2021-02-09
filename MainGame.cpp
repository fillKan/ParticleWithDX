#include "DXUT.h"
#include "MainGame.h"

#include "SampleScene.h"

#include "Mostima.h"

void MainGame::Init()
{
	IMAGE->CreateInstance();
	SCENE->CreateInstance();
	SOUND->CreateInstance();
	INPUT->CreateInstance();

	CAMERA->CreateInstance();
	OBJECT->CreateInstance();

	PARTICLE->CreateInstance();
	SCHEDULE->CreateInstance();

	SCENE->AddScene(new SampleScene);
	SCENE->LoadScene("SampleScene");

	PARTICLE->RegisteParticle(ParticleName::Mostima, new Mostima());
}

void MainGame::Update()
{
	INPUT->Update();
	SCENE->Update();
	OBJECT->Update();
	PARTICLE->Update();
	SOUND->Update();
	CAMERA->Update();
	SCHEDULE->Update();
}

void MainGame::Render()
{
	IMAGE->Begin();

	CAMERA->Render();
	SCENE->Render();
	PARTICLE->BackRender();
	OBJECT->Render();
	PARTICLE->FrontRender();

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

	PARTICLE->ReleaseInstance();
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
