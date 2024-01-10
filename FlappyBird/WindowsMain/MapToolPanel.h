#pragma once
#include "Panel.h"

class MapToolScene;
class MapToolPanel : public Panel
{
	using Super = Panel;
public:
	MapToolPanel();
	virtual ~MapToolPanel();
public:
	virtual void Init();
	virtual void Render(HDC hdc);
	virtual void Update();
	virtual void Release();

	void OnClick_Save();
	void OnClick_Revert();

public:
	MapToolScene* CheckValidation();
};

