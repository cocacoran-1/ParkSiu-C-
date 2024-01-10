#include "stdafx.h"
#include "CircleCollider.h"
#include "Actor.h"
#include "Scene.h"
#include "BoxCollider.h"

CircleCollider::CircleCollider() : Collider(ColliderType::Circle)
{

}
CircleCollider::~CircleCollider()
{

}
void CircleCollider::Init()
{
	Super::Init();
}
void CircleCollider::Render(HDC hdc)
{
    Super::Render(hdc);
    if (_showDebug == false) return;

    HBRUSH emptyBrush = GetStockBrush(NULL_BRUSH);
    HBRUSH oldBrush = (HBRUSH)SelectObject(hdc, emptyBrush);
    CenterRect renderRect = this->GetCollision().ToCenterRect();
    Vector2Int cameraPos = CurrentScene->GetCameraPos();
    Vector2Int screenSizeHalf = Vector2Int(WIN_SIZE_WIDTH / 2, WIN_SIZE_HEIGHT / 2);

    renderRect.x = static_cast<float>(renderRect.x - (cameraPos.x - screenSizeHalf.x));
    renderRect.y = static_cast<float>(renderRect.y - (cameraPos.y - screenSizeHalf.y));

    Draw::Circle(hdc, renderRect);
    SelectObject(hdc, oldBrush);
    DeleteObject(emptyBrush);
}
void CircleCollider::Update()
{

}
void CircleCollider::Release()
{

}

bool CircleCollider::CheckCollision(Collider* other)
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
        return Collision::CircleInCircle(this->GetCollision(), otherCollision);
    }
        break;

    case ColliderType::Box:
    {
        BoxCollider* otherCollider = static_cast<BoxCollider*>(other);
        CenterRect otherCollision = otherCollider->GetCollision();
        return Collision::RectInCircle(otherCollision, this->GetCollision());
        break;
    }
    }


    return false;
}
CenterCircle CircleCollider::GetCollision()
{
    CenterRect body = this->GetOwner()->GetBody();
    CenterCircle worldCollision = {
        Vector2(_collision.center.x + body.x, _collision.center.y + body.y),
        _collision.radius
    };

    return worldCollision;
}
