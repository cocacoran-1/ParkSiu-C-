#include "stdafx.h"
#include "Bullet.h"

void Bullet::Init()
{
	//�θ�Ŭ���� �⺻���� ó��
	Super::Init();
	this->SetName("Bullet");
}
void Bullet::Render(HDC hdc)
{
	if (_isActive == false) return;
	//�θ�Ŭ���� �⺻���� ó��
	Super::Render(hdc);

}
void Bullet::Update()
{
	if (_isActive == false) return;
	//�θ�Ŭ���� �⺻���� ó��
	Super::Update();

	this->Move();
}
void Bullet::Release()
{
	//�θ�Ŭ���� �⺻���� ó��
	Super::Release();

}

void Bullet::Move()
{
	_direction.Normalize();
	this->_body.x += _direction.x * DeltaTime * _speed;
	this->_body.y += _direction.y * DeltaTime * _speed;
}

void Bullet::SetBulletInfo(Vector2 direction, float speed, Vector2 spawnPos)
{
	_direction = direction;
	_speed = speed;
	_body = Shape::MakeCenterRect(spawnPos.x, spawnPos.y, 100, 100);
	this->SetSprite(L"../Resources/Power Ups/Power Up.png", _body);
}