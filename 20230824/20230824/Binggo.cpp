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
	char Binggo[25];
	int binggoLine;
	bool isPlayer;
	void shuffle(char binggo[])
	{
		for (int i = 0; i < 25; i++)
		{
			char str = '0' + i + 1;
			binggo[i] = str;
		}
		for (int i = 0; i < 10000; i++)
		{
			int rand1 = rand() % 25;
			int rand2 = rand() % 25;
			int temp = binggo[rand1];
			binggo[rand1] = binggo[rand2];
			binggo[rand2] = temp;
		}
	}
	void showBinggo(char binggo[])
	{
		int num = 1;

		for (int i = 0; i < 25; i++)
		{
			cout << binggo[i] << "\t";
			if (num == 5)
			{
				cout << endl;
				num = 0;
			}
			num++;
		}
	}
};




void numInput(char myBinggo[], char comBinggo[], char input[], int& playTime, bool isPlayer)
{
	if (isPlayer)
	{
		cout << "\t[플레이어 차례]" << endl;
		cout << "1~25까지의 숫자 중 하나를 선택해주세요" << endl;
		cin >> input[playTime];
	}
	else
	{
		cout << "\t[컴퓨터 차례]" << endl;
		input[playTime] = rand() % 25 + 1;
		cout << "컴퓨터 선택 : " << input[playTime];

	}
	
	for (int i = 0; i < 25; i++)
	{
		if (myBinggo[i] == input[playTime])
		{
			myBinggo[i] = '#';
		}

		if (comBinggo[i] == input[playTime])
		{
			comBinggo[i] = '#';
		}
	}
	int num = 1;
	playTime++;
}
void checkBinggo(char binggo[], int& binggoLine)
{
	
	// 세로 확인
	for (int i = 0; i < 5; i++)
	{
		int same = 0;
		for (int j = 0; j < 5; j++)
		{
			if (binggo[i + j * 5] == '#')
			{
				same++;
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
	char Input[25] = {};
	int playTime =0;
	bool isBinggo = false;

	srand(time(NULL));

	system("cls");

	cout << "\t  플레이어 빙고" << endl;
	my.shuffle(my.Binggo);
	my.showBinggo(my.Binggo);
	cout << endl;
	cout << "\t   컴퓨터 빙고" << endl;
	com.shuffle(com.Binggo);
	com.showBinggo(com.Binggo);

	do
	{
		numInput(my.Binggo, com.Binggo, Input, playTime,my.isPlayer);
		my.showBinggo(my.Binggo);
		com.showBinggo(com.Binggo);
		numInput(my.Binggo, com.Binggo, Input, playTime, com.isPlayer);
		my.showBinggo(my.Binggo);
		com.showBinggo(com.Binggo);
		checkBinggo(my.Binggo, my.binggoLine);
		checkBinggo(com.Binggo, com.binggoLine);
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