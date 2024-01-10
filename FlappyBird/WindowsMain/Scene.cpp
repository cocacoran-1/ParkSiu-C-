#include "stdafx.h"
#include "Scene.h"
#include "Actor.h"
#include "UI.h"

void Scene::Init()
{

	for (UI* ui : _uis)
	{
		ui->Init();
	}
}
void Scene::Render(HDC hdc)
{
	for (const vector<Actor*> actors : _actors)
	{
		for (Actor* actor : actors)
		{
			actor->Render(hdc);
		}
	}

	for (UI* ui : _uis)
	{
		ui->Render(hdc);
	}
}
void Scene::Update()
{
	for (const vector<Actor*> actors : _actors)
	{
		for (Actor* actor : actors)
		{
			actor->Update();
		}
	}

	for (UI* ui : _uis)
	{
		ui->Update();
	}
}
void Scene::Release()
{
	for (vector<Actor*>& actors : _actors)
	{
		for (Actor* actor : actors)
		{
			actor->Release();
			SAFE_DELETE(actor);
		}
		actors.clear();
	}


	for (UI* ui : _uis)
	{
		ui->Release();
		SAFE_DELETE(ui);
	}
	_uis.clear();
}


void Scene::SpawnActor(Actor* actor)
{
	//매게변수 유효성검증
	if (actor == nullptr) return;
	

	_actors[actor->GetLayerInt()].push_back(actor);
	actor->Init();
}
void Scene::DespawnActor(Actor* actor)
{
	if (actor == nullptr) return;

	vector<Actor*>& vec = _actors[actor->GetLayerInt()];

	auto findIt = find(vec.begin(), vec.end(), actor);

	if (findIt != vec.end())
	{
		(*findIt)->Release();
		Actor* deleteActor = (*findIt);
		SAFE_DELETE(deleteActor);
		vec.erase(findIt);
	}
}