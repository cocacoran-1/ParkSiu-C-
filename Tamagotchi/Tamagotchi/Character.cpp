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
	_shapeX = 110;
	_shapeY = 15;
	_textX = 105;
	_textY = 43;
	_animationIndex = 0;
	_animationTime = 0;
	_showTextTime = 0;
	_foodGauge = 50;
	_activityGauge = 0;
	_happinessGauge = 0;
	_level = 0;
	_textType = 0;
	_movementType = 0;
}

void Character::Update(int deltaTime, char inputKey)
{
	//ĳ���� �ִϸ��̼� �ڵ�
	_animationTime += deltaTime;
	if (1000 < _animationTime)
	{
		Status();

		switch (_textType)
		{
		case 0:
			CustomConsole.ClearArea(_x + 28, _y + 1, _x + 60, _y + 1);
			break;
		case 1:
			CustomConsole.ClearArea(_x + 28, _y + 1, _x + 60, _y + 1);
			CustomConsole.GotoXY(_x + 30, _y + 1);
			if (_foodGauge >= 100)
			{
				cout << "���̻� �԰� ���� �ʾ�...";
			}
			else
			{
				cout << "���ִ� ����~~~";
			}
			break;
		case 2:
			CustomConsole.ClearArea(_x + 28, _y + 1, _x + 60, _y + 1);
			CustomConsole.GotoXY(_x + 30, _y + 1);
			if (_activityGauge > 100)
			{
				cout << "���� �ڰ� ���� �ʾ�...";
			}
			else if (_foodGauge < 0)
			{
				cout << "�����...";
			}
			else
			{
				cout << "..zzZ";
			}
			break;
		case 3:
			CustomConsole.ClearArea(_x + 28, _y + 1, _x + 60, _y + 1);
			CustomConsole.GotoXY(_x + 30, _y + 1);
			if (_activityGauge < 0)
			{
				cout << "�ǰ���...";
			}
			else if (_foodGauge < 0)
			{
				cout << "�����...";
			}
			else
			{
				cout << "�ų��� ���� �ð� ^ �� ^";
			}
			break;
		case 4:
			CustomConsole.ClearArea(_x + 28, _y + 1, _x + 60, _y + 1);
			CustomConsole.GotoXY(_x + 30, _y + 1);
			cout << "�� �� ��!!";
			break;
		default:
			break;
		}
		// �̵� ����
		switch (_movementType)
		{
		case eMovement::STAY:
			Animation(9);
			StayRender();
			break;
		case eMovement::LEFT:
			Animation(10);
			if (_animationIndex % 2 == 0)
			{
				_x++;
				_shapeX++;
				// ������ �ִ� �̵�����
				if (_x >= 210)
				{
					_x = 210;
				}
			}
			RightRender();
			break;
		case eMovement::RIGHT:
			Animation(10);
			if (_animationIndex % 2 == 0)
			{
				_x--;
				_shapeX--;
				// ���� �ִ� �̵� ����
				if (_x <= 2)
				{
					_x = 2;
				}
			}
			LeftRender();
			break;
		default:
			break;
		}
	}
}

void Character::Direction()
{
	int random = rand() % 3;
	_movementType = random;
}

void Character::Animation(int index)
{
	if (_animationIndex == index)
	{
		_textType = 0;
		Direction();
	}

	_animationTime = 0;
	_animationIndex++;
	_animationIndex %= index + 1;
	Erase();
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

void Character::HeartRender()
{
	CustomConsole.ClearArea(_shapeX + 40, _shapeY - 10, _shapeX + 70, _shapeY - 4);

	CustomConsole.GotoXY(_shapeX + 40, _shapeY - 8); 
	SetPixelColor(RED);
	CustomConsole.GotoXY(_shapeX + 44, _shapeY - 8); 
	SetPixelColor(RED);
	CustomConsole.GotoXY(_shapeX + 38, _shapeY - 7);
	SetPixelColor(RED);SetPixelColor(RED);SetPixelColor(RED);SetPixelColor(RED);SetPixelColor(RED);
	CustomConsole.GotoXY(_shapeX + 40, _shapeY - 6);
	SetPixelColor(RED);SetPixelColor(RED);SetPixelColor(RED);
	CustomConsole.GotoXY(_shapeX + 42, _shapeY - 5);
	SetPixelColor(RED);
}

void Character::Erase()
{
	_showTextTime++;
	CustomConsole.ClearArea(_x - 2, _y-1, _x + 10, _y + 12);

	if (_showTextTime == 5)
	{
		CustomConsole.ClearArea(_textX + 5, _textY - 7, _textX + 55, _textY - 7);
		CustomConsole.ClearArea(_x + 30, _y - 5, _x + 44, _y - 2);
		_showTextTime = 0;
	}
}

void Character::EatFood(int index)
{
	_foodGauge += 20;
	_textType = index;
	if (_foodGauge > 100)
	{
		_foodGauge = 100;
	}
	_happinessGauge += 20;
}

void Character::Sleep(int index)
{
	_activityGauge += 20;
	_foodGauge -= 30;
	_textType = index;

	if (_activityGauge > 100)
	{
		_activityGauge = 100;
	}
	else if (_foodGauge < 0)
	{
		_foodGauge = 0;
	}
	else
	{
		CustomConsole.GotoXY(_textX + 10, _textY - 7);
		_happinessGauge += 10;
	}
}

void Character::EnjoyPlay(int index)
{
	_activityGauge -= 20;
	_textType = index;

	if (_activityGauge < 0)
	{
		_activityGauge = 0;
	}
	else if (_foodGauge < 0)
	{
		_foodGauge = 0;
	}
	else
	{
		_happinessGauge += 10;
	}
}

void Character::LevelUp(int index)
{
	if (_happinessGauge >= 100)
	{
		_textType = index;
		_happinessGauge -= 100;
		_level++;
	}
}

void Character::Status()
{
	CustomConsole.ClearArea(2, 1, 10, 5);
	CustomConsole.GotoXY(1, 1); cout << "��������������������������������������������";
	CustomConsole.GotoXY(1, 2); cout << "��                    ��";
	CustomConsole.GotoXY(1, 3); cout << "��                    ��";
	CustomConsole.GotoXY(1, 4); cout << "��                    ��";
	CustomConsole.GotoXY(1, 5); cout << "��                    ��";
	CustomConsole.GotoXY(1, 6); cout << "��                    ��";
	CustomConsole.GotoXY(1, 7); cout << "��                    ��";
	CustomConsole.GotoXY(1, 8); cout << "��������������������������������������������";
	CustomConsole.GotoXY(3, 2); cout << "���� : " << _level + 1;
	CustomConsole.GotoXY(3, 4); cout << "�ູ�� : " << _happinessGauge;
	CustomConsole.GotoXY(3, 5); cout << "������ : " << _foodGauge;
	CustomConsole.GotoXY(3, 6); cout << "Ȱ���� : " << _activityGauge;
}

void Character::Release()
{
}