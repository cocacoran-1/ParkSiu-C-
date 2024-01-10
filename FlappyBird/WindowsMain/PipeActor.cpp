#include "stdafx.h"
#include "PipeActor.h"
#include "SpriteActor.h"
#include "Sprite.h"
#include "BoxCollider.h"

void PipeActor::Init()
{
	Super::Init();
	//-----------------------------
	// 1. 리소스 로드
	//-----------------------------
	GET_SINGLE(ResourceManager)->LoadTexture("T_Pipe_Down", "FlappyBird/image/obstacle_down1.bmp");
	GET_SINGLE(ResourceManager)->LoadTexture("T_Pipe_Up", "FlappyBird/image/obstacle_up1.bmp");
	GET_SINGLE(ResourceManager)->CreateSprite("S_Pipe_Down",
		GET_SINGLE(ResourceManager)->GetTexture("T_Pipe_Down"));
	GET_SINGLE(ResourceManager)->CreateSprite("S_Pipe_Up",
		GET_SINGLE(ResourceManager)->GetTexture("T_Pipe_Up"));


	// 위 장애물 생성
	{
		SpriteActor* actor = new SpriteActor();
		Sprite* sprite = GET_SINGLE(ResourceManager)->GetSprite("S_Pipe_Up");
		actor->SetSprite(sprite);
		_sprites.push_back(actor);
	}
	
	// 아래 장애물 생성
	{
		SpriteActor* actor = new SpriteActor();
		Sprite* sprite = GET_SINGLE(ResourceManager)->GetSprite("S_Pipe_Down");
		actor->SetSprite(sprite);
		_sprites.push_back(actor);
	}

	_upCollider = new BoxCollider();
	_upCollider->Init();
	_upCollider->SetCollisionLayer(CollsionLayerType::CLT_OBSTACLE);
	this->AddComponent(_upCollider);

	_downCollider = new BoxCollider();
	_downCollider->Init();
	_downCollider->SetCollisionLayer(CollsionLayerType::CLT_OBSTACLE);
	this->AddComponent(_downCollider);

	_scoreCollider = new BoxCollider();
	_scoreCollider->Init();
	_scoreCollider->SetCollisionLayer(CollsionLayerType::CLT_SCORE);
	this->AddComponent(_scoreCollider);

	_isInit = true;
	Resize();
}
void PipeActor::Render(HDC hdc)
{

	for (auto sprite : _sprites)
	{
		sprite->Render(hdc);
	}
	Super::Render(hdc);
}
void PipeActor::Update()
{
	Super::Update();
}
void PipeActor::Release()
{
	Super::Release();
}

void PipeActor::SetPipe(int x, int y, int height)
{
	_body.x = x;
	_body.y = y;
	_height = height;

	Resize();
}
void PipeActor::SetX(int x)
{
	_body.x = x;
	Resize();
}
void PipeActor::SetY(int y)
{
	_body.y = y;
	Resize();
}
void PipeActor::SetHeight(int height)
{
	_height = height;
	Resize();
}

void PipeActor::Resize()
{
	if (_isInit == false) return;

	{
		SpriteActor* actor = _sprites[0];
		Sprite* sprite = actor->GetSprite();
		actor->SetBody(CenterRect::FromRect(
			Shape::MakeRect(
				_body.x - sprite->GetSize().x / 2,
				-sprite->GetSize().y + _body.y - _height / 2,
				sprite->GetSize().x,
				sprite->GetSize().y
			)));

		_upCollider->SetCollision(CenterRect::FromRect(
			Shape::MakeRect(
				-sprite->GetSize().x / 2,
				-sprite->GetSize().y - _height / 2,
				sprite->GetSize().x,
				sprite->GetSize().y
			)));
	}

	{
		SpriteActor* actor = _sprites[1];
		Sprite* sprite = actor->GetSprite();
		actor->SetBody(CenterRect::FromRect(
			Shape::MakeRect(
				_body.x - sprite->GetSize().x / 2,
				0 + _body.y + _height / 2,
				sprite->GetSize().x,
				sprite->GetSize().y
			)));


		_downCollider->SetCollision(CenterRect::FromRect(
			Shape::MakeRect(
				- sprite->GetSize().x / 2,
				_height / 2,
				sprite->GetSize().x,
				sprite->GetSize().y
			)));
	}

	_scoreCollider->SetCollision(Shape::MakeCenterRect(
		0,
		0,
		30,
		_height
	));
}