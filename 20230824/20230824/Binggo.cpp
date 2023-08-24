#include <iostream>
#include<time.h>
#include<Windows.h>

using namespace std;
/*
	���� ����
	5x5�� �̷���� ��ǻ�Ϳ� ���� ��
	�� ������ �ȿ��� 1~25�� ���ڰ� ����
	����� -> ��ǻ�� -> ����� -> ��ǻ�� ������ �ݺ�
	���� ������ �� �θ� ���ڴ� ���ڷ� ǥ�� �ȵǰ� #�� ǥ��
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
		cout << "\t[�÷��̾� ����]" << endl;
		cout << "1~25������ ���� �� �ϳ��� �������ּ���" << endl;
		cin >> input[playTime];
	}
	else
	{
		cout << "\t[��ǻ�� ����]" << endl;
		input[playTime] = rand() % 25 + 1;
		cout << "��ǻ�� ���� : " << input[playTime];

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
	
	// ���� Ȯ��
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

	cout << "\t  �÷��̾� ����" << endl;
	my.shuffle(my.Binggo);
	my.showBinggo(my.Binggo);
	cout << endl;
	cout << "\t   ��ǻ�� ����" << endl;
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
			cout << "\t\t�÷��̾� �¸�!!!";
			isBinggo = true;
		}
		else if (com.binggoLine == 3)
		{
			cout << "\t\t��ǻ�� �¸�....";
			isBinggo = true;
		}

	} while (!isBinggo);
	

	system("pause");

}