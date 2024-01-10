#include "stdafx.h"
#include "CameraComponent.h"
#include "Scene.h"
#include "Actor.h"
CameraComponent::CameraComponent()
{

}
CameraComponent::~CameraComponent()
{

}

void CameraComponent::Init()
{
	Super::Init();

	_originPos = CurrentScene->GetCameraPos();
	_sumTime = 0.0f;
}
void CameraComponent::Render(HDC hdc)
{
	Super::Render(hdc);
}
void CameraComponent::Update()
{
	Super::Update();

	Actor* owner = this->GetOwner();
	if (owner)
	{
		Vector2 startPos = _originPos;
		Vector2 endPos = owner->GetBody().Position();
		_sumTime += DeltaTime;

		Vector2 pos = Vector2::Lerp(startPos, endPos, DeltaTime * 10);
		_originPos = pos;

		pos.x = clamp<float>(pos.x, WIN_SIZE_WIDTH / 2, 2048 - WIN_SIZE_WIDTH / 2);
		pos.y = clamp<float>(pos.y, WIN_SIZE_HEIGHT / 2, 2048 - WIN_SIZE_HEIGHT / 2);

		Vector2Int newCameraPos = pos;


		CurrentScene->SetCameraPos(newCameraPos);
		_sumTime = 0.0f;
	}
}

void CameraComponent::Release()
{
	Super::Release();
}

