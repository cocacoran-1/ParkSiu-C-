#pragma once
#include "SpriteActor.h"
class Player : public SpriteActor
{
private:
	float _speed;
	int _level;
	vector<class Bullet*> _bullet;

public:
	void Move(Vector2 direction);

public:
	void SetPlayerInfo(CenterRect body, float speed, const WCHAR* spritePath);
	void RemoveBullet(int index);
	vector<class Bullet*> GetBullet() { return _bullet; }

public:
	using Super = SpriteActor;
public:
	virtual void Init()  override;
	virtual void Render(HDC hdc)   override;
	virtual void Update()   override;
	virtual void Release()   override;
};

