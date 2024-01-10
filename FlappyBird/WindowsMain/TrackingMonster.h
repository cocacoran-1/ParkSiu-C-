#pragma once
#include "GdiplusSpriteActor.h"
class Actor;
class TrackingMonster : public GdiplusSpriteActor
{
protected:
	Vector2 _direction;
	Vector2 _originDirection;
	float _speed;
	float _trackingRadian;
	Vector2 _originPos;

	Actor* _targetActor = nullptr;
public:
	void SetTrackingMonsterInfo(float trackingDegree, float speed, Vector2 spawnPos, Vector2 direction);
	void SetTargetActor(Actor* targetActor) { _targetActor = targetActor; }
	bool IsInTrackingRange();
public:
	using Super = GdiplusSpriteActor;
public:
	virtual void Init() override;
	virtual void Render(HDC hdc) override;
	virtual void Update() override;
	virtual void Release() override;
};

