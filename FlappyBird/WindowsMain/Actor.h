#pragma once
// Component���� ���� ���ִ�.
// Component => ���� ���
//  Collider Component => �浹üũ�����ִ� ���
// 
class Component;
class Collider;
class Actor
{
protected:
	vector<Component*> _components;
	CenterRect _body = {};	//Draw ���� (����� Actor Position)
	float _roationRadian = 0.0f;
	string _name;

	bool _isActive = true;
	LayerType _layer = LayerType::Object;
public:
	//�浹���� �Լ�
	//Unreal
	virtual void OnComponentBeginOverlap(Collider* collider, Collider* other);
	//Unity
	//virtual void OnTriggerEnter(Collider* collider, Collider* other);

	//�浹�� �Լ�
	//Unreal
	virtual void OnComponentEndOverlap(Collider* collider, Collider* other);
	//Unity
	//virtual void OnTriggerExit(Collider* collider, Collider* other);

public:
	void AddComponent(Component* component);
	void RemoveComponent(Component* component);

	CenterRect GetBody() { return _body; }
	void SetBody(CenterRect body) { _body = body; }

	string GetName() { return _name; }
	void SetName(string name) { _name = name; }

	bool GetActive() { return _isActive; }
	void SetActive(bool active) { _isActive = active; }

	LayerType GetLayer() { return _layer; }
	int GetLayerInt() { return static_cast<int>(_layer); }
	void SetLayer(LayerType layer) { _layer = layer; }

public:
	virtual void Init();
	virtual void Render(HDC hdc);
	virtual void Update();
	virtual void Release();
};

