#include "stdafx.h"
#include "FlappyBirdInGameScene.h"
#include "Actor.h"
#include "GdiplusSpriteActor.h"
#include "BoxCollider.h"
#include "SpriteActor.h"
#include "FlipbookActor.h"
#include "Flipbook.h"
#include "CameraComponent.h"
#include "Button.h"
#include "CircleCollider.h"
#include "BackgroundActor.h"
#include "Bird.h"
#include "PipeActor.h"

void FlappyBirdInGameScene::Init()
{

	{
		BackgroundActor* actor = new BackgroundActor();
		this->SpawnActor(actor);
	}

	{
		Bird* bird = new Bird();
		bird->SetBody(Shape::MakeCenterRect(100, WIN_SIZE_HEIGHT / 2 - 80, 80, 80));
		{
			BoxCollider* collider = new BoxCollider();
			collider->Init();
			collider->SetCollision(Shape::MakeCenterRect(0, 0, 50,50));
			collider->SetCollisionLayer(CollsionLayerType::CLT_BIRD);
			collider->AddCollisionFlagLayer(CollsionLayerType::CLT_OBSTACLE);
			collider->AddCollisionFlagLayer(CollsionLayerType::CLT_SCORE);
			bird->AddComponent(collider);
		}
		bird->SetBird(700, 300);
		this->SpawnActor(bird);
		_bird = bird;
		_score = _bird->GetScore();
	}

	/*{
		PipeActor* actor = new PipeActor();
		actor->SetPipe(50, 80, 30);
		this->SpawnActor(actor);
	}*/

	CurrentScene->SetCameraPos(Vector2Int(WIN_SIZE_WIDTH / 2, WIN_SIZE_HEIGHT / 2));


	Super::Init();
}

void FlappyBirdInGameScene::Render(HDC hdc)
{
	Super::Render(hdc);

	char str[250];
	sprintf_s(str, "FlappyBirdInGameScene");
	TextOutA(hdc, 0, WIN_SIZE_HEIGHT - 50, str, strlen(str));
	
	if ( _bird->GetIsDead() )
	{
		cout << "»ç¸Á" << endl;
		PlaySound(NULL, NULL, SND_PURGE);
		GET_SINGLE(SceneManager)->ChangeScene(SceneType::ScoreScene);
	}
}

void FlappyBirdInGameScene::Update()
{
	Super::Update();
	int score = _bird->GetScore();
	_score = score;

}

void FlappyBirdInGameScene::Release()
{
	Super::Release();

}


void FlappyBirdInGameScene::darkenScreen(HDC hdc)
{
	WORD gammaRamp[3][256];

	for ( int i = 0; i < 256; i++ )
	{
		gammaRamp[0][i] = gammaRamp[1][i] = gammaRamp[2][i] = static_cast<WORD>(i * 0.5); 
	}


	SetDeviceGammaRamp(hdc, gammaRamp);

	ReleaseDC(NULL, hdc);
}

void FlappyBirdInGameScene::restoreScreen(HDC hdc)
{

	WORD defaultGammaRamp[3][256];
	for ( int i = 0; i < 256; i++ )
	{
		defaultGammaRamp[0][i] = defaultGammaRamp[1][i] = defaultGammaRamp[2][i] = static_cast<WORD>(i);
	}

	SetDeviceGammaRamp(hdc, defaultGammaRamp);

	ReleaseDC(NULL, hdc);
}
