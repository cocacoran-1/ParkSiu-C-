#pragma once
#include "Panel.h"

class StartScene;

class StartPanel : public Panel
{
	using Super = Panel;
public:
	StartPanel();
	virtual ~StartPanel();
public:
	virtual void Init();
	virtual void Render(HDC hdc);
	virtual void Update();
	virtual void Release();

	void OnClick_Start();

public:
	StartScene* CheckValidation();
};

