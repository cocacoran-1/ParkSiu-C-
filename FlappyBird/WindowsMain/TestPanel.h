#pragma once
#include "Panel.h"
class TestPanel : public Panel
{
	using Super = Panel;
public:
	TestPanel();
	virtual ~TestPanel();
public:
	virtual void Init();
	virtual void Render(HDC hdc);
	virtual void Update();
	virtual void Release();

	void OnClick_StartButton();
	void OnClick_LogButton();
};

