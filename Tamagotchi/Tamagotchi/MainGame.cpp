#include "stdafx.h"
#include "MainGame.h"
#include "Character.h"

void MainGame::Init()
{
	CustomConsole.SetCursor(tvision::CURSOR_OFF);
	_boradX = 62;
	_boradY = 41;
	_textX = 110;
	_textY = 43;
	_currentSelect = 0;
	_isGameEnd = false;
	_character = new Character();
	_character->Init();

	_character->StayRender();
}

void MainGame::Update(int deltaTime)
{
	char input = '\0';
	SelectTextBoard(_currentSelect);
	CustomConsole.SetCursor(tvision::CURSOR_OFF);

	if (_kbhit())
	{
		input = _getch();
		if (input == 'w')
		{
			_currentSelect--;
			if (_currentSelect < 0)
			{
				_currentSelect = 0;
			}
		}
		else if (input == 's')
		{
			_currentSelect++;
			if (_currentSelect > 2)
			{
				_currentSelect = 2;
			}
		}
		else if (input == '\r')
		{
			switch (_currentSelect)
			{
			case 0:
				_character->EatFood();
				break;
			case 1:
				_character->Sleep();
				break;
			case 2:
				_character->EnjoyPlay();
				break;
			default:
				break;
			}
		}
		CleanBoard();
		SelectTextBoard(_currentSelect);
	}

	_character->Update(deltaTime, input);

}

void MainGame::SelectTextBoard(int _currentSelect)
{
	CustomConsole.GotoXY(_boradX, _boradY - 1);
	CustomConsole.SetTextColor(WHITE);
	cout << "������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������";
	CustomConsole.GotoXY(_boradX, _boradY);
	cout << "��                                                                                                                      ��";
	CustomConsole.GotoXY(_boradX, _boradY + 1);
	cout << "��                                                                                                                      ��";
	CustomConsole.GotoXY(_boradX, _boradY + 2);
	cout << "��                                                                                                                      ��";
	CustomConsole.GotoXY(_boradX, _boradY + 3);
	cout << "��                                                                                                                      ��";
	CustomConsole.GotoXY(_boradX, _boradY + 4);
	cout << "��                                                                                                                      ��";
	CustomConsole.GotoXY(_boradX, _boradY + 5);
	cout << "��                                                                                                                      ��";
	CustomConsole.GotoXY(_boradX, _boradY + 6);
	cout << "��                                                                                                                      ��";
	CustomConsole.GotoXY(_boradX, _boradY + 7);
	cout << "��                                                                                                                      ��";
	CustomConsole.GotoXY(_boradX, _boradY + 8);
	cout << "������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������";

	if (_currentSelect == 0)
	{
		CustomConsole.GotoXY(_textX, _textY);
		cout << "����	�� �� �� ��";
		CustomConsole.GotoXY(_textX, _textY + 2);
		cout << "	�� �� �� ��";
		CustomConsole.GotoXY(_textX, _textY + 4);
		cout << "	�� �� �� ��";
	}
	else if (_currentSelect == 1)
	{
		CustomConsole.GotoXY(_textX, _textY);
		cout << "	�� �� �� ��";
		CustomConsole.GotoXY(_textX, _textY + 2);
		cout << "����	�� �� �� ��";
		CustomConsole.GotoXY(_textX, _textY + 4);
		cout << "	�� �� �� ��";
	}
	else if (_currentSelect == 2)
	{
		CustomConsole.GotoXY(_textX, _textY);
		cout << "	�� �� �� ��";
		CustomConsole.GotoXY(_textX, _textY + 2);
		cout << "	�� �� �� ��";
		CustomConsole.GotoXY(_textX, _textY + 4);
		cout << "����	�� �� �� ��";
	}
}

void MainGame::Release()
{
	_character->Release();
	delete _character;
	_character = nullptr;
}

void MainGame::CleanBoard()
{
	CustomConsole.ClearArea(_boradX, _boradY-1, _boradX + 170, _boradX + 8);
}

bool MainGame::IsGameEnd()
{
	return _isGameEnd;
}

