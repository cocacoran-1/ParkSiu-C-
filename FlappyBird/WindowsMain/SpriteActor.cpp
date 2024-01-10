#include "stdafx.h"
#include "SpriteActor.h"
#include "Sprite.h"
#include "Scene.h"

void SpriteActor::Init()
{
	Super::Init();
}
void SpriteActor::Render(HDC hdc)
{

	if (_sprite == nullptr) return;

	Vector2Int size = _sprite->GetSize();
	Vector2Int cameraPos = CurrentScene->GetCameraPos();
	Vector2Int screenSizeHalf = Vector2Int(WIN_SIZE_WIDTH / 2, WIN_SIZE_HEIGHT / 2);

	TransparentBlt(hdc,
		(int)(_body.x - _body.width / 2) - (cameraPos.x - screenSizeHalf.x) + (int)_offset.x,
		(int)(_body.y - _body.height / 2) - (cameraPos.y - screenSizeHalf.y) + (int)_offset.y,
		size.x,
		size.y,
		_sprite->GetDC(),
		_sprite->GetPos().x,
		_sprite->GetPos().y,
		size.x,
		size.y,
		_sprite->GetTransparent());

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