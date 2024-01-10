#pragma once
#include "UI.h"
class Sprite;

enum class eButtonState
{
	Default,
	Hover,
	Pressed,
	Disabled,
	End
};

class Button : public UI
{
	using Super = UI;
protected:
	Sprite* _currentSprite = nullptr;
	Sprite* _sprites[(int)eButtonState::End] = {};
	eButtonState _state = eButtonState::End;


	function<void()> _onclick = nullptr;
public:
	void SetSprite(eButtonState state, Sprite* sprite) {
		_sprites[(int)state] = sprite;
	}
	Sprite* GetSprite(eButtonState state) { return _sprites[(int)state]; }
	
protected:
	void SetState(eButtonState state);

public:
	Button();
	virtual ~Button();
public:
	virtual void Init();
	virtual void Render(HDC hdc);
	virtual void Update();
	virtual void Release();

public:
	template<typename T>
	void AddOnClickDelegate(T* owner, void(T::* func)())
	{
		_onclick = bind(func, owner);
	}
};

