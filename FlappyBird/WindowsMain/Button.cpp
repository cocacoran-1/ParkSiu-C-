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
	if(마우스가 자기 충돌영역 안에 있다면)
	{
		if(마우스가 클릭중인 상태라면)
		{
			상태 = Pressed;
		}
		else
		{
			//클릭했다가 떼었는가?
			if(상태 == Pressed)
			{
				//클릭했다!
			}

			상태 = Hover;
		}
	}
	else
	{
		상태 = Default;
	}
	*/

	if (this->IsInMouse())
	{
		/*
		if 이번 프레임에 눌렀다면
			_state = Pressed;
		else if 이번 프레임에 떼었다면
			if( _state == Press )
				클릭했다 이벤트!
		else if 누르고 있는 중이라면 {
			
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