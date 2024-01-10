#include "stdafx.h"
#include "Texture.h"

Texture::Texture()
{

}
Texture::~Texture()
{

}

Texture* Texture::LoadBmp(const string& path)
{
	HDC hdc = ::GetDC(_hWnd);
	_hdc = CreateCompatibleDC(hdc);
	_bitmap = (HBITMAP)LoadImageA(nullptr, path.c_str(), IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);

	if (_bitmap == NULL)
	{
		Alert(path.c_str(), "Image Load Failed!");
		return nullptr;
	}

	HBITMAP prev = (HBITMAP)SelectObject(_hdc, _bitmap);
	DeleteObject(prev);

	BITMAP bit = {};
	GetObject(_bitmap, sizeof(BITMAP), &bit);
	_size.x = bit.bmWidth;
	_size.y = bit.bmHeight;

	return this;
}

HDC Texture::GetDC()
{
	return _hdc;
}