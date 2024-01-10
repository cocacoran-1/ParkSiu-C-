#include "stdafx.h"
#include "BackgroundActor.h"
#include "Sprite.h"
#include "PipeActor.h"
#include "BoxCollider.h"

void BackgroundActor::Init()
{
	//-----------------------------
	// 1. 리소스 로드
	//-----------------------------
	GET_SINGLE(ResourceManager)->LoadTexture("T_FlappybirdBackgroundLayer01", "FlappyBird/image/background_layer01.bmp");
	GET_SINGLE(ResourceManager)->LoadTexture("T_FlappybirdBackgroundLayer02", "FlappyBird/image/background_layer02.bmp");
	GET_SINGLE(ResourceManager)->CreateSprite("S_FlappybirdBackgroundLayer01",
		GET_SINGLE(ResourceManager)->GetTexture("T_FlappybirdBackgroundLayer01"));
	GET_SINGLE(ResourceManager)->CreateSprite("S_FlappybirdBackgroundLayer02",
		GET_SINGLE(ResourceManager)->GetTexture("T_FlappybirdBackgroundLayer02"));


	//-----------------------------
	// 2. 기본 변수 초기화
	//-----------------------------
	_speed = 100;
	_width = GET_SINGLE(ResourceManager)->GetSprite("S_FlappybirdBackgroundLayer01")->GetSize().x;

	//-----------------------------
	// 3. 레이어 배치
	//-----------------------------
	//_layers 에 레이어를 추가
	for ( int i = 0; i < 15; i++ )
	{
		
		BackGroundLayer layer;
		layer.X = _width * i;

		layer.Sky = new SpriteActor();
		layer.Sky->Init();
		layer.Sky->SetLayer(LayerType::BackGround);
		layer.Sky->SetSprite(GET_SINGLE(ResourceManager)->GetSprite("S_FlappybirdBackgroundLayer01"));
		layer.Sky->SetBody(CenterRect::FromRect(
			Shape::MakeRect(
				layer.X,
				0,
				layer.Sky->GetSprite()->GetSize().x,
				layer.Sky->GetSprite()->GetSize().y
			)));

		layer.Ground = new SpriteActor();
		layer.Ground->Init();
		layer.Ground->SetLayer(LayerType::BackGround);
		layer.Ground->SetSprite(GET_SINGLE(ResourceManager)->GetSprite("S_FlappybirdBackgroundLayer02"));
		layer.Ground->SetBody(CenterRect::FromRect(
			Shape::MakeRect(
				layer.X,
				WIN_SIZE_HEIGHT - layer.Ground->GetSprite()->GetSize().y,
				layer.Ground->GetSprite()->GetSize().x,
				layer.Ground->GetSprite()->GetSize().y
			)));

		{
			BoxCollider* collider = new BoxCollider();
			collider->Init();
			collider->SetCollision(CenterRect::FromRect(
				Shape::MakeRect(
					-layer.Ground->GetSprite()->GetSize().x / 2,
					-layer.Ground->GetSprite()->GetSize().y / 2,
					layer.Ground->GetSprite()->GetSize().x,
					layer.Ground->GetSprite()->GetSize().y
				)));
			collider->SetCollisionLayer(CollsionLayerType::CLT_LAND);

			layer.Ground->AddComponent(collider);
		}

		if ( i != 0 )
		{
			int rand = Random::GetInt(0, 10);
			if ( rand <9 )
			{
				PipeActor* pipe = new PipeActor();
				pipe->Init();
				pipe->SetPipe(layer.X + _width / 2, Random::GetInt(100, WIN_SIZE_HEIGHT - 300), Random::GetInt(150, 200));
				layer.Pipe.push_back(pipe);
			}
			else
			{
				float pipeGap = 75;

				int randY = Random::GetInt(200, WIN_SIZE_HEIGHT - 400);
				int randHeight = Random::GetInt(150, 200);

				float startPipeX = layer.X + (_width / 2) - (2 * pipeGap); 

				for ( int j = 0; j < 4; j++ )
				{
					PipeActor* pipe = new PipeActor();
					pipe->Init();
					float pipeX = startPipeX + (j * pipeGap); 
					pipe->SetPipe(pipeX, randY, randHeight);
					layer.Pipe.push_back(pipe);
				}

			}
		}
		_layers.push_back(layer);
	}


}
void BackgroundActor::Render(HDC hdc)
{

	for (auto layer : _layers)
	{
		layer.Sky->Render(hdc);
		for ( const auto& pipe : layer.Pipe )
		{
			pipe->Render(hdc);
		}
		layer.Ground->Render(hdc);
	}

	Super::Render(hdc);
}
void BackgroundActor::Update()
{
	static float currentTime = 0;

	currentTime += DeltaTime;
	if ( currentTime >= 1.0f )
	{
		cout << "속도 증가 !!!!" << endl;
		_speed += 6;
		currentTime = 0;
	}

	for (int i = 0; i < _layers.size(); i++)
	{
		_layers[i].SetX(_layers[i].X - DeltaTime * _speed);
	}

	for ( int i = 1; i < _layers.size(); i++ )
	{
		if ( _layers[i].X + _width <= 0 )
		{
			float lastLayerX = 0;
			int lastLayerIndex = 0;
			for ( int j = 0; j < _layers.size(); ++j )
			{
				if ( _layers[j].X > lastLayerX )
				{
					lastLayerX = _layers[j].X;
					lastLayerIndex = j;
				}
			}

			_layers[i].SetX(lastLayerX + _width);

			if ( _layers[i].Pipe.size() > 1 )
			{
				float pipeGap = 75;
				int randX = Random::GetInt(200, WIN_SIZE_HEIGHT - 400);
				int randY = Random::GetInt(150, 200);
				float startPipeX = _layers[i].X + (_width / 2) - (2 * pipeGap);

				for ( int j = 0; j < 4; j++ )
				{
					float pipeX = startPipeX + (j * pipeGap);
					_layers[i].Pipe[j]->SetPipe(
						pipeX,
						randX,
						randY);
				}
			}
			


			BackGroundLayer temp = _layers[i];
			for ( int k = i; k < lastLayerIndex; ++k )
			{
				_layers[k] = _layers[k + 1];
			}
			_layers[lastLayerIndex] = temp;
			break;
		}
	}


}
void BackgroundActor::Release()
{

}

void BackGroundLayer::SetX(float x)
{
	float deltaX = X - x;
	X = x;

	{
		CenterRect rc = this->Sky->GetBody();
		rc.x -= deltaX;
		this->Sky->SetBody(rc);
	}

	{
		CenterRect rc = this->Ground->GetBody();
		rc.x -= deltaX;
		this->Ground->SetBody(rc);
	}

	{
		for ( PipeActor* pipe : Pipe)
		{
			CenterRect rc = pipe->GetBody();
			rc.x -= deltaX;
			pipe->SetBody(rc);
			pipe->Resize();
		}
	}
}


