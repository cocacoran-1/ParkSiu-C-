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
	//1�ʵ��� �����̴� �Ÿ�  : 10
	//���� Update ~ ���� Update������ �ɸ��ð�  : GET_SINGLE(TimeManager)->GetDeltaTime()

	//�츮�� ���� �󸶳� ���������ұ�?

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

	//��Ÿ��� 
	//(��Ʈ) : std::sqrt()


	if (GET_SINGLE(KeyManager)->GetKeyDown(VK_SPACE))
	{
		Projectile* projectile = new Projectile();
		Vector2 spawnPos = { _player.x, _player.y };
		//Target -> MousePosition
		Vector2 mousePostion = { _mousePos.x, _mousePos.y };
		Vector2 direction = mousePostion - spawnPos;
		// ����ȭ
		//������ ���̸� 1�� ������ִ�
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