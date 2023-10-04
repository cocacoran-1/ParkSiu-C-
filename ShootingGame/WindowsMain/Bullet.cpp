#include "stdafx.h"
#include "Bullet.h"


void Bullet::Init()
{
	Super::Init();
	_body = Rect::MakeCenterRect(50, 200, 150, 150);
	this->SetSprite(L"../Resources/player.png", _body);
}
void Bullet::Render(HDC hdc)
{
	Super::Render(hdc);
	if (_sprite)
	{
		Gdiplus::Graphics g(hdc);
		g.DrawImage(_sprite, _body.ToGdiRect());
	}
}
void Bullet::Update()
{
	Super::Update();

	this->Move();

}
void Bullet::Release()
{
	Super::Release();

}
void Bullet::Move()
{
	_direction.Normalize();
	this->_body.x += _direction.x * _speed * DeltaTime;
	this->_body.y += _direction.y * _speed * DeltaTime;

}
void Bullet::SetBulletInfo(Vector2 direction,float speed,Vector2 spawnPos)
{
	_direction = direction;
	_speed = speed;
	_body = Rect::MakeCenterRect(spawnPos.x, spawnPos.y, 50, 50);
	this->SetSprite(L"../Resources/Bullet.png", _body);
}
