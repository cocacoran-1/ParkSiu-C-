#include <iostream>
#include<time.h>
#include<Windows.h>

int _input[25] = {};
int playTime = 0;
using namespace std;
/*
	빙고 게임
	5x5로 이루어진 컴퓨터와 나의 판
	각 빙고판 안에는 1~25의 숫자가 들어간다
	사용자 -> 컴퓨터 -> 사용자 -> 컴퓨터 순서로 반복
	각자 차례일 떄 부른 숫자는 수자로 표기 안되고 #로 표기
*/

struct Unit
{
	int Binggo[25];
	int binggoLine;
	bool isPlayer;

	void init()
	{
		for (int i = 0; i < 25; i++)
		{
			Binggo[i] = i + 1;
		}
	}
	void shuffle()
	{
		for (int i = 0; i < 10000; i++)
		{
			int rand1 = rand() % 25;
			int rand2 = rand() % 25;
			int temp = Binggo[rand1];
			Binggo[rand1] = Binggo[rand2];
			Binggo[rand2] = temp;
		}
	}
	void showBinggo()
	{
		int num = 1;

		for (int i = 0; i < 25; i++)
		{
			bool isSame = false;
			for (int j = 0; j < 25; j++)
			{
				if (Binggo[i] == _input[j])
				{
					isSame = true;
				}
			}
			if (isSame)
			{
				cout << "■\t";
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
	void checkBinggo()
	{
		// 세로 확인
		for (int i = 0; i < 5; i++)
		{
			int same = 0;
			for (int j = 0; j < 5; j++)
			{
				for (int k = 0; k < 25; k++)
				{
					if (Binggo[i + j * 5] == _input[k])
					{
						same++;
					}
				}

			}
			if (same == 5)
			{
				binggoLine++;
			}
		}
		//가로 확인
		for (int i = 0; i < 5; i++)
		{
			int same = 0;
			for (int j = 0; j < 5; j++)
			{
				for (int k = 0; k < 25; k++)
				{
					if (Binggo[i * 5 + j] == _input[k])
					{
						same++;
					}
				}
			}
			if (same == 5)
			{
				binggoLine++;
			}
		}
	}
	void numInput()
	{
		bool isSame = true;
		if (isPlayer)
		{
			while (isSame)
			{
				cout << endl << "\t  [플레이어 차례]" << endl;
				cout << "1~25까지의 숫자 중 하나를 선택해주세요" << endl;
				cin >> _input[playTime];
				cout << "플레이어 선택 : " << _input[playTime] << endl << endl;

				for (int i = 0; i < 25; i++)
				{
					if (i != playTime)
					{
						if (_input[playTime] == _input[i])
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
				_input[playTime] = rand() % 25 + 1;
				isSame = false;
				for (int i = 0; i < 25; i++)
				{
					if (i != playTime)
					{
						if (_input[playTime] == _input[i])
						{
							isSame = true;
							break;
						}
					}
				}
			}
			cout << "컴퓨터 선택 : " << _input[playTime] << endl << endl;
		}
		playTime++;
	}
};





void main()
{
	Unit my;
	my.isPlayer = true;
	my.binggoLine = 0;

	Unit com;
	com.isPlayer = false;
	com.binggoLine = 0;

	bool isBinggo = false;

	srand(time(NULL));

	system("cls");

	cout << "\t  플레이어 빙고" << endl;
	my.init();
	my.shuffle();
	my.showBinggo();
	cout << endl;
	cout << "\t   컴퓨터 빙고" << endl;
	com.init();
	com.shuffle();
	com.showBinggo();

	do
	{
		my.numInput();
		cout << "\t  플레이어 빙고" << endl;
		my.showBinggo();
		cout << endl << "\t   컴퓨터 빙고" << endl;
		com.showBinggo();

		com.numInput();
		cout << "\t  플레이어 빙고" << endl;
		my.showBinggo();
		cout << endl << "\t   컴퓨터 빙고" << endl;
		com.showBinggo();

		my.checkBinggo();
		com.checkBinggo();

		if (my.binggoLine == 3)
		{
			cout << "\t\t플레이어 승리!!!";
			isBinggo = true;
		}
		else if (com.binggoLine == 3)
		{
			cout << "\t\t컴퓨터 승리....";
			isBinggo = true;
		}
		else
		{
			my.binggoLine = 0;
			com.binggoLine = 0;
		}

	} while (!isBinggo);


	system("pause");

}