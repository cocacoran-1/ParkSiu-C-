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
	CenterRect _body;	//�׷��� ��ǥ
	float _speed;		//�ӵ�
	Vector2 _direction;	//���� ���󰥰����� ���� ���⺤��

public:
	void Init(Vector2 spawnPos, Vector2 direction);
	void Update();
	void Render(HDC hdc);
	void Release();
};

