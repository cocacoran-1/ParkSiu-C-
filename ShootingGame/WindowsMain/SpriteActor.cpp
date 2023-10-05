#include "stdafx.h"
#include "SpriteActor.h"


void SpriteActor::Init()  
{
	Super::Init();
}
void SpriteActor::Render(HDC hdc)  
{
	static Gdiplus::Graphics* g = nullptr;
	static HDC lastHdc = {};

	if (lastHdc != hdc)
	{
		SAFE_DELETE(g);
		g = new Gdiplus::Graphics(hdc);
		g->SetInterpolationMode(Gdiplus::InterpolationModeNearestNeighbor);
		lastHdc = hdc;
	}
	if (_sprite)
	{
		
		g->DrawImage(_sprite, _body.ToGdiRect());
	}
	Super::Render(hdc);

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