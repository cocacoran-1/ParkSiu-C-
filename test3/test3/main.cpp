#include <iostream>
#include <time.h>
#include <Windows.h>
#include <conio.h> 
#define CARDSIZE 52
#define GAMECOUNTX 30
#define GAMECOUNTY 1
#define TEXTLINEX 5
#define TEXTLINEY 20
#define COMPUTERTEXTX 70
#define COMPUTERTEXTY 21
using namespace std;

int _betMoney = 100;
int _currentArrow = 0;

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
struct Card
{
	int card[CARDSIZE];
	int current;

	void init()
	{
		current = 0;
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
		if (current == 51)
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
	int money;
	bool isPlayer;
	char choice;
	Card card;
	bool isBet;

	void printInfom()
	{
		if (isPlayer)
		{
			int x = TEXTLINEX;
			int y = TEXTLINEY + 1;

			Gotoxy(x + 2, y - 1);
			cout << "�÷��̾�";
			Gotoxy(x, y++);
			cout << "��������������������������������������������������������������������������������";

			Gotoxy(x, y);
			cout << "��";
			Gotoxy(x + 2, y);
			cout << "������: " << money;
			Gotoxy(x + 39, y++);
			cout << "��";

			Gotoxy(x, y);
			cout << "��";
			Gotoxy(x + 39, y++);
			cout << "��";

			Gotoxy(x, y);
			cout << "��";
			Gotoxy(x + 39, y++);
			cout << "��";

			Gotoxy(x, y);
			cout << "��";
			Gotoxy(x + 39, y++);
			cout << "��";

			Gotoxy(x, y);
			cout << "��";
			Gotoxy(x + 39, y++);
			cout << "��";

			Gotoxy(x, y++);
			cout << "��������������������������������������������������������������������������������";
		}
		else
		{
			int x = COMPUTERTEXTX;
			int y = COMPUTERTEXTY;

			Gotoxy(x + 2, y - 1);
			cout << "��ǻ��";
			Gotoxy(x, y++);
			cout << "��������������������������������������������������������������������������������";
			Gotoxy(x, y);
			cout << "��";
			Gotoxy(x + 2, y);
			cout << "������: " << money;
			Gotoxy(x + 39, y++);
			cout << "��";

			Gotoxy(x, y);
			cout << "��";
			Gotoxy(x + 39, y++);
			cout << "��";

			Gotoxy(x, y);
			cout << "��";
			Gotoxy(x + 39, y++);
			cout << "��";

			Gotoxy(x, y);
			cout << "��";
			Gotoxy(x + 39, y++);
			cout << "��";

			Gotoxy(x, y);
			cout << "��";
			Gotoxy(x + 39, y++);
			cout << "��";

			Gotoxy(x, y++);
			cout << "��������������������������������������������������������������������������������";
		}
	}
	void BetOrNot()
	{
		bool isNext = false;
		int x = 0;
		int y = 0;
		_currentArrow = 0;
		if (isPlayer)
		{
			
			while (!isNext)
			{
				Gotoxy(0, 0);
				cout << "������: " << money;
				x = TEXTLINEX*2;
				y = TEXTLINEY + 1;
				Gotoxy(x, y++);
				cout << "��������������������������������������������������������������������������������������������������������������������������������������������������������������������������";
				Gotoxy(x, y);
				cout << "��";
				Gotoxy(x + 30, y);
				cout << "������ �Ͻðڽ��ϱ�?" << endl;
				Gotoxy(x + 84, y++);
				cout << "��";
				Gotoxy(x, y);
				cout << "��";
				Gotoxy(x + 84, y++);
				cout << "��";

				Gotoxy(x, y);
				cout << "��";
				Gotoxy(x + 33, y);
				if (_currentArrow == 0)
				{
					cout << "���� YES";
				}
				else
				{
					cout << "	YES";
				}
				Gotoxy(x + 84, y++);
				cout << "��";

				Gotoxy(x, y);
				cout << "��";
				Gotoxy(x + 33, y);
				if (_currentArrow == 1)
				{
					cout << "���� NO";
				}
				else
				{
					cout << "	NO";
				}
				Gotoxy(x + 84, y++);
				cout << "��";
				Gotoxy(x, y);
				cout << "��";
				Gotoxy(x + 84, y++);
				cout << "��";
				Gotoxy(x, y++);
				cout << "��������������������������������������������������������������������������������������������������������������������������������������������������������������������������";
				if (_kbhit())
				{
					system("cls");

					char ch = _getch();
					switch (ch)
					{
						//wŰ�� ��������.
					case 'w':
						_currentArrow--;
						if (_currentArrow < 0)
						{
							_currentArrow = 0;
						}
						break;
						//sŰ�� ��������.
					case 's':
						_currentArrow++;
						if (_currentArrow > 1)
						{
							_currentArrow = 1;
						}
						break;
					case '\r':

						system("cls");
						Gotoxy(0, 0);

						if (_currentArrow == 0)
						{
							printInfom();
							Gotoxy(TEXTLINEX + 26, TEXTLINEY +2);
							cout << "[���� �Ѵ�]" << endl;
							money -= _betMoney;
							isBet = true;
							isNext = true;
						}
						else if (_currentArrow == 1)
						{
							printInfom();
							Gotoxy(TEXTLINEX + 26, TEXTLINEY +2);
							cout << "[���� ���Ѵ�]" << endl;
							isBet = false;
							isNext = true;
						}
						break;
					default:
						break;
					}

				}
			}

		}
		else if (!isPlayer)
		{
			int random = rand() % 2;
			if (random == 0)
			{
				printInfom();
				Gotoxy(COMPUTERTEXTX + 26, COMPUTERTEXTY +1);
				cout << "[���� �Ѵ�]" << endl;
				money -= _betMoney;
				isBet = true;
				Gotoxy(0, 30);
				system("pause");
			}
			else if (random == 1)
			{
				printInfom();
				Gotoxy(COMPUTERTEXTX + 26, COMPUTERTEXTY +1);
				cout << "[���� ���Ѵ�]" << endl;
				isBet = false;
				Gotoxy(0,30);
				system("pause");
			}
		}
		
	}
	void selectHighLowSeven()
	{
		if (isBet)
		{
			if (isPlayer)
			{
				cout << "High or Low or Seven (High : H, Low : L, Seven : S)" << endl;
				cin >> choice;
				if (choice == 'h')
				{
					choice = 'H';
				}
				else if (choice == 'l')
				{
					choice = 'L';
				}
				else if (choice == 's')
				{
					choice = 'S';
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
					cout << "[��ǻ�� ����...]" << endl;
					money += 2 * _betMoney;
				}
				else
				{
					cout << "[��ǻ�� ����!!!]" << endl;
				}
			}
			// Low
			if (choice == 'L')
			{
				if (7 > card)
				{
					cout << "[��ǻ�� ����...]" << endl;
					money += 2 * _betMoney;
				}
				else
				{
					cout << "[��ǻ�� ����!!!]" << endl;
				}
			}
			// Seven
			if (choice == 'S')
			{
				if (card == 7)
				{
					cout << "[��ǻ�� ����...]" << endl;
					money += 2 * _betMoney;
				}
				else
				{
					cout << "[��ǻ�� ����!!!]" << endl;
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


void main()
{
	SetCursor(false);
	srand(time(NULL));
	Card card;
	Unit player;
	player.isPlayer = true;
	player.isBet = false;
	player.money = 1000;
	Unit computer;
	computer.isPlayer = false;
	computer.isBet = false;
	computer.money = 1000;
	int x = 0;
	int y = 0;

	bool isEnd = false;

	card.init();
	while (!isEnd)
	{
		system("cls");

		isEnd = card.gameEnd();

		// ��ǻ�� �÷��̾� ���ÿ��� ����

		player.BetOrNot();

		computer.BetOrNot();

		// ��ǻ�� �÷��̾� ���ý� ���̷ο켼�� ����
		player.selectHighLowSeven();
		computer.selectHighLowSeven();
		// ��ǻ�� �÷��̾� ���ð� ī�� ��
		player.compare(card.card[card.current]);
		computer.compare(card.card[card.current]);
		cout << "�÷��̾� ������ : " << player.money << "\t��ǻ�� ������ :" << computer.money << endl;
		// �����ݿ� ���� ���г�Ÿ����
		player.checkResult(isEnd);
		computer.checkResult(isEnd);
		card.current++;
		system("pause");
	}

	if (player.money > computer.money)
	{
		cout << "\t\t{���� �¸�}" << endl;
		cout << "[��ǻ�� �й�!!!]" << "[�÷��̾� �¸�!!!]";
	}
	else if (computer.money > player.money)
	{
		cout << "\t\t{���� �¸�}" << endl;
		cout << "\t[��ǻ�� �¸�...]" << "[�÷��̾� �й�...]";
	}
	else
	{
		cout << "\t\t{���� �¸�}" << endl;
		cout << "\t[�� �� ��]";
	}

}