#pragma once
#include "Collider.h"
class CircleCollider : public Collider
{
public:
	using Super = Collider;

protected:
	CenterCircle _collision;

public:
	CenterCircle GetCollision();
	void SetCollision(CenterCircle collision) { _collision = collision; }

public:
	virtual void Init() override;
	virtual void Render(HDC hdc) override;
	virtual void Update() override;
	virtual void Release() override;

public:
	//other�� ���� collider�� �浹�ϸ� true �߻�.
	virtual bool CheckCollision(Collider* other);

public:
	CircleCollider();
	virtual ~CircleCollider();
};

