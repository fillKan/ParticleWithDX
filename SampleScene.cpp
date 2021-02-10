#include "DXUT.h"
#include "SampleScene.h"

void SampleScene::Init()
{
	Object* player = OBJECT->NewObject("Player", Vector2(WINSIZE_X / 2, WINSIZE_Y / 2), Tag::Player);

	player->AddComponent<Renderer>();
	player->AddComponent<Playable>();
	Animator* animator = player->AddComponent<Animator>();

	Animation* animation = new Animation(0.1f);
	animation->Init("PlayerIdle", "./Assets/Player/Player_", 3);
	IMAGE->AddAnimation("PlayerIdle", *animation);

	animator->Add("PlayerIdle");
}

void SampleScene::Update()
{
	if (INPUT->GetKeyDown(VK_SPACE))
	{
		PARTICLE->CreateParticle(ParticleName::ArrowEffect, true, INPUT->GetMousePoint())->GetTransform()->Rotation = D3DXToRadian(270);
		PARTICLE->CreateParticle(ParticleName::ArrowEffect, true, INPUT->GetMousePoint())->GetTransform()->Rotation = D3DXToRadian(180);
		PARTICLE->CreateParticle(ParticleName::ArrowEffect, true, INPUT->GetMousePoint())->GetTransform()->Rotation = D3DXToRadian(90);
		PARTICLE->CreateParticle(ParticleName::ArrowEffect, true, INPUT->GetMousePoint())->GetTransform();
		//OBJECT->NewObject("Player", INPUT->GetMousePoint(), Tag::Default)->AddComponent<MostimaBoom>();
	}
}

void SampleScene::Render()
{
}

void SampleScene::Release()
{
}

string SampleScene::Name()
{
	return "SampleScene";
}
