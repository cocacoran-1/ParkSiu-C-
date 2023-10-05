#pragma once
#include "SpriteActor.h"
class Enemy : public SpriteActor
{

public:
	void SetPlayerInfo(CenterRect body,  const WCHAR* spritePath);
	CenterRect GetCollision() { return _body; }
public:
	using Super = SpriteActor;
public:
	virtual void Init()  override;
	virtual void Render(HDC hdc)   override;
	virtual void Update()   override;
	virtual void Release()   override;

};

