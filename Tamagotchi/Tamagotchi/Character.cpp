#include "stdafx.h"
#include "Character.h"


void SetPixelColor(DWORD color)
{
	CustomConsole.SetBkColor(color);
	cout << "��";
}

void Character::Init()
{
	_x = 110;
	_y = 15;
	_animationIndex = 0;
	_animationTime = 0;
	_foodGauge = 50;
	_fatigueGauge = 0;
	_happinessGauge = 0;
	isStay = true;
	moveLeft = false;
	moveRight = false;
}

void Character::Update(int deltaTime, char inputKey)
{
	//ĳ���� �ִϸ��̼� �ڵ�
	Status();
	_animationTime += deltaTime;
	if (300 < _animationTime)
	{
		if (isStay)
		{
			if (_animationIndex == 9)
			{
				Direction();
			}
			_animationTime = 0;
			_animationIndex++;
			_animationIndex %= 10;
			Erase();
			StayRender();
		}
		else if (moveRight)
		{
			if (_animationIndex == 10)
			{
				Direction();
			}
			_animationTime = 0;
			_animationIndex++;
			_animationIndex %= 11;
			if (_animationIndex % 2 == 0)
			{
				_x++;
			}
			Erase();
			RightRender();
		}
		else if (moveLeft)
		{
			if (_animationIndex == 10)
			{
				Direction();
			}
			_animationTime = 0;
			_animationIndex++;
			_animationIndex %= 11;
			if (_animationIndex % 2 == 0)
			{
				_x--;
			}
			Erase();
			LeftRender();
		}

	}

}

void Character::Direction()
{
	int random = rand() % 3;
	// ���� 
	if (random == 0)
	{
		isStay = true;
		moveLeft = false;
		moveRight = false;
	}
	// ���� �̵�
	else if (random == 1)
	{
		isStay = false;
		moveLeft = true;
		moveRight = false;
	}
	// ������ �̵�
	else if (random == 2)
	{
		isStay = false;
		moveLeft = false;
		moveRight = true;
	}

}

void Character::StayRender()
{
	switch (_animationIndex)
	{
	case 0:
		CustomConsole.GotoXY(_x + 8, _y);
		SetPixelColor(BLACK); SetPixelColor(BLACK); SetPixelColor(BLACK); SetPixelColor(BLACK);
		CustomConsole.GotoXY(_x + 4, _y + 1);
		SetPixelColor(BLACK); SetPixelColor(BLACK); SetPixelColor(LIGHTGREEN); SetPixelColor(LIGHTGREEN);
		SetPixelColor(LIGHTGREEN); SetPixelColor(LIGHTGREEN); SetPixelColor(BLACK); SetPixelColor(BLACK);
		CustomConsole.GotoXY(_x + 2, _y + 2);
		SetPixelColor(BLACK); SetPixelColor(LIGHTGREEN); SetPixelColor(LIGHTGREEN); SetPixelColor(LIGHTGREEN); SetPixelColor(GREEN);
		SetPixelColor(GREEN); SetPixelColor(GREEN); SetPixelColor(LIGHTGREEN); SetPixelColor(LIGHTGREEN);SetPixelColor(BLACK);
		CustomConsole.GotoXY(_x, _y + 3);
		SetPixelColor(BLACK); SetPixelColor(LIGHTGREEN); SetPixelColor(GREEN); SetPixelColor(LIGHTGREEN); SetPixelColor(LIGHTGREEN);
		SetPixelColor(GREEN);SetPixelColor(GREEN);SetPixelColor(GREEN);SetPixelColor(GREEN);SetPixelColor(GREEN);
		SetPixelColor(LIGHTGREEN);SetPixelColor(BLACK);
		CustomConsole.GotoXY(_x, _y + 4);
		SetPixelColor(BLACK); SetPixelColor(LIGHTGREEN); SetPixelColor(GREEN);SetPixelColor(BLACK);SetPixelColor(GREEN);
		SetPixelColor(GREEN);SetPixelColor(GREEN);SetPixelColor(GREEN);SetPixelColor(BLACK);SetPixelColor(GREEN);
		SetPixelColor(LIGHTGREEN);SetPixelColor(BLACK);
		CustomConsole.GotoXY(_x - 2, _y + 5);
		SetPixelColor(BLACK); SetPixelColor(LIGHTGREEN); SetPixelColor(GREEN);SetPixelColor(GREEN);SetPixelColor(BLACK);
		SetPixelColor(GREEN);SetPixelColor(GREEN);SetPixelColor(GREEN);SetPixelColor(GREEN);SetPixelColor(BLACK);
		SetPixelColor(GREEN);SetPixelColor(GREEN);SetPixelColor(LIGHTGREEN);SetPixelColor(BLACK);
		CustomConsole.GotoXY(_x - 2, _y + 6);
		SetPixelColor(BLACK); SetPixelColor(LIGHTGREEN); SetPixelColor(GREEN);SetPixelColor(GREEN);SetPixelColor(BLACK);
		SetPixelColor(GREEN);SetPixelColor(GREEN);SetPixelColor(GREEN);SetPixelColor(GREEN);SetPixelColor(BLACK);
		SetPixelColor(GREEN);SetPixelColor(GREEN);SetPixelColor(LIGHTGREEN);SetPixelColor(BLACK);
		CustomConsole.GotoXY(_x - 2, _y + 7);
		SetPixelColor(BLACK); SetPixelColor(LIGHTGREEN); SetPixelColor(GREEN);SetPixelColor(LIGHTRED);SetPixelColor(LIGHTRED);
		SetPixelColor(GREEN);SetPixelColor(GREEN);SetPixelColor(GREEN);SetPixelColor(GREEN);SetPixelColor(LIGHTRED);
		SetPixelColor(LIGHTRED);SetPixelColor(GREEN);SetPixelColor(LIGHTGREEN);SetPixelColor(BLACK);
		CustomConsole.GotoXY(_x - 2, _y + 8);
		SetPixelColor(BLACK);SetPixelColor(GREEN); SetPixelColor(GREEN);SetPixelColor(GREEN);SetPixelColor(GREEN);
		SetPixelColor(GREEN);SetPixelColor(GREEN);SetPixelColor(GREEN);SetPixelColor(GREEN);SetPixelColor(GREEN);
		SetPixelColor(GREEN);SetPixelColor(GREEN);SetPixelColor(GREEN);SetPixelColor(BLACK);
		CustomConsole.GotoXY(_x, _y + 9);
		SetPixelColor(BLACK);SetPixelColor(GREEN);SetPixelColor(GREEN);SetPixelColor(GREEN);SetPixelColor(GREEN);
		SetPixelColor(GREEN);SetPixelColor(GREEN);SetPixelColor(GREEN);SetPixelColor(GREEN);SetPixelColor(GREEN);
		SetPixelColor(GREEN);SetPixelColor(BLACK);
		CustomConsole.GotoXY(_x + 2, _y + 10);
		SetPixelColor(BLACK);SetPixelColor(BLACK);SetPixelColor(GREEN);SetPixelColor(GREEN);SetPixelColor(GREEN);
		SetPixelColor(GREEN);SetPixelColor(GREEN);SetPixelColor(GREEN);SetPixelColor(BLACK);SetPixelColor(BLACK);
		CustomConsole.GotoXY(_x + 6, _y + 11);
		SetPixelColor(BLACK);SetPixelColor(BLACK);SetPixelColor(BLACK);SetPixelColor(BLACK);
		SetPixelColor(BLACK);SetPixelColor(BLACK);
		break;
	case 1:
		CustomConsole.GotoXY(_x + 8, _y + 1);
		SetPixelColor(BLACK); SetPixelColor(BLACK); SetPixelColor(BLACK); SetPixelColor(BLACK);
		CustomConsole.GotoXY(_x + 4, _y + 2);
		SetPixelColor(BLACK); SetPixelColor(BLACK);SetPixelColor(LIGHTGREEN); SetPixelColor(LIGHTGREEN);
		SetPixelColor(LIGHTGREEN); SetPixelColor(LIGHTGREEN);SetPixelColor(BLACK); SetPixelColor(BLACK);
		CustomConsole.GotoXY(_x + 2, _y + 3);
		SetPixelColor(BLACK);SetPixelColor(LIGHTGREEN);SetPixelColor(LIGHTGREEN);SetPixelColor(LIGHTGREEN);
		SetPixelColor(GREEN);SetPixelColor(GREEN);SetPixelColor(GREEN);
		SetPixelColor(LIGHTGREEN);SetPixelColor(LIGHTGREEN);SetPixelColor(BLACK);
		CustomConsole.GotoXY(_x, _y + 4);
		SetPixelColor(BLACK);SetPixelColor(LIGHTGREEN);SetPixelColor(GREEN);SetPixelColor(LIGHTGREEN);SetPixelColor(LIGHTGREEN);
		SetPixelColor(GREEN);SetPixelColor(GREEN);SetPixelColor(GREEN);SetPixelColor(GREEN);SetPixelColor(GREEN);
		SetPixelColor(LIGHTGREEN);SetPixelColor(BLACK);
		CustomConsole.GotoXY(_x - 2, _y + 5);
		SetPixelColor(BLACK);SetPixelColor(LIGHTGREEN);SetPixelColor(GREEN);SetPixelColor(GREEN);SetPixelColor(BLACK);
		SetPixelColor(GREEN);SetPixelColor(GREEN);SetPixelColor(GREEN);SetPixelColor(GREEN);SetPixelColor(BLACK);
		SetPixelColor(GREEN);SetPixelColor(GREEN);SetPixelColor(LIGHTGREEN);SetPixelColor(BLACK);
		CustomConsole.GotoXY(_x - 2, _y + 6);
		SetPixelColor(BLACK);SetPixelColor(LIGHTGREEN);SetPixelColor(GREEN);SetPixelColor(GREEN);
		SetPixelColor(BLACK);SetPixelColor(GREEN);SetPixelColor(GREEN);SetPixelColor(GREEN);SetPixelColor(GREEN);
		SetPixelColor(BLACK);SetPixelColor(GREEN);SetPixelColor(GREEN);SetPixelColor(LIGHTGREEN);SetPixelColor(BLACK);
		CustomConsole.GotoXY(_x - 2, _y + 7);
		SetPixelColor(BLACK);SetPixelColor(LIGHTGREEN);SetPixelColor(GREEN);SetPixelColor(GREEN);
		SetPixelColor(BLACK);SetPixelColor(GREEN);SetPixelColor(GREEN);SetPixelColor(GREEN);SetPixelColor(GREEN);
		SetPixelColor(BLACK);SetPixelColor(GREEN);SetPixelColor(GREEN);
		SetPixelColor(LIGHTGREEN);SetPixelColor(BLACK);
		CustomConsole.GotoXY(_x - 2, _y + 8);
		SetPixelColor(BLACK);SetPixelColor(GREEN);SetPixelColor(GREEN);SetPixelColor(LIGHTRED);SetPixelColor(LIGHTRED);
		SetPixelColor(GREEN);SetPixelColor(GREEN);SetPixelColor(GREEN);SetPixelColor(GREEN);
		SetPixelColor(LIGHTRED);SetPixelColor(LIGHTRED);SetPixelColor(GREEN);SetPixelColor(GREEN);SetPixelColor(BLACK);
		CustomConsole.GotoXY(_x, _y + 9);
		SetPixelColor(BLACK);SetPixelColor(GREEN);SetPixelColor(GREEN);SetPixelColor(GREEN);SetPixelColor(GREEN);
		SetPixelColor(GREEN);SetPixelColor(GREEN);SetPixelColor(GREEN);SetPixelColor(GREEN);
		SetPixelColor(GREEN);SetPixelColor(GREEN);SetPixelColor(BLACK);
		CustomConsole.GotoXY(_x + 2, _y + 10);
		SetPixelColor(BLACK);SetPixelColor(BLACK);SetPixelColor(GREEN);SetPixelColor(GREEN);SetPixelColor(GREEN);
		SetPixelColor(GREEN);SetPixelColor(GREEN);SetPixelColor(GREEN);	SetPixelColor(BLACK);SetPixelColor(BLACK);
		CustomConsole.GotoXY(_x + 6, _y + 11);
		SetPixelColor(BLACK);SetPixelColor(BLACK);SetPixelColor(BLACK);
		SetPixelColor(BLACK);SetPixelColor(BLACK);SetPixelColor(BLACK);
		break;
	case 2:
		CustomConsole.GotoXY(_x + 8, _y + 1);
		SetPixelColor(BLACK); SetPixelColor(BLACK); SetPixelColor(BLACK); SetPixelColor(BLACK);
		CustomConsole.GotoXY(_x + 4, _y + 2);
		SetPixelColor(BLACK); SetPixelColor(BLACK);SetPixelColor(LIGHTGREEN); SetPixelColor(LIGHTGREEN);
		SetPixelColor(LIGHTGREEN); SetPixelColor(LIGHTGREEN);SetPixelColor(BLACK); SetPixelColor(BLACK);
		CustomConsole.GotoXY(_x + 2, _y + 3);
		SetPixelColor(BLACK);SetPixelColor(LIGHTGREEN);SetPixelColor(LIGHTGREEN);SetPixelColor(LIGHTGREEN);
		SetPixelColor(GREEN);SetPixelColor(GREEN);SetPixelColor(GREEN);
		SetPixelColor(LIGHTGREEN);SetPixelColor(LIGHTGREEN);SetPixelColor(BLACK);
		CustomConsole.GotoXY(_x, _y + 4);
		SetPixelColor(BLACK);SetPixelColor(LIGHTGREEN);SetPixelColor(GREEN);SetPixelColor(LIGHTGREEN);SetPixelColor(LIGHTGREEN);
		SetPixelColor(GREEN);SetPixelColor(GREEN);SetPixelColor(GREEN);SetPixelColor(GREEN);SetPixelColor(GREEN);
		SetPixelColor(LIGHTGREEN);SetPixelColor(BLACK);
		CustomConsole.GotoXY(_x - 2, _y + 5);
		SetPixelColor(BLACK);SetPixelColor(LIGHTGREEN);SetPixelColor(GREEN);SetPixelColor(GREEN);SetPixelColor(GREEN);
		SetPixelColor(GREEN);SetPixelColor(GREEN);SetPixelColor(GREEN);SetPixelColor(GREEN);SetPixelColor(GREEN);
		SetPixelColor(GREEN);SetPixelColor(GREEN);SetPixelColor(LIGHTGREEN);SetPixelColor(BLACK);
		CustomConsole.GotoXY(_x - 2, _y + 6);
		SetPixelColor(BLACK);SetPixelColor(LIGHTGREEN);SetPixelColor(GREEN);SetPixelColor(GREEN);
		SetPixelColor(BLACK);SetPixelColor(GREEN);SetPixelColor(GREEN);SetPixelColor(GREEN);SetPixelColor(GREEN);
		SetPixelColor(BLACK);SetPixelColor(GREEN);SetPixelColor(GREEN);SetPixelColor(LIGHTGREEN);SetPixelColor(BLACK);
		CustomConsole.GotoXY(_x - 2, _y + 7);
		SetPixelColor(BLACK);SetPixelColor(LIGHTGREEN);SetPixelColor(GREEN);SetPixelColor(GREEN);
		SetPixelColor(BLACK);SetPixelColor(GREEN);SetPixelColor(GREEN);SetPixelColor(GREEN);SetPixelColor(GREEN);
		SetPixelColor(BLACK);SetPixelColor(GREEN);SetPixelColor(GREEN);
		SetPixelColor(LIGHTGREEN);SetPixelColor(BLACK);
		CustomConsole.GotoXY(_x - 2, _y + 8);
		SetPixelColor(BLACK);SetPixelColor(GREEN);SetPixelColor(GREEN);SetPixelColor(GREEN);SetPixelColor(BLACK);
		SetPixelColor(GREEN);SetPixelColor(GREEN);SetPixelColor(GREEN);SetPixelColor(GREEN);
		SetPixelColor(BLACK);SetPixelColor(GREEN);SetPixelColor(GREEN);SetPixelColor(GREEN);SetPixelColor(BLACK);
		CustomConsole.GotoXY(_x, _y + 9);
		SetPixelColor(BLACK);SetPixelColor(GREEN);SetPixelColor(LIGHTRED);SetPixelColor(LIGHTRED);SetPixelColor(GREEN);
		SetPixelColor(GREEN);SetPixelColor(GREEN);SetPixelColor(GREEN);SetPixelColor(LIGHTRED);
		SetPixelColor(LIGHTRED);SetPixelColor(GREEN);SetPixelColor(BLACK);
		CustomConsole.GotoXY(_x + 2, _y + 10);
		SetPixelColor(BLACK);SetPixelColor(BLACK);SetPixelColor(GREEN);SetPixelColor(GREEN);SetPixelColor(GREEN);
		SetPixelColor(GREEN);SetPixelColor(GREEN);SetPixelColor(GREEN);	SetPixelColor(BLACK);SetPixelColor(BLACK);
		CustomConsole.GotoXY(_x + 6, _y + 11);
		SetPixelColor(BLACK);SetPixelColor(BLACK);SetPixelColor(BLACK);
		SetPixelColor(BLACK);SetPixelColor(BLACK);SetPixelColor(BLACK);
		break;
	case 3:
		CustomConsole.GotoXY(_x + 8, _y);
		SetPixelColor(BLACK); SetPixelColor(BLACK); SetPixelColor(BLACK); SetPixelColor(BLACK);
		CustomConsole.GotoXY(_x + 4, _y + 1);
		SetPixelColor(BLACK); SetPixelColor(BLACK);SetPixelColor(LIGHTGREEN); SetPixelColor(LIGHTGREEN);
		SetPixelColor(LIGHTGREEN); SetPixelColor(LIGHTGREEN);SetPixelColor(BLACK); SetPixelColor(BLACK);
		CustomConsole.GotoXY(_x + 2, _y + 2);
		SetPixelColor(BLACK);SetPixelColor(LIGHTGREEN);SetPixelColor(LIGHTGREEN);SetPixelColor(LIGHTGREEN);
		SetPixelColor(GREEN);SetPixelColor(GREEN);SetPixelColor(GREEN);
		SetPixelColor(LIGHTGREEN);SetPixelColor(LIGHTGREEN);SetPixelColor(BLACK);
		CustomConsole.GotoXY(_x, _y + 3);
		SetPixelColor(BLACK);SetPixelColor(LIGHTGREEN);SetPixelColor(GREEN);SetPixelColor(LIGHTGREEN);SetPixelColor(LIGHTGREEN);
		SetPixelColor(GREEN);SetPixelColor(GREEN);SetPixelColor(GREEN);SetPixelColor(GREEN);SetPixelColor(GREEN);
		SetPixelColor(LIGHTGREEN);SetPixelColor(BLACK);
		CustomConsole.GotoXY(_x, _y + 4);
		SetPixelColor(BLACK);SetPixelColor(LIGHTGREEN);SetPixelColor(GREEN);SetPixelColor(GREEN);SetPixelColor(GREEN);
		SetPixelColor(GREEN);SetPixelColor(GREEN);SetPixelColor(GREEN);SetPixelColor(GREEN);SetPixelColor(GREEN);
		SetPixelColor(LIGHTGREEN);SetPixelColor(BLACK);
		CustomConsole.GotoXY(_x - 2, _y + 5);
		SetPixelColor(BLACK);SetPixelColor(LIGHTGREEN);SetPixelColor(GREEN);SetPixelColor(GREEN);SetPixelColor(GREEN);
		SetPixelColor(GREEN);SetPixelColor(GREEN);SetPixelColor(GREEN);SetPixelColor(GREEN);SetPixelColor(GREEN);
		SetPixelColor(GREEN);SetPixelColor(GREEN);SetPixelColor(LIGHTGREEN);SetPixelColor(BLACK);
		CustomConsole.GotoXY(_x - 2, _y + 6);
		SetPixelColor(BLACK);SetPixelColor(LIGHTGREEN);SetPixelColor(GREEN);SetPixelColor(GREEN);
		SetPixelColor(BLACK);SetPixelColor(GREEN);SetPixelColor(GREEN);SetPixelColor(GREEN);SetPixelColor(GREEN);
		SetPixelColor(BLACK);SetPixelColor(GREEN);SetPixelColor(GREEN);SetPixelColor(LIGHTGREEN);SetPixelColor(BLACK);
		CustomConsole.GotoXY(_x - 2, _y + 7);
		SetPixelColor(BLACK);SetPixelColor(LIGHTGREEN);SetPixelColor(GREEN);SetPixelColor(GREEN);
		SetPixelColor(BLACK);SetPixelColor(GREEN);SetPixelColor(GREEN);SetPixelColor(GREEN);SetPixelColor(GREEN);
		SetPixelColor(BLACK);SetPixelColor(GREEN);SetPixelColor(GREEN);
		SetPixelColor(LIGHTGREEN);SetPixelColor(BLACK);
		CustomConsole.GotoXY(_x - 2, _y + 8);
		SetPixelColor(BLACK);SetPixelColor(GREEN);SetPixelColor(GREEN);SetPixelColor(GREEN);SetPixelColor(BLACK);
		SetPixelColor(GREEN);SetPixelColor(GREEN);SetPixelColor(GREEN);SetPixelColor(GREEN);
		SetPixelColor(BLACK);SetPixelColor(GREEN);SetPixelColor(GREEN);SetPixelColor(GREEN);SetPixelColor(BLACK);
		CustomConsole.GotoXY(_x, _y + 9);
		SetPixelColor(BLACK);SetPixelColor(GREEN);SetPixelColor(LIGHTRED);SetPixelColor(LIGHTRED);SetPixelColor(GREEN);
		SetPixelColor(GREEN);SetPixelColor(GREEN);SetPixelColor(GREEN);SetPixelColor(LIGHTRED);
		SetPixelColor(LIGHTRED);SetPixelColor(GREEN);SetPixelColor(BLACK);
		CustomConsole.GotoXY(_x + 2, _y + 10);
		SetPixelColor(BLACK);SetPixelColor(BLACK);SetPixelColor(GREEN);SetPixelColor(GREEN);SetPixelColor(GREEN);
		SetPixelColor(GREEN);SetPixelColor(GREEN);SetPixelColor(GREEN);	SetPixelColor(BLACK);SetPixelColor(BLACK);
		CustomConsole.GotoXY(_x + 6, _y + 11);
		SetPixelColor(BLACK);SetPixelColor(BLACK);SetPixelColor(BLACK);
		SetPixelColor(BLACK);SetPixelColor(BLACK);SetPixelColor(BLACK);
		break;
	case 4:
		CustomConsole.GotoXY(_x + 8, _y);
		SetPixelColor(BLACK); SetPixelColor(BLACK); SetPixelColor(BLACK); SetPixelColor(BLACK);
		CustomConsole.GotoXY(_x + 4, _y + 1);
		SetPixelColor(BLACK); SetPixelColor(BLACK);SetPixelColor(LIGHTGREEN); SetPixelColor(LIGHTGREEN);
		SetPixelColor(LIGHTGREEN); SetPixelColor(LIGHTGREEN);SetPixelColor(BLACK); SetPixelColor(BLACK);
		CustomConsole.GotoXY(_x + 2, _y + 2);
		SetPixelColor(BLACK);SetPixelColor(LIGHTGREEN);SetPixelColor(LIGHTGREEN);SetPixelColor(LIGHTGREEN);
		SetPixelColor(GREEN);SetPixelColor(GREEN);SetPixelColor(GREEN);
		SetPixelColor(LIGHTGREEN);SetPixelColor(LIGHTGREEN);SetPixelColor(BLACK);
		CustomConsole.GotoXY(_x, _y + 3);
		SetPixelColor(BLACK);SetPixelColor(LIGHTGREEN);SetPixelColor(GREEN);SetPixelColor(LIGHTGREEN);SetPixelColor(LIGHTGREEN);
		SetPixelColor(GREEN);SetPixelColor(GREEN);SetPixelColor(GREEN);SetPixelColor(GREEN);SetPixelColor(GREEN);
		SetPixelColor(LIGHTGREEN);SetPixelColor(BLACK);
		CustomConsole.GotoXY(_x, _y + 4);
		SetPixelColor(BLACK);SetPixelColor(LIGHTGREEN);SetPixelColor(GREEN);SetPixelColor(GREEN);SetPixelColor(GREEN);
		SetPixelColor(GREEN);SetPixelColor(GREEN);SetPixelColor(GREEN);SetPixelColor(GREEN);SetPixelColor(GREEN);
		SetPixelColor(LIGHTGREEN);SetPixelColor(BLACK);
		CustomConsole.GotoXY(_x - 2, _y + 5);
		SetPixelColor(BLACK);SetPixelColor(LIGHTGREEN);SetPixelColor(GREEN);SetPixelColor(GREEN);SetPixelColor(BLACK);
		SetPixelColor(GREEN);SetPixelColor(GREEN);SetPixelColor(GREEN);SetPixelColor(GREEN);SetPixelColor(BLACK);
		SetPixelColor(GREEN);SetPixelColor(GREEN);SetPixelColor(LIGHTGREEN);SetPixelColor(BLACK);
		CustomConsole.GotoXY(_x - 2, _y + 6);
		SetPixelColor(BLACK);SetPixelColor(LIGHTGREEN);SetPixelColor(GREEN);SetPixelColor(GREEN);
		SetPixelColor(BLACK);SetPixelColor(GREEN);SetPixelColor(GREEN);SetPixelColor(GREEN);SetPixelColor(GREEN);
		SetPixelColor(BLACK);SetPixelColor(GREEN);SetPixelColor(GREEN);SetPixelColor(LIGHTGREEN);SetPixelColor(BLACK);
		CustomConsole.GotoXY(_x - 2, _y + 7);
		SetPixelColor(BLACK);SetPixelColor(LIGHTGREEN);SetPixelColor(GREEN);SetPixelColor(GREEN);
		SetPixelColor(BLACK);SetPixelColor(GREEN);SetPixelColor(GREEN);SetPixelColor(GREEN);SetPixelColor(GREEN);
		SetPixelColor(BLACK);SetPixelColor(GREEN);SetPixelColor(GREEN);
		SetPixelColor(LIGHTGREEN);SetPixelColor(BLACK);
		CustomConsole.GotoXY(_x - 2, _y + 8);
		SetPixelColor(BLACK);SetPixelColor(GREEN);SetPixelColor(GREEN);SetPixelColor(LIGHTRED);SetPixelColor(LIGHTRED);
		SetPixelColor(GREEN);SetPixelColor(GREEN);SetPixelColor(GREEN);SetPixelColor(GREEN);
		SetPixelColor(LIGHTRED);SetPixelColor(LIGHTRED);SetPixelColor(GREEN);SetPixelColor(GREEN);SetPixelColor(BLACK);
		CustomConsole.GotoXY(_x, _y + 9);
		SetPixelColor(BLACK);SetPixelColor(GREEN);SetPixelColor(GREEN);SetPixelColor(GREEN);SetPixelColor(GREEN);
		SetPixelColor(GREEN);SetPixelColor(GREEN);SetPixelColor(GREEN);SetPixelColor(GREEN);
		SetPixelColor(GREEN);SetPixelColor(GREEN);SetPixelColor(BLACK);
		CustomConsole.GotoXY(_x + 2, _y + 10);
		SetPixelColor(BLACK);SetPixelColor(BLACK);SetPixelColor(GREEN);SetPixelColor(GREEN);SetPixelColor(GREEN);
		SetPixelColor(GREEN);SetPixelColor(GREEN);SetPixelColor(GREEN);	SetPixelColor(BLACK);SetPixelColor(BLACK);
		CustomConsole.GotoXY(_x + 6, _y + 11);
		SetPixelColor(BLACK);SetPixelColor(BLACK);SetPixelColor(BLACK);
		SetPixelColor(BLACK);SetPixelColor(BLACK);SetPixelColor(BLACK);
		break;
	case 5:
		CustomConsole.GotoXY(_x + 8, _y);
		SetPixelColor(BLACK); SetPixelColor(BLACK); SetPixelColor(BLACK); SetPixelColor(BLACK);
		CustomConsole.GotoXY(_x + 4, _y + 1);
		SetPixelColor(BLACK); SetPixelColor(BLACK);SetPixelColor(LIGHTGREEN); SetPixelColor(LIGHTGREEN);
		SetPixelColor(LIGHTGREEN); SetPixelColor(LIGHTGREEN);SetPixelColor(BLACK); SetPixelColor(BLACK);
		CustomConsole.GotoXY(_x + 2, _y + 2);
		SetPixelColor(BLACK);SetPixelColor(LIGHTGREEN);SetPixelColor(LIGHTGREEN);SetPixelColor(LIGHTGREEN);
		SetPixelColor(GREEN);SetPixelColor(GREEN);SetPixelColor(GREEN);
		SetPixelColor(LIGHTGREEN);SetPixelColor(LIGHTGREEN);SetPixelColor(BLACK);
		CustomConsole.GotoXY(_x, _y + 3);
		SetPixelColor(BLACK);SetPixelColor(LIGHTGREEN);SetPixelColor(GREEN);SetPixelColor(LIGHTGREEN);SetPixelColor(LIGHTGREEN);
		SetPixelColor(GREEN);SetPixelColor(GREEN);SetPixelColor(GREEN);SetPixelColor(GREEN);SetPixelColor(GREEN);
		SetPixelColor(LIGHTGREEN);SetPixelColor(BLACK);
		CustomConsole.GotoXY(_x, _y + 4);
		SetPixelColor(BLACK);SetPixelColor(LIGHTGREEN);SetPixelColor(GREEN);SetPixelColor(BLACK);SetPixelColor(GREEN);
		SetPixelColor(GREEN);SetPixelColor(GREEN);SetPixelColor(GREEN);SetPixelColor(BLACK);SetPixelColor(GREEN);
		SetPixelColor(LIGHTGREEN);SetPixelColor(BLACK);
		CustomConsole.GotoXY(_x - 2, _y + 5);
		SetPixelColor(BLACK);SetPixelColor(LIGHTGREEN);SetPixelColor(GREEN);SetPixelColor(GREEN);SetPixelColor(BLACK);
		SetPixelColor(GREEN);SetPixelColor(GREEN);SetPixelColor(GREEN);SetPixelColor(GREEN);SetPixelColor(BLACK);
		SetPixelColor(GREEN);SetPixelColor(GREEN);SetPixelColor(LIGHTGREEN);SetPixelColor(BLACK);
		CustomConsole.GotoXY(_x - 2, _y + 6);
		SetPixelColor(BLACK);SetPixelColor(LIGHTGREEN);SetPixelColor(GREEN);SetPixelColor(GREEN);
		SetPixelColor(BLACK);SetPixelColor(GREEN);SetPixelColor(GREEN);SetPixelColor(GREEN);SetPixelColor(GREEN);
		SetPixelColor(BLACK);SetPixelColor(GREEN);SetPixelColor(GREEN);SetPixelColor(LIGHTGREEN);SetPixelColor(BLACK);
		CustomConsole.GotoXY(_x - 2, _y + 7);
		SetPixelColor(BLACK);SetPixelColor(LIGHTGREEN);SetPixelColor(GREEN);SetPixelColor(LIGHTRED);
		SetPixelColor(LIGHTRED);SetPixelColor(GREEN);SetPixelColor(GREEN);SetPixelColor(GREEN);SetPixelColor(GREEN);
		SetPixelColor(LIGHTRED);SetPixelColor(LIGHTRED);SetPixelColor(GREEN);
		SetPixelColor(LIGHTGREEN);SetPixelColor(BLACK);
		CustomConsole.GotoXY(_x - 2, _y + 8);
		SetPixelColor(BLACK);SetPixelColor(GREEN);SetPixelColor(GREEN);SetPixelColor(GREEN);SetPixelColor(GREEN);
		SetPixelColor(GREEN);SetPixelColor(GREEN);SetPixelColor(GREEN);SetPixelColor(GREEN);
		SetPixelColor(GREEN);SetPixelColor(GREEN);SetPixelColor(GREEN);SetPixelColor(GREEN);SetPixelColor(BLACK);
		CustomConsole.GotoXY(_x, _y + 9);
		SetPixelColor(BLACK);SetPixelColor(GREEN);SetPixelColor(GREEN);SetPixelColor(GREEN);SetPixelColor(GREEN);
		SetPixelColor(GREEN);SetPixelColor(GREEN);SetPixelColor(GREEN);SetPixelColor(GREEN);
		SetPixelColor(GREEN);SetPixelColor(GREEN);SetPixelColor(BLACK);
		CustomConsole.GotoXY(_x + 2, _y + 10);
		SetPixelColor(BLACK);SetPixelColor(BLACK);SetPixelColor(GREEN);SetPixelColor(GREEN);SetPixelColor(GREEN);
		SetPixelColor(GREEN);SetPixelColor(GREEN);SetPixelColor(GREEN);	SetPixelColor(BLACK);SetPixelColor(BLACK);
		CustomConsole.GotoXY(_x + 6, _y + 11);
		SetPixelColor(BLACK);SetPixelColor(BLACK);SetPixelColor(BLACK);
		SetPixelColor(BLACK);SetPixelColor(BLACK);SetPixelColor(BLACK);
		break;
	case 6:
		CustomConsole.GotoXY(_x + 8, _y - 1);
		SetPixelColor(BLACK); SetPixelColor(BLACK); SetPixelColor(BLACK); SetPixelColor(BLACK);
		CustomConsole.GotoXY(_x + 4, _y);
		SetPixelColor(BLACK); SetPixelColor(BLACK);SetPixelColor(LIGHTGREEN); SetPixelColor(LIGHTGREEN);
		SetPixelColor(LIGHTGREEN); SetPixelColor(LIGHTGREEN);SetPixelColor(BLACK); SetPixelColor(BLACK);
		CustomConsole.GotoXY(_x + 2, _y + 1);
		SetPixelColor(BLACK);SetPixelColor(LIGHTGREEN);SetPixelColor(LIGHTGREEN);SetPixelColor(LIGHTGREEN);
		SetPixelColor(GREEN);SetPixelColor(GREEN);SetPixelColor(GREEN);
		SetPixelColor(LIGHTGREEN);SetPixelColor(LIGHTGREEN);SetPixelColor(BLACK);
		CustomConsole.GotoXY(_x, _y + 2);
		SetPixelColor(BLACK);SetPixelColor(LIGHTGREEN);SetPixelColor(GREEN);SetPixelColor(LIGHTGREEN);SetPixelColor(LIGHTGREEN);
		SetPixelColor(GREEN);SetPixelColor(GREEN);SetPixelColor(GREEN);SetPixelColor(GREEN);SetPixelColor(GREEN);
		SetPixelColor(LIGHTGREEN);SetPixelColor(BLACK);
		CustomConsole.GotoXY(_x, _y + 3);
		SetPixelColor(BLACK);SetPixelColor(LIGHTGREEN);SetPixelColor(GREEN);SetPixelColor(BLACK);SetPixelColor(GREEN);
		SetPixelColor(GREEN);SetPixelColor(GREEN);SetPixelColor(GREEN);SetPixelColor(BLACK);SetPixelColor(GREEN);
		SetPixelColor(LIGHTGREEN);SetPixelColor(BLACK);
		CustomConsole.GotoXY(_x - 2, _y + 4);
		SetPixelColor(BLACK);SetPixelColor(LIGHTGREEN);SetPixelColor(GREEN);SetPixelColor(GREEN);SetPixelColor(BLACK);
		SetPixelColor(GREEN);SetPixelColor(GREEN);SetPixelColor(GREEN);SetPixelColor(GREEN);SetPixelColor(BLACK);
		SetPixelColor(GREEN);SetPixelColor(GREEN);SetPixelColor(LIGHTGREEN);SetPixelColor(BLACK);
		CustomConsole.GotoXY(_x - 2, _y + 5);
		SetPixelColor(BLACK);SetPixelColor(LIGHTGREEN);SetPixelColor(GREEN);SetPixelColor(GREEN);SetPixelColor(BLACK);
		SetPixelColor(GREEN);SetPixelColor(GREEN);SetPixelColor(GREEN);SetPixelColor(GREEN);SetPixelColor(BLACK);
		SetPixelColor(GREEN);SetPixelColor(GREEN);SetPixelColor(LIGHTGREEN);SetPixelColor(BLACK);
		CustomConsole.GotoXY(_x - 2, _y + 6);
		SetPixelColor(BLACK);SetPixelColor(LIGHTGREEN);SetPixelColor(GREEN);SetPixelColor(LIGHTRED);
		SetPixelColor(LIGHTRED);SetPixelColor(GREEN);SetPixelColor(GREEN);SetPixelColor(GREEN);SetPixelColor(GREEN);
		SetPixelColor(LIGHTRED);SetPixelColor(LIGHTRED);SetPixelColor(GREEN);SetPixelColor(LIGHTGREEN);SetPixelColor(BLACK);
		CustomConsole.GotoXY(_x - 2, _y + 7);
		SetPixelColor(BLACK);SetPixelColor(LIGHTGREEN);SetPixelColor(GREEN);SetPixelColor(GREEN);
		SetPixelColor(GREEN);SetPixelColor(GREEN);SetPixelColor(GREEN);SetPixelColor(GREEN);SetPixelColor(GREEN);
		SetPixelColor(GREEN);SetPixelColor(GREEN);SetPixelColor(GREEN);
		SetPixelColor(LIGHTGREEN);SetPixelColor(BLACK);
		CustomConsole.GotoXY(_x - 2, _y + 8);
		SetPixelColor(BLACK);SetPixelColor(GREEN);SetPixelColor(GREEN);SetPixelColor(GREEN);SetPixelColor(GREEN);
		SetPixelColor(GREEN);SetPixelColor(GREEN);SetPixelColor(GREEN);SetPixelColor(GREEN);
		SetPixelColor(GREEN);SetPixelColor(GREEN);SetPixelColor(GREEN);SetPixelColor(GREEN);SetPixelColor(BLACK);
		CustomConsole.GotoXY(_x, _y + 9);
		SetPixelColor(BLACK);SetPixelColor(GREEN);SetPixelColor(GREEN);SetPixelColor(GREEN);SetPixelColor(GREEN);
		SetPixelColor(GREEN);SetPixelColor(GREEN);SetPixelColor(GREEN);SetPixelColor(GREEN);
		SetPixelColor(GREEN);SetPixelColor(GREEN);SetPixelColor(BLACK);
		CustomConsole.GotoXY(_x + 2, _y + 10);
		SetPixelColor(BLACK);SetPixelColor(BLACK);SetPixelColor(GREEN);SetPixelColor(GREEN);SetPixelColor(GREEN);
		SetPixelColor(GREEN);SetPixelColor(GREEN);SetPixelColor(GREEN);	SetPixelColor(BLACK);SetPixelColor(BLACK);
		CustomConsole.GotoXY(_x + 6, _y + 11);
		SetPixelColor(BLACK);SetPixelColor(BLACK);SetPixelColor(BLACK);
		SetPixelColor(BLACK);SetPixelColor(BLACK);SetPixelColor(BLACK);
		break;
	case 7:
		CustomConsole.GotoXY(_x + 8, _y - 1);
		SetPixelColor(BLACK); SetPixelColor(BLACK); SetPixelColor(BLACK); SetPixelColor(BLACK);
		CustomConsole.GotoXY(_x + 4, _y);
		SetPixelColor(BLACK); SetPixelColor(BLACK);SetPixelColor(LIGHTGREEN); SetPixelColor(LIGHTGREEN);
		SetPixelColor(LIGHTGREEN); SetPixelColor(LIGHTGREEN);SetPixelColor(BLACK); SetPixelColor(BLACK);
		CustomConsole.GotoXY(_x + 2, _y + 1);
		SetPixelColor(BLACK);SetPixelColor(LIGHTGREEN);SetPixelColor(LIGHTGREEN);SetPixelColor(LIGHTGREEN);
		SetPixelColor(GREEN);SetPixelColor(GREEN);SetPixelColor(GREEN);
		SetPixelColor(LIGHTGREEN);SetPixelColor(LIGHTGREEN);SetPixelColor(BLACK);
		CustomConsole.GotoXY(_x, _y + 2);
		SetPixelColor(BLACK);SetPixelColor(LIGHTGREEN);SetPixelColor(GREEN);SetPixelColor(GREEN);SetPixelColor(GREEN);
		SetPixelColor(GREEN);SetPixelColor(GREEN);SetPixelColor(GREEN);SetPixelColor(GREEN);SetPixelColor(GREEN);
		SetPixelColor(LIGHTGREEN);SetPixelColor(BLACK);
		CustomConsole.GotoXY(_x, _y + 3);
		SetPixelColor(BLACK);SetPixelColor(LIGHTGREEN);SetPixelColor(GREEN);SetPixelColor(BLACK);SetPixelColor(GREEN);
		SetPixelColor(GREEN);SetPixelColor(GREEN);SetPixelColor(GREEN);SetPixelColor(BLACK);SetPixelColor(GREEN);
		SetPixelColor(LIGHTGREEN);SetPixelColor(BLACK);
		CustomConsole.GotoXY(_x - 2, _y + 4);
		SetPixelColor(BLACK);SetPixelColor(LIGHTGREEN);SetPixelColor(GREEN);SetPixelColor(GREEN);SetPixelColor(BLACK);
		SetPixelColor(GREEN);SetPixelColor(GREEN);SetPixelColor(GREEN);SetPixelColor(GREEN);SetPixelColor(BLACK);
		SetPixelColor(GREEN);SetPixelColor(GREEN);SetPixelColor(LIGHTGREEN);SetPixelColor(BLACK);
		CustomConsole.GotoXY(_x - 2, _y + 5);
		SetPixelColor(BLACK);SetPixelColor(LIGHTGREEN);SetPixelColor(GREEN);SetPixelColor(GREEN);SetPixelColor(BLACK);
		SetPixelColor(GREEN);SetPixelColor(GREEN);SetPixelColor(GREEN);SetPixelColor(GREEN);SetPixelColor(BLACK);
		SetPixelColor(GREEN);SetPixelColor(GREEN);SetPixelColor(LIGHTGREEN);SetPixelColor(BLACK);
		CustomConsole.GotoXY(_x - 2, _y + 6);
		SetPixelColor(BLACK);SetPixelColor(LIGHTGREEN);SetPixelColor(GREEN);SetPixelColor(LIGHTRED);
		SetPixelColor(LIGHTRED);SetPixelColor(GREEN);SetPixelColor(GREEN);SetPixelColor(GREEN);SetPixelColor(GREEN);
		SetPixelColor(LIGHTRED);SetPixelColor(LIGHTRED);SetPixelColor(GREEN);SetPixelColor(LIGHTGREEN);SetPixelColor(BLACK);
		CustomConsole.GotoXY(_x - 2, _y + 7);
		SetPixelColor(BLACK);SetPixelColor(LIGHTGREEN);SetPixelColor(GREEN);SetPixelColor(GREEN);
		SetPixelColor(GREEN);SetPixelColor(GREEN);SetPixelColor(GREEN);SetPixelColor(GREEN);SetPixelColor(GREEN);
		SetPixelColor(GREEN);SetPixelColor(GREEN);SetPixelColor(GREEN);
		SetPixelColor(LIGHTGREEN);SetPixelColor(BLACK);
		CustomConsole.GotoXY(_x - 2, _y + 8);
		SetPixelColor(BLACK);SetPixelColor(GREEN);SetPixelColor(GREEN);SetPixelColor(GREEN);SetPixelColor(GREEN);
		SetPixelColor(GREEN);SetPixelColor(GREEN);SetPixelColor(GREEN);SetPixelColor(GREEN);
		SetPixelColor(GREEN);SetPixelColor(GREEN);SetPixelColor(GREEN);SetPixelColor(GREEN);SetPixelColor(BLACK);
		CustomConsole.GotoXY(_x, _y + 9);
		SetPixelColor(BLACK);SetPixelColor(GREEN);SetPixelColor(GREEN);SetPixelColor(GREEN);SetPixelColor(GREEN);
		SetPixelColor(GREEN);SetPixelColor(GREEN);SetPixelColor(GREEN);SetPixelColor(GREEN);
		SetPixelColor(GREEN);SetPixelColor(GREEN);SetPixelColor(BLACK);
		CustomConsole.GotoXY(_x + 2, _y + 10);
		SetPixelColor(BLACK);SetPixelColor(BLACK);SetPixelColor(GREEN);SetPixelColor(GREEN);SetPixelColor(GREEN);
		SetPixelColor(GREEN);SetPixelColor(GREEN);SetPixelColor(GREEN);	SetPixelColor(BLACK);SetPixelColor(BLACK);
		CustomConsole.GotoXY(_x + 6, _y + 11);
		SetPixelColor(BLACK);SetPixelColor(BLACK);SetPixelColor(BLACK);
		SetPixelColor(BLACK);SetPixelColor(BLACK);SetPixelColor(BLACK);
		break;
	case 8:
		CustomConsole.GotoXY(_x + 8, _y - 1);
		SetPixelColor(BLACK); SetPixelColor(BLACK); SetPixelColor(BLACK); SetPixelColor(BLACK);
		CustomConsole.GotoXY(_x + 4, _y);
		SetPixelColor(BLACK); SetPixelColor(BLACK);SetPixelColor(LIGHTGREEN); SetPixelColor(LIGHTGREEN);
		SetPixelColor(LIGHTGREEN); SetPixelColor(LIGHTGREEN);SetPixelColor(BLACK); SetPixelColor(BLACK);
		CustomConsole.GotoXY(_x + 2, _y + 1);
		SetPixelColor(BLACK);SetPixelColor(LIGHTGREEN);SetPixelColor(LIGHTGREEN);SetPixelColor(LIGHTGREEN);
		SetPixelColor(GREEN);SetPixelColor(GREEN);SetPixelColor(GREEN);
		SetPixelColor(LIGHTGREEN);SetPixelColor(LIGHTGREEN);SetPixelColor(BLACK);
		CustomConsole.GotoXY(_x, _y + 2);
		SetPixelColor(BLACK);SetPixelColor(LIGHTGREEN);SetPixelColor(GREEN);SetPixelColor(BLACK);SetPixelColor(LIGHTGREEN);
		SetPixelColor(GREEN);SetPixelColor(GREEN);SetPixelColor(GREEN);SetPixelColor(BLACK);SetPixelColor(GREEN);
		SetPixelColor(LIGHTGREEN);SetPixelColor(BLACK);
		CustomConsole.GotoXY(_x, _y + 3);
		SetPixelColor(BLACK);SetPixelColor(LIGHTGREEN);SetPixelColor(GREEN);SetPixelColor(BLACK);SetPixelColor(GREEN);
		SetPixelColor(GREEN);SetPixelColor(GREEN);SetPixelColor(GREEN);SetPixelColor(BLACK);SetPixelColor(GREEN);
		SetPixelColor(LIGHTGREEN);SetPixelColor(BLACK);
		CustomConsole.GotoXY(_x - 2, _y + 4);
		SetPixelColor(BLACK);SetPixelColor(LIGHTGREEN);SetPixelColor(GREEN);SetPixelColor(GREEN);SetPixelColor(BLACK);
		SetPixelColor(GREEN);SetPixelColor(GREEN);SetPixelColor(GREEN);SetPixelColor(GREEN);SetPixelColor(BLACK);
		SetPixelColor(GREEN);SetPixelColor(GREEN);SetPixelColor(LIGHTGREEN);SetPixelColor(BLACK);
		CustomConsole.GotoXY(_x - 2, _y + 5);
		SetPixelColor(BLACK);SetPixelColor(LIGHTGREEN);SetPixelColor(GREEN);SetPixelColor(LIGHTRED);SetPixelColor(LIGHTRED);
		SetPixelColor(GREEN);SetPixelColor(GREEN);SetPixelColor(GREEN);SetPixelColor(GREEN);SetPixelColor(LIGHTRED);
		SetPixelColor(LIGHTRED);SetPixelColor(GREEN);SetPixelColor(LIGHTGREEN);SetPixelColor(BLACK);
		CustomConsole.GotoXY(_x - 2, _y + 6);
		SetPixelColor(BLACK);SetPixelColor(LIGHTGREEN);SetPixelColor(GREEN);SetPixelColor(GREEN);
		SetPixelColor(GREEN);SetPixelColor(GREEN);SetPixelColor(GREEN);SetPixelColor(GREEN);SetPixelColor(GREEN);
		SetPixelColor(GREEN);SetPixelColor(GREEN);SetPixelColor(GREEN);SetPixelColor(LIGHTGREEN);SetPixelColor(BLACK);
		CustomConsole.GotoXY(_x - 2, _y + 7);
		SetPixelColor(BLACK);SetPixelColor(LIGHTGREEN);SetPixelColor(GREEN);SetPixelColor(GREEN);
		SetPixelColor(GREEN);SetPixelColor(GREEN);SetPixelColor(GREEN);SetPixelColor(GREEN);SetPixelColor(GREEN);
		SetPixelColor(GREEN);SetPixelColor(GREEN);SetPixelColor(GREEN);
		SetPixelColor(LIGHTGREEN);SetPixelColor(BLACK);
		CustomConsole.GotoXY(_x - 2, _y + 8);
		SetPixelColor(BLACK);SetPixelColor(GREEN);SetPixelColor(GREEN);SetPixelColor(GREEN);SetPixelColor(GREEN);
		SetPixelColor(GREEN);SetPixelColor(GREEN);SetPixelColor(GREEN);SetPixelColor(GREEN);
		SetPixelColor(GREEN);SetPixelColor(GREEN);SetPixelColor(GREEN);SetPixelColor(GREEN);SetPixelColor(BLACK);
		CustomConsole.GotoXY(_x, _y + 9);
		SetPixelColor(BLACK);SetPixelColor(GREEN);SetPixelColor(GREEN);SetPixelColor(GREEN);SetPixelColor(GREEN);
		SetPixelColor(GREEN);SetPixelColor(GREEN);SetPixelColor(GREEN);SetPixelColor(GREEN);
		SetPixelColor(GREEN);SetPixelColor(GREEN);SetPixelColor(BLACK);
		CustomConsole.GotoXY(_x + 2, _y + 10);
		SetPixelColor(BLACK);SetPixelColor(BLACK);SetPixelColor(GREEN);SetPixelColor(GREEN);SetPixelColor(GREEN);
		SetPixelColor(GREEN);SetPixelColor(GREEN);SetPixelColor(GREEN);	SetPixelColor(BLACK);SetPixelColor(BLACK);
		CustomConsole.GotoXY(_x + 6, _y + 11);
		SetPixelColor(BLACK);SetPixelColor(BLACK);SetPixelColor(BLACK);
		SetPixelColor(BLACK);SetPixelColor(BLACK);SetPixelColor(BLACK);
		break;
	case 9:
		CustomConsole.GotoXY(_x + 8, _y);
		SetPixelColor(BLACK); SetPixelColor(BLACK); SetPixelColor(BLACK); SetPixelColor(BLACK);
		CustomConsole.GotoXY(_x + 4, _y + 1);
		SetPixelColor(BLACK); SetPixelColor(BLACK);SetPixelColor(LIGHTGREEN); SetPixelColor(LIGHTGREEN);
		SetPixelColor(LIGHTGREEN); SetPixelColor(LIGHTGREEN);SetPixelColor(BLACK); SetPixelColor(BLACK);
		CustomConsole.GotoXY(_x + 2, _y + 2);
		SetPixelColor(BLACK);SetPixelColor(LIGHTGREEN);SetPixelColor(BLACK);SetPixelColor(LIGHTGREEN);
		SetPixelColor(GREEN);SetPixelColor(GREEN);SetPixelColor(GREEN);
		SetPixelColor(BLACK);SetPixelColor(LIGHTGREEN);SetPixelColor(BLACK);
		CustomConsole.GotoXY(_x, _y + 3);
		SetPixelColor(BLACK);SetPixelColor(LIGHTGREEN);SetPixelColor(GREEN);SetPixelColor(BLACK);SetPixelColor(LIGHTGREEN);
		SetPixelColor(GREEN);SetPixelColor(GREEN);SetPixelColor(GREEN);SetPixelColor(BLACK);SetPixelColor(GREEN);
		SetPixelColor(LIGHTGREEN);SetPixelColor(BLACK);
		CustomConsole.GotoXY(_x, _y + 4);
		SetPixelColor(BLACK);SetPixelColor(LIGHTGREEN);SetPixelColor(GREEN);SetPixelColor(BLACK);SetPixelColor(GREEN);
		SetPixelColor(GREEN);SetPixelColor(GREEN);SetPixelColor(GREEN);SetPixelColor(BLACK);SetPixelColor(GREEN);
		SetPixelColor(LIGHTGREEN);SetPixelColor(BLACK);
		CustomConsole.GotoXY(_x - 2, _y + 5);
		SetPixelColor(BLACK);SetPixelColor(LIGHTGREEN);SetPixelColor(GREEN);SetPixelColor(LIGHTRED);SetPixelColor(LIGHTRED);
		SetPixelColor(GREEN);SetPixelColor(GREEN);SetPixelColor(GREEN);SetPixelColor(GREEN);SetPixelColor(LIGHTRED);
		SetPixelColor(LIGHTRED);SetPixelColor(GREEN);SetPixelColor(LIGHTGREEN);SetPixelColor(BLACK);
		CustomConsole.GotoXY(_x - 2, _y + 6);
		SetPixelColor(BLACK);SetPixelColor(LIGHTGREEN);SetPixelColor(GREEN);SetPixelColor(GREEN);
		SetPixelColor(GREEN);SetPixelColor(GREEN);SetPixelColor(GREEN);SetPixelColor(GREEN);SetPixelColor(GREEN);
		SetPixelColor(GREEN);SetPixelColor(GREEN);SetPixelColor(GREEN);SetPixelColor(LIGHTGREEN);SetPixelColor(BLACK);
		CustomConsole.GotoXY(_x - 2, _y + 7);
		SetPixelColor(BLACK);SetPixelColor(LIGHTGREEN);SetPixelColor(GREEN);SetPixelColor(GREEN);
		SetPixelColor(GREEN);SetPixelColor(GREEN);SetPixelColor(GREEN);SetPixelColor(GREEN);SetPixelColor(GREEN);
		SetPixelColor(GREEN);SetPixelColor(GREEN);SetPixelColor(GREEN);
		SetPixelColor(LIGHTGREEN);SetPixelColor(BLACK);
		CustomConsole.GotoXY(_x - 2, _y + 8);
		SetPixelColor(BLACK);SetPixelColor(GREEN);SetPixelColor(GREEN);SetPixelColor(GREEN);SetPixelColor(GREEN);
		SetPixelColor(GREEN);SetPixelColor(GREEN);SetPixelColor(GREEN);SetPixelColor(GREEN);
		SetPixelColor(GREEN);SetPixelColor(GREEN);SetPixelColor(GREEN);SetPixelColor(GREEN);SetPixelColor(BLACK);
		CustomConsole.GotoXY(_x, _y + 9);
		SetPixelColor(BLACK);SetPixelColor(GREEN);SetPixelColor(GREEN);SetPixelColor(GREEN);SetPixelColor(GREEN);
		SetPixelColor(GREEN);SetPixelColor(GREEN);SetPixelColor(GREEN);SetPixelColor(GREEN);
		SetPixelColor(GREEN);SetPixelColor(GREEN);SetPixelColor(BLACK);
		CustomConsole.GotoXY(_x + 2, _y + 10);
		SetPixelColor(BLACK);SetPixelColor(BLACK);SetPixelColor(GREEN);SetPixelColor(GREEN);SetPixelColor(GREEN);
		SetPixelColor(GREEN);SetPixelColor(GREEN);SetPixelColor(GREEN);	SetPixelColor(BLACK);SetPixelColor(BLACK);
		CustomConsole.GotoXY(_x + 6, _y + 11);
		SetPixelColor(BLACK);SetPixelColor(BLACK);SetPixelColor(BLACK);
		SetPixelColor(BLACK);SetPixelColor(BLACK);SetPixelColor(BLACK);
		break;

	default:
		break;
	}
}

void Character::RightRender()
{
	switch (_animationIndex)
	{
		// ������ �̵�
	case 0:
		CustomConsole.GotoXY(_x + 8, _y);
		SetPixelColor(BLACK); SetPixelColor(BLACK); SetPixelColor(BLACK); SetPixelColor(BLACK);
		CustomConsole.GotoXY(_x + 4, _y + 1);
		SetPixelColor(BLACK); SetPixelColor(BLACK); SetPixelColor(LIGHTGREEN); SetPixelColor(LIGHTGREEN);
		SetPixelColor(LIGHTGREEN); SetPixelColor(LIGHTGREEN); SetPixelColor(BLACK); SetPixelColor(BLACK);
		CustomConsole.GotoXY(_x + 2, _y + 2);
		SetPixelColor(BLACK); SetPixelColor(LIGHTGREEN); SetPixelColor(LIGHTGREEN); SetPixelColor(GREEN); SetPixelColor(GREEN);
		SetPixelColor(GREEN); SetPixelColor(LIGHTGREEN); SetPixelColor(LIGHTGREEN); SetPixelColor(LIGHTGREEN);SetPixelColor(BLACK);
		CustomConsole.GotoXY(_x, _y + 3);
		SetPixelColor(BLACK); SetPixelColor(LIGHTGREEN); SetPixelColor(GREEN); SetPixelColor(GREEN); SetPixelColor(GREEN);
		SetPixelColor(GREEN);SetPixelColor(GREEN);SetPixelColor(LIGHTGREEN);SetPixelColor(LIGHTGREEN);SetPixelColor(GREEN);
		SetPixelColor(LIGHTGREEN);SetPixelColor(BLACK);
		CustomConsole.GotoXY(_x, _y + 4);
		SetPixelColor(BLACK); SetPixelColor(LIGHTGREEN); SetPixelColor(GREEN);SetPixelColor(GREEN);SetPixelColor(GREEN);
		SetPixelColor(GREEN);SetPixelColor(BLACK);SetPixelColor(GREEN);SetPixelColor(GREEN);SetPixelColor(BLACK);
		SetPixelColor(LIGHTGREEN);SetPixelColor(BLACK);
		CustomConsole.GotoXY(_x - 2, _y + 5);
		SetPixelColor(BLACK); SetPixelColor(LIGHTGREEN); SetPixelColor(GREEN);SetPixelColor(GREEN);SetPixelColor(GREEN);
		SetPixelColor(GREEN);SetPixelColor(GREEN);SetPixelColor(BLACK);SetPixelColor(GREEN);SetPixelColor(GREEN);
		SetPixelColor(BLACK);SetPixelColor(GREEN);SetPixelColor(LIGHTGREEN);SetPixelColor(BLACK);
		CustomConsole.GotoXY(_x - 2, _y + 6);
		SetPixelColor(BLACK); SetPixelColor(LIGHTGREEN); SetPixelColor(GREEN);SetPixelColor(GREEN);SetPixelColor(GREEN);
		SetPixelColor(GREEN);SetPixelColor(GREEN);SetPixelColor(BLACK);SetPixelColor(GREEN);SetPixelColor(GREEN);
		SetPixelColor(BLACK);SetPixelColor(GREEN);SetPixelColor(LIGHTGREEN);SetPixelColor(BLACK);
		CustomConsole.GotoXY(_x - 2, _y + 7);
		SetPixelColor(BLACK); SetPixelColor(LIGHTGREEN); SetPixelColor(GREEN);SetPixelColor(GREEN);SetPixelColor(GREEN);
		SetPixelColor(GREEN);SetPixelColor(LIGHTRED);SetPixelColor(LIGHTRED);SetPixelColor(GREEN);SetPixelColor(GREEN);
		SetPixelColor(LIGHTRED);SetPixelColor(LIGHTRED);SetPixelColor(LIGHTGREEN);SetPixelColor(BLACK);
		CustomConsole.GotoXY(_x - 2, _y + 8);
		SetPixelColor(BLACK);SetPixelColor(GREEN); SetPixelColor(GREEN);SetPixelColor(GREEN);SetPixelColor(GREEN);
		SetPixelColor(GREEN);SetPixelColor(GREEN);SetPixelColor(GREEN);SetPixelColor(GREEN);SetPixelColor(GREEN);
		SetPixelColor(GREEN);SetPixelColor(GREEN);SetPixelColor(GREEN);SetPixelColor(BLACK);
		CustomConsole.GotoXY(_x, _y + 9);
		SetPixelColor(BLACK);SetPixelColor(GREEN);SetPixelColor(GREEN);SetPixelColor(GREEN);SetPixelColor(GREEN);
		SetPixelColor(GREEN);SetPixelColor(GREEN);SetPixelColor(GREEN);SetPixelColor(GREEN);SetPixelColor(GREEN);
		SetPixelColor(GREEN);SetPixelColor(BLACK);
		CustomConsole.GotoXY(_x + 2, _y + 10);
		SetPixelColor(BLACK);SetPixelColor(BLACK);SetPixelColor(GREEN);SetPixelColor(GREEN);SetPixelColor(GREEN);
		SetPixelColor(GREEN);SetPixelColor(GREEN);SetPixelColor(GREEN);SetPixelColor(BLACK);SetPixelColor(BLACK);
		CustomConsole.GotoXY(_x + 6, _y + 11);
		SetPixelColor(BLACK);SetPixelColor(BLACK);SetPixelColor(BLACK);SetPixelColor(BLACK);
		SetPixelColor(BLACK);SetPixelColor(BLACK);
		break;
	case 1:
		CustomConsole.GotoXY(_x + 8, _y + 1);
		SetPixelColor(BLACK); SetPixelColor(BLACK); SetPixelColor(BLACK); SetPixelColor(BLACK);
		CustomConsole.GotoXY(_x + 4, _y + 2);
		SetPixelColor(BLACK); SetPixelColor(BLACK); SetPixelColor(LIGHTGREEN); SetPixelColor(LIGHTGREEN);
		SetPixelColor(LIGHTGREEN); SetPixelColor(LIGHTGREEN); SetPixelColor(BLACK); SetPixelColor(BLACK);
		CustomConsole.GotoXY(_x + 2, _y + 3);
		SetPixelColor(BLACK); SetPixelColor(LIGHTGREEN); SetPixelColor(LIGHTGREEN); SetPixelColor(GREEN); SetPixelColor(GREEN);
		SetPixelColor(GREEN); SetPixelColor(LIGHTGREEN); SetPixelColor(LIGHTGREEN); SetPixelColor(LIGHTGREEN);SetPixelColor(BLACK);
		CustomConsole.GotoXY(_x, _y + 4);
		SetPixelColor(BLACK); SetPixelColor(LIGHTGREEN); SetPixelColor(GREEN); SetPixelColor(GREEN); SetPixelColor(GREEN);
		SetPixelColor(GREEN);SetPixelColor(GREEN);SetPixelColor(LIGHTGREEN);SetPixelColor(LIGHTGREEN);SetPixelColor(GREEN);
		SetPixelColor(LIGHTGREEN);SetPixelColor(BLACK);
		CustomConsole.GotoXY(_x - 2, _y + 5);
		SetPixelColor(BLACK); SetPixelColor(LIGHTGREEN); SetPixelColor(GREEN);SetPixelColor(GREEN);SetPixelColor(GREEN);
		SetPixelColor(GREEN);SetPixelColor(GREEN);SetPixelColor(BLACK);SetPixelColor(GREEN);SetPixelColor(GREEN);
		SetPixelColor(BLACK);SetPixelColor(GREEN);SetPixelColor(LIGHTGREEN);SetPixelColor(BLACK);
		CustomConsole.GotoXY(_x - 2, _y + 6);
		SetPixelColor(BLACK); SetPixelColor(LIGHTGREEN); SetPixelColor(GREEN);SetPixelColor(GREEN);SetPixelColor(GREEN);
		SetPixelColor(GREEN);SetPixelColor(GREEN);SetPixelColor(BLACK);SetPixelColor(GREEN);SetPixelColor(GREEN);
		SetPixelColor(BLACK);SetPixelColor(GREEN);SetPixelColor(LIGHTGREEN);SetPixelColor(BLACK);
		CustomConsole.GotoXY(_x - 2, _y + 7);
		SetPixelColor(BLACK); SetPixelColor(LIGHTGREEN); SetPixelColor(GREEN);SetPixelColor(GREEN);SetPixelColor(GREEN);
		SetPixelColor(GREEN);SetPixelColor(GREEN);SetPixelColor(BLACK);SetPixelColor(GREEN);SetPixelColor(GREEN);
		SetPixelColor(BLACK);SetPixelColor(GREEN);SetPixelColor(LIGHTGREEN);SetPixelColor(BLACK);
		CustomConsole.GotoXY(_x - 2, _y + 8);
		SetPixelColor(BLACK);SetPixelColor(GREEN); SetPixelColor(GREEN);SetPixelColor(GREEN);SetPixelColor(GREEN);
		SetPixelColor(GREEN);SetPixelColor(LIGHTRED);SetPixelColor(LIGHTRED);SetPixelColor(GREEN);SetPixelColor(GREEN);
		SetPixelColor(LIGHTRED);SetPixelColor(LIGHTRED);SetPixelColor(GREEN);SetPixelColor(BLACK);
		CustomConsole.GotoXY(_x, _y + 9);
		SetPixelColor(BLACK);SetPixelColor(GREEN);SetPixelColor(GREEN);SetPixelColor(GREEN);SetPixelColor(GREEN);
		SetPixelColor(GREEN);SetPixelColor(GREEN);SetPixelColor(GREEN);SetPixelColor(GREEN);SetPixelColor(GREEN);
		SetPixelColor(GREEN);SetPixelColor(BLACK);
		CustomConsole.GotoXY(_x + 2, _y + 10);
		SetPixelColor(BLACK);SetPixelColor(BLACK);SetPixelColor(GREEN);SetPixelColor(GREEN);SetPixelColor(GREEN);
		SetPixelColor(GREEN);SetPixelColor(GREEN);SetPixelColor(GREEN);SetPixelColor(BLACK);SetPixelColor(BLACK);
		CustomConsole.GotoXY(_x + 6, _y + 11);
		SetPixelColor(BLACK);SetPixelColor(BLACK);SetPixelColor(BLACK);SetPixelColor(BLACK);
		SetPixelColor(BLACK);SetPixelColor(BLACK);
		break;
	case 2:
		CustomConsole.GotoXY(_x + 8, _y + 1);
		SetPixelColor(BLACK); SetPixelColor(BLACK); SetPixelColor(BLACK); SetPixelColor(BLACK);
		CustomConsole.GotoXY(_x + 4, _y + 2);
		SetPixelColor(BLACK); SetPixelColor(BLACK); SetPixelColor(LIGHTGREEN); SetPixelColor(LIGHTGREEN);
		SetPixelColor(LIGHTGREEN); SetPixelColor(LIGHTGREEN); SetPixelColor(BLACK); SetPixelColor(BLACK);
		CustomConsole.GotoXY(_x + 2, _y + 3);
		SetPixelColor(BLACK); SetPixelColor(LIGHTGREEN); SetPixelColor(LIGHTGREEN); SetPixelColor(GREEN); SetPixelColor(GREEN);
		SetPixelColor(GREEN); SetPixelColor(LIGHTGREEN); SetPixelColor(LIGHTGREEN); SetPixelColor(LIGHTGREEN);SetPixelColor(BLACK);
		CustomConsole.GotoXY(_x, _y + 4);
		SetPixelColor(BLACK); SetPixelColor(LIGHTGREEN); SetPixelColor(GREEN); SetPixelColor(GREEN); SetPixelColor(GREEN);
		SetPixelColor(GREEN);SetPixelColor(GREEN);SetPixelColor(LIGHTGREEN);SetPixelColor(LIGHTGREEN);SetPixelColor(GREEN);
		SetPixelColor(LIGHTGREEN);SetPixelColor(BLACK);
		CustomConsole.GotoXY(_x - 2, _y + 5);
		SetPixelColor(BLACK); SetPixelColor(LIGHTGREEN); SetPixelColor(GREEN);SetPixelColor(GREEN);SetPixelColor(GREEN);
		SetPixelColor(GREEN);SetPixelColor(GREEN);SetPixelColor(GREEN);SetPixelColor(GREEN);SetPixelColor(GREEN);
		SetPixelColor(GREEN);SetPixelColor(GREEN);SetPixelColor(LIGHTGREEN);SetPixelColor(BLACK);
		CustomConsole.GotoXY(_x - 2, _y + 6);
		SetPixelColor(BLACK); SetPixelColor(LIGHTGREEN); SetPixelColor(GREEN);SetPixelColor(GREEN);SetPixelColor(GREEN);
		SetPixelColor(GREEN);SetPixelColor(GREEN);SetPixelColor(BLACK);SetPixelColor(GREEN);SetPixelColor(GREEN);
		SetPixelColor(BLACK);SetPixelColor(GREEN);SetPixelColor(LIGHTGREEN);SetPixelColor(BLACK);
		CustomConsole.GotoXY(_x - 2, _y + 7);
		SetPixelColor(BLACK); SetPixelColor(LIGHTGREEN); SetPixelColor(GREEN);SetPixelColor(GREEN);SetPixelColor(GREEN);
		SetPixelColor(GREEN);SetPixelColor(GREEN);SetPixelColor(BLACK);SetPixelColor(GREEN);SetPixelColor(GREEN);
		SetPixelColor(BLACK);SetPixelColor(GREEN);SetPixelColor(LIGHTGREEN);SetPixelColor(BLACK);
		CustomConsole.GotoXY(_x - 2, _y + 8);
		SetPixelColor(BLACK);SetPixelColor(GREEN); SetPixelColor(GREEN);SetPixelColor(GREEN);SetPixelColor(GREEN);
		SetPixelColor(GREEN);SetPixelColor(GREEN);SetPixelColor(BLACK);SetPixelColor(GREEN);SetPixelColor(GREEN);
		SetPixelColor(BLACK);SetPixelColor(GREEN);SetPixelColor(GREEN);SetPixelColor(BLACK);
		CustomConsole.GotoXY(_x, _y + 9);
		SetPixelColor(BLACK);SetPixelColor(GREEN);SetPixelColor(GREEN);SetPixelColor(GREEN);SetPixelColor(GREEN);
		SetPixelColor(LIGHTRED);SetPixelColor(LIGHTRED);SetPixelColor(GREEN);SetPixelColor(GREEN);SetPixelColor(LIGHTRED);
		SetPixelColor(LIGHTRED);SetPixelColor(BLACK);
		CustomConsole.GotoXY(_x + 2, _y + 10);
		SetPixelColor(BLACK);SetPixelColor(BLACK);SetPixelColor(GREEN);SetPixelColor(GREEN);SetPixelColor(GREEN);
		SetPixelColor(GREEN);SetPixelColor(GREEN);SetPixelColor(GREEN);SetPixelColor(BLACK);SetPixelColor(BLACK);
		CustomConsole.GotoXY(_x + 6, _y + 11);
		SetPixelColor(BLACK);SetPixelColor(BLACK);SetPixelColor(BLACK);SetPixelColor(BLACK);
		SetPixelColor(BLACK);SetPixelColor(BLACK);
		break;
	case 3:
		CustomConsole.GotoXY(_x + 8, _y);
		SetPixelColor(BLACK); SetPixelColor(BLACK); SetPixelColor(BLACK); SetPixelColor(BLACK);
		CustomConsole.GotoXY(_x + 4, _y + 1);
		SetPixelColor(BLACK); SetPixelColor(BLACK); SetPixelColor(LIGHTGREEN); SetPixelColor(LIGHTGREEN);
		SetPixelColor(LIGHTGREEN); SetPixelColor(LIGHTGREEN); SetPixelColor(BLACK); SetPixelColor(BLACK);
		CustomConsole.GotoXY(_x + 2, _y + 2);
		SetPixelColor(BLACK); SetPixelColor(LIGHTGREEN); SetPixelColor(LIGHTGREEN); SetPixelColor(GREEN); SetPixelColor(GREEN);
		SetPixelColor(GREEN); SetPixelColor(LIGHTGREEN); SetPixelColor(LIGHTGREEN); SetPixelColor(LIGHTGREEN);SetPixelColor(BLACK);
		CustomConsole.GotoXY(_x, _y + 3);
		SetPixelColor(BLACK); SetPixelColor(LIGHTGREEN); SetPixelColor(GREEN); SetPixelColor(GREEN); SetPixelColor(GREEN);
		SetPixelColor(GREEN);SetPixelColor(GREEN);SetPixelColor(LIGHTGREEN);SetPixelColor(LIGHTGREEN);SetPixelColor(GREEN);
		SetPixelColor(LIGHTGREEN);SetPixelColor(BLACK);
		CustomConsole.GotoXY(_x, _y + 4);
		SetPixelColor(BLACK); SetPixelColor(LIGHTGREEN); SetPixelColor(GREEN); SetPixelColor(GREEN); SetPixelColor(GREEN);
		SetPixelColor(GREEN);SetPixelColor(GREEN);SetPixelColor(GREEN);SetPixelColor(GREEN);SetPixelColor(GREEN);
		SetPixelColor(LIGHTGREEN);SetPixelColor(BLACK);
		CustomConsole.GotoXY(_x - 2, _y + 5);
		SetPixelColor(BLACK); SetPixelColor(LIGHTGREEN); SetPixelColor(GREEN);SetPixelColor(GREEN);SetPixelColor(GREEN);
		SetPixelColor(GREEN);SetPixelColor(GREEN);SetPixelColor(GREEN);SetPixelColor(GREEN);SetPixelColor(GREEN);
		SetPixelColor(GREEN);SetPixelColor(GREEN);SetPixelColor(LIGHTGREEN);SetPixelColor(BLACK);
		CustomConsole.GotoXY(_x - 2, _y + 6);
		SetPixelColor(BLACK); SetPixelColor(LIGHTGREEN); SetPixelColor(GREEN);SetPixelColor(GREEN);SetPixelColor(GREEN);
		SetPixelColor(GREEN);SetPixelColor(GREEN);SetPixelColor(BLACK);SetPixelColor(GREEN);SetPixelColor(GREEN);
		SetPixelColor(BLACK);SetPixelColor(GREEN);SetPixelColor(LIGHTGREEN);SetPixelColor(BLACK);
		CustomConsole.GotoXY(_x - 2, _y + 7);
		SetPixelColor(BLACK); SetPixelColor(LIGHTGREEN); SetPixelColor(GREEN);SetPixelColor(GREEN);SetPixelColor(GREEN);
		SetPixelColor(GREEN);SetPixelColor(GREEN);SetPixelColor(BLACK);SetPixelColor(GREEN);SetPixelColor(GREEN);
		SetPixelColor(BLACK);SetPixelColor(GREEN);SetPixelColor(LIGHTGREEN);SetPixelColor(BLACK);
		CustomConsole.GotoXY(_x - 2, _y + 8);
		SetPixelColor(BLACK);SetPixelColor(GREEN); SetPixelColor(GREEN);SetPixelColor(GREEN);SetPixelColor(GREEN);
		SetPixelColor(GREEN);SetPixelColor(GREEN);SetPixelColor(BLACK);SetPixelColor(GREEN);SetPixelColor(GREEN);
		SetPixelColor(BLACK);SetPixelColor(GREEN);SetPixelColor(GREEN);SetPixelColor(BLACK);
		CustomConsole.GotoXY(_x, _y + 9);
		SetPixelColor(BLACK);SetPixelColor(GREEN);SetPixelColor(GREEN);SetPixelColor(GREEN);SetPixelColor(GREEN);
		SetPixelColor(LIGHTRED);SetPixelColor(LIGHTRED);SetPixelColor(GREEN);SetPixelColor(GREEN);SetPixelColor(LIGHTRED);
		SetPixelColor(LIGHTRED);SetPixelColor(BLACK);
		CustomConsole.GotoXY(_x + 2, _y + 10);
		SetPixelColor(BLACK);SetPixelColor(BLACK);SetPixelColor(GREEN);SetPixelColor(GREEN);SetPixelColor(GREEN);
		SetPixelColor(GREEN);SetPixelColor(GREEN);SetPixelColor(GREEN);SetPixelColor(BLACK);SetPixelColor(BLACK);
		CustomConsole.GotoXY(_x + 6, _y + 11);
		SetPixelColor(BLACK);SetPixelColor(BLACK);SetPixelColor(BLACK);SetPixelColor(BLACK);
		SetPixelColor(BLACK);SetPixelColor(BLACK);
		break;
	case 4:
		CustomConsole.GotoXY(_x + 8, _y);
		SetPixelColor(BLACK); SetPixelColor(BLACK); SetPixelColor(BLACK); SetPixelColor(BLACK);
		CustomConsole.GotoXY(_x + 4, _y + 1);
		SetPixelColor(BLACK); SetPixelColor(BLACK); SetPixelColor(LIGHTGREEN); SetPixelColor(LIGHTGREEN);
		SetPixelColor(LIGHTGREEN); SetPixelColor(LIGHTGREEN); SetPixelColor(BLACK); SetPixelColor(BLACK);
		CustomConsole.GotoXY(_x + 2, _y + 2);
		SetPixelColor(BLACK); SetPixelColor(LIGHTGREEN); SetPixelColor(LIGHTGREEN); SetPixelColor(GREEN); SetPixelColor(GREEN);
		SetPixelColor(GREEN); SetPixelColor(LIGHTGREEN); SetPixelColor(LIGHTGREEN); SetPixelColor(LIGHTGREEN);SetPixelColor(BLACK);
		CustomConsole.GotoXY(_x, _y + 3);
		SetPixelColor(BLACK); SetPixelColor(LIGHTGREEN); SetPixelColor(GREEN); SetPixelColor(GREEN); SetPixelColor(GREEN);
		SetPixelColor(GREEN);SetPixelColor(GREEN);SetPixelColor(LIGHTGREEN);SetPixelColor(LIGHTGREEN);SetPixelColor(GREEN);
		SetPixelColor(LIGHTGREEN);SetPixelColor(BLACK);
		CustomConsole.GotoXY(_x, _y + 4);
		SetPixelColor(BLACK); SetPixelColor(LIGHTGREEN); SetPixelColor(GREEN);SetPixelColor(GREEN);SetPixelColor(GREEN);
		SetPixelColor(GREEN);SetPixelColor(GREEN);SetPixelColor(GREEN);SetPixelColor(GREEN);SetPixelColor(GREEN);
		SetPixelColor(LIGHTGREEN);SetPixelColor(BLACK);
		CustomConsole.GotoXY(_x - 2, _y + 5);
		SetPixelColor(BLACK); SetPixelColor(LIGHTGREEN); SetPixelColor(GREEN);SetPixelColor(GREEN);SetPixelColor(GREEN);
		SetPixelColor(GREEN);SetPixelColor(GREEN);SetPixelColor(BLACK);SetPixelColor(GREEN);SetPixelColor(GREEN);
		SetPixelColor(BLACK);SetPixelColor(GREEN);SetPixelColor(LIGHTGREEN);SetPixelColor(BLACK);
		CustomConsole.GotoXY(_x - 2, _y + 6);
		SetPixelColor(BLACK); SetPixelColor(LIGHTGREEN); SetPixelColor(GREEN);SetPixelColor(GREEN);SetPixelColor(GREEN);
		SetPixelColor(GREEN);SetPixelColor(GREEN);SetPixelColor(BLACK);SetPixelColor(GREEN);SetPixelColor(GREEN);
		SetPixelColor(BLACK);SetPixelColor(GREEN);SetPixelColor(LIGHTGREEN);SetPixelColor(BLACK);
		CustomConsole.GotoXY(_x - 2, _y + 7);
		SetPixelColor(BLACK); SetPixelColor(LIGHTGREEN); SetPixelColor(GREEN);SetPixelColor(GREEN);SetPixelColor(GREEN);
		SetPixelColor(GREEN);SetPixelColor(GREEN);SetPixelColor(BLACK);SetPixelColor(GREEN);SetPixelColor(GREEN);
		SetPixelColor(BLACK);SetPixelColor(GREEN);SetPixelColor(LIGHTGREEN);SetPixelColor(BLACK);
		CustomConsole.GotoXY(_x - 2, _y + 8);
		SetPixelColor(BLACK);SetPixelColor(GREEN); SetPixelColor(GREEN);SetPixelColor(GREEN);SetPixelColor(GREEN);
		SetPixelColor(GREEN);SetPixelColor(LIGHTRED);SetPixelColor(LIGHTRED);SetPixelColor(GREEN);SetPixelColor(GREEN);
		SetPixelColor(LIGHTRED);SetPixelColor(LIGHTRED);SetPixelColor(GREEN);SetPixelColor(BLACK);
		CustomConsole.GotoXY(_x, _y + 9);
		SetPixelColor(BLACK);SetPixelColor(GREEN);SetPixelColor(GREEN);SetPixelColor(GREEN);SetPixelColor(GREEN);
		SetPixelColor(GREEN);SetPixelColor(GREEN);SetPixelColor(GREEN);SetPixelColor(GREEN);SetPixelColor(GREEN);
		SetPixelColor(GREEN);SetPixelColor(BLACK);
		CustomConsole.GotoXY(_x + 2, _y + 10);
		SetPixelColor(BLACK);SetPixelColor(BLACK);SetPixelColor(GREEN);SetPixelColor(GREEN);SetPixelColor(GREEN);
		SetPixelColor(GREEN);SetPixelColor(GREEN);SetPixelColor(GREEN);SetPixelColor(BLACK);SetPixelColor(BLACK);
		CustomConsole.GotoXY(_x + 6, _y + 11);
		SetPixelColor(BLACK);SetPixelColor(BLACK);SetPixelColor(BLACK);SetPixelColor(BLACK);
		SetPixelColor(BLACK);SetPixelColor(BLACK);
		break;
	case 5:
		CustomConsole.GotoXY(_x + 8, _y);
		SetPixelColor(BLACK); SetPixelColor(BLACK); SetPixelColor(BLACK); SetPixelColor(BLACK);
		CustomConsole.GotoXY(_x + 4, _y + 1);
		SetPixelColor(BLACK); SetPixelColor(BLACK); SetPixelColor(LIGHTGREEN); SetPixelColor(LIGHTGREEN);
		SetPixelColor(LIGHTGREEN); SetPixelColor(LIGHTGREEN); SetPixelColor(BLACK); SetPixelColor(BLACK);
		CustomConsole.GotoXY(_x + 2, _y + 2);
		SetPixelColor(BLACK); SetPixelColor(LIGHTGREEN); SetPixelColor(LIGHTGREEN); SetPixelColor(GREEN); SetPixelColor(GREEN);
		SetPixelColor(GREEN); SetPixelColor(LIGHTGREEN); SetPixelColor(LIGHTGREEN); SetPixelColor(LIGHTGREEN);SetPixelColor(BLACK);
		CustomConsole.GotoXY(_x, _y + 3);
		SetPixelColor(BLACK); SetPixelColor(LIGHTGREEN); SetPixelColor(GREEN); SetPixelColor(GREEN); SetPixelColor(GREEN);
		SetPixelColor(GREEN);SetPixelColor(GREEN);SetPixelColor(LIGHTGREEN);SetPixelColor(LIGHTGREEN);SetPixelColor(GREEN);
		SetPixelColor(LIGHTGREEN);SetPixelColor(BLACK);
		CustomConsole.GotoXY(_x, _y + 4);
		SetPixelColor(BLACK); SetPixelColor(LIGHTGREEN); SetPixelColor(GREEN);SetPixelColor(GREEN);SetPixelColor(GREEN);
		SetPixelColor(GREEN);SetPixelColor(BLACK);SetPixelColor(GREEN);SetPixelColor(GREEN);SetPixelColor(BLACK);
		SetPixelColor(LIGHTGREEN);SetPixelColor(BLACK);
		CustomConsole.GotoXY(_x - 2, _y + 5);
		SetPixelColor(BLACK); SetPixelColor(LIGHTGREEN); SetPixelColor(GREEN);SetPixelColor(GREEN);SetPixelColor(GREEN);
		SetPixelColor(GREEN);SetPixelColor(GREEN);SetPixelColor(BLACK);SetPixelColor(GREEN);SetPixelColor(GREEN);
		SetPixelColor(BLACK);SetPixelColor(GREEN);SetPixelColor(LIGHTGREEN);SetPixelColor(BLACK);
		CustomConsole.GotoXY(_x - 2, _y + 6);
		SetPixelColor(BLACK); SetPixelColor(LIGHTGREEN); SetPixelColor(GREEN);SetPixelColor(GREEN);SetPixelColor(GREEN);
		SetPixelColor(GREEN);SetPixelColor(GREEN);SetPixelColor(BLACK);SetPixelColor(GREEN);SetPixelColor(GREEN);
		SetPixelColor(BLACK);SetPixelColor(GREEN);SetPixelColor(LIGHTGREEN);SetPixelColor(BLACK);
		CustomConsole.GotoXY(_x - 2, _y + 7);
		SetPixelColor(BLACK); SetPixelColor(LIGHTGREEN); SetPixelColor(GREEN);SetPixelColor(GREEN);SetPixelColor(GREEN);
		SetPixelColor(GREEN);SetPixelColor(LIGHTRED);SetPixelColor(LIGHTRED);SetPixelColor(GREEN);SetPixelColor(GREEN);
		SetPixelColor(LIGHTRED);SetPixelColor(LIGHTRED);SetPixelColor(LIGHTGREEN);SetPixelColor(BLACK);
		CustomConsole.GotoXY(_x - 2, _y + 8);
		SetPixelColor(BLACK);SetPixelColor(GREEN); SetPixelColor(GREEN);SetPixelColor(GREEN);SetPixelColor(GREEN);
		SetPixelColor(GREEN);SetPixelColor(GREEN);SetPixelColor(GREEN);SetPixelColor(GREEN);SetPixelColor(GREEN);
		SetPixelColor(GREEN);SetPixelColor(GREEN);SetPixelColor(GREEN);SetPixelColor(BLACK);
		CustomConsole.GotoXY(_x, _y + 9);
		SetPixelColor(BLACK);SetPixelColor(GREEN);SetPixelColor(GREEN);SetPixelColor(GREEN);SetPixelColor(GREEN);
		SetPixelColor(GREEN);SetPixelColor(GREEN);SetPixelColor(GREEN);SetPixelColor(GREEN);SetPixelColor(GREEN);
		SetPixelColor(GREEN);SetPixelColor(BLACK);
		CustomConsole.GotoXY(_x + 2, _y + 10);
		SetPixelColor(BLACK);SetPixelColor(BLACK);SetPixelColor(GREEN);SetPixelColor(GREEN);SetPixelColor(GREEN);
		SetPixelColor(GREEN);SetPixelColor(GREEN);SetPixelColor(GREEN);SetPixelColor(BLACK);SetPixelColor(BLACK);
		CustomConsole.GotoXY(_x + 6, _y + 11);
		SetPixelColor(BLACK);SetPixelColor(BLACK);SetPixelColor(BLACK);SetPixelColor(BLACK);
		SetPixelColor(BLACK);SetPixelColor(BLACK);
		break;
	case 6:
		CustomConsole.GotoXY(_x + 8, _y - 1);
		SetPixelColor(BLACK); SetPixelColor(BLACK); SetPixelColor(BLACK); SetPixelColor(BLACK);
		CustomConsole.GotoXY(_x + 4, _y);
		SetPixelColor(BLACK); SetPixelColor(BLACK); SetPixelColor(LIGHTGREEN); SetPixelColor(LIGHTGREEN);
		SetPixelColor(LIGHTGREEN); SetPixelColor(LIGHTGREEN); SetPixelColor(BLACK); SetPixelColor(BLACK);
		CustomConsole.GotoXY(_x + 2, _y + 1);
		SetPixelColor(BLACK); SetPixelColor(LIGHTGREEN); SetPixelColor(LIGHTGREEN); SetPixelColor(GREEN); SetPixelColor(GREEN);
		SetPixelColor(GREEN); SetPixelColor(LIGHTGREEN); SetPixelColor(LIGHTGREEN); SetPixelColor(LIGHTGREEN);SetPixelColor(BLACK);
		CustomConsole.GotoXY(_x, _y + 2);
		SetPixelColor(BLACK); SetPixelColor(LIGHTGREEN); SetPixelColor(GREEN); SetPixelColor(GREEN); SetPixelColor(GREEN);
		SetPixelColor(GREEN);SetPixelColor(GREEN);SetPixelColor(LIGHTGREEN);SetPixelColor(LIGHTGREEN);SetPixelColor(GREEN);
		SetPixelColor(LIGHTGREEN);SetPixelColor(BLACK);
		CustomConsole.GotoXY(_x, _y + 3);
		SetPixelColor(BLACK); SetPixelColor(LIGHTGREEN); SetPixelColor(GREEN);SetPixelColor(GREEN);SetPixelColor(GREEN);
		SetPixelColor(GREEN);SetPixelColor(BLACK);SetPixelColor(GREEN);SetPixelColor(GREEN);SetPixelColor(BLACK);
		SetPixelColor(LIGHTGREEN);SetPixelColor(BLACK);
		CustomConsole.GotoXY(_x - 2, _y + 4);
		SetPixelColor(BLACK); SetPixelColor(LIGHTGREEN); SetPixelColor(GREEN);SetPixelColor(GREEN);SetPixelColor(GREEN);
		SetPixelColor(GREEN);SetPixelColor(GREEN);SetPixelColor(BLACK);SetPixelColor(GREEN);SetPixelColor(GREEN);
		SetPixelColor(BLACK);SetPixelColor(GREEN);SetPixelColor(LIGHTGREEN);SetPixelColor(BLACK);
		CustomConsole.GotoXY(_x - 2, _y + 5);
		SetPixelColor(BLACK); SetPixelColor(LIGHTGREEN); SetPixelColor(GREEN);SetPixelColor(GREEN);SetPixelColor(GREEN);
		SetPixelColor(GREEN);SetPixelColor(GREEN);SetPixelColor(BLACK);SetPixelColor(GREEN);SetPixelColor(GREEN);
		SetPixelColor(BLACK);SetPixelColor(GREEN);SetPixelColor(LIGHTGREEN);SetPixelColor(BLACK);
		CustomConsole.GotoXY(_x - 2, _y + 6);
		SetPixelColor(BLACK); SetPixelColor(LIGHTGREEN); SetPixelColor(GREEN);SetPixelColor(GREEN);SetPixelColor(GREEN);
		SetPixelColor(GREEN);SetPixelColor(LIGHTRED);SetPixelColor(LIGHTRED);SetPixelColor(GREEN);SetPixelColor(GREEN);
		SetPixelColor(LIGHTRED);SetPixelColor(LIGHTRED);SetPixelColor(LIGHTGREEN);SetPixelColor(BLACK);
		CustomConsole.GotoXY(_x - 2, _y + 7);
		SetPixelColor(BLACK); SetPixelColor(LIGHTGREEN); SetPixelColor(GREEN);SetPixelColor(GREEN);SetPixelColor(GREEN);
		SetPixelColor(GREEN);SetPixelColor(GREEN);SetPixelColor(GREEN);SetPixelColor(GREEN);SetPixelColor(GREEN);
		SetPixelColor(GREEN);SetPixelColor(GREEN);SetPixelColor(LIGHTGREEN);SetPixelColor(BLACK);
		CustomConsole.GotoXY(_x - 2, _y + 8);
		SetPixelColor(BLACK);SetPixelColor(GREEN); SetPixelColor(GREEN);SetPixelColor(GREEN);SetPixelColor(GREEN);
		SetPixelColor(GREEN);SetPixelColor(GREEN);SetPixelColor(GREEN);SetPixelColor(GREEN);SetPixelColor(GREEN);
		SetPixelColor(GREEN);SetPixelColor(GREEN);SetPixelColor(GREEN);SetPixelColor(BLACK);
		CustomConsole.GotoXY(_x, _y + 9);
		SetPixelColor(BLACK);SetPixelColor(GREEN);SetPixelColor(GREEN);SetPixelColor(GREEN);SetPixelColor(GREEN);
		SetPixelColor(GREEN);SetPixelColor(GREEN);SetPixelColor(GREEN);SetPixelColor(GREEN);SetPixelColor(GREEN);
		SetPixelColor(GREEN);SetPixelColor(BLACK);
		CustomConsole.GotoXY(_x + 2, _y + 10);
		SetPixelColor(BLACK);SetPixelColor(BLACK);SetPixelColor(GREEN);SetPixelColor(GREEN);SetPixelColor(GREEN);
		SetPixelColor(GREEN);SetPixelColor(GREEN);SetPixelColor(GREEN);SetPixelColor(BLACK);SetPixelColor(BLACK);
		CustomConsole.GotoXY(_x + 6, _y + 11);
		SetPixelColor(BLACK);SetPixelColor(BLACK);SetPixelColor(BLACK);SetPixelColor(BLACK);
		SetPixelColor(BLACK);SetPixelColor(BLACK);
		break;
	case 7:
		CustomConsole.GotoXY(_x + 8, _y - 1);
		SetPixelColor(BLACK); SetPixelColor(BLACK); SetPixelColor(BLACK); SetPixelColor(BLACK);
		CustomConsole.GotoXY(_x + 4, _y);
		SetPixelColor(BLACK); SetPixelColor(BLACK); SetPixelColor(LIGHTGREEN); SetPixelColor(LIGHTGREEN);
		SetPixelColor(LIGHTGREEN); SetPixelColor(LIGHTGREEN); SetPixelColor(BLACK); SetPixelColor(BLACK);
		CustomConsole.GotoXY(_x + 2, _y + 1);
		SetPixelColor(BLACK); SetPixelColor(LIGHTGREEN); SetPixelColor(LIGHTGREEN); SetPixelColor(GREEN); SetPixelColor(GREEN);
		SetPixelColor(GREEN); SetPixelColor(LIGHTGREEN); SetPixelColor(LIGHTGREEN); SetPixelColor(LIGHTGREEN);SetPixelColor(BLACK);
		CustomConsole.GotoXY(_x, _y + 2);
		SetPixelColor(BLACK); SetPixelColor(LIGHTGREEN); SetPixelColor(GREEN); SetPixelColor(GREEN); SetPixelColor(GREEN);
		SetPixelColor(GREEN);SetPixelColor(GREEN);SetPixelColor(GREEN);SetPixelColor(GREEN);SetPixelColor(GREEN);
		SetPixelColor(LIGHTGREEN);SetPixelColor(BLACK);
		CustomConsole.GotoXY(_x, _y + 3);
		SetPixelColor(BLACK); SetPixelColor(LIGHTGREEN); SetPixelColor(GREEN);SetPixelColor(GREEN);SetPixelColor(GREEN);
		SetPixelColor(GREEN);SetPixelColor(BLACK);SetPixelColor(GREEN);SetPixelColor(GREEN);SetPixelColor(BLACK);
		SetPixelColor(LIGHTGREEN);SetPixelColor(BLACK);
		CustomConsole.GotoXY(_x - 2, _y + 4);
		SetPixelColor(BLACK); SetPixelColor(LIGHTGREEN); SetPixelColor(GREEN);SetPixelColor(GREEN);SetPixelColor(GREEN);
		SetPixelColor(GREEN);SetPixelColor(GREEN);SetPixelColor(BLACK);SetPixelColor(GREEN);SetPixelColor(GREEN);
		SetPixelColor(BLACK);SetPixelColor(GREEN);SetPixelColor(LIGHTGREEN);SetPixelColor(BLACK);
		CustomConsole.GotoXY(_x - 2, _y + 5);
		SetPixelColor(BLACK); SetPixelColor(LIGHTGREEN); SetPixelColor(GREEN);SetPixelColor(GREEN);SetPixelColor(GREEN);
		SetPixelColor(GREEN);SetPixelColor(GREEN);SetPixelColor(BLACK);SetPixelColor(GREEN);SetPixelColor(GREEN);
		SetPixelColor(BLACK);SetPixelColor(GREEN);SetPixelColor(LIGHTGREEN);SetPixelColor(BLACK);
		CustomConsole.GotoXY(_x - 2, _y + 6);
		SetPixelColor(BLACK); SetPixelColor(LIGHTGREEN); SetPixelColor(GREEN);SetPixelColor(GREEN);SetPixelColor(GREEN);
		SetPixelColor(GREEN);SetPixelColor(LIGHTRED);SetPixelColor(LIGHTRED);SetPixelColor(GREEN);SetPixelColor(GREEN);
		SetPixelColor(LIGHTRED);SetPixelColor(LIGHTRED);SetPixelColor(LIGHTGREEN);SetPixelColor(BLACK);
		CustomConsole.GotoXY(_x - 2, _y + 7);
		SetPixelColor(BLACK); SetPixelColor(LIGHTGREEN); SetPixelColor(GREEN);SetPixelColor(GREEN);SetPixelColor(GREEN);
		SetPixelColor(GREEN);SetPixelColor(GREEN);SetPixelColor(GREEN);SetPixelColor(GREEN);SetPixelColor(GREEN);
		SetPixelColor(GREEN);SetPixelColor(GREEN);SetPixelColor(LIGHTGREEN);SetPixelColor(BLACK);
		CustomConsole.GotoXY(_x - 2, _y + 8);
		SetPixelColor(BLACK);SetPixelColor(GREEN); SetPixelColor(GREEN);SetPixelColor(GREEN);SetPixelColor(GREEN);
		SetPixelColor(GREEN);SetPixelColor(GREEN);SetPixelColor(GREEN);SetPixelColor(GREEN);SetPixelColor(GREEN);
		SetPixelColor(GREEN);SetPixelColor(GREEN);SetPixelColor(GREEN);SetPixelColor(BLACK);
		CustomConsole.GotoXY(_x, _y + 9);
		SetPixelColor(BLACK);SetPixelColor(GREEN);SetPixelColor(GREEN);SetPixelColor(GREEN);SetPixelColor(GREEN);
		SetPixelColor(GREEN);SetPixelColor(GREEN);SetPixelColor(GREEN);SetPixelColor(GREEN);SetPixelColor(GREEN);
		SetPixelColor(GREEN);SetPixelColor(BLACK);
		CustomConsole.GotoXY(_x + 2, _y + 10);
		SetPixelColor(BLACK);SetPixelColor(BLACK);SetPixelColor(GREEN);SetPixelColor(GREEN);SetPixelColor(GREEN);
		SetPixelColor(GREEN);SetPixelColor(GREEN);SetPixelColor(GREEN);SetPixelColor(BLACK);SetPixelColor(BLACK);
		CustomConsole.GotoXY(_x + 6, _y + 11);
		SetPixelColor(BLACK);SetPixelColor(BLACK);SetPixelColor(BLACK);SetPixelColor(BLACK);
		SetPixelColor(BLACK);SetPixelColor(BLACK);
		break;
	case 8:
		CustomConsole.GotoXY(_x + 8, _y - 1);
		SetPixelColor(BLACK); SetPixelColor(BLACK); SetPixelColor(BLACK); SetPixelColor(BLACK);
		CustomConsole.GotoXY(_x + 4, _y);
		SetPixelColor(BLACK); SetPixelColor(BLACK); SetPixelColor(LIGHTGREEN); SetPixelColor(LIGHTGREEN);
		SetPixelColor(LIGHTGREEN); SetPixelColor(LIGHTGREEN); SetPixelColor(BLACK); SetPixelColor(BLACK);
		CustomConsole.GotoXY(_x + 2, _y + 1);
		SetPixelColor(BLACK); SetPixelColor(LIGHTGREEN); SetPixelColor(LIGHTGREEN); SetPixelColor(GREEN); SetPixelColor(GREEN);
		SetPixelColor(GREEN); SetPixelColor(GREEN); SetPixelColor(LIGHTGREEN); SetPixelColor(LIGHTGREEN);SetPixelColor(BLACK);
		CustomConsole.GotoXY(_x, _y + 2);
		SetPixelColor(BLACK); SetPixelColor(LIGHTGREEN); SetPixelColor(GREEN); SetPixelColor(GREEN); SetPixelColor(GREEN);
		SetPixelColor(GREEN);SetPixelColor(BLACK);SetPixelColor(GREEN);SetPixelColor(GREEN);SetPixelColor(BLACK);
		SetPixelColor(LIGHTGREEN);SetPixelColor(BLACK);
		CustomConsole.GotoXY(_x, _y + 3);
		SetPixelColor(BLACK); SetPixelColor(LIGHTGREEN); SetPixelColor(GREEN);SetPixelColor(GREEN);SetPixelColor(GREEN);
		SetPixelColor(GREEN);SetPixelColor(BLACK);SetPixelColor(GREEN);SetPixelColor(GREEN);SetPixelColor(BLACK);
		SetPixelColor(LIGHTGREEN);SetPixelColor(BLACK);
		CustomConsole.GotoXY(_x - 2, _y + 4);
		SetPixelColor(BLACK); SetPixelColor(LIGHTGREEN); SetPixelColor(GREEN);SetPixelColor(GREEN);SetPixelColor(GREEN);
		SetPixelColor(GREEN);SetPixelColor(GREEN);SetPixelColor(BLACK);SetPixelColor(GREEN);SetPixelColor(GREEN);
		SetPixelColor(BLACK);SetPixelColor(GREEN);SetPixelColor(LIGHTGREEN);SetPixelColor(BLACK);
		CustomConsole.GotoXY(_x - 2, _y + 5);
		SetPixelColor(BLACK); SetPixelColor(LIGHTGREEN); SetPixelColor(GREEN);SetPixelColor(GREEN);SetPixelColor(GREEN);
		SetPixelColor(GREEN);SetPixelColor(LIGHTRED);SetPixelColor(LIGHTRED);SetPixelColor(GREEN);SetPixelColor(GREEN);
		SetPixelColor(LIGHTRED);SetPixelColor(LIGHTRED);SetPixelColor(LIGHTGREEN);SetPixelColor(BLACK);
		CustomConsole.GotoXY(_x - 2, _y + 6);
		SetPixelColor(BLACK); SetPixelColor(LIGHTGREEN); SetPixelColor(GREEN);SetPixelColor(GREEN);SetPixelColor(GREEN);
		SetPixelColor(GREEN);SetPixelColor(GREEN);SetPixelColor(GREEN);SetPixelColor(GREEN);SetPixelColor(GREEN);
		SetPixelColor(GREEN);SetPixelColor(GREEN);SetPixelColor(LIGHTGREEN);SetPixelColor(BLACK);
		CustomConsole.GotoXY(_x - 2, _y + 7);
		SetPixelColor(BLACK); SetPixelColor(LIGHTGREEN); SetPixelColor(GREEN);SetPixelColor(GREEN);SetPixelColor(GREEN);
		SetPixelColor(GREEN);SetPixelColor(GREEN);SetPixelColor(GREEN);SetPixelColor(GREEN);SetPixelColor(GREEN);
		SetPixelColor(GREEN);SetPixelColor(GREEN);SetPixelColor(LIGHTGREEN);SetPixelColor(BLACK);
		CustomConsole.GotoXY(_x - 2, _y + 8);
		SetPixelColor(BLACK);SetPixelColor(GREEN); SetPixelColor(GREEN);SetPixelColor(GREEN);SetPixelColor(GREEN);
		SetPixelColor(GREEN);SetPixelColor(GREEN);SetPixelColor(GREEN);SetPixelColor(GREEN);SetPixelColor(GREEN);
		SetPixelColor(GREEN);SetPixelColor(GREEN);SetPixelColor(GREEN);SetPixelColor(BLACK);
		CustomConsole.GotoXY(_x, _y + 9);
		SetPixelColor(BLACK);SetPixelColor(GREEN);SetPixelColor(GREEN);SetPixelColor(GREEN);SetPixelColor(GREEN);
		SetPixelColor(GREEN);SetPixelColor(GREEN);SetPixelColor(GREEN);SetPixelColor(GREEN);SetPixelColor(GREEN);
		SetPixelColor(GREEN);SetPixelColor(BLACK);
		CustomConsole.GotoXY(_x + 2, _y + 10);
		SetPixelColor(BLACK);SetPixelColor(BLACK);SetPixelColor(GREEN);SetPixelColor(GREEN);SetPixelColor(GREEN);
		SetPixelColor(GREEN);SetPixelColor(GREEN);SetPixelColor(GREEN);SetPixelColor(BLACK);SetPixelColor(BLACK);
		CustomConsole.GotoXY(_x + 6, _y + 11);
		SetPixelColor(BLACK);SetPixelColor(BLACK);SetPixelColor(BLACK);SetPixelColor(BLACK);
		SetPixelColor(BLACK);SetPixelColor(BLACK);
		break;
	case 9:
		CustomConsole.GotoXY(_x + 8, _y);
		SetPixelColor(BLACK); SetPixelColor(BLACK); SetPixelColor(BLACK); SetPixelColor(BLACK);
		CustomConsole.GotoXY(_x + 4, _y + 1);
		SetPixelColor(BLACK); SetPixelColor(BLACK); SetPixelColor(LIGHTGREEN); SetPixelColor(LIGHTGREEN);
		SetPixelColor(LIGHTGREEN); SetPixelColor(LIGHTGREEN); SetPixelColor(BLACK); SetPixelColor(BLACK);
		CustomConsole.GotoXY(_x + 2, _y + 2);
		SetPixelColor(BLACK); SetPixelColor(LIGHTGREEN); SetPixelColor(LIGHTGREEN); SetPixelColor(GREEN); SetPixelColor(GREEN);
		SetPixelColor(BLACK); SetPixelColor(LIGHTGREEN); SetPixelColor(LIGHTGREEN); SetPixelColor(BLACK);SetPixelColor(BLACK);
		CustomConsole.GotoXY(_x, _y + 3);
		SetPixelColor(BLACK); SetPixelColor(LIGHTGREEN); SetPixelColor(GREEN); SetPixelColor(GREEN); SetPixelColor(GREEN);
		SetPixelColor(GREEN);SetPixelColor(BLACK);SetPixelColor(GREEN);SetPixelColor(GREEN);SetPixelColor(BLACK);
		SetPixelColor(LIGHTGREEN);SetPixelColor(BLACK);
		CustomConsole.GotoXY(_x, _y + 4);
		SetPixelColor(BLACK); SetPixelColor(LIGHTGREEN); SetPixelColor(GREEN);SetPixelColor(GREEN);SetPixelColor(GREEN);
		SetPixelColor(GREEN);SetPixelColor(BLACK);SetPixelColor(GREEN);SetPixelColor(GREEN);SetPixelColor(BLACK);
		SetPixelColor(LIGHTGREEN);SetPixelColor(BLACK);
		CustomConsole.GotoXY(_x - 2, _y + 5);
		SetPixelColor(BLACK); SetPixelColor(LIGHTGREEN); SetPixelColor(GREEN);SetPixelColor(GREEN);SetPixelColor(GREEN);
		SetPixelColor(GREEN);SetPixelColor(LIGHTRED);SetPixelColor(LIGHTRED);SetPixelColor(GREEN);SetPixelColor(GREEN);
		SetPixelColor(LIGHTRED);SetPixelColor(LIGHTRED);SetPixelColor(LIGHTGREEN);SetPixelColor(BLACK);
		CustomConsole.GotoXY(_x - 2, _y + 6);
		SetPixelColor(BLACK); SetPixelColor(LIGHTGREEN); SetPixelColor(GREEN);SetPixelColor(GREEN);SetPixelColor(GREEN);
		SetPixelColor(GREEN);SetPixelColor(GREEN);SetPixelColor(GREEN);SetPixelColor(GREEN);SetPixelColor(GREEN);
		SetPixelColor(GREEN);SetPixelColor(GREEN);SetPixelColor(LIGHTGREEN);SetPixelColor(BLACK);
		CustomConsole.GotoXY(_x - 2, _y + 7);
		SetPixelColor(BLACK); SetPixelColor(LIGHTGREEN); SetPixelColor(GREEN);SetPixelColor(GREEN);SetPixelColor(GREEN);
		SetPixelColor(GREEN);SetPixelColor(GREEN);SetPixelColor(GREEN);SetPixelColor(GREEN);SetPixelColor(GREEN);
		SetPixelColor(GREEN);SetPixelColor(GREEN);SetPixelColor(LIGHTGREEN);SetPixelColor(BLACK);
		CustomConsole.GotoXY(_x - 2, _y + 8);
		SetPixelColor(BLACK);SetPixelColor(GREEN); SetPixelColor(GREEN);SetPixelColor(GREEN);SetPixelColor(GREEN);
		SetPixelColor(GREEN);SetPixelColor(GREEN);SetPixelColor(GREEN);SetPixelColor(GREEN);SetPixelColor(GREEN);
		SetPixelColor(GREEN);SetPixelColor(GREEN);SetPixelColor(GREEN);SetPixelColor(BLACK);
		CustomConsole.GotoXY(_x, _y + 9);
		SetPixelColor(BLACK);SetPixelColor(GREEN);SetPixelColor(GREEN);SetPixelColor(GREEN);SetPixelColor(GREEN);
		SetPixelColor(GREEN);SetPixelColor(GREEN);SetPixelColor(GREEN);SetPixelColor(GREEN);SetPixelColor(GREEN);
		SetPixelColor(GREEN);SetPixelColor(BLACK);
		CustomConsole.GotoXY(_x + 2, _y + 10);
		SetPixelColor(BLACK);SetPixelColor(BLACK);SetPixelColor(GREEN);SetPixelColor(GREEN);SetPixelColor(GREEN);
		SetPixelColor(GREEN);SetPixelColor(GREEN);SetPixelColor(GREEN);SetPixelColor(BLACK);SetPixelColor(BLACK);
		CustomConsole.GotoXY(_x + 6, _y + 11);
		SetPixelColor(BLACK);SetPixelColor(BLACK);SetPixelColor(BLACK);SetPixelColor(BLACK);
		SetPixelColor(BLACK);SetPixelColor(BLACK);
		break;
	case 10:
		CustomConsole.GotoXY(_x + 8, _y);
		SetPixelColor(BLACK); SetPixelColor(BLACK); SetPixelColor(BLACK); SetPixelColor(BLACK);
		CustomConsole.GotoXY(_x + 4, _y + 1);
		SetPixelColor(BLACK); SetPixelColor(BLACK); SetPixelColor(LIGHTGREEN); SetPixelColor(LIGHTGREEN);
		SetPixelColor(LIGHTGREEN); SetPixelColor(LIGHTGREEN); SetPixelColor(BLACK); SetPixelColor(BLACK);
		CustomConsole.GotoXY(_x + 2, _y + 2);
		SetPixelColor(BLACK); SetPixelColor(LIGHTGREEN); SetPixelColor(LIGHTGREEN); SetPixelColor(GREEN); SetPixelColor(GREEN);
		SetPixelColor(GREEN); SetPixelColor(LIGHTGREEN); SetPixelColor(LIGHTGREEN); SetPixelColor(LIGHTGREEN);SetPixelColor(BLACK);
		CustomConsole.GotoXY(_x, _y + 3);
		SetPixelColor(BLACK); SetPixelColor(LIGHTGREEN); SetPixelColor(GREEN); SetPixelColor(GREEN); SetPixelColor(GREEN);
		SetPixelColor(GREEN);SetPixelColor(BLACK);SetPixelColor(GREEN);SetPixelColor(GREEN);SetPixelColor(BLACK);
		SetPixelColor(LIGHTGREEN);SetPixelColor(BLACK);
		CustomConsole.GotoXY(_x, _y + 4);
		SetPixelColor(BLACK); SetPixelColor(LIGHTGREEN); SetPixelColor(GREEN);SetPixelColor(GREEN);SetPixelColor(GREEN);
		SetPixelColor(GREEN);SetPixelColor(BLACK);SetPixelColor(GREEN);SetPixelColor(GREEN);SetPixelColor(BLACK);
		SetPixelColor(LIGHTGREEN);SetPixelColor(BLACK);
		CustomConsole.GotoXY(_x - 2, _y + 5);
		SetPixelColor(BLACK); SetPixelColor(LIGHTGREEN); SetPixelColor(GREEN);SetPixelColor(GREEN);SetPixelColor(GREEN);
		SetPixelColor(GREEN);SetPixelColor(GREEN);SetPixelColor(BLACK);SetPixelColor(GREEN);SetPixelColor(GREEN);
		SetPixelColor(BLACK);SetPixelColor(GREEN);SetPixelColor(LIGHTGREEN);SetPixelColor(BLACK);
		CustomConsole.GotoXY(_x - 2, _y + 6);
		SetPixelColor(BLACK); SetPixelColor(LIGHTGREEN); SetPixelColor(GREEN);SetPixelColor(GREEN);SetPixelColor(GREEN);
		SetPixelColor(GREEN);SetPixelColor(LIGHTRED);SetPixelColor(LIGHTRED);SetPixelColor(GREEN);SetPixelColor(GREEN);
		SetPixelColor(LIGHTRED);SetPixelColor(LIGHTRED);SetPixelColor(LIGHTGREEN);SetPixelColor(BLACK);
		CustomConsole.GotoXY(_x - 2, _y + 7);
		SetPixelColor(BLACK); SetPixelColor(LIGHTGREEN); SetPixelColor(GREEN);SetPixelColor(GREEN);SetPixelColor(GREEN);
		SetPixelColor(GREEN);SetPixelColor(GREEN);SetPixelColor(GREEN);SetPixelColor(GREEN);SetPixelColor(GREEN);
		SetPixelColor(GREEN);SetPixelColor(GREEN);SetPixelColor(LIGHTGREEN);SetPixelColor(BLACK);
		CustomConsole.GotoXY(_x - 2, _y + 8);
		SetPixelColor(BLACK);SetPixelColor(GREEN); SetPixelColor(GREEN);SetPixelColor(GREEN);SetPixelColor(GREEN);
		SetPixelColor(GREEN);SetPixelColor(GREEN);SetPixelColor(GREEN);SetPixelColor(GREEN);SetPixelColor(GREEN);
		SetPixelColor(GREEN);SetPixelColor(GREEN);SetPixelColor(GREEN);SetPixelColor(BLACK);
		CustomConsole.GotoXY(_x, _y + 9);
		SetPixelColor(BLACK);SetPixelColor(GREEN);SetPixelColor(GREEN);SetPixelColor(GREEN);SetPixelColor(GREEN);
		SetPixelColor(GREEN);SetPixelColor(GREEN);SetPixelColor(GREEN);SetPixelColor(GREEN);SetPixelColor(GREEN);
		SetPixelColor(GREEN);SetPixelColor(BLACK);
		CustomConsole.GotoXY(_x + 2, _y + 10);
		SetPixelColor(BLACK);SetPixelColor(BLACK);SetPixelColor(GREEN);SetPixelColor(GREEN);SetPixelColor(GREEN);
		SetPixelColor(GREEN);SetPixelColor(GREEN);SetPixelColor(GREEN);SetPixelColor(BLACK);SetPixelColor(BLACK);
		CustomConsole.GotoXY(_x + 6, _y + 11);
		SetPixelColor(BLACK);SetPixelColor(BLACK);SetPixelColor(BLACK);SetPixelColor(BLACK);
		SetPixelColor(BLACK);SetPixelColor(BLACK);
		break;
	default:
		break;
	}
}

void Character::LeftRender()
{
	switch (_animationIndex)
	{
	case 0:
		CustomConsole.GotoXY(_x + 8, _y);
		SetPixelColor(BLACK); SetPixelColor(BLACK); SetPixelColor(BLACK); SetPixelColor(BLACK);
		CustomConsole.GotoXY(_x + 4, _y + 1);
		SetPixelColor(BLACK); SetPixelColor(BLACK); SetPixelColor(LIGHTGREEN); SetPixelColor(LIGHTGREEN);
		SetPixelColor(LIGHTGREEN); SetPixelColor(LIGHTGREEN); SetPixelColor(BLACK); SetPixelColor(BLACK);
		CustomConsole.GotoXY(_x + 2, _y + 2);
		SetPixelColor(BLACK); SetPixelColor(LIGHTGREEN); SetPixelColor(LIGHTGREEN); SetPixelColor(LIGHTGREEN); SetPixelColor(GREEN);
		SetPixelColor(GREEN); SetPixelColor(GREEN); SetPixelColor(LIGHTGREEN); SetPixelColor(LIGHTGREEN);SetPixelColor(BLACK);
		CustomConsole.GotoXY(_x, _y + 3);
		SetPixelColor(BLACK); SetPixelColor(LIGHTGREEN); SetPixelColor(GREEN); SetPixelColor(LIGHTGREEN); SetPixelColor(LIGHTGREEN);
		SetPixelColor(GREEN);SetPixelColor(GREEN);SetPixelColor(GREEN);SetPixelColor(GREEN);SetPixelColor(GREEN);
		SetPixelColor(LIGHTGREEN);SetPixelColor(BLACK);
		CustomConsole.GotoXY(_x, _y + 4);
		SetPixelColor(BLACK); SetPixelColor(LIGHTGREEN); SetPixelColor(BLACK);SetPixelColor(GREEN);SetPixelColor(GREEN);
		SetPixelColor(BLACK);SetPixelColor(GREEN);SetPixelColor(GREEN);SetPixelColor(GREEN);SetPixelColor(GREEN);
		SetPixelColor(LIGHTGREEN);SetPixelColor(BLACK);
		CustomConsole.GotoXY(_x - 2, _y + 5);
		SetPixelColor(BLACK); SetPixelColor(LIGHTGREEN); SetPixelColor(GREEN);SetPixelColor(BLACK);SetPixelColor(GREEN);
		SetPixelColor(GREEN);SetPixelColor(BLACK);SetPixelColor(GREEN);SetPixelColor(GREEN);SetPixelColor(GREEN);
		SetPixelColor(GREEN);SetPixelColor(GREEN);SetPixelColor(LIGHTGREEN);SetPixelColor(BLACK);
		CustomConsole.GotoXY(_x - 2, _y + 6);
		SetPixelColor(BLACK); SetPixelColor(LIGHTGREEN); SetPixelColor(GREEN);SetPixelColor(BLACK);SetPixelColor(GREEN);
		SetPixelColor(GREEN);SetPixelColor(BLACK);SetPixelColor(GREEN);SetPixelColor(GREEN);SetPixelColor(GREEN);
		SetPixelColor(GREEN);SetPixelColor(GREEN);SetPixelColor(LIGHTGREEN);SetPixelColor(BLACK);
		CustomConsole.GotoXY(_x - 2, _y + 7);
		SetPixelColor(BLACK); SetPixelColor(LIGHTGREEN); SetPixelColor(LIGHTRED);SetPixelColor(LIGHTRED);SetPixelColor(GREEN);
		SetPixelColor(GREEN);SetPixelColor(LIGHTRED);SetPixelColor(LIGHTRED);SetPixelColor(GREEN);SetPixelColor(GREEN);
		SetPixelColor(GREEN);SetPixelColor(GREEN);SetPixelColor(LIGHTGREEN);SetPixelColor(BLACK);
		CustomConsole.GotoXY(_x - 2, _y + 8);
		SetPixelColor(BLACK);SetPixelColor(GREEN); SetPixelColor(GREEN);SetPixelColor(GREEN);SetPixelColor(GREEN);
		SetPixelColor(GREEN);SetPixelColor(GREEN);SetPixelColor(GREEN);SetPixelColor(GREEN);SetPixelColor(GREEN);
		SetPixelColor(GREEN);SetPixelColor(GREEN);SetPixelColor(GREEN);SetPixelColor(BLACK);
		CustomConsole.GotoXY(_x, _y + 9);
		SetPixelColor(BLACK);SetPixelColor(GREEN);SetPixelColor(GREEN);SetPixelColor(GREEN);SetPixelColor(GREEN);
		SetPixelColor(GREEN);SetPixelColor(GREEN);SetPixelColor(GREEN);SetPixelColor(GREEN);SetPixelColor(GREEN);
		SetPixelColor(GREEN);SetPixelColor(BLACK);
		CustomConsole.GotoXY(_x + 2, _y + 10);
		SetPixelColor(BLACK);SetPixelColor(BLACK);SetPixelColor(GREEN);SetPixelColor(GREEN);SetPixelColor(GREEN);
		SetPixelColor(GREEN);SetPixelColor(GREEN);SetPixelColor(GREEN);SetPixelColor(BLACK);SetPixelColor(BLACK);
		CustomConsole.GotoXY(_x + 6, _y + 11);
		SetPixelColor(BLACK);SetPixelColor(BLACK);SetPixelColor(BLACK);SetPixelColor(BLACK);
		SetPixelColor(BLACK);SetPixelColor(BLACK);
		break;
	case 1:
		CustomConsole.GotoXY(_x + 8, _y + 1);
		SetPixelColor(BLACK); SetPixelColor(BLACK); SetPixelColor(BLACK); SetPixelColor(BLACK);
		CustomConsole.GotoXY(_x + 4, _y + 2);
		SetPixelColor(BLACK); SetPixelColor(BLACK); SetPixelColor(LIGHTGREEN); SetPixelColor(LIGHTGREEN);
		SetPixelColor(LIGHTGREEN); SetPixelColor(LIGHTGREEN); SetPixelColor(BLACK); SetPixelColor(BLACK);
		CustomConsole.GotoXY(_x + 2, _y + 3);
		SetPixelColor(BLACK); SetPixelColor(LIGHTGREEN); SetPixelColor(LIGHTGREEN); SetPixelColor(LIGHTGREEN); SetPixelColor(GREEN);
		SetPixelColor(GREEN); SetPixelColor(GREEN); SetPixelColor(LIGHTGREEN); SetPixelColor(LIGHTGREEN);SetPixelColor(BLACK);
		CustomConsole.GotoXY(_x, _y + 4);
		SetPixelColor(BLACK); SetPixelColor(LIGHTGREEN); SetPixelColor(GREEN); SetPixelColor(LIGHTGREEN); SetPixelColor(LIGHTGREEN);
		SetPixelColor(GREEN);SetPixelColor(GREEN);SetPixelColor(GREEN);SetPixelColor(GREEN);SetPixelColor(GREEN);
		SetPixelColor(LIGHTGREEN);SetPixelColor(BLACK);
		CustomConsole.GotoXY(_x - 2, _y + 5);
		SetPixelColor(BLACK); SetPixelColor(LIGHTGREEN); SetPixelColor(GREEN);SetPixelColor(BLACK);SetPixelColor(GREEN);
		SetPixelColor(GREEN);SetPixelColor(BLACK);SetPixelColor(GREEN);SetPixelColor(GREEN);SetPixelColor(GREEN);
		SetPixelColor(GREEN);SetPixelColor(GREEN);SetPixelColor(LIGHTGREEN);SetPixelColor(BLACK);
		CustomConsole.GotoXY(_x - 2, _y + 6);
		SetPixelColor(BLACK); SetPixelColor(LIGHTGREEN); SetPixelColor(GREEN);SetPixelColor(BLACK);SetPixelColor(GREEN);
		SetPixelColor(GREEN);SetPixelColor(BLACK);SetPixelColor(GREEN);SetPixelColor(GREEN);SetPixelColor(GREEN);
		SetPixelColor(GREEN);SetPixelColor(GREEN);SetPixelColor(LIGHTGREEN);SetPixelColor(BLACK);
		CustomConsole.GotoXY(_x - 2, _y + 7);
		SetPixelColor(BLACK); SetPixelColor(LIGHTGREEN); SetPixelColor(GREEN);SetPixelColor(BLACK);SetPixelColor(GREEN);
		SetPixelColor(GREEN);SetPixelColor(BLACK);SetPixelColor(GREEN);SetPixelColor(GREEN);SetPixelColor(GREEN);
		SetPixelColor(GREEN);SetPixelColor(GREEN);SetPixelColor(LIGHTGREEN);SetPixelColor(BLACK);
		CustomConsole.GotoXY(_x - 2, _y + 8);
		SetPixelColor(BLACK);SetPixelColor(GREEN); SetPixelColor(LIGHTRED);SetPixelColor(LIGHTRED);SetPixelColor(GREEN);
		SetPixelColor(GREEN);SetPixelColor(LIGHTRED);SetPixelColor(LIGHTRED);SetPixelColor(GREEN);SetPixelColor(GREEN);
		SetPixelColor(GREEN);SetPixelColor(GREEN);SetPixelColor(GREEN);SetPixelColor(BLACK);
		CustomConsole.GotoXY(_x, _y + 9);
		SetPixelColor(BLACK);SetPixelColor(GREEN);SetPixelColor(GREEN);SetPixelColor(GREEN);SetPixelColor(GREEN);
		SetPixelColor(GREEN);SetPixelColor(GREEN);SetPixelColor(GREEN);SetPixelColor(GREEN);SetPixelColor(GREEN);
		SetPixelColor(GREEN);SetPixelColor(BLACK);
		CustomConsole.GotoXY(_x + 2, _y + 10);
		SetPixelColor(BLACK);SetPixelColor(BLACK);SetPixelColor(GREEN);SetPixelColor(GREEN);SetPixelColor(GREEN);
		SetPixelColor(GREEN);SetPixelColor(GREEN);SetPixelColor(GREEN);SetPixelColor(BLACK);SetPixelColor(BLACK);
		CustomConsole.GotoXY(_x + 6, _y + 11);
		SetPixelColor(BLACK);SetPixelColor(BLACK);SetPixelColor(BLACK);SetPixelColor(BLACK);
		SetPixelColor(BLACK);SetPixelColor(BLACK);
		break;
	case 2:
		CustomConsole.GotoXY(_x + 8, _y + 1);
		SetPixelColor(BLACK); SetPixelColor(BLACK); SetPixelColor(BLACK); SetPixelColor(BLACK);
		CustomConsole.GotoXY(_x + 4, _y + 2);
		SetPixelColor(BLACK); SetPixelColor(BLACK); SetPixelColor(LIGHTGREEN); SetPixelColor(LIGHTGREEN);
		SetPixelColor(LIGHTGREEN); SetPixelColor(LIGHTGREEN); SetPixelColor(BLACK); SetPixelColor(BLACK);
		CustomConsole.GotoXY(_x + 2, _y + 3);
		SetPixelColor(BLACK); SetPixelColor(LIGHTGREEN); SetPixelColor(LIGHTGREEN); SetPixelColor(LIGHTGREEN); SetPixelColor(GREEN);
		SetPixelColor(GREEN); SetPixelColor(GREEN); SetPixelColor(LIGHTGREEN); SetPixelColor(LIGHTGREEN);SetPixelColor(BLACK);
		CustomConsole.GotoXY(_x, _y + 4);
		SetPixelColor(BLACK); SetPixelColor(LIGHTGREEN); SetPixelColor(GREEN); SetPixelColor(LIGHTGREEN); SetPixelColor(LIGHTGREEN);
		SetPixelColor(GREEN);SetPixelColor(GREEN);SetPixelColor(GREEN);SetPixelColor(GREEN);SetPixelColor(GREEN);
		SetPixelColor(LIGHTGREEN);SetPixelColor(BLACK);
		CustomConsole.GotoXY(_x - 2, _y + 5);
		SetPixelColor(BLACK); SetPixelColor(LIGHTGREEN); SetPixelColor(GREEN);SetPixelColor(GREEN);SetPixelColor(GREEN);
		SetPixelColor(GREEN);SetPixelColor(GREEN);SetPixelColor(GREEN);SetPixelColor(GREEN);SetPixelColor(GREEN);
		SetPixelColor(GREEN);SetPixelColor(GREEN);SetPixelColor(LIGHTGREEN);SetPixelColor(BLACK);
		CustomConsole.GotoXY(_x - 2, _y + 6);
		SetPixelColor(BLACK); SetPixelColor(LIGHTGREEN); SetPixelColor(GREEN);SetPixelColor(BLACK);SetPixelColor(GREEN);
		SetPixelColor(GREEN);SetPixelColor(BLACK);SetPixelColor(GREEN);SetPixelColor(GREEN);SetPixelColor(GREEN);
		SetPixelColor(GREEN);SetPixelColor(GREEN);SetPixelColor(LIGHTGREEN);SetPixelColor(BLACK);
		CustomConsole.GotoXY(_x - 2, _y + 7);
		SetPixelColor(BLACK); SetPixelColor(LIGHTGREEN); SetPixelColor(GREEN);SetPixelColor(BLACK);SetPixelColor(GREEN);
		SetPixelColor(GREEN);SetPixelColor(BLACK);SetPixelColor(GREEN);SetPixelColor(GREEN);SetPixelColor(GREEN);
		SetPixelColor(GREEN);SetPixelColor(GREEN);SetPixelColor(LIGHTGREEN);SetPixelColor(BLACK);
		CustomConsole.GotoXY(_x - 2, _y + 8);
		SetPixelColor(BLACK);SetPixelColor(GREEN); SetPixelColor(GREEN);SetPixelColor(BLACK);SetPixelColor(GREEN);
		SetPixelColor(GREEN);SetPixelColor(BLACK);SetPixelColor(GREEN);SetPixelColor(GREEN);SetPixelColor(GREEN);
		SetPixelColor(GREEN);SetPixelColor(GREEN);SetPixelColor(GREEN);SetPixelColor(BLACK);
		CustomConsole.GotoXY(_x, _y + 9);
		SetPixelColor(BLACK);SetPixelColor(LIGHTRED);SetPixelColor(LIGHTRED);SetPixelColor(GREEN);SetPixelColor(GREEN);
		SetPixelColor(LIGHTRED);SetPixelColor(LIGHTRED);SetPixelColor(GREEN);SetPixelColor(GREEN);SetPixelColor(GREEN);
		SetPixelColor(GREEN);SetPixelColor(BLACK);
		CustomConsole.GotoXY(_x + 2, _y + 10);
		SetPixelColor(BLACK);SetPixelColor(BLACK);SetPixelColor(GREEN);SetPixelColor(GREEN);SetPixelColor(GREEN);
		SetPixelColor(GREEN);SetPixelColor(GREEN);SetPixelColor(GREEN);SetPixelColor(BLACK);SetPixelColor(BLACK);
		CustomConsole.GotoXY(_x + 6, _y + 11);
		SetPixelColor(BLACK);SetPixelColor(BLACK);SetPixelColor(BLACK);SetPixelColor(BLACK);
		SetPixelColor(BLACK);SetPixelColor(BLACK);
		break;
	case 3:
		CustomConsole.GotoXY(_x + 8, _y);
		SetPixelColor(BLACK); SetPixelColor(BLACK); SetPixelColor(BLACK); SetPixelColor(BLACK);
		CustomConsole.GotoXY(_x + 4, _y + 1);
		SetPixelColor(BLACK); SetPixelColor(BLACK); SetPixelColor(LIGHTGREEN); SetPixelColor(LIGHTGREEN);
		SetPixelColor(LIGHTGREEN); SetPixelColor(LIGHTGREEN); SetPixelColor(BLACK); SetPixelColor(BLACK);
		CustomConsole.GotoXY(_x + 2, _y + 2);
		SetPixelColor(BLACK); SetPixelColor(LIGHTGREEN); SetPixelColor(LIGHTGREEN); SetPixelColor(LIGHTGREEN); SetPixelColor(GREEN);
		SetPixelColor(GREEN); SetPixelColor(GREEN); SetPixelColor(LIGHTGREEN); SetPixelColor(LIGHTGREEN);SetPixelColor(BLACK);
		CustomConsole.GotoXY(_x, _y + 3);
		SetPixelColor(BLACK); SetPixelColor(LIGHTGREEN); SetPixelColor(GREEN); SetPixelColor(LIGHTGREEN); SetPixelColor(LIGHTGREEN);
		SetPixelColor(GREEN);SetPixelColor(GREEN);SetPixelColor(GREEN);SetPixelColor(GREEN);SetPixelColor(GREEN);
		SetPixelColor(LIGHTGREEN);SetPixelColor(BLACK);
		CustomConsole.GotoXY(_x, _y + 4);
		SetPixelColor(BLACK); SetPixelColor(LIGHTGREEN); SetPixelColor(GREEN); SetPixelColor(GREEN); SetPixelColor(GREEN);
		SetPixelColor(GREEN);SetPixelColor(GREEN);SetPixelColor(GREEN);SetPixelColor(GREEN);SetPixelColor(GREEN);
		SetPixelColor(LIGHTGREEN);SetPixelColor(BLACK);
		CustomConsole.GotoXY(_x - 2, _y + 5);
		SetPixelColor(BLACK); SetPixelColor(LIGHTGREEN); SetPixelColor(GREEN);SetPixelColor(GREEN);SetPixelColor(GREEN);
		SetPixelColor(GREEN);SetPixelColor(GREEN);SetPixelColor(GREEN);SetPixelColor(GREEN);SetPixelColor(GREEN);
		SetPixelColor(GREEN);SetPixelColor(GREEN);SetPixelColor(LIGHTGREEN);SetPixelColor(BLACK);
		CustomConsole.GotoXY(_x - 2, _y + 6);
		SetPixelColor(BLACK); SetPixelColor(LIGHTGREEN); SetPixelColor(GREEN);SetPixelColor(BLACK);SetPixelColor(GREEN);
		SetPixelColor(GREEN);SetPixelColor(BLACK);SetPixelColor(GREEN);SetPixelColor(GREEN);SetPixelColor(GREEN);
		SetPixelColor(GREEN);SetPixelColor(GREEN);SetPixelColor(LIGHTGREEN);SetPixelColor(BLACK);
		CustomConsole.GotoXY(_x - 2, _y + 7);
		SetPixelColor(BLACK); SetPixelColor(LIGHTGREEN); SetPixelColor(GREEN);SetPixelColor(BLACK);SetPixelColor(GREEN);
		SetPixelColor(GREEN);SetPixelColor(BLACK);SetPixelColor(GREEN);SetPixelColor(GREEN);SetPixelColor(GREEN);
		SetPixelColor(GREEN);SetPixelColor(GREEN);SetPixelColor(LIGHTGREEN);SetPixelColor(BLACK);
		CustomConsole.GotoXY(_x - 2, _y + 8);
		SetPixelColor(BLACK);SetPixelColor(GREEN); SetPixelColor(GREEN);SetPixelColor(BLACK);SetPixelColor(GREEN);
		SetPixelColor(GREEN);SetPixelColor(BLACK);SetPixelColor(GREEN);SetPixelColor(GREEN);SetPixelColor(GREEN);
		SetPixelColor(GREEN);SetPixelColor(GREEN);SetPixelColor(GREEN);SetPixelColor(BLACK);
		CustomConsole.GotoXY(_x, _y + 9);
		SetPixelColor(BLACK);SetPixelColor(LIGHTRED);SetPixelColor(LIGHTRED);SetPixelColor(GREEN);SetPixelColor(GREEN);
		SetPixelColor(LIGHTRED);SetPixelColor(LIGHTRED);SetPixelColor(GREEN);SetPixelColor(GREEN);SetPixelColor(GREEN);
		SetPixelColor(GREEN);SetPixelColor(BLACK);
		CustomConsole.GotoXY(_x + 2, _y + 10);
		SetPixelColor(BLACK);SetPixelColor(BLACK);SetPixelColor(GREEN);SetPixelColor(GREEN);SetPixelColor(GREEN);
		SetPixelColor(GREEN);SetPixelColor(GREEN);SetPixelColor(GREEN);SetPixelColor(BLACK);SetPixelColor(BLACK);
		CustomConsole.GotoXY(_x + 6, _y + 11);
		SetPixelColor(BLACK);SetPixelColor(BLACK);SetPixelColor(BLACK);SetPixelColor(BLACK);
		SetPixelColor(BLACK);SetPixelColor(BLACK);
		break;
	case 4:
		CustomConsole.GotoXY(_x + 8, _y);
		SetPixelColor(BLACK); SetPixelColor(BLACK); SetPixelColor(BLACK); SetPixelColor(BLACK);
		CustomConsole.GotoXY(_x + 4, _y + 1);
		SetPixelColor(BLACK); SetPixelColor(BLACK); SetPixelColor(LIGHTGREEN); SetPixelColor(LIGHTGREEN);
		SetPixelColor(LIGHTGREEN); SetPixelColor(LIGHTGREEN); SetPixelColor(BLACK); SetPixelColor(BLACK);
		CustomConsole.GotoXY(_x + 2, _y + 2);
		SetPixelColor(BLACK); SetPixelColor(LIGHTGREEN); SetPixelColor(LIGHTGREEN); SetPixelColor(LIGHTGREEN); SetPixelColor(GREEN);
		SetPixelColor(GREEN); SetPixelColor(GREEN); SetPixelColor(LIGHTGREEN); SetPixelColor(LIGHTGREEN);SetPixelColor(BLACK);
		CustomConsole.GotoXY(_x, _y + 3);
		SetPixelColor(BLACK); SetPixelColor(LIGHTGREEN); SetPixelColor(GREEN); SetPixelColor(LIGHTGREEN); SetPixelColor(LIGHTGREEN);
		SetPixelColor(GREEN);SetPixelColor(GREEN);SetPixelColor(GREEN);SetPixelColor(GREEN);SetPixelColor(GREEN);
		SetPixelColor(LIGHTGREEN);SetPixelColor(BLACK);
		CustomConsole.GotoXY(_x, _y + 4);
		SetPixelColor(BLACK); SetPixelColor(LIGHTGREEN); SetPixelColor(GREEN); SetPixelColor(GREEN); SetPixelColor(GREEN);
		SetPixelColor(GREEN);SetPixelColor(GREEN);SetPixelColor(GREEN);SetPixelColor(GREEN);SetPixelColor(GREEN);
		SetPixelColor(LIGHTGREEN);SetPixelColor(BLACK);
		CustomConsole.GotoXY(_x - 2, _y + 5);
		SetPixelColor(BLACK); SetPixelColor(LIGHTGREEN); SetPixelColor(GREEN);SetPixelColor(BLACK);SetPixelColor(GREEN);
		SetPixelColor(GREEN);SetPixelColor(BLACK);SetPixelColor(GREEN);SetPixelColor(GREEN);SetPixelColor(GREEN);
		SetPixelColor(GREEN);SetPixelColor(GREEN);SetPixelColor(LIGHTGREEN);SetPixelColor(BLACK);
		CustomConsole.GotoXY(_x - 2, _y + 6);
		SetPixelColor(BLACK); SetPixelColor(LIGHTGREEN); SetPixelColor(GREEN);SetPixelColor(BLACK);SetPixelColor(GREEN);
		SetPixelColor(GREEN);SetPixelColor(BLACK);SetPixelColor(GREEN);SetPixelColor(GREEN);SetPixelColor(GREEN);
		SetPixelColor(GREEN);SetPixelColor(GREEN);SetPixelColor(LIGHTGREEN);SetPixelColor(BLACK);
		CustomConsole.GotoXY(_x - 2, _y + 7);
		SetPixelColor(BLACK); SetPixelColor(LIGHTGREEN); SetPixelColor(GREEN);SetPixelColor(BLACK);SetPixelColor(GREEN);
		SetPixelColor(GREEN);SetPixelColor(BLACK);SetPixelColor(GREEN);SetPixelColor(GREEN);SetPixelColor(GREEN);
		SetPixelColor(GREEN);SetPixelColor(GREEN);SetPixelColor(LIGHTGREEN);SetPixelColor(BLACK);
		CustomConsole.GotoXY(_x - 2, _y + 8);
		SetPixelColor(BLACK);SetPixelColor(GREEN); SetPixelColor(LIGHTRED);SetPixelColor(LIGHTRED);SetPixelColor(GREEN);
		SetPixelColor(GREEN);SetPixelColor(LIGHTRED);SetPixelColor(LIGHTRED);SetPixelColor(GREEN);SetPixelColor(GREEN);
		SetPixelColor(GREEN);SetPixelColor(GREEN);SetPixelColor(GREEN);SetPixelColor(BLACK);
		CustomConsole.GotoXY(_x, _y + 9);
		SetPixelColor(BLACK);SetPixelColor(GREEN);SetPixelColor(GREEN);SetPixelColor(GREEN);SetPixelColor(GREEN);
		SetPixelColor(GREEN);SetPixelColor(GREEN);SetPixelColor(GREEN);SetPixelColor(GREEN);SetPixelColor(GREEN);
		SetPixelColor(GREEN);SetPixelColor(BLACK);
		CustomConsole.GotoXY(_x + 2, _y + 10);
		SetPixelColor(BLACK);SetPixelColor(BLACK);SetPixelColor(GREEN);SetPixelColor(GREEN);SetPixelColor(GREEN);
		SetPixelColor(GREEN);SetPixelColor(GREEN);SetPixelColor(GREEN);SetPixelColor(BLACK);SetPixelColor(BLACK);
		CustomConsole.GotoXY(_x + 6, _y + 11);
		SetPixelColor(BLACK);SetPixelColor(BLACK);SetPixelColor(BLACK);SetPixelColor(BLACK);
		SetPixelColor(BLACK);SetPixelColor(BLACK);
		break;
	case 5:
		CustomConsole.GotoXY(_x + 8, _y);
		SetPixelColor(BLACK); SetPixelColor(BLACK); SetPixelColor(BLACK); SetPixelColor(BLACK);
		CustomConsole.GotoXY(_x + 4, _y + 1);
		SetPixelColor(BLACK); SetPixelColor(BLACK); SetPixelColor(LIGHTGREEN); SetPixelColor(LIGHTGREEN);
		SetPixelColor(LIGHTGREEN); SetPixelColor(LIGHTGREEN); SetPixelColor(BLACK); SetPixelColor(BLACK);
		CustomConsole.GotoXY(_x + 2, _y + 2);
		SetPixelColor(BLACK); SetPixelColor(LIGHTGREEN); SetPixelColor(LIGHTGREEN); SetPixelColor(LIGHTGREEN); SetPixelColor(GREEN);
		SetPixelColor(GREEN); SetPixelColor(GREEN); SetPixelColor(LIGHTGREEN); SetPixelColor(LIGHTGREEN);SetPixelColor(BLACK);
		CustomConsole.GotoXY(_x, _y + 3);
		SetPixelColor(BLACK); SetPixelColor(LIGHTGREEN); SetPixelColor(GREEN); SetPixelColor(LIGHTGREEN); SetPixelColor(LIGHTGREEN);
		SetPixelColor(GREEN);SetPixelColor(GREEN);SetPixelColor(GREEN);SetPixelColor(GREEN);SetPixelColor(GREEN);
		SetPixelColor(LIGHTGREEN);SetPixelColor(BLACK);
		CustomConsole.GotoXY(_x, _y + 4);
		SetPixelColor(BLACK); SetPixelColor(LIGHTGREEN); SetPixelColor(BLACK); SetPixelColor(GREEN); SetPixelColor(GREEN);
		SetPixelColor(BLACK);SetPixelColor(GREEN);SetPixelColor(GREEN);SetPixelColor(GREEN);SetPixelColor(GREEN);
		SetPixelColor(LIGHTGREEN);SetPixelColor(BLACK);
		CustomConsole.GotoXY(_x - 2, _y + 5);
		SetPixelColor(BLACK); SetPixelColor(LIGHTGREEN); SetPixelColor(GREEN);SetPixelColor(BLACK);SetPixelColor(GREEN);
		SetPixelColor(GREEN);SetPixelColor(BLACK);SetPixelColor(GREEN);SetPixelColor(GREEN);SetPixelColor(GREEN);
		SetPixelColor(GREEN);SetPixelColor(GREEN);SetPixelColor(LIGHTGREEN);SetPixelColor(BLACK);
		CustomConsole.GotoXY(_x - 2, _y + 6);
		SetPixelColor(BLACK); SetPixelColor(LIGHTGREEN); SetPixelColor(GREEN);SetPixelColor(BLACK);SetPixelColor(GREEN);
		SetPixelColor(GREEN);SetPixelColor(BLACK);SetPixelColor(GREEN);SetPixelColor(GREEN);SetPixelColor(GREEN);
		SetPixelColor(GREEN);SetPixelColor(GREEN);SetPixelColor(LIGHTGREEN);SetPixelColor(BLACK);
		CustomConsole.GotoXY(_x - 2, _y + 7);
		SetPixelColor(BLACK); SetPixelColor(LIGHTGREEN); SetPixelColor(LIGHTRED);SetPixelColor(LIGHTRED);SetPixelColor(GREEN);
		SetPixelColor(GREEN);SetPixelColor(LIGHTRED);SetPixelColor(LIGHTRED);SetPixelColor(GREEN);SetPixelColor(GREEN);
		SetPixelColor(GREEN);SetPixelColor(GREEN);SetPixelColor(LIGHTGREEN);SetPixelColor(BLACK);
		CustomConsole.GotoXY(_x - 2, _y + 8);
		SetPixelColor(BLACK);SetPixelColor(GREEN); SetPixelColor(GREEN);SetPixelColor(GREEN);SetPixelColor(GREEN);
		SetPixelColor(GREEN);SetPixelColor(GREEN);SetPixelColor(GREEN);SetPixelColor(GREEN);SetPixelColor(GREEN);
		SetPixelColor(GREEN);SetPixelColor(GREEN);SetPixelColor(GREEN);SetPixelColor(BLACK);
		CustomConsole.GotoXY(_x, _y + 9);
		SetPixelColor(BLACK);SetPixelColor(GREEN);SetPixelColor(GREEN);SetPixelColor(GREEN);SetPixelColor(GREEN);
		SetPixelColor(GREEN);SetPixelColor(GREEN);SetPixelColor(GREEN);SetPixelColor(GREEN);SetPixelColor(GREEN);
		SetPixelColor(GREEN);SetPixelColor(BLACK);
		CustomConsole.GotoXY(_x + 2, _y + 10);
		SetPixelColor(BLACK);SetPixelColor(BLACK);SetPixelColor(GREEN);SetPixelColor(GREEN);SetPixelColor(GREEN);
		SetPixelColor(GREEN);SetPixelColor(GREEN);SetPixelColor(GREEN);SetPixelColor(BLACK);SetPixelColor(BLACK);
		CustomConsole.GotoXY(_x + 6, _y + 11);
		SetPixelColor(BLACK);SetPixelColor(BLACK);SetPixelColor(BLACK);SetPixelColor(BLACK);
		SetPixelColor(BLACK);SetPixelColor(BLACK);
		break;
	case 6:
		CustomConsole.GotoXY(_x + 8, _y - 1);
		SetPixelColor(BLACK); SetPixelColor(BLACK); SetPixelColor(BLACK); SetPixelColor(BLACK);
		CustomConsole.GotoXY(_x + 4, _y);
		SetPixelColor(BLACK); SetPixelColor(BLACK); SetPixelColor(LIGHTGREEN); SetPixelColor(LIGHTGREEN);
		SetPixelColor(LIGHTGREEN); SetPixelColor(LIGHTGREEN); SetPixelColor(BLACK); SetPixelColor(BLACK);
		CustomConsole.GotoXY(_x + 2, _y + 1);
		SetPixelColor(BLACK); SetPixelColor(LIGHTGREEN); SetPixelColor(LIGHTGREEN); SetPixelColor(LIGHTGREEN); SetPixelColor(GREEN);
		SetPixelColor(GREEN); SetPixelColor(GREEN); SetPixelColor(LIGHTGREEN); SetPixelColor(LIGHTGREEN);SetPixelColor(BLACK);
		CustomConsole.GotoXY(_x, _y + 2);
		SetPixelColor(BLACK); SetPixelColor(LIGHTGREEN); SetPixelColor(GREEN); SetPixelColor(LIGHTGREEN); SetPixelColor(LIGHTGREEN);
		SetPixelColor(GREEN);SetPixelColor(GREEN);SetPixelColor(GREEN);SetPixelColor(GREEN);SetPixelColor(GREEN);
		SetPixelColor(LIGHTGREEN);SetPixelColor(BLACK);
		CustomConsole.GotoXY(_x, _y + 3);
		SetPixelColor(BLACK); SetPixelColor(LIGHTGREEN); SetPixelColor(BLACK); SetPixelColor(GREEN); SetPixelColor(GREEN);
		SetPixelColor(BLACK);SetPixelColor(GREEN);SetPixelColor(GREEN);SetPixelColor(GREEN);SetPixelColor(GREEN);
		SetPixelColor(LIGHTGREEN);SetPixelColor(BLACK);
		CustomConsole.GotoXY(_x - 2, _y + 4);
		SetPixelColor(BLACK); SetPixelColor(LIGHTGREEN); SetPixelColor(GREEN);SetPixelColor(BLACK);SetPixelColor(GREEN);
		SetPixelColor(GREEN);SetPixelColor(BLACK);SetPixelColor(GREEN);SetPixelColor(GREEN);SetPixelColor(GREEN);
		SetPixelColor(GREEN);SetPixelColor(GREEN);SetPixelColor(LIGHTGREEN);SetPixelColor(BLACK);
		CustomConsole.GotoXY(_x - 2, _y + 5);
		SetPixelColor(BLACK); SetPixelColor(LIGHTGREEN); SetPixelColor(GREEN);SetPixelColor(BLACK);SetPixelColor(GREEN);
		SetPixelColor(GREEN);SetPixelColor(BLACK);SetPixelColor(GREEN);SetPixelColor(GREEN);SetPixelColor(GREEN);
		SetPixelColor(GREEN);SetPixelColor(GREEN);SetPixelColor(LIGHTGREEN);SetPixelColor(BLACK);
		CustomConsole.GotoXY(_x - 2, _y + 6);
		SetPixelColor(BLACK); SetPixelColor(LIGHTGREEN); SetPixelColor(LIGHTRED);SetPixelColor(LIGHTRED);SetPixelColor(GREEN);
		SetPixelColor(GREEN);SetPixelColor(LIGHTRED);SetPixelColor(LIGHTRED);SetPixelColor(GREEN);SetPixelColor(GREEN);
		SetPixelColor(GREEN);SetPixelColor(GREEN);SetPixelColor(LIGHTGREEN);SetPixelColor(BLACK);
		CustomConsole.GotoXY(_x - 2, _y + 7);
		SetPixelColor(BLACK); SetPixelColor(LIGHTGREEN); SetPixelColor(GREEN);SetPixelColor(GREEN);SetPixelColor(GREEN);
		SetPixelColor(GREEN);SetPixelColor(GREEN);SetPixelColor(GREEN);SetPixelColor(GREEN);SetPixelColor(GREEN);
		SetPixelColor(GREEN);SetPixelColor(GREEN);SetPixelColor(LIGHTGREEN);SetPixelColor(BLACK);
		CustomConsole.GotoXY(_x - 2, _y + 8);
		SetPixelColor(BLACK);SetPixelColor(GREEN); SetPixelColor(GREEN);SetPixelColor(GREEN);SetPixelColor(GREEN);
		SetPixelColor(GREEN);SetPixelColor(GREEN);SetPixelColor(GREEN);SetPixelColor(GREEN);SetPixelColor(GREEN);
		SetPixelColor(GREEN);SetPixelColor(GREEN);SetPixelColor(GREEN);SetPixelColor(BLACK);
		CustomConsole.GotoXY(_x, _y + 9);
		SetPixelColor(BLACK);SetPixelColor(GREEN);SetPixelColor(GREEN);SetPixelColor(GREEN);SetPixelColor(GREEN);
		SetPixelColor(GREEN);SetPixelColor(GREEN);SetPixelColor(GREEN);SetPixelColor(GREEN);SetPixelColor(GREEN);
		SetPixelColor(GREEN);SetPixelColor(BLACK);
		CustomConsole.GotoXY(_x + 2, _y + 10);
		SetPixelColor(BLACK);SetPixelColor(BLACK);SetPixelColor(GREEN);SetPixelColor(GREEN);SetPixelColor(GREEN);
		SetPixelColor(GREEN);SetPixelColor(GREEN);SetPixelColor(GREEN);SetPixelColor(BLACK);SetPixelColor(BLACK);
		CustomConsole.GotoXY(_x + 6, _y + 11);
		SetPixelColor(BLACK);SetPixelColor(BLACK);SetPixelColor(BLACK);SetPixelColor(BLACK);
		SetPixelColor(BLACK);SetPixelColor(BLACK);
		break;
	case 7:
		CustomConsole.GotoXY(_x + 8, _y - 1);
		SetPixelColor(BLACK); SetPixelColor(BLACK); SetPixelColor(BLACK); SetPixelColor(BLACK);
		CustomConsole.GotoXY(_x + 4, _y);
		SetPixelColor(BLACK); SetPixelColor(BLACK); SetPixelColor(LIGHTGREEN); SetPixelColor(LIGHTGREEN);
		SetPixelColor(LIGHTGREEN); SetPixelColor(LIGHTGREEN); SetPixelColor(BLACK); SetPixelColor(BLACK);
		CustomConsole.GotoXY(_x + 2, _y + 1);
		SetPixelColor(BLACK); SetPixelColor(LIGHTGREEN); SetPixelColor(LIGHTGREEN); SetPixelColor(LIGHTGREEN); SetPixelColor(GREEN);
		SetPixelColor(GREEN); SetPixelColor(GREEN); SetPixelColor(LIGHTGREEN); SetPixelColor(LIGHTGREEN);SetPixelColor(BLACK);
		CustomConsole.GotoXY(_x, _y + 2);
		SetPixelColor(BLACK); SetPixelColor(LIGHTGREEN); SetPixelColor(GREEN); SetPixelColor(GREEN); SetPixelColor(GREEN);
		SetPixelColor(GREEN);SetPixelColor(GREEN);SetPixelColor(GREEN);SetPixelColor(GREEN);SetPixelColor(GREEN);
		SetPixelColor(LIGHTGREEN);SetPixelColor(BLACK);
		CustomConsole.GotoXY(_x, _y + 3);
		SetPixelColor(BLACK); SetPixelColor(LIGHTGREEN); SetPixelColor(BLACK); SetPixelColor(GREEN); SetPixelColor(GREEN);
		SetPixelColor(BLACK);SetPixelColor(GREEN);SetPixelColor(GREEN);SetPixelColor(GREEN);SetPixelColor(GREEN);
		SetPixelColor(LIGHTGREEN);SetPixelColor(BLACK);
		CustomConsole.GotoXY(_x - 2, _y + 4);
		SetPixelColor(BLACK); SetPixelColor(LIGHTGREEN); SetPixelColor(GREEN);SetPixelColor(BLACK);SetPixelColor(GREEN);
		SetPixelColor(GREEN);SetPixelColor(BLACK);SetPixelColor(GREEN);SetPixelColor(GREEN);SetPixelColor(GREEN);
		SetPixelColor(GREEN);SetPixelColor(GREEN);SetPixelColor(LIGHTGREEN);SetPixelColor(BLACK);
		CustomConsole.GotoXY(_x - 2, _y + 5);
		SetPixelColor(BLACK); SetPixelColor(LIGHTGREEN); SetPixelColor(GREEN);SetPixelColor(BLACK);SetPixelColor(GREEN);
		SetPixelColor(GREEN);SetPixelColor(BLACK);SetPixelColor(GREEN);SetPixelColor(GREEN);SetPixelColor(GREEN);
		SetPixelColor(GREEN);SetPixelColor(GREEN);SetPixelColor(LIGHTGREEN);SetPixelColor(BLACK);
		CustomConsole.GotoXY(_x - 2, _y + 6);
		SetPixelColor(BLACK); SetPixelColor(LIGHTGREEN); SetPixelColor(LIGHTRED);SetPixelColor(LIGHTRED);SetPixelColor(GREEN);
		SetPixelColor(GREEN);SetPixelColor(LIGHTRED);SetPixelColor(LIGHTRED);SetPixelColor(GREEN);SetPixelColor(GREEN);
		SetPixelColor(GREEN);SetPixelColor(GREEN);SetPixelColor(LIGHTGREEN);SetPixelColor(BLACK);
		CustomConsole.GotoXY(_x - 2, _y + 7);
		SetPixelColor(BLACK); SetPixelColor(LIGHTGREEN); SetPixelColor(GREEN);SetPixelColor(GREEN);SetPixelColor(GREEN);
		SetPixelColor(GREEN);SetPixelColor(GREEN);SetPixelColor(GREEN);SetPixelColor(GREEN);SetPixelColor(GREEN);
		SetPixelColor(GREEN);SetPixelColor(GREEN);SetPixelColor(LIGHTGREEN);SetPixelColor(BLACK);
		CustomConsole.GotoXY(_x - 2, _y + 8);
		SetPixelColor(BLACK);SetPixelColor(GREEN); SetPixelColor(GREEN);SetPixelColor(GREEN);SetPixelColor(GREEN);
		SetPixelColor(GREEN);SetPixelColor(GREEN);SetPixelColor(GREEN);SetPixelColor(GREEN);SetPixelColor(GREEN);
		SetPixelColor(GREEN);SetPixelColor(GREEN);SetPixelColor(GREEN);SetPixelColor(BLACK);
		CustomConsole.GotoXY(_x, _y + 9);
		SetPixelColor(BLACK);SetPixelColor(GREEN);SetPixelColor(GREEN);SetPixelColor(GREEN);SetPixelColor(GREEN);
		SetPixelColor(GREEN);SetPixelColor(GREEN);SetPixelColor(GREEN);SetPixelColor(GREEN);SetPixelColor(GREEN);
		SetPixelColor(GREEN);SetPixelColor(BLACK);
		CustomConsole.GotoXY(_x + 2, _y + 10);
		SetPixelColor(BLACK);SetPixelColor(BLACK);SetPixelColor(GREEN);SetPixelColor(GREEN);SetPixelColor(GREEN);
		SetPixelColor(GREEN);SetPixelColor(GREEN);SetPixelColor(GREEN);SetPixelColor(BLACK);SetPixelColor(BLACK);
		CustomConsole.GotoXY(_x + 6, _y + 11);
		SetPixelColor(BLACK);SetPixelColor(BLACK);SetPixelColor(BLACK);SetPixelColor(BLACK);
		SetPixelColor(BLACK);SetPixelColor(BLACK);
		break;
	case 8:
		CustomConsole.GotoXY(_x + 8, _y - 1);
		SetPixelColor(BLACK); SetPixelColor(BLACK); SetPixelColor(BLACK); SetPixelColor(BLACK);
		CustomConsole.GotoXY(_x + 4, _y);
		SetPixelColor(BLACK); SetPixelColor(BLACK); SetPixelColor(LIGHTGREEN); SetPixelColor(LIGHTGREEN);
		SetPixelColor(LIGHTGREEN); SetPixelColor(LIGHTGREEN); SetPixelColor(BLACK); SetPixelColor(BLACK);
		CustomConsole.GotoXY(_x + 2, _y + 1);
		SetPixelColor(BLACK); SetPixelColor(LIGHTGREEN); SetPixelColor(LIGHTGREEN); SetPixelColor(LIGHTGREEN); SetPixelColor(GREEN);
		SetPixelColor(GREEN); SetPixelColor(GREEN); SetPixelColor(LIGHTGREEN); SetPixelColor(LIGHTGREEN);SetPixelColor(BLACK);
		CustomConsole.GotoXY(_x, _y + 2);
		SetPixelColor(BLACK); SetPixelColor(LIGHTGREEN); SetPixelColor(BLACK); SetPixelColor(GREEN); SetPixelColor(GREEN);
		SetPixelColor(BLACK);SetPixelColor(GREEN);SetPixelColor(GREEN);SetPixelColor(GREEN);SetPixelColor(GREEN);
		SetPixelColor(LIGHTGREEN);SetPixelColor(BLACK);
		CustomConsole.GotoXY(_x, _y + 3);
		SetPixelColor(BLACK); SetPixelColor(LIGHTGREEN); SetPixelColor(BLACK); SetPixelColor(GREEN); SetPixelColor(GREEN);
		SetPixelColor(BLACK);SetPixelColor(GREEN);SetPixelColor(GREEN);SetPixelColor(GREEN);SetPixelColor(GREEN);
		SetPixelColor(LIGHTGREEN);SetPixelColor(BLACK);
		CustomConsole.GotoXY(_x - 2, _y + 4);
		SetPixelColor(BLACK); SetPixelColor(LIGHTGREEN); SetPixelColor(GREEN);SetPixelColor(BLACK);SetPixelColor(GREEN);
		SetPixelColor(GREEN);SetPixelColor(BLACK);SetPixelColor(GREEN);SetPixelColor(GREEN);SetPixelColor(GREEN);
		SetPixelColor(GREEN);SetPixelColor(GREEN);SetPixelColor(LIGHTGREEN);SetPixelColor(BLACK);
		CustomConsole.GotoXY(_x - 2, _y + 5);
		SetPixelColor(BLACK); SetPixelColor(LIGHTGREEN); SetPixelColor(LIGHTRED);SetPixelColor(LIGHTRED);SetPixelColor(GREEN);
		SetPixelColor(GREEN);SetPixelColor(LIGHTRED);SetPixelColor(LIGHTRED);SetPixelColor(GREEN);SetPixelColor(GREEN);
		SetPixelColor(GREEN);SetPixelColor(GREEN);SetPixelColor(LIGHTGREEN);SetPixelColor(BLACK);
		CustomConsole.GotoXY(_x - 2, _y + 6);
		SetPixelColor(BLACK); SetPixelColor(LIGHTGREEN); SetPixelColor(GREEN);SetPixelColor(GREEN);SetPixelColor(GREEN);
		SetPixelColor(GREEN);SetPixelColor(GREEN);SetPixelColor(GREEN);SetPixelColor(GREEN);SetPixelColor(GREEN);
		SetPixelColor(GREEN);SetPixelColor(GREEN);SetPixelColor(LIGHTGREEN);SetPixelColor(BLACK);
		CustomConsole.GotoXY(_x - 2, _y + 7);
		SetPixelColor(BLACK); SetPixelColor(LIGHTGREEN); SetPixelColor(GREEN);SetPixelColor(GREEN);SetPixelColor(GREEN);
		SetPixelColor(GREEN);SetPixelColor(GREEN);SetPixelColor(GREEN);SetPixelColor(GREEN);SetPixelColor(GREEN);
		SetPixelColor(GREEN);SetPixelColor(GREEN);SetPixelColor(LIGHTGREEN);SetPixelColor(BLACK);
		CustomConsole.GotoXY(_x - 2, _y + 8);
		SetPixelColor(BLACK);SetPixelColor(GREEN); SetPixelColor(GREEN);SetPixelColor(GREEN);SetPixelColor(GREEN);
		SetPixelColor(GREEN);SetPixelColor(GREEN);SetPixelColor(GREEN);SetPixelColor(GREEN);SetPixelColor(GREEN);
		SetPixelColor(GREEN);SetPixelColor(GREEN);SetPixelColor(GREEN);SetPixelColor(BLACK);
		CustomConsole.GotoXY(_x, _y + 9);
		SetPixelColor(BLACK);SetPixelColor(GREEN);SetPixelColor(GREEN);SetPixelColor(GREEN);SetPixelColor(GREEN);
		SetPixelColor(GREEN);SetPixelColor(GREEN);SetPixelColor(GREEN);SetPixelColor(GREEN);SetPixelColor(GREEN);
		SetPixelColor(GREEN);SetPixelColor(BLACK);
		CustomConsole.GotoXY(_x + 2, _y + 10);
		SetPixelColor(BLACK);SetPixelColor(BLACK);SetPixelColor(GREEN);SetPixelColor(GREEN);SetPixelColor(GREEN);
		SetPixelColor(GREEN);SetPixelColor(GREEN);SetPixelColor(GREEN);SetPixelColor(BLACK);SetPixelColor(BLACK);
		CustomConsole.GotoXY(_x + 6, _y + 11);
		SetPixelColor(BLACK);SetPixelColor(BLACK);SetPixelColor(BLACK);SetPixelColor(BLACK);
		SetPixelColor(BLACK);SetPixelColor(BLACK);
		break;
	case 9:
		CustomConsole.GotoXY(_x + 8, _y);
		SetPixelColor(BLACK); SetPixelColor(BLACK); SetPixelColor(BLACK); SetPixelColor(BLACK);
		CustomConsole.GotoXY(_x + 4, _y + 1);
		SetPixelColor(BLACK); SetPixelColor(BLACK); SetPixelColor(LIGHTGREEN); SetPixelColor(LIGHTGREEN);
		SetPixelColor(LIGHTGREEN); SetPixelColor(LIGHTGREEN); SetPixelColor(BLACK); SetPixelColor(BLACK);
		CustomConsole.GotoXY(_x + 2, _y + 2);
		SetPixelColor(BLACK); SetPixelColor(BLACK); SetPixelColor(LIGHTGREEN); SetPixelColor(LIGHTGREEN); SetPixelColor(BLACK);
		SetPixelColor(GREEN); SetPixelColor(GREEN); SetPixelColor(LIGHTGREEN); SetPixelColor(LIGHTGREEN);SetPixelColor(BLACK);
		CustomConsole.GotoXY(_x, _y + 3);
		SetPixelColor(BLACK); SetPixelColor(LIGHTGREEN); SetPixelColor(BLACK); SetPixelColor(GREEN); SetPixelColor(GREEN);
		SetPixelColor(BLACK);SetPixelColor(GREEN);SetPixelColor(GREEN);SetPixelColor(GREEN);SetPixelColor(GREEN);
		SetPixelColor(LIGHTGREEN);SetPixelColor(BLACK);
		CustomConsole.GotoXY(_x, _y + 4);
		SetPixelColor(BLACK); SetPixelColor(LIGHTGREEN); SetPixelColor(BLACK); SetPixelColor(GREEN); SetPixelColor(GREEN);
		SetPixelColor(BLACK);SetPixelColor(GREEN);SetPixelColor(GREEN);SetPixelColor(GREEN);SetPixelColor(GREEN);
		SetPixelColor(LIGHTGREEN);SetPixelColor(BLACK);
		CustomConsole.GotoXY(_x - 2, _y + 5);
		SetPixelColor(BLACK); SetPixelColor(LIGHTGREEN); SetPixelColor(LIGHTRED);SetPixelColor(LIGHTRED);SetPixelColor(GREEN);
		SetPixelColor(GREEN);SetPixelColor(LIGHTRED);SetPixelColor(LIGHTRED);SetPixelColor(GREEN);SetPixelColor(GREEN);
		SetPixelColor(GREEN);SetPixelColor(GREEN);SetPixelColor(LIGHTGREEN);SetPixelColor(BLACK);
		CustomConsole.GotoXY(_x - 2, _y + 6);
		SetPixelColor(BLACK); SetPixelColor(LIGHTGREEN); SetPixelColor(GREEN);SetPixelColor(GREEN);SetPixelColor(GREEN);
		SetPixelColor(GREEN);SetPixelColor(GREEN);SetPixelColor(GREEN);SetPixelColor(GREEN);SetPixelColor(GREEN);
		SetPixelColor(GREEN);SetPixelColor(GREEN);SetPixelColor(LIGHTGREEN);SetPixelColor(BLACK);
		CustomConsole.GotoXY(_x - 2, _y + 7);
		SetPixelColor(BLACK); SetPixelColor(LIGHTGREEN); SetPixelColor(GREEN);SetPixelColor(GREEN);SetPixelColor(GREEN);
		SetPixelColor(GREEN);SetPixelColor(GREEN);SetPixelColor(GREEN);SetPixelColor(GREEN);SetPixelColor(GREEN);
		SetPixelColor(GREEN);SetPixelColor(GREEN);SetPixelColor(LIGHTGREEN);SetPixelColor(BLACK);
		CustomConsole.GotoXY(_x - 2, _y + 8);
		SetPixelColor(BLACK);SetPixelColor(GREEN); SetPixelColor(GREEN);SetPixelColor(GREEN);SetPixelColor(GREEN);
		SetPixelColor(GREEN);SetPixelColor(GREEN);SetPixelColor(GREEN);SetPixelColor(GREEN);SetPixelColor(GREEN);
		SetPixelColor(GREEN);SetPixelColor(GREEN);SetPixelColor(GREEN);SetPixelColor(BLACK);
		CustomConsole.GotoXY(_x, _y + 9);
		SetPixelColor(BLACK);SetPixelColor(GREEN);SetPixelColor(GREEN);SetPixelColor(GREEN);SetPixelColor(GREEN);
		SetPixelColor(GREEN);SetPixelColor(GREEN);SetPixelColor(GREEN);SetPixelColor(GREEN);SetPixelColor(GREEN);
		SetPixelColor(GREEN);SetPixelColor(BLACK);
		CustomConsole.GotoXY(_x + 2, _y + 10);
		SetPixelColor(BLACK);SetPixelColor(BLACK);SetPixelColor(GREEN);SetPixelColor(GREEN);SetPixelColor(GREEN);
		SetPixelColor(GREEN);SetPixelColor(GREEN);SetPixelColor(GREEN);SetPixelColor(BLACK);SetPixelColor(BLACK);
		CustomConsole.GotoXY(_x + 6, _y + 11);
		SetPixelColor(BLACK);SetPixelColor(BLACK);SetPixelColor(BLACK);SetPixelColor(BLACK);
		SetPixelColor(BLACK);SetPixelColor(BLACK);
		break;
	case 10:
		CustomConsole.GotoXY(_x + 8, _y);
		SetPixelColor(BLACK); SetPixelColor(BLACK); SetPixelColor(BLACK); SetPixelColor(BLACK);
		CustomConsole.GotoXY(_x + 4, _y + 1);
		SetPixelColor(BLACK); SetPixelColor(BLACK); SetPixelColor(LIGHTGREEN); SetPixelColor(LIGHTGREEN);
		SetPixelColor(LIGHTGREEN); SetPixelColor(LIGHTGREEN); SetPixelColor(BLACK); SetPixelColor(BLACK);
		CustomConsole.GotoXY(_x + 2, _y + 2);
		SetPixelColor(BLACK); SetPixelColor(LIGHTGREEN); SetPixelColor(LIGHTGREEN); SetPixelColor(LIGHTGREEN); SetPixelColor(GREEN);
		SetPixelColor(GREEN); SetPixelColor(GREEN); SetPixelColor(LIGHTGREEN); SetPixelColor(LIGHTGREEN);SetPixelColor(BLACK);
		CustomConsole.GotoXY(_x, _y + 3);
		SetPixelColor(BLACK); SetPixelColor(LIGHTGREEN); SetPixelColor(BLACK); SetPixelColor(GREEN); SetPixelColor(GREEN);
		SetPixelColor(BLACK);SetPixelColor(GREEN);SetPixelColor(GREEN);SetPixelColor(GREEN);SetPixelColor(GREEN);
		SetPixelColor(LIGHTGREEN);SetPixelColor(BLACK);
		CustomConsole.GotoXY(_x, _y + 4);
		SetPixelColor(BLACK); SetPixelColor(LIGHTGREEN); SetPixelColor(BLACK); SetPixelColor(GREEN); SetPixelColor(GREEN);
		SetPixelColor(BLACK);SetPixelColor(GREEN);SetPixelColor(GREEN);SetPixelColor(GREEN);SetPixelColor(GREEN);
		SetPixelColor(LIGHTGREEN);SetPixelColor(BLACK);
		CustomConsole.GotoXY(_x - 2, _y + 5);
		SetPixelColor(BLACK); SetPixelColor(LIGHTGREEN); SetPixelColor(GREEN);SetPixelColor(BLACK);SetPixelColor(GREEN);
		SetPixelColor(GREEN);SetPixelColor(BLACK);SetPixelColor(GREEN);SetPixelColor(GREEN);SetPixelColor(GREEN);
		SetPixelColor(GREEN);SetPixelColor(GREEN);SetPixelColor(LIGHTGREEN);SetPixelColor(BLACK);
		CustomConsole.GotoXY(_x - 2, _y + 6);
		SetPixelColor(BLACK); SetPixelColor(LIGHTGREEN); SetPixelColor(LIGHTRED);SetPixelColor(LIGHTRED);SetPixelColor(GREEN);
		SetPixelColor(GREEN);SetPixelColor(LIGHTRED);SetPixelColor(LIGHTRED);SetPixelColor(GREEN);SetPixelColor(GREEN);
		SetPixelColor(GREEN);SetPixelColor(GREEN);SetPixelColor(LIGHTGREEN);SetPixelColor(BLACK);
		CustomConsole.GotoXY(_x - 2, _y + 7);
		SetPixelColor(BLACK); SetPixelColor(LIGHTGREEN); SetPixelColor(GREEN);SetPixelColor(GREEN);SetPixelColor(GREEN);
		SetPixelColor(GREEN);SetPixelColor(GREEN);SetPixelColor(GREEN);SetPixelColor(GREEN);SetPixelColor(GREEN);
		SetPixelColor(GREEN);SetPixelColor(GREEN);SetPixelColor(LIGHTGREEN);SetPixelColor(BLACK);
		CustomConsole.GotoXY(_x - 2, _y + 8);
		SetPixelColor(BLACK);SetPixelColor(GREEN); SetPixelColor(GREEN);SetPixelColor(GREEN);SetPixelColor(GREEN);
		SetPixelColor(GREEN);SetPixelColor(GREEN);SetPixelColor(GREEN);SetPixelColor(GREEN);SetPixelColor(GREEN);
		SetPixelColor(GREEN);SetPixelColor(GREEN);SetPixelColor(GREEN);SetPixelColor(BLACK);
		CustomConsole.GotoXY(_x, _y + 9);
		SetPixelColor(BLACK);SetPixelColor(GREEN);SetPixelColor(GREEN);SetPixelColor(GREEN);SetPixelColor(GREEN);
		SetPixelColor(GREEN);SetPixelColor(GREEN);SetPixelColor(GREEN);SetPixelColor(GREEN);SetPixelColor(GREEN);
		SetPixelColor(GREEN);SetPixelColor(BLACK);
		CustomConsole.GotoXY(_x + 2, _y + 10);
		SetPixelColor(BLACK);SetPixelColor(BLACK);SetPixelColor(GREEN);SetPixelColor(GREEN);SetPixelColor(GREEN);
		SetPixelColor(GREEN);SetPixelColor(GREEN);SetPixelColor(GREEN);SetPixelColor(BLACK);SetPixelColor(BLACK);
		CustomConsole.GotoXY(_x + 6, _y + 11);
		SetPixelColor(BLACK);SetPixelColor(BLACK);SetPixelColor(BLACK);SetPixelColor(BLACK);
		SetPixelColor(BLACK);SetPixelColor(BLACK);
		break;
	default:
		break;
	}
}

void Character::Erase()
{
	CustomConsole.ClearScreen(GRAY);
}

void Character::EatFood()
{
	_foodGauge += 20;
	int _textX = 105;
	int _textY = 43;
	CustomConsole.GotoXY(_textX, _textY + 2);
	if (_foodGauge > 100)
	{
		_foodGauge = 100;
		cout << "���̻� �԰� ���� �ʾ�...";
	}
	else
	{
		cout << "��~~~ ���ִ� ����~~~";
		_happinessGauge += 10;
	}
}

void Character::Sleep()
{
	_fatigueGauge += 20;
	int _textX = 105;
	int _textY = 43;
	CustomConsole.GotoXY(_textX, _textY + 2);
	if (_fatigueGauge > 100)
	{
		_fatigueGauge = 100;
		cout << "���� �ڰ� ���� �ʾ�...";
	}
	else
	{
		cout << "..zzZ";
		_happinessGauge += 10;
	}
}

void Character::EnjoyPlay()
{
	_fatigueGauge -= 20;
	int _textX = 105;
	int _textY = 43;
	CustomConsole.GotoXY(_textX, _textY + 2);
	if (_fatigueGauge <= 0)
	{
		cout << "�ǰ��ؼ� �����̰� ���� �ʾ� �Ф�...";
	}
	else if (_foodGauge <= 0)
	{
		cout << "����ļ� ������ ���� ���� �Ф�...";
	}
	else
	{
		cout << "�ų��� ���� �ð� ^ �� ^";
		_happinessGauge += 10;
	}
}

void Character::Status()
{
	CustomConsole.ClearArea(0, 0, 10, 2);
	CustomConsole.GotoXY(0, 0); cout << "�ູ�� : " << _happinessGauge;
	CustomConsole.GotoXY(0, 1); cout << "������ : " << _foodGauge;
	CustomConsole.GotoXY(0, 2); cout << "�Ƿε� : " << _fatigueGauge;
}

void Character::Release()
{
}
