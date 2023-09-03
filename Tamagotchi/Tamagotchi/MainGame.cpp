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
			SelectTextBoard(_currentSelect);
		}
		else if (input == 's')
		{
			_currentSelect++;
			if (_currentSelect > 2)
			{
				_currentSelect = 2;
			}
			SelectTextBoard(_currentSelect);
		}
		else if (input == '\r')
		{
			if (_currentSelect == 0)
			{
				_character->EatFood();

			}
			else if (_currentSelect == 1)
			{
				_character->Sleep();
			}
			else if (_currentSelect == 2)
			{
				_character->EnjoyPlay();
			}
		}

	}

	_character->Update(deltaTime, input);

}

void MainGame::SelectTextBoard(int _currentSelect)
{
	CustomConsole.ClearArea(_textX, _textY, _textX + 10, _textY + 4);
	CustomConsole.SetCursor(tvision::CURSOR_OFF);
	CustomConsole.GotoXY(_boradX, _boradY - 1);
	CustomConsole.SetBkColor(GRAY);
	CustomConsole.SetTextColor(BLACK);
	cout << "忙式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式忖";
	CustomConsole.GotoXY(_boradX, _boradY);
	cout << "弛                                                                                                                      弛";
	CustomConsole.GotoXY(_boradX, _boradY + 1);
	cout << "弛                                                                                                                      弛";
	CustomConsole.GotoXY(_boradX, _boradY + 2);
	cout << "弛                                                                                                                      弛";
	CustomConsole.GotoXY(_boradX, _boradY + 3);
	cout << "弛                                                                                                                      弛";
	CustomConsole.GotoXY(_boradX, _boradY + 4);
	cout << "弛                                                                                                                      弛";
	CustomConsole.GotoXY(_boradX, _boradY + 5);
	cout << "弛                                                                                                                      弛";
	CustomConsole.GotoXY(_boradX, _boradY + 6);
	cout << "弛                                                                                                                      弛";
	CustomConsole.GotoXY(_boradX, _boradY + 7);
	cout << "弛                                                                                                                      弛";
	CustomConsole.GotoXY(_boradX, _boradY + 8);
	cout << "戌式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式戎";

	if (_currentSelect == 0)
	{
		CustomConsole.GotoXY(_textX, _textY);
		cout << "ⅠⅡ	嫣 詳 朝 棻";
		CustomConsole.GotoXY(_textX, _textY + 2);
		cout << "	濠 楝 除 棻";
		CustomConsole.GotoXY(_textX, _textY + 4);
		cout << "	啾 楝 除 棻";
	}
	else if (_currentSelect == 1)
	{
		CustomConsole.GotoXY(_textX, _textY);
		cout << "	嫣 詳 朝 棻";
		CustomConsole.GotoXY(_textX, _textY + 2);
		cout << "ⅠⅡ	濠 楝 除 棻";
		CustomConsole.GotoXY(_textX, _textY + 4);
		cout << "	啾 楝 除 棻";
	}
	else if (_currentSelect == 2)
	{
		CustomConsole.GotoXY(_textX, _textY);
		cout << "	嫣 詳 朝 棻";
		CustomConsole.GotoXY(_textX, _textY + 2);
		cout << "	濠 楝 除 棻";
		CustomConsole.GotoXY(_textX, _textY + 4);
		cout << "ⅠⅡ	啾 楝 除 棻";
	}
}

void MainGame::Release()
{
	_character->Release();
	delete _character;
	_character = nullptr;
}

bool MainGame::IsGameEnd()
{
	return _isGameEnd;
}

