#pragma once
#include "FlipbookActor.h"

enum ePlayerDirection : int {
	RIGHT,
	LEFT,
	END
};

enum class eWallDirection : int {
	UP,
	RIGHT,
	LEFT,
	DOWN,
	NONE
};

enum class ePlayerState
{
	Idle,
	Move,
	JumpFall,

	End
};

class Player : public FlipbookActor
{
private:
	float _speed;
	float _gravity;
	Vector2 _velocity;


	Flipbook* _idleFlipbook[ePlayerDirection::END] = {};
	Flipbook* _moveFlipbook[ePlayerDirection::END] = {};
	Flipbook* _attackFlipbook[ePlayerDirection::END] = {};
	Flipbook* _hitFlipbook[ePlayerDirection::END] = {};


	Vector2 _direction = {};
	ePlayerDirection _dir = ePlayerDirection::RIGHT;
	ePlayerState _state = ePlayerState::Idle;
	bool _isAttackFlag = false;
	bool _isHitFlag = false;
public:
	void Move(Vector2 direction);

public:
	void SetPlayerInfo(CenterRect body, float speed);

	void SetState(ePlayerState state);
	ePlayerState GetState() { return _state; }

	bool CanChangeDirection();
	bool CanJump();

public:
	using Super = FlipbookActor;
public:
	virtual void Init() override;
	virtual void Render(HDC hdc) override;
	virtual void Update() override;
	virtual void Release() override;

public:
	void UpdateInput();
	void UpdateMove();
	void UpdateIdle();
	void UpdateJumpFall();
	void UpdateGravity();
public:

	virtual void OnComponentBeginOverlap(Collider* collider, Collider* other) override;
	virtual void OnComponentEndOverlap(Collider* collider, Collider* other) override;

public:
	eWallDirection AdjustPosition(Collider* collider, Collider* other);
};

