#include "stdafx.h"
#include "ScoreScene.h"
#include "ScoreBoard.h"
#include "SpriteActor.h"
#include "CameraComponent.h"


void ScoreScene::Init()
{
	Super::Init();


	{
		ScoreBoard* scoreBoard = new ScoreBoard();
		this->SpawnActor(scoreBoard);
	}
	this->SetCameraPos(Vector2Int(WIN_SIZE_WIDTH / 2, WIN_SIZE_HEIGHT / 2));

}

void ScoreScene::Render(HDC hdc)
{
	Super::Render(hdc);
}

void ScoreScene::Update()
{
	Super::Update();
}

void ScoreScene::Release()
{
	Super::Release();
}

void ScoreScene::LoadResource()
{
}

void ScoreScene::OnClick_ChangeScene(SceneType scenType)
{
}
