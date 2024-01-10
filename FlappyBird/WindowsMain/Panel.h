#pragma once
#include "UI.h"
class Panel : public UI
{
protected:
	vector<UI*> _children;

	using Super = UI;
public:
	Panel();
	virtual ~Panel();
public:
	virtual void Init();
	virtual void Render(HDC hdc);
	virtual void Update();
	virtual void Release();


public:
	void AddChild(UI* ui);
	bool RemoveChild(UI* ui);
};

