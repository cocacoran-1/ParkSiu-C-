#pragma once
class Actor;
class UI;
class Scene
{
protected:
	vector<Actor*> _actors[LAYER_MAXCOUNT];
	vector<UI*> _uis;

	Vector2Int _cameraPosition = {};
//--------------------------
//  기본 함수
//--------------------------
public:
	virtual void Init();
	virtual void Render(HDC hdc);
	virtual void Update();
	virtual void Release();

public:
	void SpawnActor(Actor* actor);
	void DespawnActor(Actor* actor);

public:
	void SetCameraPos(Vector2Int pos) { _cameraPosition = pos; }
	Vector2Int GetCameraPos() { return _cameraPosition; }
};
