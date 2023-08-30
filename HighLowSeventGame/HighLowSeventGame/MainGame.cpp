#include "Main.h"
#include "Card.h"
#include "MainGame.h"

void MainGame::Init()
{
	srand(time(NULL));
	for (int i = 0; i < 52; i++)
	{
		_card[i] = i;
	}
	_playerMoney = 1000;
	_playerBet = 0;
	_choice = eBetChoice::END;
	_currentIndex = 4;

	for (int i = 0; i < 10000; i++)
	{
		int num1 = rand() % 52;
		int num2 = rand() % 52;
		int temp = _card[num1];
		_card[num1] = _card[num2];
		_card[num2] = temp;
	}
}

void MainGame::Update()
{
	system("cls");
	for (int i = 4; i > 0; i--)
	{
		PrintCard(_card[_currentIndex - i]);
		cout << "\t";
	}

	system("pause");
}

void MainGame::Release()
{
}

bool MainGame::IsEnd()
{
	return false;
}
