#include <iostream>
#include<time.h>
#include<Windows.h>

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
			Binggo[i] = i+1;
		}
	}
	void shuffle(int binggo[])
	{
		for (int i = 0; i < 10000; i++)
		{
			int rand1 = rand() % 25;
			int rand2 = rand() % 25;
			int temp = binggo[rand1];
			binggo[rand1] = binggo[rand2];
			binggo[rand2] = temp;
		}
	}
	void showBinggo(int binggo[], int input[])
	{
		int num = 1;
		bool isSame = false;
		for (int i = 0; i < 25; i++)
		{
			for (int j = 0; j < 25; j++)
			{
				if (binggo[i] == input[j])
				{
					isSame = true;
					break;
				}
				else
				{
					isSame = false;
				}
			}
			if (isSame)
			{
				cout << "#\t";
			}
			else
			{
				cout << binggo[i] << "\t";
			}
		
			if (num == 5)
			{
				cout << endl;
				num = 0;
			}
			num++;
		}
	}
};

void numInput(int myBinggo[], int comBinggo[], int input[], int& playTime, bool isPlayer)
{
	if (isPlayer)
	{
		cout << "\t[플레이어 차례]" << endl;
		cout << "1~25까지의 숫자 중 하나를 선택해주세요" << endl;
		cin >> input[playTime];
		cout << "플레이어 선택 : " << input[playTime] << endl;
	}
	else
	{
		cout << "\t[컴퓨터 차례]" << endl;
		input[playTime] = rand() % 25 + 1;
		cout << "컴퓨터 선택 : " << input[playTime] << endl;
	}

	playTime++;
}
void checkBinggo(int binggo[], int& binggoLine, int input[])
{
	
	// 세로 확인
	for (int i = 0; i < 5; i++)
	{
		int same = 0;
		for (int j = 0; j < 5; j++)
		{
			for (int k = 0; k < 25; k++)
			{
				if (binggo[i + j * 5] == input[k])
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

	for (int i = 0; i < 5; i++)
	{
		int same = 0;
		for (int j = 0; j < 5; j++)
		{
			if (binggo[i + j] == '#')
			{
				same++;
			}
		}
		if (same == 5)
		{
			binggoLine++;
		}
	}
}

void main()
{
	Unit my;
	Unit com;
	my.isPlayer = true;
	my.binggoLine = 0;
	com.isPlayer = false;
	com.binggoLine = 0;
	int Input[25] = {};
	int playTime =0;
	bool isBinggo = false;

	srand(time(NULL));

	system("cls");
	

	cout << "\t  플레이어 빙고" << endl;
	my.init();
	my.shuffle(my.Binggo);
	my.showBinggo(my.Binggo, Input);
	cout << endl;
	cout << "\t   컴퓨터 빙고" << endl;
	com.init();
	com.shuffle(com.Binggo);
	com.showBinggo(com.Binggo, Input);

	do
	{
		numInput(my.Binggo, com.Binggo, Input, playTime,my.isPlayer);
		my.showBinggo(my.Binggo,Input);
		com.showBinggo(com.Binggo,Input);
		numInput(my.Binggo, com.Binggo, Input, playTime, com.isPlayer);
		my.showBinggo(my.Binggo,Input);
		com.showBinggo(com.Binggo,Input);
		checkBinggo(my.Binggo, my.binggoLine, Input);
		checkBinggo(com.Binggo, com.binggoLine, Input);
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

	} while (!isBinggo);
	

	system("pause");

}