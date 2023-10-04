#include "stdafx.h"
#include "SpriteActor.h"


void SpriteActor::Init()  
{
	Super::Init();
}
void SpriteActor::Render(HDC hdc)  
{
	Super::Render(hdc);
	if (_sprite)
	{
		Gdiplus::Graphics g(hdc);
		g.DrawImage(_sprite, _body.ToGdiRect());
	}
}
void SpriteActor::Update()  
{
	Super::Update();

}
void SpriteActor::Release()  
{
	Super::Release();

}

void SpriteActor::SetSprite(const WCHAR* filePath, CenterRect body)
{
	_sprite = Gdiplus::Image::FromFile(filePath);
	_body = body;
}