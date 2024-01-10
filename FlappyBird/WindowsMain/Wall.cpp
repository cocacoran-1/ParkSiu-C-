#include "stdafx.h"
#include "Wall.h"
#include "BoxCollider.h"
#include "Scene.h"

void Wall::Init()
{
	Super::Init();
}
void Wall::Render(HDC hdc)
{
	Super::Render(hdc);
#if _DEBUG
	Vector2Int cameraPos = CurrentScene->GetCameraPos();
	Draw::Rect(hdc, this->GetBody().ToRect(), cameraPos);
#endif
}
void Wall::Update()
{
	Super::Update();
}
void Wall::Release()
{
	Super::Release();
}

void Wall::SetWallInfo(RECT rc)
{
	CenterRect cr = CenterRect::FromRect(rc);
	this->SetBody(cr);

	//콜리더 추가
	BoxCollider* collider = new BoxCollider();
	collider->SetCollision(Shape::MakeCenterRect(0, 0, cr.width, cr.height));
	collider->SetCollisionLayer(CollsionLayerType::CLT_WALL);
	this->AddComponent(collider);
}

void Wall::OnComponentBeginOverlap(Collider* collider, Collider* other)
{
	cout << "충돌" << endl;
}
void Wall::OnComponentEndOverlap(Collider* collider, Collider* other)
{

}