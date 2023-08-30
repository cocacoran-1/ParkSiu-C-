#include <iostream>
#include <time.h>
#include <Windows.h>
#include <conio.h> 
#include <string>

#define TEXT_LINE_X 35
#define TEXT_LINE_Y 40
#define COMPUTER_TEXT_X 140
#define COMPUTER_TEXT_Y 42

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
	int card[52];
	int current;
	string suit;
	string value;

	void Init()
	{
		current = 0;
		// ī�忡 ���� �ο�
		for (int i = 0; i < 52; i++)
		{
			card[i] = i;
		}

		for (int i = 0; i < 10000; i++)
		{
			int num1 = rand() % 52;
			int num2 = rand() % 52;
			int temp = card[num1];
			card[num1] = card[num2];
			card[num2] = temp;
		}
	}

	void PrintCardFront()
	{
		int num = card[current];
		string suit;
		switch (num / 13)
		{
		case 0:
			suit = "��";
			break;
		case 1:
			suit = "��";
			break;
		case 2:
			suit = "��";
			break;
		case 3:
			suit = "��";
			break;
		default:
			break;
		}

		string value;
		switch (num % 13 + 1)
		{
		case 1:
			value = "A";
			break;
		case 11:
			value = "J";
			break;
		case 12:
			value = "Q";
			break;
		case 13:
			value = "K";
			break;
		default:
			value = to_string(num % 13 + 1);
			break;
		}
		int y = 0;
		int x = 65;
		Gotoxy(x, y++);
		cout << " ����������������������������������������������������������������������������";
		Gotoxy(x, y++);
		if (value == "10")
		{
			cout << " �� " << value;
		}
		else
		{
			cout << " ��  " << value;
		}
		if (value.length() == 1)
			cout << "              ";
		else
			cout << "             ";
		if (value == "10")
		{
			cout << "                    ��";
		}
		else
		{
			cout << "                   ��";
		}

		for (int i = 0; i < 13; i++)
		{
			Gotoxy(x, y++);
			cout << " ��                                    ��";
		}
		Gotoxy(x, y++);
		cout << " ��                  " << suit << "                ��";
		for (int i = 0; i < 13; i++)
		{
			Gotoxy(x, y++);
			cout << " ��                                    ��";
		}
		Gotoxy(x, y++);
		if (value == "10")
		{
			cout << " ��                                  " << value << "��";
		}
		else
		{
			cout << " ��                                  " << value << " ��";
		}
		Gotoxy(x, y++);
		cout << " ����������������������������������������������������������������������������";
		Gotoxy(0, 50);

	}
	void PrintCardBack()
	{
		int y = 0;
		int x = 105;
		Gotoxy(x, y++);
		cout << " ����������������������������������������������������������������������������";

		for (int i = 0; i < 29; i++)
		{
			Gotoxy(x, y++);
			cout << " ���ƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƦ�";
		}
		Gotoxy(x, y++);
		cout << " ����������������������������������������������������������������������������";
		Gotoxy(0, 50);

	}


	bool GameEnd()
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
struct User
{
	bool isPlayer;
	char choice;
	bool isBet;
	int money;
	int cardNum;

	void Init()
	{
		money = 1000;
		choice = '\0';
		bool isPlayer = false;
		isBet = false;
	}
	void PrintInfom()
	{
		if (isPlayer)
		{
			int x = TEXT_LINE_X;
			int y = TEXT_LINE_Y + 1;

			Gotoxy(x + 2, y - 1);
			cout << "�÷��̾�";
			Gotoxy(x, y++);
			cout << "��������������������������������������������������������������������������������";

			Gotoxy(x, y);
			cout << "��";
			Gotoxy(x + 2, y);
			cout << "������: " << money;
			Gotoxy(TEXT_LINE_X + 26, TEXT_LINE_Y + 2);
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
			int x = COMPUTER_TEXT_X;
			int y = COMPUTER_TEXT_Y;

			Gotoxy(x + 2, y - 1);
			cout << "��ǻ��";
			Gotoxy(x, y++);
			cout << "��������������������������������������������������������������������������������";
			Gotoxy(x, y);
			cout << "��";
			Gotoxy(x + 2, y);
			cout << "������: " << money;
			Gotoxy(COMPUTER_TEXT_X + 26, COMPUTER_TEXT_Y + 1);
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
	void PrintInfomAll()
	{
		int x = TEXT_LINE_X;
		int y = TEXT_LINE_Y + 1;

		Gotoxy(x + 2, y - 1);
		cout << "�÷��̾�";
		Gotoxy(x, y++);
		cout << "��������������������������������������������������������������������������������";

		Gotoxy(x, y);
		cout << "��";
		Gotoxy(x + 2, y);
		cout << "������: " << money;
		Gotoxy(TEXT_LINE_X + 26, TEXT_LINE_Y + 2);
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

		x = COMPUTER_TEXT_X;
		y = COMPUTER_TEXT_Y;

		Gotoxy(x + 2, y - 1);
		cout << "��ǻ��";
		Gotoxy(x, y++);
		cout << "��������������������������������������������������������������������������������";
		Gotoxy(x, y);
		cout << "��";
		Gotoxy(x + 2, y);
		cout << "������: " << money;
		Gotoxy(COMPUTER_TEXT_X + 26, COMPUTER_TEXT_Y + 1);
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
				PrintInfomAll();

				x = TEXT_LINE_X * 2 - 7;
				y = TEXT_LINE_Y - 10;
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
					cout << "����	YES";
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
					cout << "����	NO";
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
					PrintInfomAll();
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
							PrintInfom();
							isNext = true;
						}
						else if (_currentArrow == 1)
						{
							isBet = false;
							PrintInfom();
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
				PrintInfom();

			}
			else if (random == 1)
			{
				isBet = false;
				PrintInfom();
			}
		}

	}
	void SelectHighLowSeven()
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

					x = 78;
					switch (_currentArrow)
					{
					case 0:
						Gotoxy(x + 20, y - 4);
						cout << "                ";
						Gotoxy(x + 20, y - 4);
						cout << "����	HIGH";
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
						cout << "����	LOW";
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
						cout << "����	SEVEN";
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
							PrintInfom();
							if (_currentArrow < 0)
							{
								_currentArrow = 0;
							}
							break;
							//sŰ�� ��������.
						case 's':
							_currentArrow++;
							PrintInfom();
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
								PrintInfom();
								choice = 'H';
								isNext = true;
							}
							else if (_currentArrow == Low)
							{
								PrintInfom();
								choice = 'L';
								isNext = true;
							}
							else if (_currentArrow == Seven)
							{
								PrintInfom();
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
					PrintInfom();
					choice = 'H';
				}
				else if (random == 1)
				{
					PrintInfom();
					choice = 'L';
				}
				else if (random == 2)
				{
					PrintInfom();
					choice = 'S';
				}
			}
		}
		else
		{
			PrintInfom();
		}
	}

};

struct GameManager
{
	bool isEnd;
	Card card;
	User player;
	User computer;

	void Init()
	{
		isEnd = false;
	}
	void CompareWithCurrentCard(int cardNum)
	{
		if (player.isBet)
		{
			// High
			if (player.choice == 'H')
			{
				if (cardNum > 7)
				{
					player.money += 2 * _betMoney;
					player.PrintInfom();
					Gotoxy(TEXT_LINE_X, TEXT_LINE_Y + 4);
					cout << "\t[�÷��̾� ����!!!]" << endl;
				}
				else
				{
					player.PrintInfom();
					Gotoxy(TEXT_LINE_X, TEXT_LINE_Y + 4);
					cout << "\t[�÷��̾� ����...]" << endl;
				}
			}
			// Low
			if (player.choice == 'L')
			{
				if (7 > cardNum)
				{
					player.money += 2 * _betMoney;
					player.PrintInfom();
					Gotoxy(TEXT_LINE_X, TEXT_LINE_Y + 4);
					cout << "\t[�÷��̾� ����!!!]" << endl;
				}
				else
				{
					player.PrintInfom();
					Gotoxy(TEXT_LINE_X, TEXT_LINE_Y + 4);
					cout << "\t[�÷��̾� ����...]" << endl;
				}
			}
			// Seven
			if (player.choice == 'S')
			{
				if (cardNum == 7)
				{
					player.money += 5 * _betMoney;
					player.PrintInfom();
					Gotoxy(TEXT_LINE_X, TEXT_LINE_Y + 4);
					cout << "\t[�÷��̾� ����!!!]" << endl;
				}
				else
				{
					player.PrintInfom();
					Gotoxy(TEXT_LINE_X, TEXT_LINE_Y + 4);
					cout << "\t[�÷��̾� ����...]" << endl;
				}
			}

		}
		else
		{
			player.PrintInfom();
		}

		if (computer.isBet)
		{
			// High
			if (computer.choice == 'H')
			{
				if (cardNum > 7)
				{
					computer.money += 2 * _betMoney;
					computer.PrintInfom();
					Gotoxy(COMPUTER_TEXT_X, COMPUTER_TEXT_Y + 3);
					cout << "\t[��ǻ�� ����...]" << endl;
				}
				else
				{
					computer.PrintInfom();
					Gotoxy(COMPUTER_TEXT_X, COMPUTER_TEXT_Y + 3);
					cout << "\t[��ǻ�� ����!!!]" << endl;
				}
			}
			// Low
			if (computer.choice == 'L')
			{
				if (7 > cardNum)
				{
					computer.money += 2 * _betMoney;
					computer.PrintInfom();
					Gotoxy(COMPUTER_TEXT_X, COMPUTER_TEXT_Y + 3);
					cout << "\t[��ǻ�� ����...]" << endl;
				}
				else
				{
					computer.PrintInfom();
					Gotoxy(COMPUTER_TEXT_X, COMPUTER_TEXT_Y + 3);
					cout << "\t[��ǻ�� ����!!!]" << endl;
				}
			}
			// Seven
			if (computer.choice == 'S')
			{
				if (cardNum == 7)
				{
					computer.money += 5 * _betMoney;
					computer.PrintInfom();
					Gotoxy(COMPUTER_TEXT_X, COMPUTER_TEXT_Y + 3);
					cout << "\t[��ǻ�� ����...]" << endl;
				}
				else
				{
					computer.PrintInfom();
					Gotoxy(COMPUTER_TEXT_X, COMPUTER_TEXT_Y + 3);
					cout << "\t[��ǻ�� ����!!! ]" << endl;
				}
			}


		}
		else
		{
			computer.PrintInfom();
		}

	}

	void CheckResult()
	{
		isEnd = false;
		if (player.money == 0)
		{
			int x = 90;
			int y = 36;
			Gotoxy(TEXT_LINE_X, TEXT_LINE_Y + 5);
			cout << "\t[�Ļ��߽��ϴ�...]" << endl;
			Gotoxy(x, y);
			cout << "��������������������������������������������������������������������������";
			Gotoxy(x, y + 1);
			cout << "��";
			Gotoxy(x + 10, y + 1);
			cout << "[�÷��̾� �й�...]" << endl;
			Gotoxy(x + 36, y + 1);
			cout << "��";
			Gotoxy(x, y + 2);
			cout << "��������������������������������������������������������������������������";
			isEnd = true;
			Gotoxy(0, 50);
		}
		else if (computer.money == 0)
		{
			int x = 90;
			int y = 36;
			Gotoxy(COMPUTER_TEXT_X, COMPUTER_TEXT_Y + 3);
			cout << "\t[��밡 �Ļ��߽��ϴ�!!!]" << endl;
			Gotoxy(x, y);
			cout << "��������������������������������������������������������������������������";
			Gotoxy(x, y + 1);
			cout << "��";
			Gotoxy(x + 10, y + 1);
			cout << "[�÷��̾� �¸�!!!]" << endl;
			Gotoxy(x + 36, y + 1);
			cout << "��";
			Gotoxy(x, y + 2);
			cout << "��������������������������������������������������������������������������";
			isEnd = true;
			Gotoxy(0, 50);
		}
	}
};
void main()
{
	SetCursor(false);
	srand(time(NULL));

	Card card;
	GameManager gameManager;

	gameManager.player.isBet = false;
	gameManager.computer.isBet = false;

	int x = 0;
	int y = 0;

	card.Init();
	gameManager.player.Init();
	gameManager.computer.Init();
	gameManager.Init();
	gameManager.computer.isPlayer = false;
	gameManager.player.isPlayer = true;

	while (!gameManager.isEnd)
	{
		system("cls");

		gameManager.isEnd = card.GameEnd();

		// ��ǻ�� �÷��̾� ���ÿ��� ����
		gameManager.player.BetOrNot();
		gameManager.computer.BetOrNot();

		// ��ǻ�� �÷��̾� ���ý� ���̷ο켼�� ����
		gameManager.player.SelectHighLowSeven();
		gameManager.computer.SelectHighLowSeven();
		// ��ǻ�� �÷��̾� ���ð� ī�� ��
		gameManager.CompareWithCurrentCard(card.card[card.current]);

		card.PrintCardFront();
		card.PrintCardBack();
		// �����ݿ� ���� ���г�Ÿ����
		gameManager.CheckResult();

		card.current++;
		system("pause");
	}

	if (gameManager.player.money > gameManager.computer.money)
	{
		Gotoxy(x, y);
		cout << "��������������������������������������������������������������������������";
		Gotoxy(x, y + 1);
		cout << "��";
		Gotoxy(x + 10, y + 1);
		cout << "[�÷��̾� �¸�!!!]" << endl;
		Gotoxy(x + 36, y + 1);
		cout << "��";
		Gotoxy(x, y + 2);
		cout << "��������������������������������������������������������������������������";
		Gotoxy(0, 50);
	}
	else if (gameManager.computer.money > gameManager.player.money)
	{
		Gotoxy(x, y);
		cout << "��������������������������������������������������������������������������";
		Gotoxy(x, y + 1);
		cout << "��";
		Gotoxy(x + 10, y + 1);
		cout << "[��ǻ�� �¸�...]" << endl;
		Gotoxy(x + 36, y + 1);
		cout << "��";
		Gotoxy(x, y + 2);
		cout << "��������������������������������������������������������������������������";
		Gotoxy(0, 50);
	}
	else
	{
		Gotoxy(x, y);
		cout << "��������������������������������������������������������������������������";
		Gotoxy(x, y + 1);
		cout << "��";
		Gotoxy(x + 10, y + 1);
		cout << "[�� �� ��]" << endl;
		Gotoxy(x + 36, y + 1);
		cout << "��";
		Gotoxy(x, y + 2);
		cout << "��������������������������������������������������������������������������";
		Gotoxy(0, 50);
	}
}