#include "stdafx.h"
#include "Actor.h"
#include "Component.h"
#include "Collider.h"

void Actor::OnComponentBeginOverlap(Collider* collider, Collider* other)
{
	cout << "충돌시작" << endl;
}

void Actor::OnComponentEndOverlap(Collider* collider, Collider* other)
{
	cout << "충돌종료" << endl;

}

void Actor::AddComponent(Component* component)
{
	if (component == nullptr) return;
	component->SetOwner(this);
	_components.push_back(component);
}

void Actor::RemoveComponent(Component* component)
{
	auto findIt = find(_components.begin(), _components.end(), component);

	if (findIt != _components.end())
	{
		_components.erase(findIt);
	}
}

void Actor::Init()
{
	for(Component* componet : _components)
	{
		componet->Init();
	}
}

void Actor::Render(HDC hdc)
{
	for (Component* componet : _components)
	{
		componet->Render(hdc);
	}
}

void Actor::Update()
{
	for (Component* componet : _components)
	{
		componet->Update();
	}
}

void Actor::Release()
{
	for (Component* componet : _components)
	{
		componet->Release();
	}
}
