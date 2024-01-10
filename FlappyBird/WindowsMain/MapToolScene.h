#pragma once
#include "Scene.h"

enum class MapToolState
{
	IDLE,
	WALL_MAKE,
};

class MapToolScene : public Scene
{
	using Super = Scene;
private:
	MapToolState _state = MapToolState::IDLE;
	vector<RECT> _wallVec = {};
	RECT _currentRect = {};

public:
	virtual void Init();
	virtual void Render(HDC hdc);
	virtual void Update();
	virtual void Release();

public:
	void UpdateInput();
	void UpdateIdle();
	void UpdateWallMake();

public:
	void RenderIdle(HDC hdc);
	void RenderWallMake(HDC hdc);

public:
	void Save();
	void Revert();
};

