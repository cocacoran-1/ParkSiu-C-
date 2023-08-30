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
	- ж檜煎辦撮綻
	- 蘋萄 掘褻羹蒂 虜萇棻
	- 蘋萄縑 陝陝 璋濠蒂 睡罹и棻
	- 蘋萄曖 廓�� 滌煎 僥曄擊 睡罹и棻
	- 蘋萄蒂 摩朝棻
	- 餌辨濠 掘褻羹蒂 虜萇棻 (餌辨濠 模雖旎, 寡た 罹睡)
	- 餌辨濠陛 寡た й雖 寰й雖 薑и棻
	- 餌辨濠陛 寡た擊 ж雖 彊戲賊 模雖旎擎 斜渠煎 嶸雖
	- 餌辨濠陛 寡た擊 ж賊 模雖旎縑憮 漆た 旎擋 虜躑 離馬
		>> 餌辨濠陛 ж檜 煎辦 撮綻 醞 ж釭蒂 摹鷗и棻
	- 闡У攪紫 寡た擊 й雖 寰й雖 薑и棻
	- 闡У攪陛 寡た擊 ж賊 模雖旎縑憮 漆た 旎擋 虜躑 離馬
		>> 闡У攪陛 楠渾戲煎 ж檜 煎辦 撮綻 醞 ж釭蒂 摹��и棻
	- 餌辨濠諦 闡У攪曖 唸婁蒂 �挫恉炾� ж檜, 煎辦蒂 蜃轔 唳辦 寡た 旎擋曖 2寡 撮綻擊 蜃轔唳辦 7寡
	- ぎ萼 唳辦 嬴鼠匙紫 橢雖 彊朝棻
	- п渡 啪歜擊 蘋萄 熱 虜躑 奩犒и棻
	- 啪歜 醞 漆た擊 п撿ж朝等 模雖旎檜 0檜賊 だ骯 鼻渠寞檜 蝓葬
	- 翕衛縑 だ骯 衛 鼠蝓睡
	- 蘋萄 偃熱 虜躑 啪歜擊 霞чж堅 葆雖虞 模雖旎擊 綠掖п憮 蝓ぬ 薑и棻
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
		// 蘋萄縑 璋濠 睡罹
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
			suit = "Ⅵ";
			break;
		case 1:
			suit = "Ⅷ";
			break;
		case 2:
			suit = "﹣";
			break;
		case 3:
			suit = "Ⅳ";
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
		cout << " 忙式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式忖";
		Gotoxy(x, y++);
		if (value == "10")
		{
			cout << " 弛 " << value;
		}
		else
		{
			cout << " 弛  " << value;
		}
		if (value.length() == 1)
			cout << "              ";
		else
			cout << "             ";
		if (value == "10")
		{
			cout << "                    弛";
		}
		else
		{
			cout << "                   弛";
		}

		for (int i = 0; i < 13; i++)
		{
			Gotoxy(x, y++);
			cout << " 弛                                    弛";
		}
		Gotoxy(x, y++);
		cout << " 弛                  " << suit << "                弛";
		for (int i = 0; i < 13; i++)
		{
			Gotoxy(x, y++);
			cout << " 弛                                    弛";
		}
		Gotoxy(x, y++);
		if (value == "10")
		{
			cout << " 弛                                  " << value << "弛";
		}
		else
		{
			cout << " 弛                                  " << value << " 弛";
		}
		Gotoxy(x, y++);
		cout << " 戌式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式戎";
		Gotoxy(0, 50);

	}
	void PrintCardBack()
	{
		int y = 0;
		int x = 105;
		Gotoxy(x, y++);
		cout << " 忙式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式忖";

		for (int i = 0; i < 29; i++)
		{
			Gotoxy(x, y++);
			cout << " 弛〤〤〤〤〤〤〤〤〤〤〤〤〤〤〤〤〤〤〤〤〤〤〤〤〤〤〤〤〤〤〤〤〤〤〤〤弛";
		}
		Gotoxy(x, y++);
		cout << " 戌式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式戎";
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
			cout << "Ы溯檜橫";
			Gotoxy(x, y++);
			cout << "旨收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收旬";

			Gotoxy(x, y);
			cout << "早";
			Gotoxy(x + 2, y);
			cout << "模雖旎: " << money;
			Gotoxy(TEXT_LINE_X + 26, TEXT_LINE_Y + 2);
			if (isBet)
			{
				cout << "[漆た и棻]" << endl;
			}
			else if (!isBet)
			{
				cout << "[漆た 寰и棻]" << endl;
			}

			Gotoxy(x + 39, y++);
			cout << "早";

			Gotoxy(x, y);
			cout << "早";
			Gotoxy(x + 39, y++);
			cout << "早";

			Gotoxy(x, y);
			cout << "早";
			Gotoxy(x + 39, y++);
			cout << "早";

			Gotoxy(x, y);
			cout << "早";
			Gotoxy(x + 39, y++);
			cout << "早";

			Gotoxy(x, y);
			cout << "早";
			Gotoxy(x + 39, y++);
			cout << "早";

			Gotoxy(x, y++);
			cout << "曲收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收旭";
		}
		else
		{
			int x = COMPUTER_TEXT_X;
			int y = COMPUTER_TEXT_Y;

			Gotoxy(x + 2, y - 1);
			cout << "闡У攪";
			Gotoxy(x, y++);
			cout << "旨收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收旬";
			Gotoxy(x, y);
			cout << "早";
			Gotoxy(x + 2, y);
			cout << "模雖旎: " << money;
			Gotoxy(COMPUTER_TEXT_X + 26, COMPUTER_TEXT_Y + 1);
			if (isBet)
			{
				cout << "[漆た и棻]" << endl;
			}
			else if (!isBet)
			{
				cout << "[漆た 寰и棻]" << endl;
			}
			Gotoxy(x + 39, y++);
			cout << "早";

			Gotoxy(x, y);
			cout << "早";
			Gotoxy(x + 39, y++);
			cout << "早";

			Gotoxy(x, y);
			cout << "早";
			Gotoxy(x + 39, y++);
			cout << "早";

			Gotoxy(x, y);
			cout << "早";
			Gotoxy(x + 39, y++);
			cout << "早";

			Gotoxy(x, y);
			cout << "早";
			Gotoxy(x + 39, y++);
			cout << "早";

			Gotoxy(x, y++);
			cout << "曲收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收旭";
		}
	}
	void PrintInfomAll()
	{
		int x = TEXT_LINE_X;
		int y = TEXT_LINE_Y + 1;

		Gotoxy(x + 2, y - 1);
		cout << "Ы溯檜橫";
		Gotoxy(x, y++);
		cout << "旨收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收旬";

		Gotoxy(x, y);
		cout << "早";
		Gotoxy(x + 2, y);
		cout << "模雖旎: " << money;
		Gotoxy(TEXT_LINE_X + 26, TEXT_LINE_Y + 2);
		if (isBet)
		{
			cout << "[漆た и棻]" << endl;
		}
		else if (!isBet)
		{
			cout << "[漆た 寰и棻]" << endl;
		}

		Gotoxy(x + 39, y++);
		cout << "早";

		Gotoxy(x, y);
		cout << "早";
		Gotoxy(x + 39, y++);
		cout << "早";

		Gotoxy(x, y);
		cout << "早";
		Gotoxy(x + 39, y++);
		cout << "早";

		Gotoxy(x, y);
		cout << "早";
		Gotoxy(x + 39, y++);
		cout << "早";

		Gotoxy(x, y);
		cout << "早";
		Gotoxy(x + 39, y++);
		cout << "早";

		Gotoxy(x, y++);
		cout << "曲收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收旭";

		x = COMPUTER_TEXT_X;
		y = COMPUTER_TEXT_Y;

		Gotoxy(x + 2, y - 1);
		cout << "闡У攪";
		Gotoxy(x, y++);
		cout << "旨收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收旬";
		Gotoxy(x, y);
		cout << "早";
		Gotoxy(x + 2, y);
		cout << "模雖旎: " << money;
		Gotoxy(COMPUTER_TEXT_X + 26, COMPUTER_TEXT_Y + 1);
		if (isBet)
		{
			cout << "[漆た и棻]" << endl;
		}
		else if (!isBet)
		{
			cout << "[漆た 寰и棻]" << endl;
		}
		Gotoxy(x + 39, y++);
		cout << "早";

		Gotoxy(x, y);
		cout << "早";
		Gotoxy(x + 39, y++);
		cout << "早";

		Gotoxy(x, y);
		cout << "早";
		Gotoxy(x + 39, y++);
		cout << "早";

		Gotoxy(x, y);
		cout << "早";
		Gotoxy(x + 39, y++);
		cout << "早";

		Gotoxy(x, y);
		cout << "早";
		Gotoxy(x + 39, y++);
		cout << "早";

		Gotoxy(x, y++);
		cout << "曲收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收旭";
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
				cout << "旨收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收旬";
				Gotoxy(x, y);
				cout << "早";
				Gotoxy(x + 30, y);
				cout << "漆た擊 ж衛啊蝗棲梱?" << endl;
				Gotoxy(x + 84, y++);
				cout << "早";
				Gotoxy(x, y);
				cout << "早";
				Gotoxy(x + 84, y++);
				cout << "早";

				Gotoxy(x, y);
				cout << "早";
				Gotoxy(x + 33, y);
				if (_currentArrow == 0)
				{
					cout << "ⅠⅡ	YES";
				}
				else
				{
					cout << "	YES";
				}
				Gotoxy(x + 84, y++);
				cout << "早";

				Gotoxy(x, y);
				cout << "早";
				Gotoxy(x + 33, y);
				if (_currentArrow == 1)
				{
					cout << "ⅠⅡ	NO";
				}
				else
				{
					cout << "	NO";
				}
				Gotoxy(x + 84, y++);
				cout << "早";
				Gotoxy(x, y);
				cout << "早";
				Gotoxy(x + 84, y++);
				cout << "早";
				Gotoxy(x, y++);
				cout << "曲收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收旭";
				if (_kbhit())
				{
					system("cls");
					PrintInfomAll();
					char ch = _getch();
					switch (ch)
					{
						//w酈蒂 揚毓擊陽.
					case 'w':
						_currentArrow--;
						if (_currentArrow < 0)
						{
							_currentArrow = 0;
						}
						break;
						//s酈蒂 揚毓擊陽.
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
					cout << "旨收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收旬";

					Gotoxy(x, y);
					cout << "早";
					Gotoxy(x + 20, y);
					cout << "High or Low or Seven (High : H, Low : L, Seven : S)" << endl;
					Gotoxy(x + 90, y++);
					cout << "早";

					Gotoxy(x, y);
					cout << "早";
					Gotoxy(x + 90, y++);
					cout << "早";

					Gotoxy(x, y);
					cout << "早";
					Gotoxy(x + 90, y++);
					cout << "早";

					Gotoxy(x, y);
					cout << "早";
					Gotoxy(x + 90, y++);
					cout << "早";
					Gotoxy(x, y);
					cout << "早";
					Gotoxy(x + 90, y++);
					cout << "早";
					Gotoxy(x, y);
					cout << "早";
					Gotoxy(x + 90, y++);
					cout << "早";
					Gotoxy(x, y);
					cout << "曲收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收旭";

					x = 78;
					switch (_currentArrow)
					{
					case 0:
						Gotoxy(x + 20, y - 4);
						cout << "                ";
						Gotoxy(x + 20, y - 4);
						cout << "ⅠⅡ	HIGH";
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
						cout << "ⅠⅡ	LOW";
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
						cout << "ⅠⅡ	SEVEN";
						break;
					default:
						break;
					}

					if (_kbhit())
					{

						char ch = _getch();
						switch (ch)
						{
							//w酈蒂 揚毓擊陽.
						case 'w':
							_currentArrow--;
							PrintInfom();
							if (_currentArrow < 0)
							{
								_currentArrow = 0;
							}
							break;
							//s酈蒂 揚毓擊陽.
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
					cout << "\t[Ы溯檜橫 撩奢!!!]" << endl;
				}
				else
				{
					player.PrintInfom();
					Gotoxy(TEXT_LINE_X, TEXT_LINE_Y + 4);
					cout << "\t[Ы溯檜橫 褒ぬ...]" << endl;
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
					cout << "\t[Ы溯檜橫 撩奢!!!]" << endl;
				}
				else
				{
					player.PrintInfom();
					Gotoxy(TEXT_LINE_X, TEXT_LINE_Y + 4);
					cout << "\t[Ы溯檜橫 褒ぬ...]" << endl;
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
					cout << "\t[Ы溯檜橫 撩奢!!!]" << endl;
				}
				else
				{
					player.PrintInfom();
					Gotoxy(TEXT_LINE_X, TEXT_LINE_Y + 4);
					cout << "\t[Ы溯檜橫 褒ぬ...]" << endl;
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
					cout << "\t[闡У攪 撩奢...]" << endl;
				}
				else
				{
					computer.PrintInfom();
					Gotoxy(COMPUTER_TEXT_X, COMPUTER_TEXT_Y + 3);
					cout << "\t[闡У攪 褒ぬ!!!]" << endl;
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
					cout << "\t[闡У攪 撩奢...]" << endl;
				}
				else
				{
					computer.PrintInfom();
					Gotoxy(COMPUTER_TEXT_X, COMPUTER_TEXT_Y + 3);
					cout << "\t[闡У攪 褒ぬ!!!]" << endl;
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
					cout << "\t[闡У攪 撩奢...]" << endl;
				}
				else
				{
					computer.PrintInfom();
					Gotoxy(COMPUTER_TEXT_X, COMPUTER_TEXT_Y + 3);
					cout << "\t[闡У攪 褒ぬ!!! ]" << endl;
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
			cout << "\t[だ骯ц蝗棲棻...]" << endl;
			Gotoxy(x, y);
			cout << "旨收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收旬";
			Gotoxy(x, y + 1);
			cout << "早";
			Gotoxy(x + 10, y + 1);
			cout << "[Ы溯檜橫 ぬ寡...]" << endl;
			Gotoxy(x + 36, y + 1);
			cout << "早";
			Gotoxy(x, y + 2);
			cout << "曲收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收旭";
			isEnd = true;
			Gotoxy(0, 50);
		}
		else if (computer.money == 0)
		{
			int x = 90;
			int y = 36;
			Gotoxy(COMPUTER_TEXT_X, COMPUTER_TEXT_Y + 3);
			cout << "\t[鼻渠陛 だ骯ц蝗棲棻!!!]" << endl;
			Gotoxy(x, y);
			cout << "旨收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收旬";
			Gotoxy(x, y + 1);
			cout << "早";
			Gotoxy(x + 10, y + 1);
			cout << "[Ы溯檜橫 蝓葬!!!]" << endl;
			Gotoxy(x + 36, y + 1);
			cout << "早";
			Gotoxy(x, y + 2);
			cout << "曲收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收旭";
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

		// 闡У攪 Ы溯檜橫 寡た罹睡 摹鷗
		gameManager.player.BetOrNot();
		gameManager.computer.BetOrNot();

		// 闡У攪 Ы溯檜橫 寡た衛 ж檜煎辦撮綻 摹鷗
		gameManager.player.SelectHighLowSeven();
		gameManager.computer.SelectHighLowSeven();
		// 闡У攪 Ы溯檜橫 摹鷗婁 蘋萄 綠掖
		gameManager.CompareWithCurrentCard(card.card[card.current]);

		card.PrintCardFront();
		card.PrintCardBack();
		// 模雖旎縑 評塭 蝓ぬ釭顫頂晦
		gameManager.CheckResult();

		card.current++;
		system("pause");
	}

	if (gameManager.player.money > gameManager.computer.money)
	{
		Gotoxy(x, y);
		cout << "旨收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收旬";
		Gotoxy(x, y + 1);
		cout << "早";
		Gotoxy(x + 10, y + 1);
		cout << "[Ы溯檜橫 蝓葬!!!]" << endl;
		Gotoxy(x + 36, y + 1);
		cout << "早";
		Gotoxy(x, y + 2);
		cout << "曲收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收旭";
		Gotoxy(0, 50);
	}
	else if (gameManager.computer.money > gameManager.player.money)
	{
		Gotoxy(x, y);
		cout << "旨收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收旬";
		Gotoxy(x, y + 1);
		cout << "早";
		Gotoxy(x + 10, y + 1);
		cout << "[闡У攪 蝓葬...]" << endl;
		Gotoxy(x + 36, y + 1);
		cout << "早";
		Gotoxy(x, y + 2);
		cout << "曲收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收旭";
		Gotoxy(0, 50);
	}
	else
	{
		Gotoxy(x, y);
		cout << "旨收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收旬";
		Gotoxy(x, y + 1);
		cout << "早";
		Gotoxy(x + 10, y + 1);
		cout << "[鼠 蝓 睡]" << endl;
		Gotoxy(x + 36, y + 1);
		cout << "早";
		Gotoxy(x, y + 2);
		cout << "曲收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收旭";
		Gotoxy(0, 50);
	}
}