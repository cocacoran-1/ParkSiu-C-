#pragma once
#include "Actor.h"
class Sprite;
class SpriteActor : public Actor
{
protected:
	Sprite* _sprite = nullptr;
	Vector2 _offset = { 0,0 };
public:
	void SetSprite(Sprite* sprite) { _sprite = sprite; }
	Sprite* GetSprite() { return _sprite; }
	void SetOffset(Vector2 offset) { _offset = offset; }
	Vector2 GetOffset() { return _offset; }
public:
	using Super = Actor;
public:
	virtual void Init() override;
	virtual void Render(HDC hdc) override;
	virtual void Update() override;
	virtual void Release() override;

};

