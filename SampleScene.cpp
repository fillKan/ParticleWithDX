#include "DXUT.h"
#include "SampleScene.h"

void SampleScene::Init()
{
	Object* player = OBJECT->NewObject("Player", Vector2(WINSIZE_X / 2, WINSIZE_Y / 2), Tag::Player);

	player->AddComponent<Renderer>();
	Animator* animator = player->AddComponent<Animator>();

	Animation* animation = new Animation(0.1f);
	animation->Init("PlayerIdle", "./Assets/Player/Player_", 3);
	IMAGE->AddAnimation("PlayerIdle", *animation);

	animator->Add("PlayerIdle");
}

void SampleScene::Update()
{
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
