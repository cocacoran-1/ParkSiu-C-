#pragma once
#include "FlipbookActor.h"

enum class eBirdDirection
{
	Up,
	Normal,
	Down,

	End
};


class Bird : public FlipbookActor
{
private:
	Flipbook* _flipbook[(int)eBirdDirection::End] = {};
	float _gravity = 0;
	float _jumpPower = 0;
	Vector2 _velocity = { 10,0 };
	int _score = 500;
	Vector2 _endPos;
	float _speed = 100;
	bool _pushBack = false;
	bool _sceneChange = false;
	bool _isDead = false;

public:
	bool GetIsDead() { return _isDead; }
	int GetScore() { return _score; }
public:
	void SetBird(float gravity, float jumpPower);

public:
	void HandleTrigger_Obstacle(Collider* collider, Collider* other);
	void HandleTrigger_Score(Collider* collider, Collider* other);
	void HandleTrigger_Land(Collider* collider, Collider* other);


public:
	virtual void OnComponentBeginOverlap(Collider* collider, Collider* other) override;
	virtual void OnComponentEndOverlap(Collider* collider, Collider* other) override;

public:
	using Super = FlipbookActor;
public:
	virtual void Init() override;
	virtual void Render(HDC hdc) override;
	virtual void Update() override;
	virtual void Release() override;
};

