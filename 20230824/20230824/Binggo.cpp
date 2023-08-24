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
		cout << "\t[�÷��̾� ����]" << endl;
		cout << "1~25������ ���� �� �ϳ��� �������ּ���" << endl;
		cin >> input[playTime];
		cout << "�÷��̾� ���� : " << input[playTime] << endl;
	}
	else
	{
		cout << "\t[��ǻ�� ����]" << endl;
		input[playTime] = rand() % 25 + 1;
		cout << "��ǻ�� ���� : " << input[playTime] << endl;
	}

	playTime++;
}
void checkBinggo(int binggo[], int& binggoLine, int input[])
{
	
	// ���� Ȯ��
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
	

	cout << "\t  �÷��̾� ����" << endl;
	my.init();
	my.shuffle(my.Binggo);
	my.showBinggo(my.Binggo, Input);
	cout << endl;
	cout << "\t   ��ǻ�� ����" << endl;
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