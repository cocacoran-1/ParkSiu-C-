#include "stdafx.h"
#include "TestPanel.h"
#include "Button.h"

TestPanel::TestPanel()
{

}
TestPanel::~TestPanel()
{

}

void TestPanel::Init()
{
	Super::Init();


	{
		Button* button = new Button();
		button->SetRect(Shape::MakeCenterRect(WIN_SIZE_WIDTH / 2, WIN_SIZE_HEIGHT / 2, 200, 200));

		button->SetSprite(eButtonState::Default, GET_SINGLE(ResourceManager)->GetSprite("S_StartButton_Default"));
		button->SetSprite(eButtonState::Hover, GET_SINGLE(ResourceManager)->GetSprite("S_StartButton_Hover"));
		button->SetSprite(eButtonState::Pressed, GET_SINGLE(ResourceManager)->GetSprite("S_StartButton_Pressed"));
		button->SetSprite(eButtonState::Disabled, GET_SINGLE(ResourceManager)->GetSprite("S_StartButton_Disabled"));
		button->AddOnClickDelegate(this, &TestPanel::OnClick_StartButton);
		_children.push_back(button);
	}

	{
		Button* button = new Button();
		button->SetRect(Shape::MakeCenterRect(WIN_SIZE_WIDTH / 2, WIN_SIZE_HEIGHT / 2 + 250, 200, 200));

		button->SetSprite(eButtonState::Default, GET_SINGLE(ResourceManager)->GetSprite("S_StartButton_Default"));
		button->SetSprite(eButtonState::Hover, GET_SINGLE(ResourceManager)->GetSprite("S_StartButton_Hover"));
		button->SetSprite(eButtonState::Pressed, GET_SINGLE(ResourceManager)->GetSprite("S_StartButton_Pressed"));
		button->SetSprite(eButtonState::Disabled, GET_SINGLE(ResourceManager)->GetSprite("S_StartButton_Disabled"));
		button->AddOnClickDelegate(this, &TestPanel::OnClick_LogButton);
		_children.push_back(button);
	}
}
void TestPanel::Render(HDC hdc)
{
	Super::Render(hdc);
}
void TestPanel::Update()
{
	Super::Update();
}
void TestPanel::Release()
{
	Super::Release();
}

void TestPanel::OnClick_StartButton()
{
	GET_SINGLE(SceneManager)->ChangeScene(SceneType::Dev2Scene);
}

void TestPanel::OnClick_LogButton()
{
	cout << "My Log" << endl;
}