#include "stdafx.h"
#include "UI.h"

UI::UI()
{
}
UI::~UI()
{

}
void UI::Init()
{

}
void UI::Render(HDC hdc)
{

}
void UI::Update()
{

}
void UI::Release()
{

}

void UI::SetRect(CenterRect rect)
{
	_pos.x = rect.x;
	_pos.y = rect.y;
	_size.x = static_cast<int>(rect.width);
	_size.y = static_cast<int>(rect.height);
}

CenterRect UI::GetRect()
{
	return CenterRect{
		_pos.x,
		_pos.y,
		static_cast<float>(_size.x),
		static_cast<float>(_size.y)
	};
}

bool UI::IsInMouse()
{
	return Collision::PtInRect(this->GetRect(), _mousePos);
}
