#pragma once
class Game
{
private:

public:
	void Init();
	void Update();
	void Render();
	void Release();


//---------------------------------------
//	## Gdiplus ����
//---------------------------------------
private:
	ULONG_PTR _gdiPlusToken;


//---------------------------------------
//	## ������۸� ����
//---------------------------------------
private:
	HDC _hdc;
	HDC _hdcBack;
	HBITMAP _bmpBack;

};

