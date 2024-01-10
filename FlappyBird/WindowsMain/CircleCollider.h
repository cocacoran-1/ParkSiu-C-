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
	//other와 현재 collider가 충돌하면 true 발생.
	virtual bool CheckCollision(Collider* other);

public:
	CircleCollider();
	virtual ~CircleCollider();
};

