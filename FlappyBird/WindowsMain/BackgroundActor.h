#pragma once
#include "SpriteActor.h"
class PipeActor;

struct BackGroundLayer
{
public:
	SpriteActor* Sky;
	SpriteActor* Ground;
	vector<PipeActor*> Pipe;
	float X;

public:
	void SetX(float x);
};

class BackgroundActor : public SpriteActor
{
	//XXX : 레이어 레거시 코드 
	vector<vector<SpriteActor*>> _imagesLayer;
	vector<Vector2> _offsetList;

	vector<BackGroundLayer> _layers;

	int _width = 0;
	float _speed = 100;


public:
	using Super = Actor;
public:
	virtual void Init() override;
	virtual void Render(HDC hdc) override;
	virtual void Update() override;
	virtual void Release() override;
};

