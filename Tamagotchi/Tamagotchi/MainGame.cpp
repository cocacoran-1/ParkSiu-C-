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
	CustomConsole.SetCursor(tvision::CURSOR_OFF);

	if (_kbhit())
	{
		input = _getch();
		
		if (input == 'w' || input == 'W')
		{
			_currentSelect--;
			if (_currentSelect < 0)
			{
				_currentSelect = 0;
			}
			CleanBoard();
			SelectTextBoard(_currentSelect);
		}
		else if (input == 's' || input == 'S')
		{
			_currentSelect++;
			if (_currentSelect > 2)
			{
				_currentSelect = 2;
			}
			CleanBoard();
			SelectTextBoard(_currentSelect);
		}
		else if (input == '\r')
		{
			switch (_currentSelect)
			{
			case 0:
				_character->EatFood(1);
				break;
			case 1:
				_character->Sleep(2);
				break;
			case 2:
				_character->EnjoyPlay(3);
				break;
			default:
				break;
			}
			_character->LevelUp(4);
			CleanBoard();
			SelectTextBoard(_currentSelect);
		}
	}

	_character->Update(deltaTime, input);
}

void MainGame::SelectTextBoard(int _currentSelect)
{
	CustomConsole.GotoXY(_boradX, _boradY - 1);
	CustomConsole.SetTextColor(WHITE);
	cout << "������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������ ";
	CustomConsole.GotoXY(_boradX, _boradY);
	cout << "��                                                                                                                      �� ";
	CustomConsole.GotoXY(_boradX, _boradY + 1);
	cout << "��                                                                                                                      �� ";
	CustomConsole.GotoXY(_boradX, _boradY + 2);
	cout << "��                                                                                                                      �� ";
	CustomConsole.GotoXY(_boradX, _boradY + 3);
	cout << "��                                                                                                                      �� ";
	CustomConsole.GotoXY(_boradX, _boradY + 4);
	cout << "��                                                                                                                      �� ";
	CustomConsole.GotoXY(_boradX, _boradY + 5);
	cout << "��                                                                                                                      �� ";
	CustomConsole.GotoXY(_boradX, _boradY + 6);
	cout << "��                                                                                                                      �� ";
	CustomConsole.GotoXY(_boradX, _boradY + 7);
	cout << "��                                                                                                                      �� ";
	CustomConsole.GotoXY(_boradX, _boradY + 8);
	cout << "������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������ ";

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
	CustomConsole.ClearArea(_textX, _textY, _textX+20, _textY + 4);
}

bool MainGame::IsGameEnd()
{
	return _isGameEnd;
}

