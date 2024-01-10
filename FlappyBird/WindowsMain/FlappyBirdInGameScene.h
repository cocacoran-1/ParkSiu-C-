#pragma once
#include "Scene.h"

class GdiplusSpriteActor;
class Player;
class Bird;
class FlappyBirdInGameScene : public Scene
{
	Bird* _bird;
	int _score = 500;

public:
	int GetScore() { return _score; }
	void darkenScreen(HDC hdc);
	void restoreScreen(HDC hdc);

	using Super = Scene;
public:
	virtual void Init() override;
	virtual void Render(HDC hdc) override;
	virtual void Update() override;
	virtual void Release() override;
};

