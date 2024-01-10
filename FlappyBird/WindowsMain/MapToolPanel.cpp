#include "stdafx.h"
#include "MapToolPanel.h"
#include "Button.h"
#include "MapToolScene.h"
MapToolPanel::MapToolPanel()
{

}
MapToolPanel::~MapToolPanel()
{

}

void MapToolPanel::Init()
{
	Super::Init();

	GET_SINGLE(ResourceManager)->LoadTexture("T_StartButton", "Buttons/Start.bmp", RGB(255, 0, 210));
	GET_SINGLE(ResourceManager)->CreateSprite("S_StartButton_Default",
		GET_SINGLE(ResourceManager)->GetTexture("T_StartButton"), 0, 0, 200, 200);
	GET_SINGLE(ResourceManager)->CreateSprite("S_StartButton_Hover",
		GET_SINGLE(ResourceManager)->GetTexture("T_StartButton"), 200, 0, 200, 200);
	GET_SINGLE(ResourceManager)->CreateSprite("S_StartButton_Pressed",
		GET_SINGLE(ResourceManager)->GetTexture("T_StartButton"), 400, 0, 200, 200);
	GET_SINGLE(ResourceManager)->CreateSprite("S_StartButton_Disabled",
		GET_SINGLE(ResourceManager)->GetTexture("T_StartButton"), 600, 0, 200, 200);


	{
		Button* button = new Button();
		button->SetRect(Shape::MakeCenterRect(WIN_SIZE_WIDTH / 2 - 200, WIN_SIZE_HEIGHT * 3 / 4 , 200, 200));

		button->SetSprite(eButtonState::Default, GET_SINGLE(ResourceManager)->GetSprite("S_StartButton_Default"));
		button->SetSprite(eButtonState::Hover, GET_SINGLE(ResourceManager)->GetSprite("S_StartButton_Hover"));
		button->SetSprite(eButtonState::Pressed, GET_SINGLE(ResourceManager)->GetSprite("S_StartButton_Pressed"));
		button->SetSprite(eButtonState::Disabled, GET_SINGLE(ResourceManager)->GetSprite("S_StartButton_Disabled"));
		button->AddOnClickDelegate(this, &MapToolPanel::OnClick_Save);
		_children.push_back(button);
	}

	{
		Button* button = new Button();
		button->SetRect(Shape::MakeCenterRect(WIN_SIZE_WIDTH / 2 + 200, WIN_SIZE_HEIGHT * 3 / 4, 200, 200));

		button->SetSprite(eButtonState::Default, GET_SINGLE(ResourceManager)->GetSprite("S_StartButton_Default"));
		button->SetSprite(eButtonState::Hover, GET_SINGLE(ResourceManager)->GetSprite("S_StartButton_Hover"));
		button->SetSprite(eButtonState::Pressed, GET_SINGLE(ResourceManager)->GetSprite("S_StartButton_Pressed"));
		button->SetSprite(eButtonState::Disabled, GET_SINGLE(ResourceManager)->GetSprite("S_StartButton_Disabled"));
		button->AddOnClickDelegate(this, &MapToolPanel::OnClick_Revert);
		_children.push_back(button);
	}
}
void MapToolPanel::Render(HDC hdc)
{
	Super::Render(hdc);
}
void MapToolPanel::Update()
{
	Super::Update();
}
void MapToolPanel::Release()
{
	Super::Release();
}

void MapToolPanel::OnClick_Save()
{
	MapToolScene* mapToolScene = CheckValidation();
	if (nullptr == mapToolScene)
	{
		return;
	}

	mapToolScene->Save();
	cout << "Save" << endl;
}
void MapToolPanel::OnClick_Revert()
{
	MapToolScene* mapToolScene = CheckValidation();
	if (nullptr == mapToolScene)
	{
		return;
	}

	mapToolScene->Revert();


	cout << "Revert" << endl;
}

MapToolScene* MapToolPanel::CheckValidation()
{
	Scene* currentScene = GET_SINGLE(SceneManager)->GetCurrentScene();
	MapToolScene* mapToolScene = dynamic_cast<MapToolScene*>(currentScene);
	if (mapToolScene == nullptr)
	{
		Alert("Error", "해당 버튼은 MapToolScene에서만 작동합니다,");
		return nullptr;
	}

	return mapToolScene;
}