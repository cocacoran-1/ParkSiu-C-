#pragma once
class Scene
{
private:
	CenterRect _player;
	vector<class Projectile*> _projectiles;
	float _speed;

public:
	void Init();
	void Render(HDC hdc);
	void Update();
	void Release();
};


class Projectile
{
	CenterRect _body;	//그려줄 좌표
	float _speed;		//속도
	Vector2 _direction;	//어디로 날라갈건지에 대한 방향벡터

public:
	void Init(Vector2 spawnPos, Vector2 direction);
	void Update();
	void Render(HDC hdc);
	void Release();
};

