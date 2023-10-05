#pragma once
#include "Scene.h"

class SpriteActor;
class Player;
class Dev1Scene : public Scene
{

private:
	vector<class Enemy*> _enemies;
	Player* _player;

public:
	virtual void OnCollisionEnemyBullet();
public:
	virtual void Init() override;
	virtual void Render(HDC hdc) override;
	virtual void Update() override;

	virtual void Release() override;
};

