#include "stdafx.h"
#include "Button.h"
#include "Sprite.h"

Button::Button()
{

}
Button::~Button()
{

}

void Button::Init()
{
	Super::Init();
	SetState(eButtonState::Default);
}
void Button::Render(HDC hdc)
{
	Super::Render(hdc);
	if (_currentSprite)
	{
		TransparentBlt(hdc,
			this->_pos.x - _currentSprite->GetSize().x / 2,
			this->_pos.y - _currentSprite->GetSize().y / 2,
			_currentSprite->GetSize().x,
			_currentSprite->GetSize().y,
			_currentSprite->GetDC(),
			_currentSprite->GetPos().x,
			_currentSprite->GetPos().y,
			_currentSprite->GetSize().x,
			_currentSprite->GetSize().y,
			_currentSprite->GetTransparent());
	}
	else
	{
		Draw::Rect(hdc, this->GetRect());
	}
}
void Button::Update()
{
	Super::Update();
	/*
	if(���콺�� �ڱ� �浹���� �ȿ� �ִٸ�)
	{
		if(���콺�� Ŭ������ ���¶��)
		{
			���� = Pressed;
		}
		else
		{
			//Ŭ���ߴٰ� �����°�?
			if(���� == Pressed)
			{
				//Ŭ���ߴ�!
			}

			���� = Hover;
		}
	}
	else
	{
		���� = Default;
	}
	*/

	if (this->IsInMouse())
	{
		/*
		if �̹� �����ӿ� �����ٸ�
			_state = Pressed;
		else if �̹� �����ӿ� �����ٸ�
			if( _state == Press )
				Ŭ���ߴ� �̺�Ʈ!
		else if ������ �ִ� ���̶�� {
			
		}
		else  {
			_state = Hover;
		}
		*/

		if (Input->GetKeyDown(VK_LBUTTON))
		{
			SetState(eButtonState::Pressed);
		}
		else if (Input->GetKeyUp(VK_LBUTTON))
		{
			if (_state == eButtonState::Pressed)
			{
				if (_onclick)
				{
					_onclick();
				}
			}
		}
		else if (Input->GetKey(VK_LBUTTON))
		{

		}
		else {
			SetState(eButtonState::Hover);
		}
		
	}
	else
	{
		SetState(eButtonState::Default);
	}
}
void Button::Release()
{
	Super::Release();
}

void Button::SetState(eButtonState state)
{
	if (_state == state) return;

	_state = state;
	_currentSprite = _sprites[(int)state];
}