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
			cout << "플레이어";
			Gotoxy(x, y++);
			cout << "┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓";

			Gotoxy(x, y);
			cout << "┃";
			Gotoxy(x + 2, y);
			cout << "소지금: " << money;
			Gotoxy(x + 39, y++);
			cout << "┃";

			Gotoxy(x, y);
			cout << "┃";
			Gotoxy(x + 39, y++);
			cout << "┃";

			Gotoxy(x, y);
			cout << "┃";
			Gotoxy(x + 39, y++);
			cout << "┃";

			Gotoxy(x, y);
			cout << "┃";
			Gotoxy(x + 39, y++);
			cout << "┃";

			Gotoxy(x, y);
			cout << "┃";
			Gotoxy(x + 39, y++);
			cout << "┃";

			Gotoxy(x, y++);
			cout << "┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛";
		}
		else
		{
			int x = COMPUTERTEXTX;
			int y = COMPUTERTEXTY;

			Gotoxy(x + 2, y - 1);
			cout << "컴퓨터";
			Gotoxy(x, y++);
			cout << "┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓";
			Gotoxy(x, y);
			cout << "┃";
			Gotoxy(x + 2, y);
			cout << "소지금: " << money;
			Gotoxy(x + 39, y++);
			cout << "┃";

			Gotoxy(x, y);
			cout << "┃";
			Gotoxy(x + 39, y++);
			cout << "┃";

			Gotoxy(x, y);
			cout << "┃";
			Gotoxy(x + 39, y++);
			cout << "┃";

			Gotoxy(x, y);
			cout << "┃";
			Gotoxy(x + 39, y++);
			cout << "┃";

			Gotoxy(x, y);
			cout << "┃";
			Gotoxy(x + 39, y++);
			cout << "┃";

			Gotoxy(x, y++);
			cout << "┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛";
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
				cout << "소지금: " << money;
				x = TEXTLINEX*2;
				y = TEXTLINEY + 1;
				Gotoxy(x, y++);
				cout << "┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓";
				Gotoxy(x, y);
				cout << "┃";
				Gotoxy(x + 30, y);
				cout << "베팅을 하시겠습니까?" << endl;
				Gotoxy(x + 84, y++);
				cout << "┃";
				Gotoxy(x, y);
				cout << "┃";
				Gotoxy(x + 84, y++);
				cout << "┃";

				Gotoxy(x, y);
				cout << "┃";
				Gotoxy(x + 33, y);
				if (_currentArrow == 0)
				{
					cout << "▷▶ YES";
				}
				else
				{
					cout << "	YES";
				}
				Gotoxy(x + 84, y++);
				cout << "┃";

				Gotoxy(x, y);
				cout << "┃";
				Gotoxy(x + 33, y);
				if (_currentArrow == 1)
				{
					cout << "▷▶ NO";
				}
				else
				{
					cout << "	NO";
				}
				Gotoxy(x + 84, y++);
				cout << "┃";
				Gotoxy(x, y);
				cout << "┃";
				Gotoxy(x + 84, y++);
				cout << "┃";
				Gotoxy(x, y++);
				cout << "┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛";
				if (_kbhit())
				{
					system("cls");

					char ch = _getch();
					switch (ch)
					{
						//w키를 눌렀을때.
					case 'w':
						_currentArrow--;
						if (_currentArrow < 0)
						{
							_currentArrow = 0;
						}
						break;
						//s키를 눌렀을때.
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
							cout << "[베팅 한다]" << endl;
							money -= _betMoney;
							isBet = true;
							isNext = true;
						}
						else if (_currentArrow == 1)
						{
							printInfom();
							Gotoxy(TEXTLINEX + 26, TEXTLINEY +2);
							cout << "[베팅 안한다]" << endl;
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
				cout << "[베팅 한다]" << endl;
				money -= _betMoney;
				isBet = true;
				Gotoxy(0, 30);
				system("pause");
			}
			else if (random == 1)
			{
				printInfom();
				Gotoxy(COMPUTERTEXTX + 26, COMPUTERTEXTY +1);
				cout << "[베팅 안한다]" << endl;
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
					cout << "[플레이어 성공!!!]" << endl;
					money += 2 * _betMoney;
				}
				else
				{
					cout << "[플레이어 실패...]" << endl;
				}
			}
			// Low
			if (choice == 'L')
			{
				if (7 > card)
				{
					cout << "[플레이어 성공!!!]" << endl;
					money += 2 * _betMoney;
				}
				else
				{
					cout << "[플레이어 실패...]" << endl;
				}
			}
			// Seven
			if (choice == 'S')
			{
				if (card == 7)
				{
					cout << "[플레이어 성공!!!]" << endl;
					money += 2 * _betMoney;
				}
				else
				{
					cout << "[플레이어 실패...]" << endl;
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
					cout << "[컴퓨터 성공...]" << endl;
					money += 2 * _betMoney;
				}
				else
				{
					cout << "[컴퓨터 실패!!!]" << endl;
				}
			}
			// Low
			if (choice == 'L')
			{
				if (7 > card)
				{
					cout << "[컴퓨터 성공...]" << endl;
					money += 2 * _betMoney;
				}
				else
				{
					cout << "[컴퓨터 실패!!!]" << endl;
				}
			}
			// Seven
			if (choice == 'S')
			{
				if (card == 7)
				{
					cout << "[컴퓨터 성공...]" << endl;
					money += 2 * _betMoney;
				}
				else
				{
					cout << "[컴퓨터 실패!!!]" << endl;
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
				cout << "[파산했습니다...]" << endl;
				cout << "[플레이어 패배...]" << endl;
				isEnd = true;
			}
		}
		else
		{
			if (money == 0)
			{
				cout << "[상대가 파산했습니다!!!]" << endl;
				cout << "[플레이어 승리!!!]" << endl;
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

		// 컴퓨터 플레이어 배팅여부 선택

		player.BetOrNot();

		computer.BetOrNot();

		// 컴퓨터 플레이어 배팅시 하이로우세븐 선택
		player.selectHighLowSeven();
		computer.selectHighLowSeven();
		// 컴퓨터 플레이어 선택과 카드 비교
		player.compare(card.card[card.current]);
		computer.compare(card.card[card.current]);
		cout << "플레이어 소지금 : " << player.money << "\t컴퓨터 소지금 :" << computer.money << endl;
		// 소지금에 따라 승패나타내기
		player.checkResult(isEnd);
		computer.checkResult(isEnd);
		card.current++;
		system("pause");
	}

	if (player.money > computer.money)
	{
		cout << "\t\t{최종 승리}" << endl;
		cout << "[컴퓨터 패배!!!]" << "[플레이어 승리!!!]";
	}
	else if (computer.money > player.money)
	{
		cout << "\t\t{최종 승리}" << endl;
		cout << "\t[컴퓨터 승리...]" << "[플레이어 패배...]";
	}
	else
	{
		cout << "\t\t{최종 승리}" << endl;
		cout << "\t[무 승 부]";
	}

}