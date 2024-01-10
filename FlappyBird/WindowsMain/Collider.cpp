#include "stdafx.h"
#include "Collider.h"


void Collider::Init()
{
	GET_SINGLE(CollisionManager)->AddCollider(this);
}
void Collider::Render(HDC hdc)
{
}
void Collider::Update()
{

}
void Collider::Release()
{
	GET_SINGLE(CollisionManager)->RemoveCollider(this);
}
bool Collider::CheckCollision(Collider* other)
{
	//레이어 검사

	//나 => Other
	uint8 otherLayer = other->GetCollisionLayer();
	if (_collisionFlag & (1 << otherLayer))
	{
		//Other => 나
		uint8 myLayer = this->GetCollisionLayer();
		if (other->GetCollisionFlag() & (1 << myLayer))
		{
			return true;
		}
	}


	return false;
}


void Collider::AddCollisionFlagLayer(CollsionLayerType layer)
{
	// layer = CLT_WALL(2)

	//_flag = 0b000001
	//==> 해당 자릿수(layer)의 플래그만 1로 켜준다.
	//_flag = 0b000101

	_collisionFlag |= (1 << layer);

}
void Collider::RemoveCollisionFlagLayer(CollsionLayerType layer)
{
	// layer = CLT_WALL(2)

	//_flag = 0b000111
	//==> 해당 자릿수(layer)의 플래그만 0으로 꺼준다.
	//_flag = 0b000011
	_collisionFlag &= ~(1 << layer);
}