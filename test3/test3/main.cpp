#include <iostream>
#include <time.h>
#include <Windows.h>
#include <conio.h> 
#define CARDSIZE 52
#define TEXTLINEX 35
#define TEXTLINEY 40
#define COMPUTERTEXTX 140
#define COMPUTERTEXTY 42
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
enum HighLowSeven
{
	High,
	Low,
	Seven,
	End
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
			Gotoxy(TEXTLINEX + 26, TEXTLINEY + 2);
			if (isBet)
			{
				cout << "[���� �Ѵ�]" << endl;
			}
			else if (!isBet)
			{
				cout << "[���� ���Ѵ�]" << endl;
			}

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
			Gotoxy(COMPUTERTEXTX + 26, COMPUTERTEXTY + 1);
			if (isBet)
			{
				cout << "[���� �Ѵ�]" << endl;
			}
			else if (!isBet)
			{
				cout << "[���� ���Ѵ�]" << endl;
			}
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
				x = TEXTLINEX * 2;
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
							money -= _betMoney;
							isBet = true;
							printInfom();
							isNext = true;
						}
						else if (_currentArrow == 1)
						{
							isBet = false;
							printInfom();
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
				money -= _betMoney;
				isBet = true;
				printInfom();

			}
			else if (random == 1)
			{
				isBet = false;
				printInfom();
			}
		}

	}
	void selectHighLowSeven()
	{

		bool isNext = false;
		_currentArrow = 0;

		if (isBet)
		{
			if (isPlayer)
			{
				while (!isNext)
				{
					int x = 63;
					int y = 30;
					Gotoxy(x, y++);
					cout << "��������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������";

					Gotoxy(x, y);
					cout << "��";
					Gotoxy(x + 20, y);
					cout << "High or Low or Seven (High : H, Low : L, Seven : S)" << endl;
					Gotoxy(x + 90, y++);
					cout << "��";

					Gotoxy(x, y);
					cout << "��";
					Gotoxy(x + 90, y++);
					cout << "��";

					Gotoxy(x, y);
					cout << "��";
					Gotoxy(x + 90, y++);
					cout << "��";

					Gotoxy(x, y);
					cout << "��";
					Gotoxy(x + 90, y++);
					cout << "��";
					Gotoxy(x, y);
					cout << "��";
					Gotoxy(x + 90, y++);
					cout << "��";
					Gotoxy(x, y);
					cout << "��";
					Gotoxy(x + 90, y++);
					cout << "��";
					Gotoxy(x, y);
					cout << "��������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������";


					switch (_currentArrow)
					{
					case 0:
						Gotoxy(x + 20, y - 4);
						cout << "                ";
						Gotoxy(x + 20, y - 4);
						cout << "���� HIGH";
						Gotoxy(x + 20, y - 3);
						cout << "                ";
						Gotoxy(x + 20, y - 3);
						cout << "	LOW";
						Gotoxy(x + 20, y - 2);
						cout << "                ";
						Gotoxy(x + 20, y - 2);
						cout << "	SEVEN";
						break;
					case 1:
						Gotoxy(x + 20, y - 4);
						cout << "                ";
						Gotoxy(x + 20, y - 4);
						cout << "	HIGH";
						Gotoxy(x + 20, y - 3);
						cout << "                ";
						Gotoxy(x + 20, y - 3);
						cout << "���� LOW";
						Gotoxy(x + 20, y - 2);
						cout << "                ";
						Gotoxy(x + 20, y - 2);
						cout << "	SEVEN";
						break;
					case 2:
						Gotoxy(x + 20, y - 4);
						cout << "                ";
						Gotoxy(x + 20, y - 4);
						cout << "	HIGH";
						Gotoxy(x + 20, y - 3);
						cout << "                ";
						Gotoxy(x + 20, y - 3);
						cout << "	LOW";
						Gotoxy(x + 20, y - 2);
						cout << "                ";
						Gotoxy(x + 20, y - 2);
						cout << "���� SEVEN";
						break;
					default:
						break;
					}

					if (_kbhit())
					{

						char ch = _getch();
						switch (ch)
						{
							//wŰ�� ��������.
						case 'w':
							_currentArrow--;
							printInfom();
							if (_currentArrow < 0)
							{
								_currentArrow = 0;
							}
							break;
							//sŰ�� ��������.
						case 's':
							_currentArrow++;
							printInfom();
							if (_currentArrow > 2)
							{
								_currentArrow = 2;
							}
							break;
						case '\r':
							Gotoxy(0, 50);
							system("cls");
							if (_currentArrow == High)
							{
								printInfom();
								choice = 'H';
								isNext = true;
							}
							else if (_currentArrow == Low)
							{
								printInfom();
								choice = 'L';
								isNext = true;
							}
							else if (_currentArrow == Seven)
							{
								printInfom();
								choice = 'S';
								isNext = true;
							}
							break;
						default:
							break;
						}

					}

				}
			}
			else
			{
				int random = rand() % 3;
				if (random == 0)
				{
					printInfom();
					choice = 'H';
				}
				else if (random == 1)
				{
					printInfom();
					choice = 'L';
				}
				else if (random == 2)
				{
					printInfom();
					choice = 'S';
				}
			}
		}
		else
		{
			printInfom();
			Gotoxy(0, 50);
			system("pause");
		}
	}
	void compare(int card)
	{
		if (isBet)
		{
			if (isPlayer)
			{
				// High
				if (choice == 'H')
				{
					if (card > 7)
					{
						money += 2 * _betMoney;
						printInfom();
						Gotoxy(TEXTLINEX, TEXTLINEY + 4);
						cout << "\t[�÷��̾� ����!!!]" << endl;
					}
					else
					{
						printInfom();
						Gotoxy(TEXTLINEX, TEXTLINEY + 4);
						cout << "\t[�÷��̾� ����...]" << endl;
					}
				}
				// Low
				if (choice == 'L')
				{
					if (7 > card)
					{
						money += 2 * _betMoney;
						printInfom();
						Gotoxy(TEXTLINEX, TEXTLINEY + 4);
						cout << "\t[�÷��̾� ����!!!]" << endl;
					}
					else
					{
						printInfom();
						Gotoxy(TEXTLINEX, TEXTLINEY + 4);
						cout << "\t[�÷��̾� ����...]" << endl;
					}
				}
				// Seven
				if (choice == 'S')
				{
					if (card == 7)
					{
						money += 5 * _betMoney;
						printInfom();
						Gotoxy(TEXTLINEX, TEXTLINEY + 4);
						cout << "\t[�÷��̾� ����!!!]" << endl;
					}
					else
					{
						printInfom();
						Gotoxy(TEXTLINEX, TEXTLINEY + 4);
						cout << "\t[�÷��̾� ����...]" << endl;
					}
				}
			}
			else if (!isPlayer)
			{
				// High
				if (choice == 'H')
				{
					if (card > 7)
					{
						money += 2 * _betMoney;
						printInfom();
						Gotoxy(COMPUTERTEXTX, COMPUTERTEXTY + 3);
						cout << "\t[��ǻ�� ����...]" << endl;
					}
					else
					{
						printInfom();
						Gotoxy(COMPUTERTEXTX, COMPUTERTEXTY + 3);
						cout << "\t[��ǻ�� ����!!!]" << endl;
					}
				}
				// Low
				if (choice == 'L')
				{
					if (7 > card)
					{
						money += 2 * _betMoney;
						printInfom();
						Gotoxy(COMPUTERTEXTX, COMPUTERTEXTY + 3);
						cout << "\t[��ǻ�� ����...]" << endl;
					}
					else
					{
						printInfom();
						Gotoxy(COMPUTERTEXTX, COMPUTERTEXTY + 3);
						cout << "\t[��ǻ�� ����!!!]" << endl;
					}
				}
				// Seven
				if (choice == 'S')
				{
					if (card == 7)
					{
						money += 5 * _betMoney;
						printInfom();
						Gotoxy(COMPUTERTEXTX, COMPUTERTEXTY + 3);
						cout << "\t[��ǻ�� ����...]" << endl;
					}
					else
					{
						printInfom();
						Gotoxy(COMPUTERTEXTX, COMPUTERTEXTY + 3);
						cout << "\t[��ǻ�� ����!!! ]" << endl;
					}
				}
			}

		}
		else
		{
			printInfom();
		}
		Gotoxy(0, 0);
		system("pause");

	}
	void checkResult(bool isEnd)
	{
		isEnd = false;
		if (isPlayer)
		{
			if (money == 0)
			{
				int x = 90;
				int y = 36;
				Gotoxy(TEXTLINEX, TEXTLINEY + 5);
				cout << "\t[�Ļ��߽��ϴ�...]" << endl;
				Gotoxy(x, y);
				cout << "��������������������������������������������������������������������������";
				Gotoxy(x, y+1);
				cout << "��";
				Gotoxy(x+10, y+1);
				cout << "[�÷��̾� �й�...]" << endl;
				Gotoxy(x+36, y+1);
				cout << "��";
				Gotoxy(x, y+2);
				cout << "��������������������������������������������������������������������������";
				isEnd = true;
				Gotoxy(0, 50);
			}
		}
		else
		{
			if (money == 0)
			{
				int x = 90;
				int y = 36;
				Gotoxy(COMPUTERTEXTX, COMPUTERTEXTY + 3);
				cout << "\t[��밡 �Ļ��߽��ϴ�!!!]" << endl;
				Gotoxy(x, y);
				cout << "��������������������������������������������������������������������������";
				Gotoxy(x, y+1);
				cout << "��";
				Gotoxy(x+10, y+1);
				cout << "[�÷��̾� �¸�!!!]" << endl;
				Gotoxy(x+36, y+1);
				cout << "��";
				Gotoxy(x, y+2);
				cout << "��������������������������������������������������������������������������";
				isEnd = true;
				Gotoxy(0, 50);
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
	computer.money = 100;
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