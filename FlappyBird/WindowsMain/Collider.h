#pragma once
#include "Component.h"
class Collider : public Component
{
protected:
	ColliderType _colliderType = ColliderType::None;
	//����׿����� �浹���� �׸��� �׷��ٰ��ΰ�.
	bool _showDebug
#if _DEBUG
		= true;
#else 
		= false;
#endif

	//���� ��������?
	CollsionLayerType _collisionLayer = CLT_OBJECT;
	//������ �浹�Ұ���?
	uint32 _collisionFlag = ~0;	//0xFFFFFFFF;

public: // �����ӿ�ũ�ܿ� ����� ����
	unordered_set<Collider*> _collisionMap;

public:
	using Super = Component;

public:
	virtual void Init() override;
	virtual void Render(HDC hdc) override;
	virtual void Update() override;
	virtual void Release() override;

public:
	//other�� ���� collider�� �浹�ϸ� true �߻�.
	virtual bool CheckCollision(Collider* other);
	ColliderType GetColliderType() { return _colliderType; }


public:
	CollsionLayerType GetCollisionLayer() { return _collisionLayer; }
	void SetCollisionLayer(CollsionLayerType collisionLayer) { _collisionLayer = collisionLayer; }

	uint32 GetCollisionFlag() { return _collisionFlag; }
	void SetCollisionFlag(uint32 flag) { _collisionFlag = flag; }
	void ResetCollisionFlag() { _collisionFlag = 0; }
	void AddCollisionFlagLayer(CollsionLayerType layer);
	void RemoveCollisionFlagLayer(CollsionLayerType layer);

public:
	Collider(ColliderType colliderType) { _colliderType = colliderType; }
	virtual ~Collider() {}
};

