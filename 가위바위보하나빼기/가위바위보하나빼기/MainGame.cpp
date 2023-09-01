#include "stdafx.h"
#include "MainGame.h"
#include "User.h"

void MainGame::Init()
{
	_playerShapeX = 0;
	_playerShapeY = 8;
	_computerShapeX = 100;
	_computerShapeY = 8;
	CustomConsole.SetCursor(tvision::CURSOR_OFF);
	_player = new User();
	_player->Init();

	_computer = new User();
	_computer->Init();
	_computer->_x = 87;


	_menuX = 25;
	_menuY = 20;

	

}

void MainGame::Update()
{
	int isSelect = 0;
	int current = 0;
	system("cls");
	CustomConsole.GotoXY(_player->_x, _player->_y);	cout << "┌──────────────────────────────┐";
	CustomConsole.GotoXY(_player->_x, _player->_y + 1);	cout << "│                              │";
	CustomConsole.GotoXY(_player->_x, _player->_y + 2);	cout << "│                              │";
	CustomConsole.GotoXY(_player->_x, _player->_y + 3);	cout << "└──────────────────────────────┘";

	CustomConsole.GotoXY(_computer->_x, _computer->_y); cout << "┌──────────────────────────────┐";
	CustomConsole.GotoXY(_computer->_x, _computer->_y + 1); cout << "│                              │";
	CustomConsole.GotoXY(_computer->_x, _computer->_y + 2); cout << "│                              │";
	CustomConsole.GotoXY(_computer->_x, _computer->_y + 3); cout << "└──────────────────────────────┘";
	CustomConsole.GotoXY(_menuX, _menuY); cout << "┌────────────────────────────────────────────────────────────────────┐";
	CustomConsole.GotoXY(_menuX, _menuY + 1); cout << "│                                                                    │";
	CustomConsole.GotoXY(_menuX, _menuY + 2); cout << "│                                                                    │";
	CustomConsole.GotoXY(_menuX, _menuY + 3); cout << "│                                                                    │";
	CustomConsole.GotoXY(_menuX, _menuY + 4); cout << "│                                                                    │";
	CustomConsole.GotoXY(_menuX, _menuY + 5); cout << "│                                                                    │";
	CustomConsole.GotoXY(_menuX, _menuY + 6); cout << "│                                                                    │";
	CustomConsole.GotoXY(_menuX, _menuY + 7); cout << "│                                                                    │";
	CustomConsole.GotoXY(_menuX, _menuY + 8); cout << "└────────────────────────────────────────────────────────────────────┘";
	CustomConsole.GotoXY(_player->_x + 2, _player->_y + 1); cout << "플레이어";
	CustomConsole.GotoXY(_player->_x + 2, _player->_y + 2); cout << "소지금 : " << _player->_money;
	CustomConsole.GotoXY(_computer->_x + 2, _computer->_y + 1); cout << "컴퓨터";
	CustomConsole.GotoXY(_computer->_x + 2, _computer->_y + 2);cout << "소지금 : " << _computer->_money;

	CustomConsole.ClearArea(_menuX + 2, _menuY + 1, _menuX + 68, _menuY + 6);
	CustomConsole.ClearArea(_playerShapeX, _playerShapeY, _playerShapeX+20, _playerShapeY+7);
	CustomConsole.ClearArea(_computerShapeX, _computerShapeY, _computerShapeX + 20, _computerShapeY + 7);

	while (isSelect <2)
	{

		if (_kbhit())
		{
			char ch = _getch();
			if (ch == 'w')
			{
				current--;
				if (current <= 0)
				{
					current = 0;
				}
			}
			else if (ch == 's')
			{
				current++;
				if (current >= 2)
				{
					current = 2;
				}
			}
			else if (ch == '\r')
			{
				if (current == eRockScissorsPaper::ROCK)
				{
					_player->_choice[isSelect] = 0;
				}
				else if (current == eRockScissorsPaper::SCISSORS)
				{
					_player->_choice[isSelect] = 1;
				}
				else if (current == eRockScissorsPaper::PAPER)
				{
					_player->_choice[isSelect] = 2;
				}
				isSelect++;
			}
			
			switch (current)
			{
			case 0:
				CustomConsole.ClearArea(_menuX + 30, _menuY + 4, _menuX + 50, _menuY + 6);
				CustomConsole.GotoXY(_menuX + 22, _menuY + 2); cout << "Rock or Scissors or Paper";
				CustomConsole.GotoXY(_menuX + 30, _menuY + 4); cout << "▷▶	Rock";
				CustomConsole.GotoXY(_menuX + 30, _menuY + 5); cout << "	Scissors";
				CustomConsole.GotoXY(_menuX + 30, _menuY + 6); cout << "	Paper";
				break;
			case 1:
				CustomConsole.ClearArea(_menuX + 30, _menuY + 4, _menuX + 50, _menuY + 6);
				CustomConsole.GotoXY(_menuX + 22, _menuY + 2); cout << "Rock or Scissors or Paper";
				CustomConsole.GotoXY(_menuX + 30, _menuY + 4); cout << "	Rock";
				CustomConsole.GotoXY(_menuX + 30, _menuY + 5); cout << "▷▶	Scissors";
				CustomConsole.GotoXY(_menuX + 30, _menuY + 6); cout << "	Paper";
				break;
			case 2:
				CustomConsole.ClearArea(_menuX + 30, _menuY + 4, _menuX + 50, _menuY + 6);
				CustomConsole.GotoXY(_menuX + 22, _menuY + 2); cout << "Rock or Scissors or Paper";
				CustomConsole.GotoXY(_menuX + 30, _menuY + 4); cout << "	Rock";
				CustomConsole.GotoXY(_menuX + 30, _menuY + 5); cout << "	Scissors";
				CustomConsole.GotoXY(_menuX + 30, _menuY + 6); cout << "▷▶	Paper";
				break;
			default:
				break;
			}
		}
	}

	CustomConsole.ClearArea(_menuX+2, _menuY + 2, _menuX + 50, _menuY + 6);
	string name[2] = { "0", };
	for (int i = 0; i < 2; i++)
	{
		int random = rand() % 3;
		_computer->_choice[i] = random;
	}
	for (int i = 0; i < 2; i++)
	{
		if (_computer->_choice[i] == eRockScissorsPaper::ROCK)
		{
			name[i] = "Rock";
		}
		else if (_computer->_choice[i] == eRockScissorsPaper::SCISSORS)
		{
			name[i] = "Scissors";
		}
		else if (_computer->_choice[i] == eRockScissorsPaper::PAPER)
		{
			name[i] = "Paper";
		}
	}
	CustomConsole.GotoXY(_menuX + 61, _menuY + 1); cout << "컴퓨터";
	CustomConsole.GotoXY(_menuX + 61, _menuY + 3); cout << name[0];
	CustomConsole.GotoXY(_menuX + 61, _menuY + 4); cout << name[1];

	for (int i = 0; i < 2; i++)
	{
		if (_player->_choice[i] == eRockScissorsPaper::ROCK)
		{
			name[i] = "Rock";
		}
		else if (_player->_choice[i] == eRockScissorsPaper::SCISSORS)
		{
			name[i] = "Scissors";
		}
		else if (_player->_choice[i] == eRockScissorsPaper::PAPER)
		{
			name[i] = "Paper";
		}
	}
	CustomConsole.GotoXY(_menuX + 3, _menuY + 1); cout << "플레이어";
	CustomConsole.GotoXY(_menuX + 3, _menuY + 3); cout << name[0];
	CustomConsole.GotoXY(_menuX + 3, _menuY + 4); cout << name[1];

	CustomConsole.GotoXY(_menuX + 30, _menuY + 1); cout << "Choose One";
	CustomConsole.GotoXY(_menuX + 30, _menuY + 3); cout << name[0];
	CustomConsole.GotoXY(_menuX + 30, _menuY + 4); cout << name[1];

	current = 0;
	while (true)
	{
		if (_kbhit())
		{
			char ch = _getch();
			if (ch == 'w')
			{
				current--;
				if (current <= 0)
				{
					current = 0;
				}
			}
			else if (ch == 's')
			{
				current++;
				if (current >= 1)
				{
					current = 1;
				}
			}
			else if (ch == '\r')
			{
				if (current == 0)
				{
					_player->_finalChoice = _player->_choice[0];
				}
				else if (current == 1)
				{
					_player->_finalChoice = _player->_choice[1];
				}
				break;
			}
			switch (current)
			{
			case 0:
				CustomConsole.ClearArea(_menuX + 30, _menuY + 3, _menuX + 47, _menuY + 4);
				CustomConsole.GotoXY(_menuX + 30, _menuY + 1); cout << "Choose One";
				CustomConsole.GotoXY(_menuX + 30, _menuY + 3); cout << "▷▶\t" <<name[0];
				CustomConsole.GotoXY(_menuX + 30, _menuY + 4); cout << "\t" << name[1];
				break;
			case 1:
				CustomConsole.ClearArea(_menuX + 30, _menuY + 3, _menuX + 47, _menuY + 4);
				CustomConsole.GotoXY(_menuX + 30, _menuY + 1); cout << "Choose One";
				CustomConsole.GotoXY(_menuX + 30, _menuY + 3); cout << "\t" << name[0];
				CustomConsole.GotoXY(_menuX + 30, _menuY + 4); cout << "▷▶\t" << name[1];
				break;
			default:
				break;
			}
		}
	}
	CustomConsole.ClearArea(_menuX + 2, _menuY + 1, _menuX + 68, _menuY + 6);
	
	int random = rand() % 2;
	_computer->_finalChoice = _computer->_choice[random];

	CustomConsole.GotoXY(_menuX + 3, _menuY + 1); cout << "플레이어";
	CustomConsole.GotoXY(_menuX + 3, _menuY + 3); 

	if (_player->_finalChoice == eRockScissorsPaper::ROCK)
	{
		cout << "Rock";
		CustomConsole.GotoXY(_playerShapeX, _playerShapeY);
		cout << "    _______" ;
		CustomConsole.GotoXY(_playerShapeX, _playerShapeY+1);
		cout << "---'   ____)";
		CustomConsole.GotoXY(_playerShapeX, _playerShapeY + 2);
		cout << "      (_____)";
		CustomConsole.GotoXY(_playerShapeX, _playerShapeY + 3);
		cout << "      (_____)";
		CustomConsole.GotoXY(_playerShapeX, _playerShapeY + 4);
		cout << "      (____)";
		CustomConsole.GotoXY(_playerShapeX, _playerShapeY + 5);
		cout << "---.__(___)";
	}
	else if (_player->_finalChoice == eRockScissorsPaper::SCISSORS)
	{
		cout << "Scissors";
		CustomConsole.GotoXY(_playerShapeX, _playerShapeY);
		cout << "_______";
		CustomConsole.GotoXY(_playerShapeX, _playerShapeY + 1);
		cout << "---'  ____)____" ;
		CustomConsole.GotoXY(_playerShapeX, _playerShapeY + 2);
		cout << "	______)";
		CustomConsole.GotoXY(_playerShapeX, _playerShapeY + 3);
		cout << "	   __________)";
		CustomConsole.GotoXY(_playerShapeX, _playerShapeY + 4);
		cout << "	  (____)";
		CustomConsole.GotoXY(_playerShapeX, _playerShapeY + 5);
		cout << "---.__(___)" ;
	}
	else if (_player->_finalChoice == eRockScissorsPaper::PAPER)
	{
		cout << "Paper";
		CustomConsole.GotoXY(_playerShapeX, _playerShapeY);
		cout << "	_______";
		CustomConsole.GotoXY(_playerShapeX, _playerShapeY + 1);
		cout << "---'   ____)____";
		CustomConsole.GotoXY(_playerShapeX, _playerShapeY + 2);
		cout << "		  ______)";
		CustomConsole.GotoXY(_playerShapeX, _playerShapeY + 3);
		cout << "		  _______)";
		CustomConsole.GotoXY(_playerShapeX, _playerShapeY + 4);
		cout << "		 _______)";
		CustomConsole.GotoXY(_playerShapeX, _playerShapeY + 5);
		cout << "---.__________)";
		
	}
	

	CustomConsole.GotoXY(_menuX + 61, _menuY + 1); cout << "컴퓨터";
	CustomConsole.GotoXY(_menuX + 61, _menuY + 3); 
	if (_computer->_finalChoice == eRockScissorsPaper::ROCK)
	{
		cout << "Rock";
		CustomConsole.GotoXY(_computerShapeX, _computerShapeY);
		cout << "	  _______ ";
		CustomConsole.GotoXY(_computerShapeX, _computerShapeY+1);
		cout << "	 (____ '---";
		CustomConsole.GotoXY(_computerShapeX, _computerShapeY+2);
		cout << "	(______)";
		CustomConsole.GotoXY(_computerShapeX, _computerShapeY+3);
		cout << "	(______)";
		CustomConsole.GotoXY(_computerShapeX, _computerShapeY+4);
		cout << "	 (____)";
		CustomConsole.GotoXY(_computerShapeX, _computerShapeY+5);
		cout << "		(___)__.---";
	}
	else if (_computer->_finalChoice == eRockScissorsPaper::SCISSORS)
	{
		cout << "Scissors";
		CustomConsole.GotoXY(_computerShapeX, _computerShapeY);
		cout << "	   _______ ";
		CustomConsole.GotoXY(_computerShapeX, _computerShapeY+1);
		cout << " ____(____ '---";
		CustomConsole.GotoXY(_computerShapeX, _computerShapeY+2);
		cout << "(______";
		CustomConsole.GotoXY(_computerShapeX, _computerShapeY+3);
		cout << "(__________";
		CustomConsole.GotoXY(_computerShapeX, _computerShapeY+4);
		cout << "	(____)";
		CustomConsole.GotoXY(_computerShapeX, _computerShapeY+4);
		cout << "	 (___)__.---";
	}
	else if (_computer->_finalChoice == eRockScissorsPaper::PAPER)
	{
		cout << "Paper";
		CustomConsole.GotoXY(_computerShapeX, _computerShapeY);
		cout << "		 _______ ";
		CustomConsole.GotoXY(_computerShapeX, _computerShapeY+1);
		cout << "	____(____ '---";
		CustomConsole.GotoXY(_computerShapeX, _computerShapeY+2);
		cout << "  (_______";
		CustomConsole.GotoXY(_computerShapeX, _computerShapeY+3);
		cout << " (_______";
		CustomConsole.GotoXY(_computerShapeX, _computerShapeY+4);
		cout << "  (_______";
		CustomConsole.GotoXY(_computerShapeX, _computerShapeY+5);
		cout << "   (__________.---";
	}

	if (_player->_finalChoice == _computer->_finalChoice)
	{
		CustomConsole.GotoXY(_menuX + 30, _menuY + 2); cout << "D R A W";
	}
	else if (_player->_finalChoice == eRockScissorsPaper::ROCK && _computer->_finalChoice == eRockScissorsPaper::SCISSORS)
	{
		CustomConsole.GotoXY(_menuX + 24, _menuY + 2); cout << "P L A Y E R	W I N";
		_player->_money += 100;
		_computer->_money -= 100;
 	}
	else if (_player->_finalChoice == eRockScissorsPaper::SCISSORS && _computer->_finalChoice == eRockScissorsPaper::PAPER)
	{
		CustomConsole.GotoXY(_menuX + 24, _menuY + 2); cout << "P L A Y E R	W I N";
		_player->_money += 100;
		_computer->_money -= 100;
	}
	else if (_player->_finalChoice == eRockScissorsPaper::PAPER && _computer->_finalChoice == eRockScissorsPaper::ROCK)
	{
		CustomConsole.GotoXY(_menuX + 24, _menuY + 2); cout << "P L A Y E R	W I N";
		_player->_money += 100;
		_computer->_money -= 100;
	}
	else
	{
		CustomConsole.GotoXY(_menuX + 24, _menuY + 2); cout << "C O M P U T E R	W I N";
		_player->_money -= 100;
		_computer->_money += 100;
	}
	CustomConsole.ClearArea(_player->_x + 2, _player->_y + 2, _player->_x + 20, _player->_y + 2);
	CustomConsole.ClearArea(_computer->_x + 2, _computer->_y + 2, _computer->_x + 20, _computer->_y + 2);
	CustomConsole.GotoXY(_player->_x+2, _player->_y + 1); cout << "플레이어";
	CustomConsole.GotoXY(_player->_x + 2, _player->_y + 2); cout << "소지금 : " << _player->_money;
	CustomConsole.GotoXY(_computer->_x+2, _computer->_y + 1); cout << "컴퓨터";
	CustomConsole.GotoXY(_computer->_x + 2, _computer->_y + 2); cout << "소지금 : " << _computer->_money;

	CustomConsole.GotoXY(0, 29);
	system("pause");
}

void MainGame::Release()
{
}

bool MainGame::IsEnd()
{
	if (_player->_money == 0 || _computer->_money == 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}
