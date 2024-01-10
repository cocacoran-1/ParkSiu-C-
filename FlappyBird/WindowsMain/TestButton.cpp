#include "stdafx.h"
#include "TestButton.h"

void TestButton::OnClick()
{
	GET_SINGLE(SceneManager)->ChangeScene(SceneType::Dev2Scene);
}