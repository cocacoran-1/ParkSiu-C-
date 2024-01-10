#include "stdafx.h"
#include "StartScene.h"
#include "StartPanel.h"
#include "SpriteActor.h"


void StartScene::Init()
{
	Super::Init();


	GET_SINGLE(ResourceManager)->LoadTexture("T_start_background_layer01", "FlappyBird/image/start_background_layer01.bmp");
	GET_SINGLE(ResourceManager)->CreateSprite("S_start_background_layer01",
		GET_SINGLE(ResourceManager)->GetTexture("T_start_background_layer01"));

	SpriteActor* backgroundActor = new SpriteActor();
	backgroundActor->SetLayer(LayerType::BackGround);
	backgroundActor->SetSprite(GET_SINGLE(ResourceManager)->GetSprite("S_start_background_layer01"));
	backgroundActor->SetBody(CenterRect::FromRect(RECT(350, 0, WIN_SIZE_WIDTH/2, WIN_SIZE_HEIGHT)));

	this->SpawnActor(backgroundActor);
	this->SetCameraPos(Vector2Int(WIN_SIZE_WIDTH / 2, WIN_SIZE_HEIGHT / 2));


	{
		Panel* panel = new StartPanel();
		panel->Init();
		_uis.push_back(panel);
	}
}

void StartScene::Render(HDC hdc)
{
	Super::Render(hdc);
}

void StartScene::Update()
{
	Super::Update();
}

void StartScene::Release()
{
	Super::Release();
	
}

void StartScene::LoadResource()
{
}

void StartScene::OnClick_ChangeScene(SceneType scenType)
{
	PlaySound("../Resources/Sound/Arcade-background-music.wav", NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);
	GET_SINGLE(SceneManager)->ChangeScene(scenType);
}
