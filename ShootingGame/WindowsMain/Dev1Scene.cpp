#include "stdafx.h"
#include "Dev1Scene.h"
#include "SpriteActor.h"
#include "Player.h"
#include "Enemy.h"
#include "Bullet.h"
#include "Collider.h"
#include "BoxCollider.h"



void Dev1Scene::Init()
{
	SpriteActor* _backgroundActor = new SpriteActor();
	_backgroundActor->Init();
	_backgroundActor->SetSprite(L"../Resources/background.png", Rect::MakeCenterRect(WIN_SIZE_WIDTH / 2, WIN_SIZE_HEIGHT / 2, WIN_SIZE_WIDTH, WIN_SIZE_HEIGHT));
	_actors.push_back(_backgroundActor);

	{
		Player* player = new Player();
		player->SetPlayerInfo(Rect::MakeCenterRect(50, 200, 150, 150), 350, L"../Resources/player.png");
		{
			// 컴포넌트 추가
			BoxCollider* collider = new BoxCollider();
			collider->SetCollision(Rect::MakeCenterRect(0, 0, 200, 200));
			player->AddComponent(collider);
			player->SetName("Player");
		}
		this->SpawnActor(player);
		_actors.push_back(player);
	}

	Enemy* enemy = new Enemy();
	enemy->Init();
	_enemies.push_back(enemy);
	enemy->SetPlayerInfo(Rect::MakeCenterRect(1050, 300, 500, 275), L"../Resources/Enemy.png");
	_actors.push_back(enemy);

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
	/*this->OnCollisionEnemyBullet();*/
}

//void Dev1Scene::OnCollisionEnemyBullet()
//{
//	for (int i = 0; i < _enemies.size(); i++)
//	{
//		for (int j = 0; j < _player->GetBullet().size(); j++)
//		{
//			CenterRect enemyCollision = _enemies[i]->GetCollision();
//			CenterRect bulletCollision = _player->GetBullet()[i]->GetCollision();
//
//			if (Collision::RectInRect(enemyCollision, bulletCollision))
//			{
//				_enemies[i]->Release();
//				SAFE_DELETE(_enemies[i]);
//
//				_enemies.erase(_enemies.begin() + i);
//				_player->RemoveBullet(j);
//				return;
//			}
//		}
//	}
//}

void Dev1Scene::Release()
{
	for (int i = 0; i < _actors.size(); i++)
	{
		_actors[i]->Release();
		SAFE_DELETE(_actors[i]);
	}

	_actors.clear();
}