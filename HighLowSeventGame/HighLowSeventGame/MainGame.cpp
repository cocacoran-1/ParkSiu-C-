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

	cout << "이전 카드 : ";
	for (int i = 4; i > 0; i--)
	{
		PrintCard(_card[_currentIndex - i]);
		cout << "\t";
	}
	cout << "플레이어 소지금 : " << _playerMoney << endl;
	cout << endl << "베팅하시겠습니가? (한다 : 0, 안한다 : 1)" << endl;
	int input = 0;
	cin >> input;
	if (input == 0)
	{
		cout << "High or Low or Seven (High : 0, Low : 1, Seven : 2)" << endl;
		cin >> _choice;

		cout << "베팅 금액을 설정해주세요 : " << endl;
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

	cout << "현재 카드 : ";
	PrintCard(_card[_currentIndex]);
	cout << endl;
	int cardNum = _card[_currentIndex] % 13 + 1;
	if (cardNum == 7 && _choice == eBetType::SEVEN)
	{
		cout << "축하합니다 SEVEN을 맞췄습니다" << endl;
		_playerMoney += _playerBet * 10;
	}
	else if(cardNum > 7 && _choice == eBetType::HIGH)
	{
		cout << "축하합니다 HIGH를 맞췄습니다" << endl;
		_playerMoney += _playerBet * 2;
	}
	else if (cardNum < 7 && _choice == eBetType::LOW)
	{
		cout << "축하합니다 LOW를 맞췄습니다" << endl;
		_playerMoney += _playerBet * 2;
	}
	else
	{
		cout << "실패......" << endl;
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
