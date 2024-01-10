#include "stdafx.h"
#include "Player.h"
#include "Scene.h"
#include "Bullet.h"
#include "BoxCollider.h"
#include "Flipbook.h"

void Player::Init()
{
	//부모클래스 기본적인 처리
	Super::Init();


	this->SetName("Player");
	_dir = ePlayerDirection::RIGHT;
	this->SetState(ePlayerState::JumpFall);
}
void Player::Render(HDC hdc)
{
	if (_isActive == false) return;
	//부모클래스 기본적인 처리
	Super::Render(hdc);

}
void Player::Update()
{
	if (_isActive == false) return;
	//부모클래스 기본적인 처리
	Super::Update();

	UpdateInput();
	UpdateGravity();

	switch (_state)
	{
	case ePlayerState::Idle:
		this->UpdateIdle();
		break;
	case ePlayerState::Move:
		this->UpdateMove();
		break;
	case ePlayerState::JumpFall:
		this->UpdateJumpFall();
		break;
	case ePlayerState::End:
		Alert("Player State Error", "currentState : End");
		break;
	default:
		break;
	}
}
void Player::Release()
{
	//부모클래스 기본적인 처리
	Super::Release();

}

void Player::OnComponentBeginOverlap(Collider* collider, Collider* other)
{
	//벽과 충돌되었으면
	//왔던방향으로 다시 밀린다.
	if (other->GetCollisionLayer() == CollsionLayerType::CLT_WALL)
	{
		eWallDirection dir = AdjustPosition(collider, other);
		if (dir == eWallDirection::UP)
		{
			_velocity.y = 0;
			this->SetState(ePlayerState::Idle);
		}
	}

}

eWallDirection Player::AdjustPosition(Collider* collider, Collider* other)
{
	eWallDirection rv = eWallDirection::NONE;
	BoxCollider* b1 = dynamic_cast<BoxCollider*>(collider);
	BoxCollider* b2 = dynamic_cast<BoxCollider*>(other);

	CenterRect body = this->GetBody();
	Vector2 pos = body.Position();
	if (b1 != nullptr && b2 != nullptr)
	{
		RECT r1 = b1->GetCollision().ToRect();
		RECT r2 = b2->GetCollision().ToRect();

		RECT intersect = {};
		if (::IntersectRect(&intersect, &r1, &r2))
		{
			int width = intersect.right - intersect.left;
			int height = intersect.bottom - intersect.top;

			//가로가 더길면 세로방향으로 밀쳐내야한다.
			if (width > height)
			{
				// 위에서 떨어졌다.
				if (intersect.bottom == r1.bottom)
				{
					pos.y -= static_cast<float>(height);
					rv = eWallDirection::UP;
				}
				else
				{
					pos.y += static_cast<float>(height);
					rv = eWallDirection::DOWN;
				}
			}
			//가로방향으로 밀쳐내야한다.
			else
			{
				// 왼쪽에서 왔다.
				if (intersect.right == r1.right)
				{
					pos.x -= static_cast<float>(width);
					rv = eWallDirection::LEFT;
				}
				else
				{
					// 오른쪽에서 왔다.
					pos.x += static_cast<float>(width);
					rv = eWallDirection::RIGHT;
				}
			}
		}
	}

	this->_body.x = pos.x;
	this->_body.y = pos.y;

	return rv;
}

void Player::OnComponentEndOverlap(Collider* collider, Collider* other)
{
}


void Player::UpdateMove()
{
	if (EPSILON < _velocity.Length())
	{
		this->Move(_velocity);
	}

	ePlayerState newState = this->GetState();
	uint32 currentOrder = 0;

	//Idle 처리
	if (currentOrder <= 0 && false == (EPSILON < _direction.Length()))
	{
		newState = ePlayerState::Idle;
		currentOrder = 0;
	}


	this->SetState(newState);
}

void Player::UpdateIdle()
{
	ePlayerState newState = this->GetState();
	uint32 currentOrder = 0;


	if (EPSILON < _velocity.Length())
	{
		this->Move(_velocity);
	}


	//Move처리
	if (currentOrder <= 1 && EPSILON < _direction.Length())
	{
		newState = ePlayerState::Move;
		currentOrder = 1;
	}

	this->SetState(newState);
}

void Player::UpdateJumpFall()
{
	if (EPSILON < _velocity.Length())
	{
		this->Move(_velocity);
	}
}


void Player::UpdateInput()
{
	_isAttackFlag = false;
	ePlayerState currentState = this->GetState();

	_velocity.x = 0;
	if (GET_SINGLE(KeyManager)->GetKey('A'))
	{
		_velocity = _velocity + Vector2(-1, 0) * _speed;

		if (CanChangeDirection())
		{
			_dir = ePlayerDirection::LEFT;
		}
	}

	if (GET_SINGLE(KeyManager)->GetKey('D'))
	{
		_velocity = _velocity + Vector2(1, 0) * _speed;

		if (CanChangeDirection())
		{
			_dir = ePlayerDirection::RIGHT;
		}
	}


	if (GET_SINGLE(KeyManager)->GetKeyDown(VK_SPACE))
	{
		if (CanJump())
		{
			_velocity.y = -700;
			this->SetState(ePlayerState::JumpFall);
		}
	}
}

bool Player::CanJump()
{
	return true;
}

void Player::UpdateGravity()
{
	_velocity.y += _gravity;
}

void Player::Move(Vector2 direction)
{
	if (DeltaTime > 0.1f) return;

	this->_body.x += _velocity.x * DeltaTime;
	this->_body.y += _velocity.y * DeltaTime;
}

void Player::SetPlayerInfo(CenterRect body, float speed)
{
	_body = body;
	_speed = speed;
	_gravity = 3.8f;

	_dir = ePlayerDirection::RIGHT;

	_idleFlipbook[ePlayerDirection::LEFT] = GET_SINGLE(ResourceManager)->GetFlipbook("FB_Character_Idle_Left");
	_idleFlipbook[ePlayerDirection::RIGHT] = GET_SINGLE(ResourceManager)->GetFlipbook("FB_Character_Idle_Right");

	_moveFlipbook[ePlayerDirection::LEFT] = GET_SINGLE(ResourceManager)->GetFlipbook("FB_Character_Move_Left");
	_moveFlipbook[ePlayerDirection::RIGHT] = GET_SINGLE(ResourceManager)->GetFlipbook("FB_Character_Move_Right");

	_attackFlipbook[ePlayerDirection::LEFT] = GET_SINGLE(ResourceManager)->GetFlipbook("FB_Character_Attack_Left");
	_attackFlipbook[ePlayerDirection::RIGHT] = GET_SINGLE(ResourceManager)->GetFlipbook("FB_Character_Attack_Right");


	_hitFlipbook[ePlayerDirection::LEFT] = GET_SINGLE(ResourceManager)->GetFlipbook("FB_Character_Hit_Left");
	_hitFlipbook[ePlayerDirection::RIGHT] = GET_SINGLE(ResourceManager)->GetFlipbook("FB_Character_Hit_Right");

	this->SetFlipbook(_idleFlipbook[_dir]);
}


void Player::SetState(ePlayerState state)
{
	_state = state;
	switch (_state)
	{
	case ePlayerState::Idle:
		this->SetFlipbook(_idleFlipbook[_dir]);
		break;
	case ePlayerState::Move:
		this->SetFlipbook(_moveFlipbook[_dir]);
		break;
	case ePlayerState::JumpFall:
		this->SetFlipbook(_hitFlipbook[_dir]);
		break;
	case ePlayerState::End:

		break;
	default:
		break;
	}
}

bool Player::CanChangeDirection()
{
	ePlayerState state = this->GetState();

	if (state == ePlayerState::Idle ||
		state == ePlayerState::Move)
	{
		return true;
	}

	return false;
}