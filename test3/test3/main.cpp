#include <iostream>
#include <time.h>
#include <Windows.h>
#include <conio.h> 
#define CARDSIZE 52
using namespace std;

int _betMoney = 100;

/*
	- ���̷ο켼��
	- ī�� ����ü�� �����
	- ī�忡 ���� ���ڸ� �ο��Ѵ�
	- ī���� ��ȣ ���� ������ �ο��Ѵ�
	- ī�带 ���´�
	- ����� ����ü�� ����� (����� ������, ���� ����)
	- ����ڰ� ���� ���� ������ ���Ѵ�
	- ����ڰ� ������ ���� ������ �������� �״�� ����
	- ����ڰ� ������ �ϸ� �����ݿ��� ���� �ݾ� ��ŭ ����
		>> ����ڰ� ���� �ο� ���� �� �ϳ��� �����Ѵ�
	- ��ǻ�͵� ������ ���� ������ ���Ѵ�
	- ��ǻ�Ͱ� ������ �ϸ� �����ݿ��� ���� �ݾ� ��ŭ ����
		>> ��ǻ�Ͱ� �������� ���� �ο� ���� �� �ϳ��� �����Ѵ�
	- ����ڿ� ��ǻ���� ����� Ȯ���ϰ� ����, �ο츦 ���� ��� ���� �ݾ��� 2�� ������ ������ 7��
	- Ʋ�� ��� �ƹ��͵� ���� �ʴ´�
	- �ش� ������ ī�� �� ��ŭ �ݺ��Ѵ�
	- ���� �� ������ �ؾ��ϴµ� �������� 0�̸� �Ļ� ������ �¸�
	- ���ÿ� �Ļ� �� ���º�
	- ī�� ���� ��ŭ ������ �����ϰ� ������ �������� ���ؼ� ���� ���Ѵ�
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
			cout << "������ �Ͻðڽ��ϱ�? (Yes : Y , No : N)" << endl;
			cin >> select;
			if (select == 'Y' || select == 'y')
			{
				cout << "[�����Ѵ�]" << endl;
				return true;
			}
			else if (select == 'N' || select == 'n')
			{
				cout << "[���� ���Ѵ�]" << endl;
				return false;
			}
		}
		else
		{
			int random = rand() % 2;
			if (random == 0)
			{
				cout << "��ǻ�� : [�����Ѵ�]" << endl;
				return true;
			}
			else if (random == 1)
			{
				cout << "��ǻ�� : [���� ���Ѵ�]" << endl;
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
		// ī�忡 ���� �ο�
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
			cout << "��";
			break;
		case 1:
			cout << "��";
			break;
		case 2:
			cout << "��";
			break;
		case 3:
			cout << "��";
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