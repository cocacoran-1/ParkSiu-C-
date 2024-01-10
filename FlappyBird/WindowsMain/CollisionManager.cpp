#include "stdafx.h"
#include "CollisionManager.h"
#include "Collider.h"
#include "Actor.h"
void CollisionManager::Init()
{
}

void CollisionManager::Update()
{
	//�������� �浹ó��!!
	
	//
	// ��� Collider�� �ѹ��� ���Ѵ�. (CheckCollision)
	// �浹�Ǿ�����, �浹Map�� �־��ش�. (�Լ�����!)
	// �浹 �ȵǾ�����, �浹Map���� �ִٸ� �����ش�. (�Լ�����!)
	//	* �浹�� : _collisionMap
	// 

	//_colliders
	for (int i = 0; i < _colliders.size(); i++)
	{
		Collider* c1 = _colliders[i];
		if (c1->GetOwner()->GetActive() == false) continue;

		for (int j = i + 1; j < _colliders.size(); j++)
		{
			Collider* c2 = _colliders[j];
			if (c2->GetOwner()->GetActive() == false) continue;

			//�浹 �Ǿ�����.
			if (c1->CheckCollision(c2))
			{
				//�浹Map�� �־��ش�
				// �̹� c1�� c2�� �浹�ؼ�, �浹�ʿ� ���ٸ�
				if (false == c1->_collisionMap.contains(c2))
				{
					//�Լ�����!
					c1->GetOwner()->OnComponentBeginOverlap(c1, c2);
					c2->GetOwner()->OnComponentBeginOverlap(c2, c1);
					c1->_collisionMap.insert(c2);
					c2->_collisionMap.insert(c1);
				}
			}
			else
			{
				//�浹�ʿ� �ִµ�, �浹�� �ȵȻ���!
				if (c1->_collisionMap.contains(c2))
				{
					c1->GetOwner()->OnComponentEndOverlap(c1, c2);
					c2->GetOwner()->OnComponentEndOverlap(c2, c1);
					c1->_collisionMap.erase(c2);
					c2->_collisionMap.erase(c1);
				}
			}
		}
	}

}

void CollisionManager::AddCollider(Collider* collider)
{
	_colliders.push_back(collider);
}

void CollisionManager::RemoveCollider(Collider* collider)
{
	auto findIt = find(_colliders.begin(), _colliders.end(), collider);

	if (findIt != _colliders.end())
	{
		_colliders.erase(findIt);
	}
}
