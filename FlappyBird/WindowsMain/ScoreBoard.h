#pragma once
#include "Actor.h"
#include "FlappyBirdInGameScene.h"

class SpriteActor;
class ScoreScene;
class ScoreBoard : public Actor
{
private:
	vector<SpriteActor*> _sprites;
	int _score;
public:
	using Super = Actor;
public:
	virtual void Init();
	virtual void Render(HDC hdc);
	virtual void Update();
	virtual void Release();
};



