#include "stdafx.h"
#include "Button.h"
#include "StartPanel.h"
#include "StartScene.h"

StartPanel::StartPanel()
{
}

StartPanel::~StartPanel()
{
}

void StartPanel::Init()
{
	Super::Init();

	GET_SINGLE(ResourceManager)->LoadTexture("T_start_normal", "FlappyBird/image/splash/game_start_normal.bmp");
	GET_SINGLE(ResourceManager)->CreateSprite("S_start_normal",
		GET_SINGLE(ResourceManager)->GetTexture("T_start_normal"));
	GET_SINGLE(ResourceManager)->LoadTexture("T_start_press", "FlappyBird/image/splash/game_start_press.bmp");
	GET_SINGLE(ResourceManager)->CreateSprite("S_start_press",
		GET_SINGLE(ResourceManager)->GetTexture("T_start_press"));

	{
		Button* button = new Button();
		button->SetRect(Shape::MakeCenterRect(WIN_SIZE_WIDTH / 2 +10 , WIN_SIZE_HEIGHT * 3 / 4 - 100, 336, 104));

		button->SetSprite(eButtonState::Default, GET_SINGLE(ResourceManager)->GetSprite("S_start_normal"));
		button->SetSprite(eButtonState::Hover, GET_SINGLE(ResourceManager)->GetSprite("S_start_press"));
		button->SetSprite(eButtonState::Pressed, GET_SINGLE(ResourceManager)->GetSprite("S_start_press"));
		button->SetSprite(eButtonState::Disabled, GET_SINGLE(ResourceManager)->GetSprite("S_start_normal"));
		button->AddOnClickDelegate(this, &StartPanel::OnClick_Start);
		_children.push_back(button);
	}


}

void StartPanel::Render(HDC hdc)
{
	Super::Render(hdc);
}

void StartPanel::Update()
{
	Super::Update();
}

void StartPanel::Release()
{
	Super::Release();
}


void StartPanel::OnClick_Start()
{
	StartScene* startScene = CheckValidation();
	if ( nullptr == startScene )
	{
		return;
	}

	startScene->OnClick_ChangeScene(SceneType::FlappyBirdInGameScene);
	cout << "FlappyBirdStart" << endl;
}


StartScene* StartPanel::CheckValidation()
{

	Scene* currentScene = GET_SINGLE(SceneManager)->GetCurrentScene();
	StartScene* startScene = dynamic_cast<StartScene*>(currentScene);
	if ( startScene == nullptr )
	{
		Alert("Error", "해당 버튼은 MapToolScene에서만 작동합니다,");
		return nullptr;
	}

	return startScene;
	return nullptr;
}
