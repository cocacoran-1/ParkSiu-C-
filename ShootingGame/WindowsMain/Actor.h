#pragma once
#include "Collider.h"


class Component;
class Actor
{
protected:
	vector<Component*> _components;
	CenterRect _body = {};

public:
	virtual void OnComponentBeginOverlap(Collider* collider, Collider* other);
	virtual void OnComponentEndOverlap(Collider* collider, Collider* other);

public:
	void AddComponent(Component* component);
	void RemoveComponent(Component* component);

	CenterRect GetBody() { return _body; }
	void SetBody(CenterRect body) { _body = body; }
public:
	virtual void Init();
	virtual void Render(HDC hdc);
	virtual void Update();
	virtual void Release();

	string GetName(string name) { return name; }
	void SetName(string name) { ;}
};

