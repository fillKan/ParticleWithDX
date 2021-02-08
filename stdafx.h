#pragma once
#include <map>
#include <list>
#include <vector>
#include <queue>
#include <functional>
#include <algorithm>
#include <string>
#include "SDKsound.h"
#include "SDKwavefile.h"
#pragma comment(lib, "legacy_stdio_definitions.lib")
#pragma comment(lib, "dsound.lib")

#define Device DXUTGetD3D9Device()
#define DeltaTime DXUTGetElapsedTime()
#define PURE =0
#define RELEASE(p) {if(p) {delete(p); p = nullptr;}}

const float WINSIZE_X = 1280;
const float WINSIZE_Y = 720;

using namespace std;
using Vector2 = D3DXVECTOR2;
using Matrix = D3DXMATRIX;
using Sound  = LPDIRECTSOUNDBUFFER;

const Vector2 ZERO = Vector2( 0,  0);
const Vector2 UP   = Vector2( 0,  1);
const Vector2 DOWN = Vector2( 0, -1);
const Vector2 LEFT = Vector2(-1,  0);
const Vector2 RIGHT= Vector2( 1,  0);
const Vector2 ONE  = Vector2( 1,  1);
const Vector2 HALF = Vector2( 0.5f, 0.5f);

#include "Math.h"
using namespace Math;

enum Tag
{
	Default, Player, End
};

#include "Singleton.h"
#include "MainCamera.h"
#include "InputManager.h"
#include "ScheduleManager.h"
#include "SoundManager.h"
#include "Scene.h"
#include "SceneManager.h"
#include "ImageManager.h"
#include "TagCollection.h"
#include "Object.h"
#include "ObjectManager.h"

#include "Animation.h"

#include "Component.h"
#include "Transform.h"
#include "BoxCollider.h"
#include "CircleCollider.h"
#include "Renderer.h"
#include "Animator.h"