#include "stdafx.h"
#include "Dev1Scene.h"
#include "SpriteActor.h"
#include "Player.h"
#include "Enemy.h"


void Dev1Scene::Init()
{
	SpriteActor* _backgroundActor = new SpriteActor();
	_backgroundActor->Init();
	_backgroundActor->SetSprite(L"../Resources/background.png", Rect::MakeCenterRect(WIN_SIZE_WIDTH / 2, WIN_SIZE_HEIGHT / 2, WIN_SIZE_WIDTH, WIN_SIZE_HEIGHT));
	_actors.push_back(_backgroundActor);

	Player* _player = new Player();
	_player->Init();
	_player->SetPlayerInfo(Rect::MakeCenterRect(50, 200, 150, 150), 350, L"../Resources/player.png");
	_actors.push_back(_player);

	Enemy* _enemy = new Enemy();
	_enemy->Init();
	_enemy->SetPlayerInfo(Rect::MakeCenterRect(1050, 300, 500, 275), L"../Resources/Enemy.png");
	_actors.push_back(_enemy);

}
void Dev1Scene::Render(HDC hdc)
{
	for (int i = 0; i < _actors.size(); i++)
	{
		_actors[i]->Render(hdc);
	}
	char str[250];
	sprintf_s(str, "Dev1Scene");
	TextOutA(hdc, 0, WIN_SIZE_HEIGHT - 50, str, strlen(str));

}
void Dev1Scene::Update()
{
	for (int i = 0; i < _actors.size(); i++)
	{
		_actors[i]->Update();
	}

}
void Dev1Scene::Release()
{
	for (int i = 0; i < _actors.size(); i++)
	{
		_actors[i]->Release();
		SAFE_DELETE(_actors[i]);
	}
	_actors.clear();
}