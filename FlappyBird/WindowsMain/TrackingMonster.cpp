#include "stdafx.h"
#include "TrackingMonster.h"
#include "Scene.h"

//Radian - ���� ==> PI�������� �̷���� ���� �� (3.141592 ==> 180��)
//Degree - ���� ==> 180�� ==> 180
void TrackingMonster::SetTrackingMonsterInfo(float trackingRadian, float speed, Vector2 spawnPos, Vector2 direction)
{
	_trackingRadian = trackingRadian;
	_speed = speed;
	_direction = direction;
	_originDirection = direction;
	_originPos = spawnPos;

	this->SetBody(CenterRect{ spawnPos.x, spawnPos.y, 70, 70 });
	this->SetSprite(L"../Resources/Enemies/Enemy_02.png", this->GetBody());
}

void TrackingMonster::Init()
{
	Super::Init();
}

void TrackingMonster::Render(HDC hdc)
{
	Super::Render(hdc);

	Vector2Int cameraPos = CurrentScene->GetCameraPos();
	Vector2Int screenSizeHalf = Vector2Int(WIN_SIZE_WIDTH / 2, WIN_SIZE_HEIGHT / 2);

	//���Ӽ���
	Vector2 forwardDirection = _direction.Normalize();
	Vector2 leftDirection = Vector2(-forwardDirection.y, forwardDirection.x);
	Vector2 rightDirection = Vector2(forwardDirection.y, -forwardDirection.x);
	
	Vector2 leftEndPos = Vector2(_body.x, _body.y) + (forwardDirection * cos(_trackingRadian / 2) + leftDirection * sin(_trackingRadian / 2)) * 200;
	Vector2 rightEndPos = Vector2(_body.x, _body.y) + (forwardDirection * cos(_trackingRadian / 2) + rightDirection * sin(_trackingRadian / 2)) * 200;

	Draw::Line(hdc, Vector2(_body.x, _body.y) - Vector2(cameraPos - screenSizeHalf), Vector2(leftEndPos - (cameraPos - screenSizeHalf)));
	Draw::Line(hdc, Vector2(_body.x, _body.y) - Vector2(cameraPos - screenSizeHalf), Vector2(rightEndPos - (cameraPos - screenSizeHalf)));
}

void TrackingMonster::Update()
{
	Super::Update();

	//�����ڵ�
	/*
	���� ���� ���� �����ڵ�
	 
	if (_targetActor) then
		if ( �÷��̾ ���� �������� �ȿ� ��ġ ) then
			���Ͱ� �÷��̾� �������� �̵��Ѵ�
		else then
			�ƹ��͵� ���Ѵ�. (���ڸ��� ���ư���.)
	*/

	if (_targetActor)
	{
		if (IsInTrackingRange())
		{
			Vector2 moveVec = (_targetActor->GetBody().Position() - this->GetBody().Position()).Normalize();
			this->_direction = moveVec;
			this->_body.x += moveVec.x * DeltaTime * _speed;
			this->_body.y += moveVec.y * DeltaTime * _speed;
		}
		else
		{
			//�����ڸ��� ���ư���.
			Vector2 toTarget = (_originPos - this->GetBody().Position());
			if (toTarget.Length() > 2.0f)
			{
				Vector2 moveVec = toTarget.Normalize();
				this->_direction = moveVec;
				this->_body.x += moveVec.x * DeltaTime * _speed;
				this->_body.y += moveVec.y * DeltaTime * _speed;
			}
			else
			{
				this->_direction = _originDirection;
			}
		}
	}

	_roationRadian = Vector2::Down().SignedAngle(this->_direction);
}

void TrackingMonster::Release()
{
	Super::Release();
}

bool TrackingMonster::IsInTrackingRange() 
{
	// _targetActor�� ���� �������� �ȿ� ��ġ���ִٸ�,,,

	// �������� : Angle + Distance

	float distance = (_targetActor->GetBody().Position() - this->_body.Position()).Length();

	if (distance < 200)
	{
		// ����
		Vector2 toTarget = _targetActor->GetBody().Position() - this->_body.Position();
		Vector2 forwardDirection = _direction;

		toTarget.Normalize();
		forwardDirection.Normalize();

		float signedAngle = forwardDirection.SignedAngle(toTarget);

		if (abs(signedAngle) < this->_trackingRadian / 2)
		{
			return true;
		}
	}


	return false;
}