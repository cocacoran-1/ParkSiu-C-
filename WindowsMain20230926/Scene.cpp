#include "stdafx.h"
#include "Scene.h"

void Scene::Init()
{
	_player = Rect::MakeCenterRect(100, 100, 100, 100);
	_speed = 300;
}
void Scene::Render(HDC hdc)
{
	Draw::Rect(hdc, _player);

	for (int i = 0; i < _projectiles.size(); i++)
	{
		_projectiles[i]->Render(hdc);
	}

}
void Scene::Update()
{
	//1초동안 움직이는 거리  : 10
	//이전 Update ~ 현재 Update까지의 걸린시간  : GET_SINGLE(TimeManager)->GetDeltaTime()

	//우리가 현재 얼마나 움직여야할까?

	//1 : _speed = GET_SINGLE(TimeManager)->GetDeltaTime() : ????
	//???? = _speed * GET_SINGLE(TimeManager)->GetDeltaTime();


	cout << _speed * GET_SINGLE(TimeManager)->GetDeltaTime() << endl;

	if(GET_SINGLE(KeyManager)->GetKey(VK_UP))
	{
		_player.y -= _speed * GET_SINGLE(TimeManager)->GetDeltaTime();
	}
	if (GET_SINGLE(KeyManager)->GetKey(VK_LEFT))
	{
		_player.x -= _speed * GET_SINGLE(TimeManager)->GetDeltaTime();
	}
	if (GET_SINGLE(KeyManager)->GetKey(VK_RIGHT))
	{
		_player.x += _speed * GET_SINGLE(TimeManager)->GetDeltaTime();
	}
	if (GET_SINGLE(KeyManager)->GetKey(VK_DOWN))
	{
		_player.y += _speed * GET_SINGLE(TimeManager)->GetDeltaTime();
	}

	//피타고라스 
	//(루트) : std::sqrt()


	if (GET_SINGLE(KeyManager)->GetKeyDown(VK_SPACE))
	{
		Projectile* projectile = new Projectile();
		Vector2 spawnPos = { _player.x, _player.y };
		//Target -> MousePosition
		Vector2 mousePostion = { _mousePos.x, _mousePos.y };
		Vector2 direction = mousePostion - spawnPos;
		// 정규화
		//벡터의 길이를 1로 만들어주는
		direction.Normalize();

		projectile->Init(spawnPos, direction);
		_projectiles.push_back(projectile);
	}

	for (int i = 0; i < _projectiles.size(); i++)
	{
		_projectiles[i]->Update();
	}

}
void Scene::Release()
{
	for (int i = 0; i < _projectiles.size(); i++)
	{
		SAFE_DELETE(_projectiles[i]);
	}
	_projectiles.clear();
}

void Projectile::Init(Vector2 spawnPos, Vector2 direction)
{
	_body = Rect::MakeCenterRect(spawnPos.x, spawnPos.y, 30, 30);
	_speed = 400;
	_direction = direction;
}

void Projectile::Update()
{
	float deltaTime = DeltaTime;
	_body.x += _direction.x * deltaTime * _speed;
	_body.y += _direction.y * deltaTime * _speed;
}


void Projectile::Render(HDC hdc)
{
	Draw::Rect(hdc, _body);
}
void Projectile::Release()
{

}