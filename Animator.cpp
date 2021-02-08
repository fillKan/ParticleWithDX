#include "DXUT.h"
#include "Animator.h"

void Animator::Init()
{
	IsEnable = (AttachRenderer = Owner->GetComponent<Renderer>()) != nullptr;
	_PlayingAnim = nullptr;
}

void Animator::Update()
{
	_PlayingAnim->Update(DeltaTime * PlaySpeed);

	AttachRenderer->Image = _PlayingAnim->CurrentFrame();
}

void Animator::Render()
{
}

void Animator::Release()
{
	_Animations.clear();
}

void Animator::OnAlarm(string key)
{
}

void Animator::OnCollision(Object* other)
{
}

void Animator::OnAnimationEnd(string key)
{
}

void Animator::Add(string name, Animation* animation)
{
	if (animation == nullptr)
	{
		animation = IMAGE->FindAnimation(name);
	}
	_Animations.insert(make_pair(name, animation));

	if (_PlayingAnim == nullptr) {

		Change(name);
	}
}

void Animator::Change(string name)
{
	if (_Animations.find(name) != _Animations.end())
	{
		_PlayingAnimName = name;
		_PlayingAnim = _Animations[name];
	}
}

Animation* Animator::PlayingAnimation()
{
	return _PlayingAnim;
}
