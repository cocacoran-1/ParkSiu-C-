#include <iostream>
#include<time.h>
#include<Windows.h>
#define BINGO_SIZE 5
#define BOARD_SIZE (BINGO_SIZE * BINGO_SIZE)

int _input[BOARD_SIZE] = {};
int playCount = 0;
using namespace std;

struct User
{
	int Binggo[BOARD_SIZE];
	int bingGoLine;
	bool isPlayer;

	void init()
	{
		for (int i = 0; i < BOARD_SIZE; i++)
		{
			Binggo[i] = i + 1;
		}
	}
	void shuffle()
	{
		for (int i = 0; i < 10000; i++)
		{
			int num1 = rand() % BOARD_SIZE;
			int num2 = rand() % BOARD_SIZE;
			int temp = Binggo[num1];
			Binggo[num1] = Binggo[num2];
			Binggo[num2] = temp;
		}
	}
	void Show()
	{
		int num = 1;

		for (int i = 0; i < BOARD_SIZE; i++)
		{
			bool Same = false;
			for (int j = 0; j < BOARD_SIZE; j++)
			{
				if (Binggo[i] == _input[j])
				{
					Same = true;
				}
			}
			if (Same)
			{
				cout << "#\t";
			}
			else
			{
				cout << Binggo[i] << "\t";
			}

			if (num == 5)
			{
				cout << endl;
				num = 0;
			}
			num++;
		}
	}
	void Check()
	{
		// 세로 확인
		for (int i = 0; i < BINGO_SIZE; i++)
		{
			int sameCount = 0;
			for (int j = 0; j < BINGO_SIZE; j++)
			{
				for (int k = 0; k < BOARD_SIZE; k++)
				{
					if (Binggo[i + j * BINGO_SIZE] == _input[k])
					{
						sameCount++;
					}
				}

			}
			if (sameCount == BINGO_SIZE)
			{
				bingGoLine++;
			}
		}
		//가로 확인
		for (int i = 0; i < BINGO_SIZE; i++)
		{
			int sameCount = 0;
			for (int j = 0; j < BINGO_SIZE; j++)
			{
				for (int k = 0; k < BOARD_SIZE; k++)
				{
					if (Binggo[i * BINGO_SIZE + j] == _input[k])
					{
						sameCount++;
					}
				}
			}
			if (sameCount == BINGO_SIZE)
			{
				bingGoLine++;
			}
		}
		// 대각선 확인
		for (int i = 0; i < BINGO_SIZE; i++)
		{
			int sameCount = 0;
			for (int j = 0; j < BOARD_SIZE; j++)
			{
				if (Binggo[i * 6] == _input[j])
				{
					sameCount++;
				}
			}
			if (sameCount == BINGO_SIZE)
			{
				bingGoLine++;
			}
		}
		for (int i = 0; i < BINGO_SIZE; i++)
		{
			int sameCount = 0;
			for (int j = 0; j < BOARD_SIZE; j++)
			{
				if (Binggo[i * 4] == _input[j])
				{
					sameCount++;
				}
			}
			if (sameCount == BINGO_SIZE)
			{
				bingGoLine++;
			}
		}
	}
	void Input()
	{
		bool isSame = true;
		if (isPlayer)
		{
			while (isSame)
			{
				cout << endl << "\t  [플레이어 차례]" << endl;
				cout << "1~25까지의 숫자 중 하나를 선택해주세요" << endl;
				cin >> _input[playCount];
				cout << "플레이어 선택 : " << _input[playCount] << endl << endl;

				for (int i = 0; i < BOARD_SIZE; i++)
				{
					if (i != playCount)
					{
						if (_input[playCount] == _input[i])
						{
							cout << "이미 선택된 숫자입니다. 다시 선택해주세요" << endl;
							isSame = true;
						}
						else
						{
							isSame = false;
						}
					}
				}
			}
		}
		else
		{
			isSame = true;
			cout << endl << "\t   [컴퓨터 차례]" << endl;

			while (isSame)
			{
				_input[playCount] = rand() % BOARD_SIZE + 1;
				isSame = false;
				for (int i = 0; i < BOARD_SIZE; i++)
				{
					if (i != playCount)
					{
						if (_input[playCount] == _input[i])
						{
							isSame = true;
							break;
						}
					}
				}
			}
			cout << "컴퓨터 선택 : " << _input[playCount] << endl << endl;
		}
		playCount++;
	}
};

struct GameManager
{
	User player;
	User computer;
	void Init()
	{
		player.isPlayer = true;
		player.bingGoLine = 0;
		computer.isPlayer = false;
		computer.bingGoLine = 0;
	}
};



void main()
{
	GameManager gameManager;
	
	gameManager.Init();

	bool isBinggo = false;

	srand(time(NULL));
	system("cls");

	cout << "플레이어" << endl;
	gameManager.player.init();
	gameManager.player.shuffle();
	gameManager.player.Show();
	cout << "컴퓨터" << endl;
	gameManager.computer.init();
	gameManager.computer.shuffle();
	gameManager.computer.Show();

	do
	{
		gameManager.player.Input();
		cout << "\t  플레이어 빙고" << endl;
		gameManager.player.Show();
		cout << endl << "\t   컴퓨터 빙고" << endl;
		gameManager.computer.Show();

		gameManager.computer.Input();
		cout << "\t  플레이어 빙고" << endl;
		gameManager.player.Show();
		cout << endl << "\t   컴퓨터 빙고" << endl;
		gameManager.computer.Show();

		gameManager.player.Check();
		gameManager.computer.Check();

		if (gameManager.player.bingGoLine == 3)
		{
			cout << "플레이어 승";
			isBinggo = true;
		}
		else if (gameManager.computer.bingGoLine == 3)
		{
			cout << "컴퓨터 승";
			isBinggo = true;
		}
		else
		{
			gameManager.player.bingGoLine = 0;
			gameManager.computer.bingGoLine = 0;
		}

	} while (!isBinggo);


	system("pause");

}