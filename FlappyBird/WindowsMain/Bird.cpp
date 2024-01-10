#include "stdafx.h"
#include "Bird.h"
#include "Flipbook.h"
#include "Collider.h"
#include "PipeActor.h"
#include "BoxCollider.h"
#include "Scene.h"
#include "BackgroundActor.h"
void Bird::Init()
{
	//-----------------------------
	// 1. 리소스 로드
	//-----------------------------
	GET_SINGLE(ResourceManager)->LoadTexture("T_Bird_Down", "FlappyBird/image/bird/bird_down.bmp");
	GET_SINGLE(ResourceManager)->LoadTexture("T_Bird_Up", "FlappyBird/image/bird/bird_up.bmp");
	GET_SINGLE(ResourceManager)->LoadTexture("T_Bird_Normal", "FlappyBird/image/bird/bird_normal.bmp");
	//Down
	{
		FlipbookInfo info;
		info.texture = GET_SINGLE(ResourceManager)->GetTexture("T_Bird_Down");
		info.duration = 0.5f;
		info.start = 0;
		info.end = 2;
		info.line = 0;
		info.loop = true;
		info.size = { 80, 80 };

		GET_SINGLE(ResourceManager)->CreateFlipbook("FB_Bird_Down", info);
	}

	//Normal
	{
		FlipbookInfo info;
		info.texture = GET_SINGLE(ResourceManager)->GetTexture("T_Bird_Normal");
		info.duration = 0.5f;
		info.start = 0;
		info.end = 2;
		info.line = 0;
		info.loop = true;
		info.size = { 80, 80 };

		GET_SINGLE(ResourceManager)->CreateFlipbook("FB_Bird_Normal", info);
	}

	//Up
	{
		FlipbookInfo info;
		info.texture = GET_SINGLE(ResourceManager)->GetTexture("T_Bird_Up");
		info.duration = 0.5f;
		info.start = 0;
		info.end = 2;
		info.line = 0;
		info.loop = true;
		info.size = { 80, 80 };

		GET_SINGLE(ResourceManager)->CreateFlipbook("FB_Bird_Up", info);
	}

	_flipbook[(int)eBirdDirection::Down] = GET_SINGLE(ResourceManager)->GetFlipbook("FB_Bird_Down");
	_flipbook[(int)eBirdDirection::Up] = GET_SINGLE(ResourceManager)->GetFlipbook("FB_Bird_Up");
	_flipbook[(int)eBirdDirection::Normal] = GET_SINGLE(ResourceManager)->GetFlipbook("FB_Bird_Normal");
	Super::Init();
	_endPos = CurrentScene->GetCameraPos();

	this->SetFlipbook(_flipbook[(int)eBirdDirection::Normal]);
}
void Bird::Render(HDC hdc)
{
	Super::Render(hdc);

	char str[250];
	sprintf_s(str, "Score : %d", _score);
	TextOutA(hdc, WIN_SIZE_WIDTH - 120, 0, str, strlen(str));

}
void Bird::Update()
{
	Super::Update();

	static float currentTime = 0;

	currentTime += DeltaTime;
	if ( currentTime >= 1.0f )
	{
		_speed += 6;
		currentTime = 0;
	}
	if ( _body.x < _endPos.x - 25 )
	{
		GET_SINGLE(SceneManager)->ChangeScene(SceneType::StartScene);

	}

	if ( Input->GetKeyDown(VK_SPACE) )
	{
		_velocity.y = _jumpPower;
	}

	if ( _pushBack )
	{
		_body.x -= _speed * DeltaTime;
	}
	if ( _body.y < 0 )
	{
		_velocity.y = 0;
	}
	_velocity.y -= _gravity * DeltaTime;

	_body.y -= _velocity.y * DeltaTime;
}
void Bird::Release()
{
	Super::Release();
}

void Bird::SetBird(float gravity, float jumpPower)
{
	_gravity = gravity;
	_jumpPower = jumpPower;
}

void Bird::OnComponentBeginOverlap(Collider* collider, Collider* other)
{
	switch ( other->GetCollisionLayer() )
	{
		case CollsionLayerType::CLT_OBSTACLE:
			HandleTrigger_Obstacle(collider, other);
			break;
		case CollsionLayerType::CLT_SCORE:
			HandleTrigger_Score(collider, other);
			break;
		case CollsionLayerType::CLT_LAND:
			HandleTrigger_Land(collider, other);
			break;

	}
}
void Bird::OnComponentEndOverlap(Collider* collider, Collider* other)
{

	_pushBack = false;

}

void Bird::HandleTrigger_Obstacle(Collider* collider, Collider* other)
{
	cout << "HandleTrigger_Obstacle" << endl;
	BoxCollider* thisCollider = dynamic_cast<BoxCollider*>(collider);
	BoxCollider* obstacleCollider = dynamic_cast<BoxCollider*>(other);

	if ( thisCollider && obstacleCollider )
	{
		RECT thisRect = thisCollider->GetCollision().ToRect();
		RECT obstacleRect = obstacleCollider->GetCollision().ToRect();

		RECT intersect = {};
		if ( ::IntersectRect(&intersect, &thisRect, &obstacleRect) )
		{
			int width = intersect.right - intersect.left;
			int height = intersect.bottom - intersect.top;

			if ( width > height )
			{
				if ( intersect.bottom == thisRect.bottom )
				{
					_body.y -= _gravity * DeltaTime;
				}
				else
				{
					_velocity.y = 0;
				}
			}
			else
			{
				if ( intersect.right == thisRect.right )
				{
					_pushBack = true;
					
				}
			}
		}
	}
}
void Bird::HandleTrigger_Score(Collider* collider, Collider* other)
{
	cout << "HandleTrigger_Score" << endl;
	_score += 100;

}

void Bird::HandleTrigger_Land(Collider* collider, Collider* other)
{
	cout << "HandleTrigger_Land" << endl;

	if ( !_sceneChange )
	{
		_sceneChange = true;
		_isDead = true;
		//GET_SINGLE(SceneManager)->ChangeScene(SceneType::StartScene);
	}
}


