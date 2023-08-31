#include "Main.h"
#include "MainGame.h"

void MainGame::Init()
{
	srand(time(NULL));
	_choice = 0;
	_round = 0;
	_isEnd = false;
}

void MainGame::Update()
{
	cout << "가위 바위 보 하나를 선택하세요(바위 : 0, 가위 : 1, 보 : 2)" << endl;
	cin >> _choice;

	if (_choice == eRockScissorsPaper::ROCK)
	{
		cout << "플레이어 선택 : 바위\t";
	}
	else if (_choice == eRockScissorsPaper::SCISSORS)
	{
		cout << "플레이어 선택 : 가위\t";
	}
	else if (_choice == eRockScissorsPaper::PAPER)
	{
		cout << "플레이어 선택 : 보\t";
	}

	_randomChoice = rand() % 3;

	if (_randomChoice == eRockScissorsPaper::ROCK)
	{
		cout << "컴퓨터 선택 : 바위";
	}
	else if (_randomChoice == eRockScissorsPaper::SCISSORS)
	{
		cout << "컴퓨터 선택 : 가위";
	}
	else if (_randomChoice == eRockScissorsPaper::PAPER)
	{
		cout << "컴퓨터 선택 : 보";
	}

	cout << endl;
	if (_choice == _randomChoice)
	{
		cout << "무승부" << endl;
	}
	else if (_choice == eRockScissorsPaper::ROCK && _randomChoice == eRockScissorsPaper::SCISSORS)
	{
		cout << "플레이어 승" << endl;
	}
	else if (_choice == eRockScissorsPaper::SCISSORS && _randomChoice == eRockScissorsPaper::PAPER)
	{
		cout << "플레이어 승" << endl;
	}
	else if (_choice == eRockScissorsPaper::PAPER && _randomChoice == eRockScissorsPaper::ROCK)
	{
		cout << "플레이어 승" << endl;
	}
	else
	{
		cout << "컴퓨터 승" << endl;
	}

	if (_round == 4)
	{
		_isEnd = true;
	}
	else
	{
		_isEnd = false;
	}
	_round++;
}

bool MainGame::IsEnd()
{
	return _isEnd;
}

void MainGame::Release()
{
}
