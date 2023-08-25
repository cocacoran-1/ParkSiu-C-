#include <iostream>
#include <time.h>
#include <Windows.h>
#include <conio.h> 
#define CARDSIZE 52
using namespace std;

int _betMoney = 100;

/*
	- 하이로우세븐
	- 카드 구조체를 만든다
	- 카드에 각각 숫자를 부여한다
	- 카드의 번호 별로 문양을 부여한다
	- 카드를 섞는다
	- 사용자 구조체를 만든다 (사용자 소지금, 배팅 여부)
	- 사용자가 배팅 할지 안할지 정한다
	- 사용자가 배팅을 하지 않으면 소지금은 그대로 유지
	- 사용자가 배팅을 하면 소지금에서 베팅 금액 만큼 차감
		>> 사용자가 하이 로우 세븐 중 하나를 선택한다
	- 컴퓨터도 배팅을 할지 안할지 정한다
	- 컴퓨터가 배팅을 하면 소지금에서 베팅 금액 만큼 차감
		>> 컴퓨터가 랜덤으로 하이 로우 세븐 중 하나를 선탣한다
	- 사용자와 컴퓨터의 결과를 확인하고 하이, 로우를 맞춘 경우 배팅 금액의 2배 세븐을 맞춘경우 7배
	- 틀린 경우 아무것도 얻지 않는다
	- 해당 게임을 카드 수 만큼 반복한다
	- 게임 중 베팅을 해야하는데 소지금이 0이면 파산 상대방이 승리
	- 동시에 파산 시 무승부
	- 카드 개수 만큼 게임을 진행하고 마지막 소지금을 비교해서 승패 정한다
*/
struct Unit
{
	int money;
	int choice;
	bool betOrNot;
	bool isPlayer;
	
	bool isBet()
	{
		
		if (isPlayer)
		{
			char select = '\0';
			cout << "베팅을 하시겠습니까? (Yes : Y , No : N)" << endl;
			cin >> select;
			if (select == 'Y' || select == 'y')
			{
				cout << "[베팅한다]" << endl;
				return true;
			}
			else if (select == 'N' || select == 'n')
			{
				cout << "[베팅 안한다]" << endl;
				return false;
			}
		}
		else
		{
			int random = rand() % 2;
			if (random == 0)
			{
				cout << "컴퓨터 : [베팅한다]" << endl;
				return true;
			}
			else if (random == 1)
			{
				cout << "컴퓨터 : [베팅 안한다]" << endl;
				return false;
			}
		}
	}
};

struct Card
{
	int card[CARDSIZE];

	void init()
	{
		// 카드에 숫자 부여
		for (int i = 0; i < CARDSIZE; i++)
		{
			card[i] = i;
		}
	}

	void printCard(int num)
	{
		switch (num / 13)
		{
		case 0:
			cout << "♥";
			break;
		case 1:
			cout << "♣";
			break;
		case 2:
			cout << "◆";
			break;
		case 3:
			cout << "♠";
			break;
		default:
			break;
		}
		switch (num % 13 + 1)
		{
		case 1:
			cout << "A";
			break;
		case 11:
			cout << "J";
			break;
		case 12:
			cout << "Q";
			break;
		case 13:
			cout << "K" << endl;
			break;
		default:
			cout << num % 13 + 1;
			break;
		}
	}
};

void Gotoxy(int x, int y)
{
	COORD pos = { x,y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

void SetCursor(bool isShow)
{
	CONSOLE_CURSOR_INFO cursorInfo;
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	if (isShow)
	{
		cursorInfo.bVisible = TRUE;
		cursorInfo.dwSize = 10;
	}
	else
	{
		cursorInfo.bVisible = FALSE;
		cursorInfo.dwSize = 10;
	}

	SetConsoleCursorInfo(hConsole, &cursorInfo);
}

void main()
{
	srand(time(NULL));
	Card card;
	Unit player = { 1000,0,false,true };
	Unit computer = { 1000,0,false,false };
}