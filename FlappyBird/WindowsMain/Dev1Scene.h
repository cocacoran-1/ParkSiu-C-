#pragma once
#include "Scene.h"

class GdiplusSpriteActor;
class Player;
class Dev1Scene : public Scene
{
	using Super = Scene;
public:
	virtual void Init() override;
	virtual void Render(HDC hdc) override;
	virtual void Update() override;
	virtual void Release() override;

public:
	void LoadResource();

	void OnClick_ChangeScene();
};

