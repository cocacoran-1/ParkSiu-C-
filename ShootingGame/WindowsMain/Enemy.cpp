#include "stdafx.h"
#include "Enemy.h"

void Enemy::Init()
{
	Super::Init();
	_body = Rect::MakeCenterRect(500, 400, 700, 500);
	this->SetSprite(L"../Resources/Enemy.png", _body);
}
void Enemy::Render(HDC hdc)
{
	Super::Render(hdc);
	if (_sprite)
	{
		Gdiplus::Graphics g(hdc);
		g.DrawImage(_sprite, _body.ToGdiRect());
	}
}
void Enemy::Update()
{
	Super::Update();

	
}
void Enemy::Release()
{
	Super::Release();

}


void Enemy::SetPlayerInfo(CenterRect body, const WCHAR* spritePath)
{
	_body = body;
	this->SetSprite(spritePath, _body);
}

