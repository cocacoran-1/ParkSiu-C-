#pragma once
#include "Actor.h"
class SpriteActor : public Actor
{
protected:
	Gdiplus::Image* _sprite = nullptr;

public:
	void SetSprite(const WCHAR* filePath, CenterRect body);

public:
	using Super = Actor;

public:
	virtual void Init()  override;
	virtual void Render(HDC hdc)   override;
	virtual void Update()   override;
	virtual void Release()   override;
};

