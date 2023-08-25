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


struct Card
{
	int card[CARDSIZE];
	int current;

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
	bool gameEnd()
	{
		if (current == 52)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
};
struct Unit
{
	Card card;
	int money;
	char choice;
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
				this->money -= _betMoney;
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
				this->money -= _betMoney;
				return true;
			}
			else if (random == 1)
			{
				cout << "��ǻ�� : [���� ���Ѵ�]" << endl;
				return false;
			}
		}
	}
	void selectHighLowSeven()
	{
		if (isBet())
		{
			if (isPlayer)
			{
				cout << "High or Low or Seven (High : H, Low : L, Seven : S)" << endl;
				cin >> choice;
				if (choice == 'h')
				{
					choice == 'H';
				}
				else if (choice == 'l')
				{
					choice == 'L';
				}
				else if (choice == 's')
				{
					choice == 'S';
				}
			}
			else
			{
				int random = rand() % 3;
				if (random == 0)
				{
					choice = 'H';
				}
				else if (random == 1)
				{
					choice = 'L';
				}
				else if (random == 2)
				{
					choice = 'S';
				}
			}
		}
	}
	void compare(int card)
	{
		if (isPlayer)
		{
			// High
			if (choice == 'H')
			{
				if (card > 7)
				{
					cout << "[�÷��̾� ����!!!]" << endl;
					money += 2 * _betMoney;
				}
				else
				{
					cout << "[�÷��̾� ����...]" << endl;
				}
			}
			// Low
			if (choice == 'L')
			{
				if (7 > card)
				{
					cout << "[�÷��̾� ����!!!]" << endl;
					money += 2 * _betMoney;
				}
				else
				{
					cout << "[�÷��̾� ����...]" << endl;
				}
			}
			// Seven
			if (choice == 'S')
			{
				if (card == 7)
				{
					cout << "[�÷��̾� ����!!!]" << endl;
					money += 2 * _betMoney;
				}
				else
				{
					cout << "[�÷��̾� ����...]" << endl;
				}
			}
		}
		else
		{
			// High
			if (choice == 'H')
			{
				if (card > 7)
				{
					cout << "[��ǻ�� ����!!!]" << endl;
					money += 2 * _betMoney;
				}
				else
				{
					cout << "[��ǻ�� ����...]" << endl;
				}
			}
			// Low
			if (choice == 'L')
			{
				if (7 > card)
				{
					cout << "[��ǻ�� ����!!!]" << endl;
					money += 2 * _betMoney;
				}
				else
				{
					cout << "[��ǻ�� ����...]" << endl;
				}
			}
			// Seven
			if (choice == 'S')
			{
				if (card == 7)
				{
					cout << "[��ǻ�� ����!!!]" << endl;
					money += 2 * _betMoney;
				}
				else
				{
					cout << "[��ǻ�� ����...]" << endl;
				}
			}
		}
		
	}
	void checkResult(bool isEnd)
	{
		isEnd = false;
		if (isPlayer)
		{
			if (money == 0)
			{
				cout << "[�Ļ��߽��ϴ�...]" << endl;
				cout << "[�÷��̾� �й�...]" << endl;
				isEnd = true;
			}
		}
		else
		{
			if (money == 0)
			{
				cout << "[��밡 �Ļ��߽��ϴ�!!!]" << endl;
				cout << "[�÷��̾� �¸�!!!]" << endl;
				isEnd = true;
			}
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
	bool isEnd = false;

	do
	{
		isEnd == card.gameEnd();
		// ��ǻ�� �÷��̾� ���ÿ��� ����
		player.isBet();
		computer.isBet();
		// ��ǻ�� �÷��̾� ���ý� ���̷ο켼�� ����
		player.selectHighLowSeven();
		computer.selectHighLowSeven();
		// ��ǻ�� �÷��̾� ���ð� ī�� ��
		player.compare(card.card[card.current]);
		computer.compare(card.card[card.current]);
		// �����ݿ� ���� ���г�Ÿ����
		player.checkResult(isEnd);
		computer.checkResult(isEnd);

	} while (!isEnd);

	if (player.money > computer.money)
	{
		cout << "�÷��̾� ������ : " << player.money << "\t��ǻ�� ������ :" << computer.money << endl;
		cout << "[��ǻ�� �й�!!!]" << endl;
		cout << "[�÷��̾� �¸�!!!]";
	}
	else if (computer.money > player.money)
	{
		cout << "�÷��̾� ������ : " << player.money << "\t��ǻ�� ������ :" << computer.money << endl;
		cout << "[��ǻ�� �¸�...]" << endl;
		cout << "[�÷��̾� �й�...]";
	}
	else
	{
		cout << "�÷��̾� ������ : " << player.money << "\t��ǻ�� ������ :" << computer.money << endl;
		cout << "[�� �� ��]";
	}
}