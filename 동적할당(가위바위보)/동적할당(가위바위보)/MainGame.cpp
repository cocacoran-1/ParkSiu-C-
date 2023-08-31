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
	cout << "���� ���� �� �ϳ��� �����ϼ���(���� : 0, ���� : 1, �� : 2)" << endl;
	cin >> _choice;

	if (_choice == eRockScissorsPaper::ROCK)
	{
		cout << "�÷��̾� ���� : ����\t";
	}
	else if (_choice == eRockScissorsPaper::SCISSORS)
	{
		cout << "�÷��̾� ���� : ����\t";
	}
	else if (_choice == eRockScissorsPaper::PAPER)
	{
		cout << "�÷��̾� ���� : ��\t";
	}

	_randomChoice = rand() % 3;

	if (_randomChoice == eRockScissorsPaper::ROCK)
	{
		cout << "��ǻ�� ���� : ����";
	}
	else if (_randomChoice == eRockScissorsPaper::SCISSORS)
	{
		cout << "��ǻ�� ���� : ����";
	}
	else if (_randomChoice == eRockScissorsPaper::PAPER)
	{
		cout << "��ǻ�� ���� : ��";
	}

	cout << endl;
	if (_choice == _randomChoice)
	{
		cout << "���º�" << endl;
	}
	else if (_choice == eRockScissorsPaper::ROCK && _randomChoice == eRockScissorsPaper::SCISSORS)
	{
		cout << "�÷��̾� ��" << endl;
	}
	else if (_choice == eRockScissorsPaper::SCISSORS && _randomChoice == eRockScissorsPaper::PAPER)
	{
		cout << "�÷��̾� ��" << endl;
	}
	else if (_choice == eRockScissorsPaper::PAPER && _randomChoice == eRockScissorsPaper::ROCK)
	{
		cout << "�÷��̾� ��" << endl;
	}
	else
	{
		cout << "��ǻ�� ��" << endl;
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
