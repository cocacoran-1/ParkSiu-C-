#include "stdafx.h"
#include "FlipbookActor.h"
#include "Flipbook.h"
#include "Texture.h"
#include "Scene.h"


void FlipbookActor::Init()
{
	Super::Init();
}
void FlipbookActor::Render(HDC hdc)
{

	const FlipbookInfo& info = _flipbook->GetInfo();

	Vector2Int cameraPos = CurrentScene->GetCameraPos();
	Vector2Int screenSizeHalf = Vector2Int(WIN_SIZE_WIDTH / 2, WIN_SIZE_HEIGHT / 2);

	TransparentBlt(hdc,
		(int)(_body.x - info.size.x / 2) - (cameraPos.x - screenSizeHalf.x),
		(int)(_body.y - info.size.y / 2) - (cameraPos.y - screenSizeHalf.y),
		info.size.x,
		info.size.y,
		info.texture->GetDC(),
		(_index)*info.size.x,
		(info.line) * info.size.y,
		info.size.x,
		info.size.y,
		info.texture->GetTransparent());
	Super::Render(hdc);
}
void FlipbookActor::Update()
{
	Super::Update();

	if (_flipbook == nullptr)
	{
		return;
	}

	const FlipbookInfo& info = _flipbook->GetInfo();
	_sumTime += DeltaTime;

	int frameAmount = (info.end - info.start + 1);
	float delta = info.duration / frameAmount;

	if (delta <= _sumTime)
	{
		if (false == (info.loop == false && _index == info.end))
		{
			_sumTime -= delta;
			_index++;
			_index %= frameAmount + info.start;
		}
	}

}
void FlipbookActor::Release()
{
	Super::Release();
}
void FlipbookActor::Reset()
{
	_sumTime = 0.0f;
	_index = 0;
}

void FlipbookActor::SetFlipbook(Flipbook* flipbook)
{
	if (!flipbook)  return;
	if (_flipbook == flipbook) return;

	_flipbook = flipbook;
	Reset();
}