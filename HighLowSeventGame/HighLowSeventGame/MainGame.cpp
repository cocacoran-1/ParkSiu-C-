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
	_choice = eBetType::END;
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

	cout << "���� ī�� : ";
	for (int i = 4; i > 0; i--)
	{
		PrintCard(_card[_currentIndex - i]);
		cout << "\t";
	}
	cout << "�÷��̾� ������ : " << _playerMoney << endl;
	cout << endl << "�����Ͻðڽ��ϰ�? (�Ѵ� : 0, ���Ѵ� : 1)" << endl;
	int input = 0;
	cin >> input;
	if (input == 0)
	{
		cout << "High or Low or Seven (High : 0, Low : 1, Seven : 2)" << endl;
		cin >> _choice;

		cout << "���� �ݾ��� �������ּ��� : " << endl;
		cin >> _playerBet;

		if (_playerBet > _playerMoney)
		{
			cout << "ALL - IN" << endl;
			_playerBet = _playerMoney;
		}
		_playerMoney -= _playerBet;
	}
	else
	{
		_choice = eBetType::NOBET;
	}

	cout << "���� ī�� : ";
	PrintCard(_card[_currentIndex]);
	cout << endl;
	int cardNum = _card[_currentIndex] % 13 + 1;
	if (cardNum == 7 && _choice == eBetType::SEVEN)
	{
		cout << "�����մϴ� SEVEN�� ������ϴ�" << endl;
		_playerMoney += _playerBet * 10;
	}
	else if(cardNum > 7 && _choice == eBetType::HIGH)
	{
		cout << "�����մϴ� HIGH�� ������ϴ�" << endl;
		_playerMoney += _playerBet * 2;
	}
	else if (cardNum < 7 && _choice == eBetType::LOW)
	{
		cout << "�����մϴ� LOW�� ������ϴ�" << endl;
		_playerMoney += _playerBet * 2;
	}
	else
	{
		cout << "����......" << endl;
	}
	_currentIndex++;

	system("pause");
}

void MainGame::Release()
{
}

bool MainGame::IsEnd()
{
	return _currentIndex == 52 || _playerMoney<= 0;
}
