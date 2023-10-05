#include "stdafx.h"
#include "BoxCollider.h"
#include "Actor.h"

CenterRect BoxCollider::GetCollision()
{
	CenterRect body = this->GetOwner()->GetBody();
	CenterRect wordCollision = Rect::MakeCenterRect(body.x + _collision.x, body.y + _collision.y, _collision.width, _collision.height);

	return wordCollision;
}

void BoxCollider::Init()
{
	Super::Init();
}

void BoxCollider::Render(HDC hdc)
{
	Super::Render(hdc);
	CenterRect body = this->GetOwner()->GetBody();
	CenterRect drawCollision = Rect::MakeCenterRect(body.x + _collision.x, body.y + _collision.y, _collision.width, _collision.height);

	HBRUSH emptyBrush = GetStockBrush(NULL_BRUSH);
	HBRUSH oldBrush = (HBRUSH)SelectObject(hdc, emptyBrush);
	Draw::Rect(hdc,this->GetCollision());
	SelectObject(hdc, oldBrush);
	DeleteObject(emptyBrush);
}

void BoxCollider::Update()
{
	Super::Update();

}

void BoxCollider::Release()
{
	Super::Release();

}

bool BoxCollider::CheckCollision(Collider* other)
{
	switch (other->GetColliderType())
	{
	case ColliderType::Circle:
		break;
	case ColliderType::Box:
		BoxCollider* otherCollider = static_cast<BoxCollider*>(other);
		CenterRect otherCollision = otherCollider->GetCollision();
		return Collision::RectInRect(_collision, otherCollision);
		break;
	
	}
	return false;
}

BoxCollider::BoxCollider() : Collider(ColliderType::Box)
{
	_collision = {};
}

BoxCollider::~BoxCollider()
{
}
