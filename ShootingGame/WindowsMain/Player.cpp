#include "stdafx.h"
#include "Player.h"
#include "Scene.h"
#include "Bullet.h"
#include "BoxCollider.h"


void Player::Init()
{
	Super::Init();
	_level = 0;
	_body = Rect::MakeCenterRect(50, 200, 150, 150);
	this->SetSprite(L"../Resources/player.png", _body);
}
void Player::Render(HDC hdc)
{
	Super::Render(hdc);
}
void Player::Update()
{
	Super::Update();

	Vector2 direction = {};
	if (GET_SINGLE(KeyManager)->GetKey('W'))
	{
		direction = direction + Vector2(0, -1);
	}
	if (GET_SINGLE(KeyManager)->GetKey('A'))
	{
		direction = direction + Vector2(-1, 0);
	}
	if (GET_SINGLE(KeyManager)->GetKey('S'))
	{
		direction = direction + Vector2(0, 1);
	}
	if (GET_SINGLE(KeyManager)->GetKey('D'))
	{
		direction = direction + Vector2(1, 0);
	}
	if (GET_SINGLE(KeyManager)->GetKeyDown('U'))
	{
		_level++;
		if (_level >= 2)
		{
			_level = 2;
		}
	}
	if (GET_SINGLE(KeyManager)->GetKeyDown(VK_SPACE))
	{
		for (int i = 0; i <= _level; i++)
		{
			Bullet* playerBullet = new Bullet();
			playerBullet->Init();
			_bullet.push_back(playerBullet);
			if (_level < 2)
			{
				playerBullet->SetBulletInfo(Vector2(1, 0), 600, Vector2(_body.x, _body.y - _level * 20 + i * 35));
				{
					BoxCollider* collider = new BoxCollider();
					collider->SetCollision(Rect::MakeCenterRect(0, 0, 200, 200));
					playerBullet->AddComponent(collider);
				}
			}
			else
			{
				int x = (i % 2) * 25;
				playerBullet->SetBulletInfo(Vector2(1, 0), 600, Vector2(_body.x + x, _body.y - _level * 20 + i * 35));
				{
					BoxCollider* collider = new BoxCollider();
					collider->SetCollision(Rect::MakeCenterRect(0, 0, 200, 200));
					playerBullet->AddComponent(collider);
				}
			}

			GET_SINGLE(SceneManager)->GetCurrentScene()->SpawnActor(playerBullet);
		}
	}
	if (GET_SINGLE(KeyManager)->GetKeyDown('J'))
	{
		for (int i = 0; i < 10; i++)
		{
			Bullet* playerBullet = new Bullet();
			playerBullet->Init();
			_bullet.push_back(playerBullet);

			playerBullet->SetBulletInfo(Vector2(1, 0), 600, Vector2(_body.x + i * 20, _body.y - 50 + ((i % 2) + 1) * 35));
			GET_SINGLE(SceneManager)->GetCurrentScene()->SpawnActor(playerBullet);
		}

	}
	if (GET_SINGLE(KeyManager)->GetKeyDown('K'))
	{
		int numBullets = 36;
		float bulletSpacing = 360.0f / numBullets;

		for (int i = 0; i < numBullets; i++)
		{
			
			float angle = i * (2 * 3.14 / numBullets);  
			Vector2 direction(cos(angle), sin(angle));

			Bullet* playerBullet = new Bullet();
			playerBullet->Init();
			_bullet.push_back(playerBullet);
			playerBullet->SetBulletInfo(direction, 600, Vector2(_body.x, _body.y));
			GET_SINGLE(SceneManager)->GetCurrentScene()->SpawnActor(playerBullet);
		}
	}

	direction.Normalize();
	this->Move(direction);

}
void Player::Release()
{
	Super::Release();
	for (int i = 0; i < _bullet.size(); i++)
	{
		_bullet[i]->Release();
		SAFE_DELETE(_bullet[i]);
	}
}

void Player::Move(Vector2 direction)
{
	direction.Normalize();
	this->_body.x += direction.x * _speed * DeltaTime;
	this->_body.y += direction.y * _speed * DeltaTime;
}

void Player::SetPlayerInfo(CenterRect body, float speed, const WCHAR* spritePath)
{
	_body = body;
	_speed = speed;
	this->SetSprite(spritePath, _body);
}

//void Player::RemoveBullet(int index)
//{
//	_bullet[index]->Release();
//	SAFE_DELETE(_bullet[index]);
//	_bullet.erase(_bullet.begin() + index);
//}
