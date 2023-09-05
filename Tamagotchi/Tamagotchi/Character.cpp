#include "stdafx.h"
#include "Character.h"


void SetPixelColor(DWORD color)
{
	CustomConsole.SetBkColor(color);
	cout << "ㅤ";
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
	//캐릭터 애니메이션 코드
	_animationTime += deltaTime;
	if (300 < _animationTime)
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
			if (_foodGauge > 100)
			{
				cout << "더이상 먹고 싶지 않아...";
			}
			else
			{
				cout << "맛있는 음식~~~";
				HeartRender();
			}
			break;
		case 2:
			CustomConsole.ClearArea(_x + 28, _y + 1, _x + 60, _y + 1);
			CustomConsole.GotoXY(_x + 30, _y + 1);
			if (_activityGauge > 100)
			{
				cout << "아직 자고 싶지 않아...";
			}
			else if (_foodGauge < 0)
			{
				cout << "배고파...";
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
				cout << "피곤해...";
			}
			else if (_foodGauge < 0)
			{
				cout << "배고파...";
			}
			else
			{
				cout << "신나는 놀이 시간 ^ ㅡ ^";
				HeartRender();
			}
			break;
		case 4:
			CustomConsole.ClearArea(_x + 28, _y + 1, _x + 60, _y + 1);
			CustomConsole.GotoXY(_x + 30, _y + 1);
			cout << "레 벨 업!!";
			break;
		default:
			break;
		}
		// 이동 방향
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
				// 오른쪽 최대 이동범위
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
				// 왼쪽 최대 이동 범위
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
		// 오른쪽 이동
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
	CustomConsole.ClearArea(_shapeX + 30, _shapeY - 5, _shapeX + 54, _shapeY - 2);

	CustomConsole.GotoXY(_shapeX + 40, _shapeY - 5); SetPixelColor(RED);
	CustomConsole.GotoXY(_shapeX + 44, _shapeY - 5); SetPixelColor(RED);
	CustomConsole.GotoXY(_shapeX + 38, _shapeY - 4); SetPixelColor(RED);SetPixelColor(RED);SetPixelColor(RED);SetPixelColor(RED);SetPixelColor(RED);
	CustomConsole.GotoXY(_shapeX + 40, _shapeY - 3); SetPixelColor(RED);SetPixelColor(RED);SetPixelColor(RED);
	CustomConsole.GotoXY(_shapeX + 42, _shapeY - 2); SetPixelColor(RED);
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
	CustomConsole.ClearArea(0, 0, 15, 3);
	CustomConsole.SetCursor(tvision::CURSOR_OFF);
	CustomConsole.GotoXY(0, 0); cout << "┌────────────────────┐";
	CustomConsole.GotoXY(0, 1); cout << "│                    │";
	CustomConsole.GotoXY(0, 2); cout << "│                    │";
	CustomConsole.GotoXY(0, 3); cout << "│                    │";
	CustomConsole.GotoXY(0, 4); cout << "│                    │";
	CustomConsole.GotoXY(0, 5); cout << "│                    │";
	CustomConsole.GotoXY(0, 6); cout << "│                    │";
	CustomConsole.GotoXY(0, 7); cout << "└────────────────────┘";
	CustomConsole.GotoXY(2, 1); cout << "레벨 : " << _level + 1;
	CustomConsole.GotoXY(2, 3); cout << "행복도 : " << _happinessGauge;
	CustomConsole.GotoXY(2, 4); cout << "포만감 : " << _foodGauge;
	CustomConsole.GotoXY(2, 5); cout << "활동력 : " << _activityGauge;
}

void Character::Release()
{
}