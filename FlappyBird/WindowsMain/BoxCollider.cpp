#include "stdafx.h"
#include "BoxCollider.h"
#include "Actor.h"
#include "Scene.h"
#include "CircleCollider.h"

void BoxCollider::Init()
{
    Super::Init();
}

void BoxCollider::Render(HDC hdc)
{
    Super::Render(hdc);
    if (_showDebug == false) return;

    HBRUSH emptyBrush = GetStockBrush(NULL_BRUSH);
    HBRUSH oldBrush = (HBRUSH)SelectObject(hdc, emptyBrush);
    CenterRect renderRect = this->GetCollision();
    Vector2Int cameraPos = CurrentScene->GetCameraPos();
    Vector2Int screenSizeHalf = Vector2Int(WIN_SIZE_WIDTH / 2, WIN_SIZE_HEIGHT / 2);

    renderRect.x = static_cast<float>(renderRect.x - (cameraPos.x - screenSizeHalf.x));
    renderRect.y = static_cast<float>(renderRect.y - (cameraPos.y - screenSizeHalf.y));

    Draw::Rect(hdc, renderRect);
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
    if (Super::CheckCollision(other) == false)
    {
        return false;
    }

    switch (other->GetColliderType())
    {
    case ColliderType::Circle:
    {
        CircleCollider* otherCollider = static_cast<CircleCollider*>(other);
        CenterCircle otherCollision = otherCollider->GetCollision();
        return Collision::RectInCircle(this->GetCollision(), otherCollision);
        break;
    }
    case ColliderType::Box:
    {
        BoxCollider* otherCollider = static_cast<BoxCollider*>(other);
        CenterRect otherCollision = otherCollider->GetCollision();
        return Collision::RectInRect(this->GetCollision(), otherCollision);
    }
    }


    return false;
}

CenterRect BoxCollider::GetCollision()
{
    CenterRect body = this->GetOwner()->GetBody();
    CenterRect worldCollision = Shape::MakeCenterRect(body.x + _collision.x, body.y + _collision.y, _collision.width, _collision.height);

    return worldCollision;
}

BoxCollider::BoxCollider() : Collider(ColliderType::Box)
{
    _collision = {};
}

BoxCollider::~BoxCollider()
{
}
