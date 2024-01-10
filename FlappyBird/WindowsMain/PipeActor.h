#pragma once
#include "Actor.h"
class SpriteActor;
class BoxCollider;
class PipeActor : public Actor
{
private:
	int _height = 0;
	vector<SpriteActor*> _sprites;

	BoxCollider* _upCollider;
	BoxCollider* _downCollider;

	BoxCollider* _scoreCollider;

	bool _isInit = false;
public:
	void SetPipe(int x, int y, int height);
	void SetX(int x);
	void SetY(int y);
	void SetHeight(int height);

	//���⼭ �������� ��ġ�� ��ȭ��Ų��.
	void Resize();

public:
	using Super = Actor;
public:
	virtual void Init() override;
	virtual void Render(HDC hdc) override;
	virtual void Update() override;
	virtual void Release() override;
};

